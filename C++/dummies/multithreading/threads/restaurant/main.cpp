#include "restaurant.hpp"
#include <thread>


int main() {
    Restaurant restaurant;
    std::thread chef(&Restaurant::chef, std::ref(restaurant));
    std::thread waiter(&Restaurant::waiter, std::ref(restaurant));
    chef.join();
    waiter.join();
    return 0;
}
