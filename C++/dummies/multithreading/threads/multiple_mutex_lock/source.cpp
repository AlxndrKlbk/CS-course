#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
std::mutex m2;

void function(int thread_num) {
    std::lock(m1, m2);
    std::lock_guard<std::mutex> lk1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> lk2(m2, std::adopt_lock);

    // C++17 alternative, to avoid lock std::lock_guard or handly mutex.unlock()
    // std::scoped_lock lock(m1, m2);

    // Код, защищенный мьютексами
    std::cout << "Мьютексы захвачены потоком " << thread_num << std::endl;

}

int main() {
    std::thread thread1(function, 1);
    std::thread thread2(function, 2);


    if (thread1.joinable()) {
        thread1.join();
    }

    if (thread2.joinable()) {
        thread2.join();
    }

    return 0;
}
