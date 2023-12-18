#pragma once
#include <iostream>
#include <vector>
#include <memory>

#include "../Engine/Entity.h"

class GameManager;

class IGameState : std::enable_shared_from_this<IGameState>
{

public:
    std::map<std::string, std::shared_ptr<Entity>> entityList;
    GameManager* gameManager;
    IGameState() = default;
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Update() = 0;

    virtual std::string GetStateID() const = 0;
    void ClearRefs();

    ~IGameState() = default;
    
};




class GameState : public IGameState , std::enable_shared_from_this<GameState>
{
    const std::string stateID = "";
    
public:
    GameState(GameManager* manager);
    void Start() override;
    void Stop() override;
    void Update() override;

    virtual std::string GetStateID() const override{ return stateID; };

    ~GameState() {}
};
