#include <vector>
#include <mutex>
#include <queue>
#include <thread>
#include <iostream>


class ThreadSafeQueue
{
private:
    std::queue<int> mRawQueue;
    std::mutex mBlock;

public:

    int retrieve_and_delete()
    {
        int front_value = 0; // если пустая, возвращает 0
        std::lock_guard<std::mutex> lg(mBlock);

        if( !mRawQueue.empty() ) {
            front_value = mRawQueue.front();
            mRawQueue.pop();
        }

        return front_value;
    };

    void push(int val)
    {
        std::lock_guard<std::mutex> lg(mBlock);
        mRawQueue.push(val);
    };
};

std::mutex queue_usage_mtx;
void queue_usage(ThreadSafeQueue& queue, int threadNum) {
    std::lock_guard<std::mutex> lc(queue_usage_mtx);
    std::cout << "queue used by thread № " << threadNum << '\n';
    queue.push(threadNum);
}

int main (int argc, char** argv) {

    ThreadSafeQueue queue;
    std::vector<std::thread> threads;

    for (int i = 1; i < 5; i++) {
        threads.emplace_back(std::thread(queue_usage, std::ref(queue), i));
    }

    for (auto&& thread : threads) {
        thread.join();
    }

    while (true) {
        auto&& val = queue.retrieve_and_delete();
        std::cout << val << ' ';

        if (val == 0) {
            break;
        }
    }
    std::cout << '\n';

    return 0;
}
