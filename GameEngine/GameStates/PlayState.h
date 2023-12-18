#pragma once
#include "GameState.h"
#include "../TextureManager.h"

class Collision;

class PlayState : public GameState
{
    const std::string stateID = "Play";
    std::shared_ptr<Collision> playerCollision;
    Vector2D recordingTextSize;
    Color scoreTextColour = {0xff, 0xff, 0xff};


public:
    PlayState();
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~PlayState();
};
