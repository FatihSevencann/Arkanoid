
#include "MainMenuState.h"
#include "Scenes/MainMenuScene.h"
#include "Base/FSM/StateMachine.h"

MainMenuState::MainMenuState(std::shared_ptr<StateMachine> stateMachine): IState(stateMachine)
{
}
MainMenuState::~MainMenuState()
{
}
void MainMenuState::enter()
{
    CCLOG("MenuState");
    auto scene =MainMenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.3f, scene));
}
void MainMenuState::execute()
{
}
void MainMenuState::exit()
{
}

