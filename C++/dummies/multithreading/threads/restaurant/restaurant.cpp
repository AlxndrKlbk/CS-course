#include "restaurant.hpp"

#include <iostream>


void Restaurant::chef() {
    std::unique_lock<std::mutex> ul(order);
    orderBell.wait(ul, [this]() { return orderStatus == Status::newOrder; });
    //приготовление блюд из заказа
    orderStatus = Status::ready;
    orderBell.notify_one();

}

void Restaurant::waiter() {
    {
        std::lock_guard<std::mutex> lg(order);
        orderStatus = Status::newOrder;
        orderBell.notify_one();
    } // lg вне области видимости = order.unlock()

    std::unique_lock<std::mutex> ul(order);
    orderBell.wait(ul, [this]() { return orderStatus == Status::ready; });
    orderStatus = Status::idle;
    ul.unlock();
}
