#include "MainMenuState.h"
#include "Scenes/MainMenuScene.h"
#include "Base/FSM/StateMachine.h"

MainMenuState::MainMenuState(const int pId, std::shared_ptr<StateMachine> stateMachine, EventManager &eventManager)
        : Observer<Events>(pId), IState(std::move(stateMachine), eventManager) {
    init(&eventManager);
}

MainMenuState::~MainMenuState() {
    mEventManager->detach(this);
}

void MainMenuState::enter() {
    CCLOG("MainMenuState enter");
    mEventManager->attach(this);

    auto scene = MainMenuScene::createScene(mEventManager);
    Director::getInstance()->replaceScene(TransitionFade::create(1.3f, scene));
}

void MainMenuState::execute() {

}

void MainMenuState::exit() {
}

void MainMenuState::handleNotification(Events pEvent) {
    if (pEvent == Events::GAME_PLAY) {
        CCLOG("ChangeState");
        states->changeState(States::Play);
    }
}
