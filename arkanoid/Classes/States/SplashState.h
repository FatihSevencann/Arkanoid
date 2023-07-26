#pragma once
#include "IState.h"
#include "cocos2d.h"

class StateMachine;

class SplashState: public IState{
public:
    SplashState(std::shared_ptr<StateMachine> stateMachine);

    ~SplashState();
private:

    void enter() override;
    void execute()override;
    void exit() override;

    float elapsedTime = 0.0f;
    const float splashDuration = 4.0f;
    bool isExiting = false;
};