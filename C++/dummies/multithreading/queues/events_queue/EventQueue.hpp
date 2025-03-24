#pragma once

#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <string>
#include <stdint.h>

#ifdef USE_TESTS
#include <map>
#endif

#ifdef USE_TESTS
using MapStats = std::map<ObjectType, uint32_t>;
#endif

class EventsCache
{
public:
    void invalidate() {};
};

enum class ObjectType
{
    USER,
    GROUP,
    COMMENT,
    ADDRESS
};

struct Event
{
    uint32_t id;
    std::string message;
    ObjectType type;
};

class EventQueue
{
public:

    EventQueue();
    ~EventQueue();

    void addEvent(Event const& event);

#ifdef USE_TESTS
    MapStats getTestStats() {return mTestStats; }
#endif

private:
    // mThread is not copyable
    EventQueue(EventQueue const &) = delete;
    EventQueue(EventQueue &&) = delete;
    EventQueue& operator=(EventQueue const &) = delete;
    EventQueue& operator=(EventQueue &&) = delete;

    void processEvents();

    /**
     * @brief dropCache - clear caches state
     */
    void dropCache();

private:
    std::mutex mQueueMutex;
    std::thread mThread;
    std::queue<Event> mEventQueue;
    std::condition_variable mEventIOCondition;
    std::atomic<bool> mAlive;
#ifdef USE_TESTS
    MapStats mTestStats;
#endif

    EventsCache* mCache = nullptr;
};
