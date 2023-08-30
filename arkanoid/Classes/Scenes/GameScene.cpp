#include "GameScene.h"
#include "ui/UIButton.h"
USING_NS_CC;

using namespace cocos2d::ui;

Scene* GameScene::createScene()
{
    auto scene=Scene::create();
    auto layer=GameScene::create();
    scene->addChild(layer);
    return scene;
}
bool GameScene::init() {
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    createGameLabel(visibleSize);
    createGameBackground(visibleSize);
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

