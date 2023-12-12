#pragma once
#include "GameState.h"
#include "..\TextureManager.h"


class PlayState : public GameState
{
    const std::string stateID = "Play";

public:
    PlayState(GameManager* manager);
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~PlayState();
};
