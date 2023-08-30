#pragma once
#include <memory>

class StateMachine;

class IState {
public:
    explicit IState(std::shared_ptr<StateMachine> stateHolder) : states(stateHolder) {}

    void setEnter()
    {
        enter();
    }
    void setExecute()
    {
        execute();
    }
    void setExit()
    {
        exit();
    }
protected:
    std::shared_ptr<StateMachine> states;
private:

    virtual void enter() = 0;
    virtual void execute() = 0;
    virtual void exit() = 0;

};