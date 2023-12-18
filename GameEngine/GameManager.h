#pragma once
#include "GameStates/GameState.h"
#include <map>
#include <memory>

#include "Level.h"


class GameManager : std::enable_shared_from_this<GameManager> {
    std::map<std::string, std::shared_ptr<Entity>> entityList;
    struct Private{};

public:
    std::map<std::string, std::shared_ptr<GameState>> allStates;
    std::shared_ptr<GameState> activeState;
    std::shared_ptr<Level> activeLevel;
    std::shared_ptr<Entity> playerEntity;
    std::shared_ptr<std::array<std::array<std::array<char, TilemapX>, TilemapY>, 7>> gridData;
    int strokes;

    explicit GameManager(Private);
    static std::shared_ptr<GameManager> Create();
    void Initialize(const std::shared_ptr<GameManager> gameManagerPtr);
    void PushState(std::shared_ptr<GameState> pushState);
    void Start();
    void Stop();

    //Might not need pop
    //void PopState();
    void ChangeActiveState(std::string changeID);
    void RestartLevel(bool buildNextLevel);
    void BuildLevel(int index);
    std::shared_ptr<Entity> GetEntity(const std::string& entityName);
    std::shared_ptr<GameManager> GetPtr();
    //Probs same
    void Update();

    ~GameManager() {
    }
};
