#include "App.h"
#include "cocos2d.h"
#include "States/MainMenuState.h"
#include "States/PlayState.h"
#include "States/SplashState.h"


void App::Init() {
    mEventManager = make_shared<EventManager>();

    SetupStateMachine();

    cocos2d::Director::getInstance()->getScheduler()->scheduleUpdate(mStateMachine.get(), 0, false);
}
void App::SetupStateMachine()
{
    mStateMachine = std::make_shared<StateMachine>(States::Splash, std::make_shared<SplashState>(0,mStateMachine,*mEventManager));

    mStateMachine->addState(States::Splash, std::make_shared<SplashState>(0,mStateMachine,*mEventManager));
    mStateMachine->addState(States::Menu, std::make_shared<MainMenuState>(1,mStateMachine,*mEventManager));
    mStateMachine->addState(States::Play,std::make_shared<PlayState>(2,mStateMachine,*mEventManager));
    mStateMachine->changeState(States::Splash);
}


