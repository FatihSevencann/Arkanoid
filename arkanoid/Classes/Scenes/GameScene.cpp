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
    auto label = Label::createWithTTF("MAIN MENU", "fonts/arial.ttf", 30);
    label->setPosition(Vec2(visibleSize.width*1.3f, visibleSize.height*0.8f));
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
        if (type == Widget::TouchEventType::BEGAN) {

            mEventManager->notifyEvent(Events::GAME_BACK);
        }
    });
}
