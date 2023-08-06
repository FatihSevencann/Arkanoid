#pragma once

#include <memory>
#include "Base/FSM/StateMachine.h"
#include "Base/System/Events/Observer.h"
#include "Base/System/Events/Events.h"
#include "IState.h"
#include <vector>

class MainMenuState : public Observer<Events>, public IState {
public:
    MainMenuState(const int pId, std::shared_ptr<StateMachine> stateMachine, EventManager &eventManager);

    ~MainMenuState();

    std::vector<Events> getEventTypes() const override {
        return {Events::GAME_PLAY};
    }

    void handleNotification(Events pEvent) override;

private:
    void enter() override;

    void execute() override;

    void exit() override;
};
