#pragma once
#include "GameState.h"

class Lose : public GameState {
    const std::string stateID = "Lose";

public:
    Lose(GameManager* manager);
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~Lose() {
    }
};
