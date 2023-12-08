#pragma once
#include "GameState.h"
#include "..\TextureManager.h"


class PlayState : public GameState
{
    const std::string stateID = "Play";
    int pos_x =0;
    int pos_y =0;

public:
    PlayState() {}
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() override { return stateID; }

    ~PlayState() {}
};
