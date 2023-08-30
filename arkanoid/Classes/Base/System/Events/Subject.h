#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>

template<class EventType>
class Observer;

template<class EventType>
class Subject {
public:
    Subject() {}

    ~Subject() {}

    void attach(Observer<EventType>* observer) {
        const auto& events = observer->getEventTypes();
        for (const auto& event : events) {
            mObserverList[event].push_back(observer);
        }
    }

    void detach(Observer<EventType>* observer) {
        for (auto& entry : mObserverList) {
            auto& observerList = entry.second;
            observerList.erase(
                    std::remove(observerList.begin(), observerList.end(), observer),
                    observerList.end()
            );
        }
    }

    void notify(const EventType& pEvent) {
        auto it = mObserverList.find(pEvent);
        if (it != mObserverList.end()) {
            auto& observerList = it->second;
            for (auto observer : observerList) {
                observer->handleNotification(pEvent);
            }
        }
    }

private:
    std::unordered_map<EventType, std::vector<Observer<EventType>*>> mObserverList;
};
