#include <chrono>
#include <functional>
#include <map>
#include <thread>
#include <mutex>
#include <memory>
#include <condition_variable>
#include <iostream>

using namespace std::chrono;

using unique_id_t = std::uint16_t;
using duration_t = std::chrono::milliseconds;
using callback_t = std::function<void(unique_id_t)>;

struct Timer {
    unique_id_t id;
    duration_t duration;        // amount of time in seconds to launch callback
    callback_t cb;
};

/**
 * @brief The TimerReactor class - execute callback after given time
 */
class TimerReactor // 1 thread
{
public:

    TimerReactor()
    {
        mIntercept = false;
        mPool = std::make_unique<std::thread>(&TimerReactor::process, this);
    }

    ~TimerReactor()
    {
        mIntercept = true;
        mCondition.notify_all();
        mPool->join();
    }

    void add(Timer const& timer) // timer started
    {
        std::lock_guard quard(mBlock);
        auto exec_time = time_point_cast<milliseconds>(high_resolution_clock::now() + timer.duration).time_since_epoch();
        mTask[exec_time].push_back(timer);
        mCondition.notify_all();
    }

    void process()
    {
        auto task_process = [this]() {
            auto nearest = mTask.begin();
            auto current = time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch();
            if (current > nearest->first){
                for (auto const& event : nearest->second) {
                    event.cb(event.id);
                }
                mTask.erase(nearest);
            }
        };

        while (true) {
            if (mIntercept) {
                std::lock_guard guard(mBlock);
                while (!mTask.empty()) {
                    task_process();
                }
                return;
            }

            std::unique_lock lock(mBlock);
            if (mTask.empty()) {
                mCondition.wait(lock);
            }
            task_process();
        }
    }

private:
    std::unordered_map<unique_id_t, callback_t> mCallbacks;
    std::map<std::chrono::milliseconds, std::vector<Timer>> mTask;
    std::mutex mBlock;
    std::atomic<bool> mIntercept;
    std::unique_ptr<std::thread> mPool;
    std::condition_variable mCondition;
};


int main(int argc, char** argv)
{
    TimerReactor r;

    auto cb = [](auto id){ std::cout << id << std::endl;};

    r.add({1, milliseconds(10000), cb}); // t1
    r.add({2, milliseconds(5000), cb}); // t2
    r.add({3, milliseconds(1000), cb}); // t3

    sleep(1);
    r.add({4, milliseconds(0), cb});

    return 0;
}



