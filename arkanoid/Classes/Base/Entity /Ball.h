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

    float getLeft()const override;
    float getRight()const override;
    float getTop()const override;
    float getBottom()const override;

    float getRadius()const;
    void setRadius(float radius);

    void setSize(const cocos2d::Size& size);
    cocos2d::Size getSize() const;

    void attach(IObserver *observer);
    void detach(IObserver *observer);
    void update(float dt);
private:
    std::list<IObserver*> mObservers;
    cocos2d::Size mBallSize;

    void notifyObservers();
};

class IObserver {
public:
    virtual void handleBallPosChange(Ball *ball) = 0;
};
