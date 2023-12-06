#pragma once
#include "GameState.h"

struct PauseState : GameState
{
    void OnEnter() override;
    void OnExit() override;
    void Update() override;
};
