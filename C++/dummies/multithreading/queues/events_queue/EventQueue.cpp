#include "EventQueue.hpp"

EventQueue::EventQueue()
    : mAlive{true}
{
    mThread = std::thread(&EventQueue::processEvents, this);

    mCache = new EventsCache();
}

EventQueue::~EventQueue()
{
    mAlive = false;
    mEventIOCondition.notify_all();
    mThread.join();
    delete mCache;
}

void EventQueue::addEvent(Event const& event)
{
    std::unique_lock<std::mutex> lck(mQueueMutex);
    mEventQueue.push(event);
    mEventIOCondition.notify_all();
}

void EventQueue::processEvents()
{
    while (mAlive)
    {
        Event event;

        /* Critical section with IO wait if no new events in queue
         * thread capture mutex only to queue usage
         */
        {
            std::unique_lock<std::mutex> lck(mQueueMutex);
            while (mEventQueue.empty())
            {
                mEventIOCondition.wait(lck);
                if (!mAlive) {
                    return;
                }
            }
            event = mEventQueue.front();
            mEventQueue.pop();
        }
#ifdef USE_TESTS
        mTestStats[event.type]++;
#endif
        switch (event.type)
        {
        case ObjectType::USER:
            // call to ProjectCache
            break;
        case ObjectType::GROUP:
            // call to BoreholeCache
            break;
        case ObjectType::COMMENT:
            // call to LogCache
            break;
        case ObjectType::ADDRESS:
            // mCache->processEvent(event);
            break;
        default:
            // etc
            break;
        }
    }
}

void EventQueue::dropCache()
{
    mCache->invalidate();
}

int main(int argc, char** argv)
{
    EventQueue queue;
    queue.addEvent({0, "some message", ObjectType::USER});
    queue.addEvent({1, "some message2", ObjectType::ADDRESS});
    return 0;
}
