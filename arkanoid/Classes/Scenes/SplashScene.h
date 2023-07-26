#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class SplashScene : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();

    CREATE_FUNC(SplashScene);
private:
    void createBackground();

};


