#pragma once

#include "cocos2d.h"
#include "Base/Component/RenderableObject.h"
#include "Ball.h"

class Paddle : public MovableObject, public IObserver{
public:
    Paddle(const cocos2d::Vec2 Vec2, const std::string& spriteFile, float speed);
    ~Paddle();

};

