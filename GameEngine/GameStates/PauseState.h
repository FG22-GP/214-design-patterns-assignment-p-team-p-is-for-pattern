#pragma once
#include "GameState.h"

class PauseState : public GameState
{
    std::string stateID = "Pause";

public:
    PauseState() {}
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() { return stateID; }

    ~PauseState() {}
};
