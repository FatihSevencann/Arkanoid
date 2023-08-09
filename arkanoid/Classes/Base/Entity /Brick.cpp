#include "Brick.h"

Brick::Brick(const cocos2d::Vec2 vec2, const std::string &spriteFile, int durability): RenderableObject(vec2,cocos2d::Sprite::create(spriteFile))
{

    mLifeDuration=(durability<=3 && durability>0)?durability:3;
    UpdateBrickTypes();
    mBrickSize=dynamic_cast<cocos2d::Sprite*>(sprite)->getContentSize();
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


