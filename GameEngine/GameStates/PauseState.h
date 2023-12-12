#pragma once
#include "GameState.h"

class PauseState : public GameState
{
    std::string stateID = "Pause";

public:
    PauseState(GameManager* manager);
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~PauseState() {}
};
