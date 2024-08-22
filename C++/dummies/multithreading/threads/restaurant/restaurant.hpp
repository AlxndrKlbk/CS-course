#include <mutex>
#include <condition_variable>

class Restaurant {
    enum class Status { idle, newOrder, ready };
    Status orderStatus = Status::idle;
    std::mutex order;
    std::condition_variable orderBell;

public:
    void chef();
    void waiter();

};
