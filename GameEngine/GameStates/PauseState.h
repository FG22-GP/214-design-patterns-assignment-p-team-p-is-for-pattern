#pragma once
#include "GameState.h"

class PauseState : public GameState
{

public:
    PauseState() {}
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() override;

    ~PauseState() {}
};
