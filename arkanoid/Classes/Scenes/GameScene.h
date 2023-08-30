#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class GameScene : public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
private:
    void createGameBackground(Size visibleSize);
    void createGameLabel(Size visiableSize);
};

