#pragma once
#include "GameState.h"

class WonState : public GameState
{

    

public:
    WonState() {}
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() override;

    ~WonState() {}
};
