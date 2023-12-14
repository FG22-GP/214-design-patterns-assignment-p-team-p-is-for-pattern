#pragma once
#include "GameState.h"
#include "..\TextureManager.h"

class Collision;

class PlayState : public GameState
{
    const std::string stateID = "Play";
    // std::shared_ptr<Entity> player;
    std::shared_ptr<Collision> playerCollision;

public:
    PlayState(GameManager* manager);
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~PlayState();
};
