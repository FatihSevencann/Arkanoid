#include "Paddle.h"

USING_NS_CC;

Paddle::Paddle(cocos2d::Vec2 vec2, const std::string& spriteFile, float speed) :
        MovableObject(vec2, Sprite::create(spriteFile), speed, Vec2(0.f, 0.f)),
        paddleSize(Size(0, 0))
{
    paddleSize = dynamic_cast<Sprite*>(sprite)->getContentSize();

    setPosition(vec2);
    setAnchorPoint(Vec2(0.5f, 0.5f));

}
cocos2d::Size Paddle::getSize() const
{
    return paddleSize;
}

Paddle::~Paddle()
{
}

float Paddle::getWidth() const
{
    return paddleSize.width;
}

float Paddle::getHeight() const
{
    return paddleSize.height;
}

void Paddle::setSize(const Size& size)
{
    paddleSize = size;
    dynamic_cast<Sprite*>(sprite)->setScaleX(size.width / sprite->getContentSize().width);
    dynamic_cast<Sprite*>(sprite)->setScaleY(size.height / sprite->getContentSize().height);
}

float Paddle::getRight() const
{
    return getPosition().x + paddleSize.width / 2.f;
}

float Paddle::getLeft() const
{
    return getPosition().x - paddleSize.width / 2.f;
}

float Paddle::getTop() const
{
    return getPosition().y + paddleSize.height / 2.f;
}

float Paddle::getBottom() const
{
    return getPosition().y - paddleSize.height / 2.f;
}

void Paddle::moveLeft()
{
    setVelocityX(-getMoveRate());
}

void Paddle::moveRight()
{
    setVelocityX(getMoveRate());
}
void Paddle::stayAtPlace() {
    setVelocityX(0.f);
}

bool Paddle::init() {
    if (!MovableObject::init())
    {
        return false;
    }
    this->scheduleUpdate();
    CCLOG("Paddle init called");
    return true;
}

void Paddle::update(float delta)
{
    setPosition(getPosition() + getVelocity() * delta);
}

