#pragma once
#include "Base/Entity /Paddle.h"

class MontionDirective
{
public:
    virtual void Execute(Paddle &paddle)=0;
};


