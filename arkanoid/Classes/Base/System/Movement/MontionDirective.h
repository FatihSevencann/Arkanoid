#pragma once
#include "Base/Entity /Paddle.h"

class MontionDirective
{
public:
    virtual void Execute(Paddle &paddle)=0;
};

class MoveLeftDirective:public MontionDirective
{
    void Execute(Paddle &paddle)
    {
        paddle.moveLeft();
    }
};

class MoveRightDirective:public MontionDirective
{
public:
    void Execute(Paddle &paddle)
    {
        paddle.moveRight();
    }
};
