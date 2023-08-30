#pragma once
#include "cocos2d.h"

class GameObject {
public:
    virtual const cocos2d::Vec2& getPosition() const = 0;
    virtual void setPosition(const cocos2d::Vec2& pos) = 0;
    virtual float getLeft() const = 0;
    virtual float getRight() const = 0;
    virtual float getTop() const = 0;
    virtual float getBottom() const = 0;

    virtual bool isIntersects(const GameObject& another) const = 0;
};

