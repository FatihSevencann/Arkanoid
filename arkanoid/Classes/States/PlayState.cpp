#include "PlayState.h"
#include "Scenes/GameScene.h"

PlayState::PlayState(const int pId, std::shared_ptr<StateMachine> stateMachine,EventManager& eventManager)
        : Observer<Events>(pId), IState(stateMachine,eventManager)
{
    init(&eventManager);
}

PlayState::~PlayState()
{
}

 mEventManager->detach(this);
void PlayState::enter()
{
    auto playScene=GameScene::createScene();
    cocos2d::Director::getInstance()->runWithScene(playScene);
    mEventManager->attach(this);
    auto gameScene = GameScene::createScene(mEventManager);
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