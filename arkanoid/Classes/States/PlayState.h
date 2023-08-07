#pragma once
#include "States//IState.h"
#include "Base/System/Events/Observer.h"
#include "Base/FSM/StateMachine.h"
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

};


