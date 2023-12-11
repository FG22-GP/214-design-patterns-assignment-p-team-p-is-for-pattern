#pragma once
#include "GameStates/GameState.h"
#include <map>
#include <memory>

class GameManager 
{
 
    std::map<std::string,std::shared_ptr<GameState>> allstates;

protected:



public:

    std::shared_ptr<GameState> activeState;

    GameManager();


    //Warmup

    //Restructure
    void PushState(std::shared_ptr<GameState> pushState);


    //Might not need pop
    //void PopState();
    void ChangeActiveState(std::string changeID);

    //Probs same
    void Update();

    ~GameManager() {}
};
