#include "PlayState.h"

#include "../GameManager.h"
#include "..\EventHandler.h"
#include "../Components/Collision.h"

//const std::string PlayState::stateID = "Play";

PlayState::PlayState(GameManager* manager) : GameState(manager) {
}

void PlayState::Start() {
    GameState::Start();
}

void PlayState::Stop() {
    GameState::Stop();
}

void PlayState::Update() {
    GameState::Update();
    if (!EventHandler::Empty()) {
        EventHandler::TryPop();
        return;
    }

    for (const auto& entity : entityList) { // cursed refactor
        const auto CollisionComponent = entity->GetComponent<Collision>();
        if (!CollisionComponent) continue;
        for (const auto& entity2 : entityList) {
            if (entity == entity2) continue;

            if (CollisionComponent->CheckCollision(entity2)) {
               gameManager->ChangeActiveState("Won");
                return;
            }
            
        }
    }

    gameManager->ChangeActiveState("Lose");
}

PlayState::~PlayState() = default;
