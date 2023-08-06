#pragma once
#include "IState.h"
#include "Base/FSM/StateMachine.h"
#include "Base/System/Events/Observer.h"
#include "Base/System/Events/Events.h"

class SplashState : public Observer<Events>,public IState
{
public:
    SplashState(const int pId, std::shared_ptr<StateMachine> stateMachine, EventManager& eventManager);
    ~SplashState();

    std::vector<Events> getEventTypes() const override {
        return { Events::GAME_START };
    }
    void handleNotification(Events pEvent) override;

private:
    void enter() override;
    void execute() override;
    void exit() override;

    float mElapsedTime = 0.0f;
    float mSplashDuration = 3.0f;
    bool mIsExiting = false;
};
