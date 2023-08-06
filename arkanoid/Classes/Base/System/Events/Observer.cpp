#include "Observer.h"

template <class EventType>
Observer<EventType>::Observer(const int pId) : mId(pId), mSubject(nullptr) {}

template <class EventType>
Observer<EventType>::~Observer() {}

template <class EventType>
void Observer<EventType>::init(Subject<EventType>* subject) {
    mSubject = subject;
    printf("Observer initialized with Subject.\n");
}

template class Observer<Events>;
