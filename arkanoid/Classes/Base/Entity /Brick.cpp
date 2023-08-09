#include "Brick.h"

Brick::Brick(const cocos2d::Vec2 vec2, const std::string &spriteFile, int durability): RenderableObject(vec2,cocos2d::Sprite::create(spriteFile))
{

    mLifeDuration=(durability<=3 && durability>0)?durability:3;
    UpdateBrickTypes();
    mBrickSize=dynamic_cast<cocos2d::Sprite*>(sprite)->getContentSize();
}
Brick::~Brick() noexcept
{

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





