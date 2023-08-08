#include "Ball.h"
#include <list>

Ball::Ball( cocos2d::Vec2 vec2, const std::string &spriteFile, float ball_velocity)
        :
        MovableObject(vec2, cocos2d::Sprite::create(spriteFile), ball_velocity,
                      cocos2d::Vec2(ball_velocity, ball_velocity))
{


}

