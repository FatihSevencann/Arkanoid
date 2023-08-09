#pragma once
#include "Ball.h"
#include "Base/Component/RenderableObject.h"
class Brick: public RenderableObject,public IObserver{
public:

    Brick(const cocos2d::Vec2 Vec2,const std::string& spriteFile,int durability);
    ~Brick();

    float getWidth()const;
    float getHeight()const;
    void setSize(const cocos2d::Size& size);
    cocos2d::Size getSize() const;

    float getLeft()const override;
    float getRight()const override;
    float getTop()const override;
    float getBottom()const override;

    Brick* Clone();
    bool isAlive()const;
    void onHit();
    void handleBallPosChange(Ball *ball) override;
private:
    int mLifeDuration;
    void UpdateBrickTypes();
    cocos2d::Size mBrickSize;
};

