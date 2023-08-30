#include "MainMenuScene.h"
#include "ui/UIButton.h"
USING_NS_CC;

using namespace cocos2d::ui;

Scene* MainMenuScene::createScene()
{
    auto scene=Scene::create();
    auto layer=MainMenuScene::create();
    scene->addChild(layer);
    return scene;
}
bool MainMenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();

    createMenuBackground(visibleSize);
    createMenuLabel(visibleSize);
    createPlayButton(visibleSize);
    createCharacterButton(visibleSize);
    createMissionButton(visibleSize);
    return true;
}

void MainMenuScene::createPlayButton(cocos2d::Size visibleSize)
{
    auto playButton = Button::create("PlayButton.png", "");
    playButton->setPosition(Vec2(visibleSize.width *1.2, visibleSize.height*0.35 ));
    playButton->setTag(0);
    this->addChild(playButton);
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