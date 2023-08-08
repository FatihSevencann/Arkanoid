#include "Paddle.h"

USING_NS_CC;

Paddle::Paddle(cocos2d::Vec2 vec2, const std::string& spriteFile, float speed) :
        MovableObject(vec2, Sprite::create(spriteFile), speed, Vec2(0.f, 0.f))
{

    setPosition(vec2);
    setAnchorPoint(Vec2(0.5f, 0.5f));
}

