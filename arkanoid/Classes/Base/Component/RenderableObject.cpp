    #include "RenderableObject.h"

    RenderableObject::RenderableObject(const cocos2d::Vec2& position, cocos2d::Sprite* sprite)
    {
        this->sprite = sprite;
        this->addChild(sprite);
        sprite->setPosition(position);

    }
    bool RenderableObject::init() {
        if (!Node::init()) {
            return false;
        }
        return true;
    }

    const cocos2d::Vec2& RenderableObject::getPosition() const {
        return sprite->getPosition();
    }


    float RenderableObject::getLeft() const
    {
        return sprite->getPosition().x - sprite->getContentSize().width * sprite->getAnchorPoint().x;
    }

    float RenderableObject::getRight() const
    {
        return sprite->getPosition().x + sprite->getContentSize().width * (1 - sprite->getAnchorPoint().x);
    }

    float RenderableObject::getTop() const
    {
        return sprite->getPosition().y + sprite->getContentSize().height * (1 - sprite->getAnchorPoint().y);
    }

    float RenderableObject::getBottom() const
    {
        return sprite->getPosition().y - sprite->getContentSize().height * sprite->getAnchorPoint().y;

    }

    void RenderableObject::setPosition(const cocos2d::Vec2& pos)
    {
        sprite->setPosition(pos);
    }

    bool RenderableObject::isIntersects(const GameObject& another) const
    {
        return this->getRight() >= another.getLeft() && this->getLeft() <= another.getRight() &&
               this->getBottom() >= another.getTop() && this->getTop() <= another.getBottom();
    }
