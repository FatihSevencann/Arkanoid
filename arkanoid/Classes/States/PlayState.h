#pragma once
#include "IState.h"
#include "cocos2d.h"

class PlayState: public IState{
public:
    PlayState(std::shared_ptr<StateMachine> stateMachine);

    ~PlayState();
private:
    void enter()override;

    void execute()override;

    void exit()override;

private:
    float elapsedTime = 0.0f;
    const float splashDuration = 3.0f;
    bool isExiting = false;


};


