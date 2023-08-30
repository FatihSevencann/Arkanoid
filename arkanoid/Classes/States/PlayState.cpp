#include "PlayState.h"

const float BALL_VELOCITY=50.0f;
const float PADDLE_VELOCITY=75.0f;


PlayState::PlayState(const int pId, std::shared_ptr<StateMachine> stateMachine,EventManager& eventManager)
        : Observer<Events>(pId), IState(stateMachine,eventManager), mPaddle(nullptr),mBall(nullptr)
{
    init(&eventManager);

    mDefaultDirective=new DefaultDirective;
    mButtonLeft=new MoveLeftDirective;
    mButtonRight=new MoveRightDirective;
    mCurrentDirective=mDefaultDirective;


}

PlayState::~PlayState()
{
    mEventManager->detach(this);

    if(mPaddle!= nullptr)
    {
        delete mPaddle;
    }
    if(mButtonLeft != nullptr)
    {
        delete mButtonLeft;
    }
    if(mButtonRight != nullptr)
    {
        delete mButtonRight;
    }
    if(mDefaultDirective != nullptr)
    {
        delete mDefaultDirective;
    }
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
    if(mBall->getLeft()<mVisibleSize.width *0.32f)
         mBall->setVelocityX(BALL_VELOCITY);
    else if (mBall->getRight()>mVisibleSize.width*0.67f)
        mBall->setVelocityX(-BALL_VELOCITY);

    if(mBall->getTop() > mVisibleSize.height)
        mBall->setVelocityY(-BALL_VELOCITY);

    else if(mBall->getBottom() < 0)
    {
        mIsGameOver = true;
        printf("GAME OVER");
        return;
    }
    mBall->update(0.01);
    mPaddle->update(0.01);
}
void PlayState::exit()
{
    mBall->detach(mPaddle);
}
void PlayState::handleNotification(Events pEvent)
{
    if (pEvent == Events::GAME_BACK)
    {
        CCLOG("ChangeState");
        states->changeState(States::Menu);
    }
    else
    {
        if(pEvent==Events::BUTTON_LEFT && mPaddle->getLeft()>mVisibleSize.width *0.32f)
        {
            mCurrentDirective=mButtonLeft;
            mIsClickedButton=true;
        }
        if(pEvent==Events::BUTTON_RIGHT && mPaddle->getRight()< mVisibleSize.width*0.67f)
        {
            mIsClickedButton=true;
            mCurrentDirective=mButtonRight;
        }

        if(mCurrentDirective!= nullptr&& mPaddle != nullptr && mIsClickedButton)
        {
            mCurrentDirective->Execute(*mPaddle);
        }
        mIsClickedButton= false;
    }
}
