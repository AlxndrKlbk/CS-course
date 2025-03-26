#include <vector>
#include <thread>
#include <future>
#include <iostream>
#include <chrono>

int myFunction(std::promise<int>&& promise)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    promise.set_value(88);
    return 0;
}

int main(int argc, char** argv)
{
    std::vector<std::pair<std::thread, std::future<int>>> threads;

    std::promise<int> prms;
    std::future<int> fut = prms.get_future();

    std::thread th(myFunction, std::move(prms));
    threads.push_back(make_pair(std::move(th), std::move(fut)));

    while (!threads.empty())
    {

        auto e = threads.begin();
        auto& th = e->first;
        auto& fut = e->second;

        // with small wait_for value (like 0 seconds), looks like th starve and will newer set promise value
        auto status = fut.valid() ? fut.wait_for(std::chrono::milliseconds(100)) : std::future_status::deferred;
        if (status == std::future_status::ready) {
            int thread_value = fut.get();
            std::cout << thread_value << std::endl;
            th.join();
            threads.erase(e);
        } else if (status == std::future_status::deferred) {
            if (th.joinable()) {
                th.join();
            } else {
                th.detach();
            }
            break;
        }else {
            std::cout << "still waiting to response ..." << std::endl;
        }
    }

    return 0;
}
