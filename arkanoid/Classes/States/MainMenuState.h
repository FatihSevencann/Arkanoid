#pragma once
#include "IState.h"
#include "cocos2d.h"

class StateMachine;

class MainMenuState:public IState{
public:
    MainMenuState(std::shared_ptr<StateMachine> stateMachine);

    ~MainMenuState();
private:
    void enter() override;

    void execute()override;

    void exit()override;
};
