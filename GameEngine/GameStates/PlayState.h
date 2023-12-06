#pragma once
#include "GameState.h"

struct PlayState : GameState 
{
    void OnEnter() override;
    void OnExit() override;
    void Update() override;
};
