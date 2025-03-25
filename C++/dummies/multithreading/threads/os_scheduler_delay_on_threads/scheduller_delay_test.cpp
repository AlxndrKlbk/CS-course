#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>

void thread_on_mutex(int threads_num)
{
    std::mutex shared_mutex;

    auto cout_msg = [&shared_mutex](int thread_num) {
        std::lock_guard<std::mutex> lock(shared_mutex);
        std::cout << "message from thread #" << thread_num << std::endl;
    };

    std::vector<std::thread> thread_storrage;
    for (int i = 0; i < threads_num; i++) {
        thread_storrage.emplace_back(std::thread(cout_msg, i));
    }

    for (auto&& thread : thread_storrage) {
        thread.join();
    }
}

void thread_on_atomic(int threads_num)
{
    std::atomic<bool> cout_block = true;

    auto cout_msg = [&cout_block](int thread_num) {
        while(!cout_block) {}
        cout_block = false;
        std::cout << "message from thread #" << thread_num << std::endl;
        cout_block = true;
    };

    std::vector<std::thread> thread_storrage;
    for (int i = 0; i < threads_num; i++) {
        thread_storrage.emplace_back(std::thread(cout_msg, i));
    }

    for (auto&& thread : thread_storrage) {
        thread.join();
    }

}

std::chrono::high_resolution_clock timer;

int main(int argc, char** argv)
{

    std::ofstream dev_null("/dev/null");
    std::streambuf* strm_buffer = std::cout.rdbuf();
    std::cout.rdbuf(dev_null.rdbuf());

    auto begin = timer.now();
    thread_on_mutex(10000);
    auto end = timer.now();

    std::cout.rdbuf(strm_buffer);
    std::cout << "Runtime on thread with mutex:" << std::chrono::duration_cast<std::chrono::milliseconds>((end - begin)) << std::endl;

    std::cout.rdbuf(dev_null.rdbuf());
    begin = timer.now();
    thread_on_atomic(10000);
    end = timer.now();
    std::cout.rdbuf(strm_buffer);
    std::cout << "Runtime on thread with atomic:" << std::chrono::duration_cast<std::chrono::milliseconds>((end - begin)) << std::endl;

    return 0;
}
