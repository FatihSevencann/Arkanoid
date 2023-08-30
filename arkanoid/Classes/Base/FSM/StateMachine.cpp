#include "StateMachine.h"
#include "States/IState.h"
StateMachine::~StateMachine()
{
}
StateMachine::StateMachine(States::statesCode state, std::shared_ptr<IState> startState)
{
    currentState=startState;
    currentStateID=state;
}
void StateMachine::addState(States::statesCode stateID, std::shared_ptr<IState> stateToAdd)
{
    states.insert(make_pair(stateID,stateToAdd));
}
void StateMachine::changeState(States::statesCode changeState)
{
    currentState->setExit();
    std::shared_ptr<IState> nextState = states.at(changeState);
    nextState->setEnter();
    currentStateID = changeState;
    currentState = nextState;
}
std::shared_ptr<IState> StateMachine::getState() const
{
    return currentState;
}
void StateMachine::update(float dt) {
    if (currentState) {
        currentState->setExecute();
    }
}