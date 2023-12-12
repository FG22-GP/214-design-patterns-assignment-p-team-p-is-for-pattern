#pragma once
#include "GameState.h"
#include "..\Vector2D.h"

class WonState : public GameState
{
    const std::string stateID = "Won";
    
    Vector2D wonTextSize;

public:
    WonState(GameManager* manager);
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~WonState() {}
};
