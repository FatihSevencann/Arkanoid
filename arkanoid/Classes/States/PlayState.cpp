#include "PlayState.h"
#include "IState.h"
#include "Scenes/GameScene.h"
#include "Base/FSM/StateMachine.h"

PlayState::PlayState(std::shared_ptr<StateMachine> stateMachine) : IState(stateMachine)
{
}

PlayState::~PlayState()
{
}

void PlayState::enter()
{
    auto playScene=GameScene::createScene();
    cocos2d::Director::getInstance()->runWithScene(playScene);
}
void PlayState::execute()
{

}

void PlayState::exit()
{


}