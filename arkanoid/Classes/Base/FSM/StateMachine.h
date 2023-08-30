#pragma once
#include <memory>
#include "map"
using namespace std;

class IState;

namespace States
{
    enum statesCode
    {
        Splash,
        Play,
        Menu,
        Character,
        Missions,
        Pause,
        EndGame
    };
}
class StateMachine{
public:
    StateMachine(States::statesCode state,std::shared_ptr<IState> startState);
    ~StateMachine();
    void addState(States::statesCode stateID,std::shared_ptr<IState> stateToAdd);

    void changeState(States::statesCode state);
    std::shared_ptr<IState> getState()const;
    void update();

private:
    std::map<States::statesCode, std::shared_ptr<IState>> states;
    shared_ptr<IState> currentState;
    States::statesCode currentStateID;

};
