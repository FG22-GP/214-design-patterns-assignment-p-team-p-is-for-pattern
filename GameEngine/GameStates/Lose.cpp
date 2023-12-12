#include "Lose.h"

Lose::Lose(GameManager* manager) : GameState(manager) {
    
}

void Lose::Start() {
    GameState::Start();
}

void Lose::Stop() {
    GameState::Stop();
}

void Lose::Update() {
    GameState::Update();
}
