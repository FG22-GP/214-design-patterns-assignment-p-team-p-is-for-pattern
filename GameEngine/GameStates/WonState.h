#pragma once
#include "GameState.h"

struct WonState : GameState
{
    void OnEnter() override;
    void OnExit() override;
    void Update() override;
};
