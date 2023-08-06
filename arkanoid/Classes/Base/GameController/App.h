#pragma once
#include <memory>
#include "Base/System/Events/EventManager.h"
#include "Base/FSM/StateMachine.h"


class App {
public:
    void Init();

private:
    void SetupStateMachine();
    std::shared_ptr<StateMachine> mStateMachine;
    std::shared_ptr<EventManager> mEventManager;
};
