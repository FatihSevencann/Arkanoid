#pragma once
#include "cocos2d.h"
#include "Base/Component/RenderableObject.h"
#include "Ball.h"

class Paddle : public MovableObject, public IObserver{
public:
    Paddle(const cocos2d::Vec2 Vec2, const std::string& spriteFile, float speed);

    ~Paddle();

    float getWidth() const;
    float getHeight() const;

    float getLeft() const override;
    float getRight() const override;
    float getTop() const override;
    float getBottom() const override;

    void moveLeft();
    void moveRight();
    void stayAtPlace();

    void handleBallPosChange(Ball *ball) override;

    void setSize(const cocos2d::Size& size);
    cocos2d::Size getSize() const;

    void update(float delta) override;

private:
    virtual bool init() override;
    cocos2d::Size paddleSize;


};

