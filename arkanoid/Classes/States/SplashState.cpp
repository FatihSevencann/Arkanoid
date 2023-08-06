#include "SplashState.h"
#include <utility>
#include "Scenes/SplashScene.h"

SplashState::SplashState(const int pId, std::shared_ptr<StateMachine> stateMachine,EventManager& eventManager):Observer<Events>(pId), IState(stateMachine,eventManager)
{
    states = stateMachine;
}
SplashState::~SplashState()
{
}
void SplashState::enter()
{
    auto splashScene = SplashScene::createScene();
    Director::getInstance()->replaceScene(splashScene);
}

void SplashState::execute()
{
    mElapsedTime += Director::getInstance()->getDeltaTime();
    if (mElapsedTime >= mSplashDuration && !mIsExiting)
    {
        mIsExiting = true;
      states->changeState(States::statesCode::Menu);
    }
}
void SplashState::exit()
{
}
void SplashState::handleNotification(Events pEvent)
{
}
