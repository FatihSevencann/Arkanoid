#include "MainMenuScene.h"
#include "ui/UIButton.h"
#include "States/MainMenuState.h"


USING_NS_CC;

using namespace cocos2d::ui;
class MainMenuState;

Scene* MainMenuScene::createScene(EventManager* eventManager)
{
    auto scene = Scene::create();
    auto layer = MainMenuScene::create(eventManager);
    scene->addChild(layer);
    return scene;
}
MainMenuScene* MainMenuScene::create(EventManager* eventManager)
{
    MainMenuScene* layer = new MainMenuScene();
    if (layer && layer->init(eventManager))
    {
        layer->autorelease();
        return layer;
    }
    else
    {
        delete layer;
        return nullptr;
    }
}

bool MainMenuScene::init(EventManager* eventManager)
{
    if (!Layer::init())
    {
        return false;
    }
    mEventManager = eventManager;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    createMenuButtons(visibleSize);

    return true;
}

#pragma region CreateButtons
void MainMenuScene::createMenuButtons(cocos2d::Size visibleSize)
{
    createMenuBackground(visibleSize);
    createMenuLabel(visibleSize);
    createPlayButton(visibleSize);
    createCharacterButton(visibleSize);
    createMissionButton(visibleSize);
}
void MainMenuScene::createPlayButton(cocos2d::Size visibleSize)
{
    auto playButton = Button::create("PlayButton.png","");
    playButton->setPosition(Vec2(visibleSize.width *1.2, visibleSize.height*0.35 ));
    playButton->setTag(0);
    this->addChild(playButton);

    playButton->addTouchEventListener([&](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
        {
            CCLOG("Play button clicked");

          mEventManager->notifyEvent(Events::GAME_PLAY);
        }
    });
}
void MainMenuScene::createCharacterButton(cocos2d::Size visibleSize)
{
    auto characterButton = Button::create("characterSelectButton.jpg", "");
    characterButton->setPosition(Vec2(visibleSize.width, visibleSize.height*0.25));
    characterButton->setTag(1);
    this->addChild(characterButton);
}
void MainMenuScene::createMissionButton(cocos2d::Size visibleSize)
{
    auto missionButton = Button::create("missionButton.png", "");
    missionButton->setPosition(Vec2(visibleSize.width*1.5f, visibleSize.height*0.25f ));
    missionButton->setTag(2);
    this->addChild(missionButton);
}
#pragma endregion

void MainMenuScene::createMenuBackground(Size visibleSize)
{
    auto sprite=Sprite::create("menuBackground.png");
    sprite->setPosition(Vec2(visibleSize.width*1.25f,visibleSize.height*0.5));
    float scaleX = visibleSize.width / sprite->getContentSize().width;
    float scaleY = visibleSize.height / sprite->getContentSize().height;
    sprite->setScale(scaleX, scaleY);
    this->addChild(sprite);
}
void MainMenuScene::createMenuLabel(Size visibleSize )
{
    auto label = Label::createWithTTF("MAIN MENU", "fonts/arial.ttf", 30);
    label->setPosition(Vec2(visibleSize.width*1.3f, visibleSize.height*0.8f));
    this->addChild(label);
}

