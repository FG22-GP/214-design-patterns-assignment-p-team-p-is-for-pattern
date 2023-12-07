#pragma once
#include "GameStates/GameState.h"
#include <vector>
#include <memory>

class GameManager 
{
   
    std::vector<std::shared_ptr<GameState>> gameStates;

protected:



public:


    GameManager();

    void PushState(std::shared_ptr<GameState> pushState);
    void PopState();
    void ChangeState(std::shared_ptr<GameState> changeState);


    void Update();

    ~GameManager() {}
};
