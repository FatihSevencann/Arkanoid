#include "Brick.h"

Brick::Brick(const cocos2d::Vec2 vec2, const std::string &spriteFile, int durability): RenderableObject(vec2,cocos2d::Sprite::create(spriteFile))
{
    mLifeDuration=(durability<=3 && durability>0)?durability:3;
    UpdateBrickTypes();
    mBrickSize=dynamic_cast<cocos2d::Sprite*>(sprite)->getContentSize();
}
Brick::~Brick() noexcept
{
    if (sprite!= nullptr)
        delete dynamic_cast<cocos2d::Sprite*>(sprite);
    sprite= nullptr;
}
void Brick::UpdateBrickTypes()
{
    switch (mLifeDuration)
    {
        case 3:
            sprite->create("Bricks/pinkBrick.png");
            break;
        case 2:
            sprite->create("Bricks/brickBlue.png");
            break;
        case 1:
            sprite->create("Bricks/brickRed.png");
            break;
    }
}
cocos2d::Size Brick::getSize() const
{
    return mBrickSize;
}
float Brick::getWidth() const
{
    return mBrickSize.width;
}
float Brick::getHeight() const
{
    return mBrickSize.height;
}
void Brick::setSize(const cocos2d::Size &size)
{
    mBrickSize=size;
    dynamic_cast<cocos2d::Sprite*>(sprite)->setScaleX(size.width / sprite->getContentSize().width);
    dynamic_cast<cocos2d::Sprite*>(sprite)->setScaleY(size.height / sprite->getContentSize().height);
}
float Brick::getRight() const
{
    return getPosition().x+mBrickSize.width/2;
}
float Brick::getLeft() const
{
    return getPosition().x-mBrickSize.width/2;
}
float Brick::getTop() const
{
    return getPosition().y+mBrickSize.height/2;
}
float Brick::getBottom() const
{
    return getPosition().y-mBrickSize.height/2;
}
bool Brick::isAlive() const
{
    return mLifeDuration!=0;
}
Brick *Brick::Clone()
{
    return new Brick(cocos2d::Vec2(getPosition().x,getPosition().y),"Bricks/pinkBrick.png",3);
}
void Brick::onHit()
{
    mLifeDuration--;
    UpdateBrickTypes();
}

void Brick::handleBallPosChange(Ball *ball)
{
    if(!RenderableObject::isIntersects(*ball)) return;
    onHit();

    float mOverlapXFromLeft=ball->getRight()-getLeft();
    float mOverlapXFromRight=getRight()-ball->getLeft();
    float mOverlapYFromTop=ball->getBottom()-getTop();
    float mOverlapYFromBottom=getBottom()-ball->getTop();

    bool mBallFromLeft=std::abs(mOverlapXFromLeft)< abs(mOverlapXFromRight);
    bool mBallFromTop=std::abs(mOverlapYFromTop)< abs(mOverlapYFromBottom);

    float mMinOverlapX=mBallFromLeft ? mOverlapXFromLeft: mOverlapXFromRight;
    float mMinOverlapY=mBallFromTop ? mOverlapYFromTop : mOverlapYFromBottom;

    if(std::abs(mMinOverlapX) < std::abs(mMinOverlapY))
    {
        ball->setVelocityX(mBallFromLeft?-ball->getMoveRate():ball->getMoveRate());
    }
    else
        ball->setVelocityY(mBallFromTop? -ball->getMoveRate():ball->getMoveRate());
}

BrickSpawner::BrickSpawner(cocos2d::Vec2)
{
    mEasyBrick=new Brick(cocos2d::Vec2::ZERO,"Bricks/brickRed.png",1);
    mMediumBrick=new Brick(cocos2d::Vec2::ZERO,"Bricks/brickBlue",2);
    mStrongBrick=new Brick(cocos2d::Vec2::ZERO,"Bricks/pinkBrick",3);
}
BrickSpawner::~BrickSpawner()
{
    delete mEasyBrick;
    delete mMediumBrick;
    delete mStrongBrick;
}
Brick *BrickSpawner::getBrick(int type) const
{
    Brick *out= nullptr;

    switch (type)
    {
        case 3:
            out=mStrongBrick->Clone();
            break;
        case 2:
            out=mMediumBrick->Clone();
            break;
        case 1:
            out=mEasyBrick->Clone();
            break;
    }
    return out;
}





