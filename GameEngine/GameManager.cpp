#include "GameManager.h"

#include "GameStates/PlayState.h"


GameManager::GameManager()
{
    currentState = new PlayState();
}

void GameManager::ChangeState(GameState* newState)
{
    currentState->OnExit();
    currentState = newState;
    currentState->OnEnter();
}

void GameManager::Start()
{
    currentState->OnEnter();
}

void GameManager::Update()
{
    currentState->Update();
}

void GameManager::Stop()
{
    currentState->OnExit();
}