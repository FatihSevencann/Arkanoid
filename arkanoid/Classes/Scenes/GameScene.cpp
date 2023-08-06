#include "GameScene.h"
#include "ui/UIButton.h"
#include <memory>
USING_NS_CC;

using namespace cocos2d::ui;

Scene* GameScene::createScene(EventManager* eventManager)
{
    auto scene=Scene::create();
    auto layer=GameScene::create(eventManager);
    scene->addChild(layer);
    return scene;
}

GameScene* GameScene::create(EventManager* eventManager)
{
    std::unique_ptr<GameScene> layer(new GameScene());
    if (layer && layer->init(eventManager))
    {
        return layer.release();
    }
    else
    {
        return nullptr;
    }
}

bool GameScene::init(EventManager* eventManager)
{
    if (!Layer::init()) {
        return false;
    }
    mEventManager = eventManager;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    createGameLabel(visibleSize);
    createGameBackground(visibleSize);
    createBackButton(visibleSize);



    return true;
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
