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

