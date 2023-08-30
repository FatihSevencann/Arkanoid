#pragma once
#include "Observer.h"

class EventManager : public Subject<Events> {
public:
    using Subject<Events>::notify;

    void notifyEvent(Events event)
    {
        notify(event);
    }
};