#pragma once

#include "cocos2d.h"
#include <list>
#include "Base/Component/RenderableObject.h"

class IObserver;

class IObservable {
public:
    virtual void attach(IObserver *observer) = 0;
    virtual void detach(IObserver *observer) = 0;
};


class Ball : public MovableObject, public IObservable {
public:
    Ball( cocos2d::Vec2 vec2, const std::string &spriteFile, float ball_velocity);
    ~Ball() override;


};

class IObserver {
public:
    virtual void handleBallPosChange(Ball *ball) = 0;
};
