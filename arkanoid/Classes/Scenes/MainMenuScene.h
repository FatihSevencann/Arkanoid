#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class MainMenuScene : public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainMenuScene);
private:
    void createMenuBackground(Size visibleSize);
    void createPlayButton(Size visibleSize);
    void createCharacterButton(Size visibleSize);
    void createMissionButton(Size visibleSize);
    void createMenuLabel(Size visiableSize);
};


