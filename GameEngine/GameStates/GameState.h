#pragma once
#include <iostream>
#include <vector>
#include <memory>

#include "../Engine/Entity.h"

class GameManager;

class IGameState : std::enable_shared_from_this<IGameState>
{

public:
    std::shared_ptr<GameManager> gameManager;
    IGameState() = default;
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Update() = 0;

    virtual std::string GetStateID() const = 0;
    void ClearRefs();
    virtual void SetGameManager(std::shared_ptr<GameManager> manager) = 0;

    virtual ~IGameState() = default;
    
};




class GameState : public IGameState , std::enable_shared_from_this<GameState>
{
    const std::string stateID = "";
    
public:
    explicit GameState() = default;
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override{ return stateID; }
    void SetGameManager(std::shared_ptr<GameManager> manager) override;

    ~GameState() override = default;
};
