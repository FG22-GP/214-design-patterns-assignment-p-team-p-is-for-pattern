#pragma once
#include "GameState.h"

class PlayState : public GameState
{

public:
    PlayState() {}
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() override;

    ~PlayState() {}
};
