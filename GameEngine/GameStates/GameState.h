#pragma once
#include <iostream>
#include <vector>
#include <memory>

#include "../Entity.h"

class IGameState : std::enable_shared_from_this<IGameState>
{
protected:
    const static std::string stateID;

    std::vector<std::shared_ptr<Mono>> entityList;

public:
    IGameState() = default;
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Update() = 0;

    virtual std::string GetStateID() const = 0;

    ~IGameState() = default;
};




class GameState : public IGameState , std::enable_shared_from_this<GameState>
{


public:
    GameState() = default;
    void Start() override;
    void Stop() override;
    void Update() override;

    virtual std::string GetStateID() = 0;

    ~GameState() {}
};
