#pragma once
#include "cocos2d.h"

#include "States/PlayState.h"
using namespace cocos2d;

class GameScene : public Layer
{
public:

    ~GameScene();

    static Scene* createScene(EventManager* eventManager);
    virtual bool init(EventManager* eventManager);
    static GameScene* create(EventManager* eventManager);
private:
    void createGameBackground(Size visibleSize);
    void createGameLabel(Size visiableSize);
    void createGameLabel(Size visibleSize);
    void createBackButton(Size visibleSize);
    void createPaddle(Size visibleSize,Paddle *paddle);
    void CreateLeftButton(Size visiableSize);
    void CreateRightButton(Size visiableSize);
    EventManager* mEventManager;
};

