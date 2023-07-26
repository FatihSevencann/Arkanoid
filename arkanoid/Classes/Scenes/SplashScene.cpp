#include "SplashScene.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    auto scene=Scene::create();
    auto layer=SplashScene::create();
    scene->addChild(layer);
    return scene;
}

bool SplashScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    createBackground(visibleSize,origin);

    return true;
}

void SplashScene::createBackground(Size visibleSize,Vec2 origin)
{
    auto sprite=Sprite::create("splashBackground.png");
    sprite->setPosition(Vec2(visibleSize.width/2 +origin.x,visibleSize.height/2+origin.y));

    float scaleX = visibleSize.width / sprite->getContentSize().width;
    float scaleY = visibleSize.height / sprite->getContentSize().height;

    sprite->setScale(scaleX, scaleY);
    this->addChild(sprite);
}
