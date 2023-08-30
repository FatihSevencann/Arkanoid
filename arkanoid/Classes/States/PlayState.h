#pragma once
#include "States//IState.h"
#include "Base/System/Events/Observer.h"
#include "Base/FSM/StateMachine.h"
#include "Scenes/GameScene.h"

extern const float BALL_VELOCITY;
extern const float PADDLE_VELOCITY;

class PlayState : public Observer< Events>,public IState{
public:
    PlayState(const int pId,std::shared_ptr<StateMachine> stateMachine,EventManager& eventManager);
    ~PlayState();


    std::vector<Events> getEventTypes() const override
    {
        return { Events::GAME_BACK, Events::BUTTON_RIGHT, Events::BUTTON_LEFT };
    }

    void handleNotification(Events pEvent) override;

private:
    void enter() override;
    void execute() override;
    void exit() override;

    Paddle *mPaddle;
    Ball *mBall;
    cocos2d::Size mVisibleSize;
    bool mIsClickedButton=false;
    bool mIsGameOver=false;

};


