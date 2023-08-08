#include "GameScene.h"
#include "ui/UIButton.h"
#include <memory>
USING_NS_CC;
using namespace cocos2d::ui;

Scene* GameScene::createScene(EventManager* eventManager,Paddle* paddle,Ball* ball)
{
    auto scene=Scene::create();
    auto layer=GameScene::create(eventManager,paddle,ball);
    scene->addChild(layer);

    return scene;
}

GameScene* GameScene::create(EventManager* eventManager,Paddle* paddle,Ball* ball)
{
    std::unique_ptr<GameScene> layer(new GameScene());

    if (layer && layer->init(eventManager,paddle,ball))
    {
        return layer.release();
    }

    else
    {
        return nullptr;
    }
}

bool GameScene::init(EventManager* eventManager,Paddle* paddle,Ball* ball)
{
    if (!Layer::init()) {
        return false;
    }
    mEventManager = eventManager;
    mPaddle=paddle;
    mBall=ball;

    auto visibleSize = Director::getInstance()->getVisibleSize();

    std::cout << "Visible Size - Width: " << visibleSize.width << " Height: " << visibleSize.height << std::endl;


    createGameLabel(visibleSize);
    createGameBackground(visibleSize);
    createBackButton(visibleSize);

    createPaddle(visibleSize ,mPaddle);
    createBall(visibleSize,mBall);
    CreateLeftButton(visibleSize);

    this->scheduleUpdate();
    return true;
}

void GameScene::update(float delta)
{
    if (mPaddle != nullptr)
    {
        mPaddle->scheduleUpdate();
    }
    if(mBall != nullptr)
    {
        mBall->scheduleUpdate();
    }
}
GameScene::~GameScene() noexcept
{
    if (mPaddle != nullptr)
    {
        delete mPaddle;
    }
    if(mBall!= nullptr)
    {
        delete mBall;
    }
}

void GameScene::createGameLabel(Size visibleSize )
{
    auto label = Label::createWithTTF("GAME SCENE", "fonts/arial.ttf", 30);
    label->setPosition(Vec2(visibleSize.width*1.7f, visibleSize.height*0.8f));
    this->addChild(label);
}

void GameScene::createGameBackground(Size visibleSize)
{
    auto sprite=Sprite::create("menuBackground.png");
    sprite->setPosition(Vec2(visibleSize.width*1.25f,visibleSize.height*0.5));
    float scaleX = visibleSize.width / sprite->getContentSize().width;
    float scaleY = visibleSize.height / sprite->getContentSize().height;
    sprite->setScale(scaleX, scaleY);
    this->addChild(sprite);
}
void GameScene::createBackButton(Size visibleSize)
{
    auto backButton = Button::create("CloseNormal.png", "");
    backButton->setPosition(Vec2(visibleSize.width*1.7f, visibleSize.height*0.95f));
    backButton->setTag(3);
    this->addChild(backButton);

    backButton->addTouchEventListener([=](Ref* sender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::BEGAN)
        {
            mEventManager->notifyEvent(Events::GAME_BACK);
        }
    });
}
void GameScene::createPaddle(Size visibleSize,Paddle *paddle)
{
    Size mPaddleSize = paddle->getSize()*0.5f;
    Vec2 mPaddlePosition=Vec2(visibleSize.width*1.20f,visibleSize.height*0.15);
    paddle->setPosition(mPaddlePosition);
    paddle->setSize(mPaddleSize);
    this->addChild(paddle);
}
void GameScene::createBall(Size visibleSize,Ball *ball)
{
    Size mBallSize=ball->getSize()*0.5f;
    Vec2 mBallPosition=Vec2(visibleSize.width*1.20f,visibleSize.height*0.20);
    ball->setPosition(mBallPosition);
    ball->setSize(mBallSize);
    this->addChild(ball);
}

void GameScene::CreateLeftButton(cocos2d::Size visibleSize)
{
    auto mLeftButton=Button::create("Left_Button.png","");
    mLeftButton->setPosition(Vec2(visibleSize.width*0.9f,visibleSize.height*0.075f));
    this->addChild(mLeftButton);

    mLeftButton->addTouchEventListener([=](Ref* sender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::BEGAN)
        {
            isMovingLeft=true;
            mEventManager->notifyEvent(Events::BUTTON_LEFT);
        }
        else if (type == Widget::TouchEventType::ENDED||type == Widget::TouchEventType::MOVED ) {
            isMovingLeft = false;
            mPaddle->stayAtPlace();
        }
    });
}
}