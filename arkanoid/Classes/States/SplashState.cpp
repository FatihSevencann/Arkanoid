#include "SplashState.h"
#include "Scenes/SplashScene.h"
#include "Base/FSM/StateMachine.h"


SplashState::SplashState(std::shared_ptr<StateMachine> stateMachine): IState(stateMachine)
{
}
SplashState::~SplashState()
{
}
void SplashState::enter()
{
    auto splashScene=SplashScene::createScene();
    cocos2d::Director::getInstance()->runWithScene(splashScene);
}
void SplashState::execute()
{
    states->changeState(States::Menu);

    elapsedTime += cocos2d::Director::getInstance()->getDeltaTime();
    if (elapsedTime >= splashDuration) {

    }
}
void SplashState::exit()
{
}