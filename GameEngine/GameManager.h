#pragma once
#include "GameStates/GameState.h"
#include <map>
#include <memory>

#include "Level.h"


class GameManager {
public:
    std::map<std::string, std::shared_ptr<GameState>> allStates;
    std::shared_ptr<GameState> activeState;
    std::shared_ptr<Level> activeLevel;
    std::shared_ptr<Entity> playerEntity;
    int strokes;

    GameManager();
    void PushState(std::shared_ptr<GameState> pushState);
    void Start();
    void Stop();

    //Might not need pop
    //void PopState();
    void ChangeActiveState(std::string changeID, bool shouldPassEntites = false);
    void RestartLevel(bool generateNewLevel);
    //Probs same
    void Update();

    ~GameManager() {
    }
};
