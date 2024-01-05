#include "GameState.h"

#include "../GameManager.h"

void IGameState::ClearRefs() {
}

void GameState::Start()
{
}

void GameState::Stop()
{
}

void GameState::Update() 
{
}

void GameState::SetGameManager(std::shared_ptr<GameManager> manager) {
    gameManager = manager;
}
