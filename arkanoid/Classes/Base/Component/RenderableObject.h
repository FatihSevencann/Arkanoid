#pragma once
#include "GameObject.h"
#include "cocos2d.h"

class RenderableObject : public cocos2d::Node, public GameObject {
public:
    RenderableObject(const cocos2d::Vec2& position, cocos2d::Sprite* sprite);

    virtual bool init() override;
    const cocos2d::Vec2& getPosition() const override;
    void setPosition(const cocos2d::Vec2& pos) override;
    virtual float getLeft() const override;
    virtual float getRight() const override;
    virtual float getTop() const override;
    virtual float getBottom() const override;

    virtual bool isIntersects(const GameObject& another) const override;

protected:
    cocos2d::Sprite* sprite;
};

