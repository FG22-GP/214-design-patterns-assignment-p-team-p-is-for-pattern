#pragma once
#include "GameState.h"

class WonState : public GameState
{
    const std::string stateID = "Won";
    

public:
    WonState(GameManager* manager);
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~WonState() {}
};
