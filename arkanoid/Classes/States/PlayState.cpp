#include "PlayState.h"

const float BALL_VELOCITY=50.0f;
const float PADDLE_VELOCITY=75.0f;


PlayState::PlayState(const int pId, std::shared_ptr<StateMachine> stateMachine,EventManager& eventManager)
        : Observer<Events>(pId), IState(stateMachine,eventManager), mPaddle(nullptr),mBall(nullptr)
{
    init(&eventManager);
}

PlayState::~PlayState()
{
    mEventManager->detach(this);

    if(mPaddle!= nullptr)
    {
        delete mPaddle;
    }
void PlayState::enter()
{
    CCLOG("PlayState");
    mEventManager->attach(this);

    mPaddle= new Paddle(Vec2::ZERO, "paddle.png", PADDLE_VELOCITY);

    mBall=new Ball(Vec2::ZERO,"ball.png",BALL_VELOCITY);

    mBall->attach(mPaddle);

    auto gameScene = GameScene::createScene(mEventManager,mPaddle,mBall);
    Director::getInstance()->replaceScene(gameScene);

    mVisibleSize = gameScene->getContentSize();

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