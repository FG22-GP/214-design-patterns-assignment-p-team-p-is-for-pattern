#pragma once
#include "GameState.h"
#include "../TextureManager.h"

class Collision;

class PlayState : public GameState {
    const std::string stateID = "Play";
    std::shared_ptr<Collision> playerCollision;
    Vector2D recordingTextSize;
    Color scoreRedTextColour = {0x80, 0x00, 0x00};
    Color scoreGreenTextColour = {0x00, 0x80, 0x00};

public:
    PlayState();
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~PlayState();
};
