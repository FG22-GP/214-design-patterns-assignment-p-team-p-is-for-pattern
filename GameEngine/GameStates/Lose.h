#pragma once
#include "GameState.h"
#include "../Vector2D.h"
#include "../Constants/Constants.h"

class Lose : public GameState {
    const std::string stateID = "Lose";

    Vector2D loseTextSize;
    Vector2D restartTextSize;
 
    

public:
    Lose();
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~Lose() {
    }
};
