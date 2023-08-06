#pragma once

#include <memory>
#include <utility>
#include "Base/System/Events/EventManager.h"

class StateMachine;

class IState {
public:
    explicit IState(std::shared_ptr<StateMachine> stateHolder, EventManager &eventManager) : states(
            std::move(stateHolder)), mEventManager(&eventManager) {}

    void setEnter() {
        enter();
    }

    void setExecute() {
        execute();
    }

    void setExit() {
        exit();
    }

protected:
    std::shared_ptr<StateMachine> states;
    EventManager *mEventManager;
private:

    virtual void enter() = 0;

    virtual void execute() = 0;

    virtual void exit() = 0;

};