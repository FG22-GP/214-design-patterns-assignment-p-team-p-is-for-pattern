#pragma once
#include "GameState.h"

class WonState : public GameState
{
    const std::string stateID = "Won";
    

public:
    WonState() {}
    void Start() override;
    void Stop() override;
    void Update() override;

    const std::string GetStateID() override { return stateID; }

    ~WonState() {}
};
