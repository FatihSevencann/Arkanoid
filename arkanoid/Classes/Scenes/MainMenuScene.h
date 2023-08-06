#pragma once
#include "cocos2d.h"
#include "ui/UIButton.h"
#include "States/MainMenuState.h"
#include "Base/System/Events/EventManager.h"
#include "Base/FSM/StateMachine.h"
using namespace cocos2d;

class MainMenuScene : public Layer
{
public:
    static Scene* createScene(EventManager* eventManager);
    virtual bool init(EventManager* eventManager);
    static MainMenuScene* create(EventManager* eventManager);

private:
    EventManager* mEventManager;

    void createMenuButtons(Size visibleSize);
    void createMenuBackground(Size visibleSize);
    void createPlayButton(Size visibleSize);
    void createCharacterButton(Size visibleSize);
    void createMissionButton(Size visibleSize);
    void createMenuLabel(Size visibleSize);
};
