#include "PlayState.h"
#include "Scenes/GameScene.h"

PlayState::PlayState(const int pId, std::shared_ptr<StateMachine> stateMachine,EventManager& eventManager)
        : Observer<Events>(pId), IState(stateMachine,eventManager)
        : Observer<Events>(pId), IState(stateMachine,eventManager), mPaddle(nullptr)
{
    init(&eventManager);
}

PlayState::~PlayState()
{
}

 mEventManager->detach(this);
    if(mPaddle!= nullptr)
    {
        delete mPaddle;
    }
void PlayState::enter()
{
    auto playScene=GameScene::createScene();
    cocos2d::Director::getInstance()->runWithScene(playScene);
    mEventManager->attach(this);
    auto gameScene = GameScene::createScene(mEventManager);
    mPaddle= new Paddle(Vec2::ZERO, "paddle.png", 75.f);
    auto gameScene = GameScene::createScene(mEventManager,mPaddle);
    Director::getInstance()->replaceScene(gameScene);
}
void PlayState::execute()
{

}

void PlayState::exit()
{
}
void PlayState::handleNotification(Events pEvent)
{
    if (pEvent == Events::GAME_BACK)
    {
        CCLOG("ChangeState");
        states->changeState(States::Menu);
    }


}