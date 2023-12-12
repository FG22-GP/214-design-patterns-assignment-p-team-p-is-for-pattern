#pragma once
#include "GameStates/GameState.h"
#include <map>
#include <memory>
#include <vector>


class GameManager
{
protected:



public:

    std::map<std::string, std::shared_ptr<GameState>> allstates;

    std::shared_ptr<GameState> activeState;

    GameManager();

    void PushState(std::shared_ptr<GameState> pushState);

    void Start();
    void Stop();

    //Might not need pop
    //void PopState();
    void ChangeActiveState(std::string changeID, bool shouldPassEntites = false);

    //Probs same
    void Update();

    ~GameManager() {}

};
