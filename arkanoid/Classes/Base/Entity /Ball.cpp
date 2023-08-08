#include "Ball.h"
#include <list>

Ball::Ball( cocos2d::Vec2 vec2, const std::string &spriteFile, float ball_velocity)
        :
        MovableObject(vec2, cocos2d::Sprite::create(spriteFile), ball_velocity,
                      cocos2d::Vec2(ball_velocity, ball_velocity)), mBallSize(cocos2d::Size(0, 0))
{
    mBallSize = dynamic_cast<cocos2d::Sprite*>(sprite)->getContentSize();

}

Ball::~Ball() noexcept
{

}
cocos2d::Size Ball::getSize() const
{
    return mBallSize;
}

void Ball::setSize(const cocos2d::Size& size)
{
    mBallSize = size;
    dynamic_cast<cocos2d::Sprite*>(sprite)->setScaleX(size.width / sprite->getContentSize().width);
    dynamic_cast<cocos2d::Sprite*>(sprite)->setScaleY(size.height / sprite->getContentSize().height);
}
float Ball::getRadius() const
{
    return getContentSize().width * getScaleX() * 0.5f;
}

void Ball::setRadius(float radius)
{
    setScale(radius * 2 / getContentSize().width);
}
float Ball::getLeft() const
{
    return getPosition().x - getRadius();
}

float Ball::getRight() const {
    return getPosition().x + getRadius();
}

float Ball::getTop() const {
    return getPosition().y - getRadius();
}

float Ball::getBottom() const {
    return getPosition().y + getRadius();
}


void Ball::attach(IObserver *observer) {
    mObservers.push_back(observer);
}

void Ball::detach(IObserver *observer) {
    mObservers.remove(observer);
}

void Ball::notifyObservers() {
    for(IObserver *iter : mObservers) {
        iter->handleBallPosChange(this);
    }
}

void Ball::update(float dt) {
    MovableObject::update(dt);
    notifyObservers();
}