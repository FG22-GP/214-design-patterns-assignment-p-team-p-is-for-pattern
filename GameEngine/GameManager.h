#pragma once
#include "Engine/Mono.h"
#include "GameStates/GameState.h"

struct GameManager : Mono
{
    GameState* currentState;

    GameManager();
    
    void ChangeState(GameState* newState);

    void Start() override;
    void Update() override;
    void Stop() override;
};
