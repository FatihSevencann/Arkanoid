#pragma once
#include "cocos2d.h"

#include "Base/Entity /Paddle.h"
#include "Base/Entity /Ball.h"
#include "States/PlayState.h"
using namespace cocos2d;

class GameScene : public Layer
{
public:

    ~GameScene();

    static Scene* createScene(EventManager* eventManager,Paddle* paddle,Ball* ball);
    virtual bool init(EventManager* eventManager,Paddle* paddle,Ball* ball);
    static GameScene* create(EventManager* eventManager,Paddle* paddle,Ball* ball);
private:
    void createGameBackground(Size visibleSize);
    void createGameLabel(Size visibleSize);
    void createBackButton(Size visibleSize);
    void createPaddle(Size visibleSize,Paddle *paddle);
    void createBall(Size visibleSize,Ball *ball);
    void CreateLeftButton(Size visiableSize);
    void CreateRightButton(Size visiableSize);

    Paddle *mPaddle;
    Ball  *mBall;
    EventManager* mEventManager;
    bool isMovingLeft = false;
    bool isMovingRight=false;
    void update(float delta);
};

