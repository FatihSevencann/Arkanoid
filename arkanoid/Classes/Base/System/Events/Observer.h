#pragma once
#include <memory>
#include "Events.h"
#include "Subject.h"

template <class EventType>
class Observer {
public:
    explicit Observer(const int pId);
    virtual ~Observer();
    void init(Subject<EventType>* subject);

    virtual void handleNotification(EventType pEvent) = 0;
    virtual std::vector<EventType> getEventTypes() const = 0;
    int mId;
private:
   Subject<EventType>* mSubject;
};


