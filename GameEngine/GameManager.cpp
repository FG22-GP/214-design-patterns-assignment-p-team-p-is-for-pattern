#include "GameManager.h"

#include "GameStates/PlayState.h"


GameManager::GameManager() : Mono(*this) {
    currentState = new PlayState();
}

void GameManager::ChangeState(GameState* newState) // todo: make smart pointer and enable smart pointer on gamestate.
{
    currentState->OnExit();
    currentState = newState;
    currentState->OnEnter();
}

void GameManager::Start() {
    currentState->OnEnter();
}

void GameManager::Update() {
    currentState->Update();
}

void GameManager::Stop() {
    currentState->OnExit();
}
