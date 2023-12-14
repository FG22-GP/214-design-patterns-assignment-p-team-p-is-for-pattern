#include "PlayState.h"

#include "../GameManager.h"
#include "..\EventHandler.h"
#include "../Components/Collision.h"
#include "../Constants/Constants.h"
#include "../Engine/Engine.h"
#include "../Components/Render.h"

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

    for (const auto& entity : entityList) {
        // cursed refactor
        const auto CollisionComponent = entity->GetComponent<Collision>();
        if (!CollisionComponent) continue;

        // TextureManager::Instance()->SetAlpha(entity->GetComponent<Render>()->imageName, 1); // TODO: Makes Entity invisible lol -Petter

        for (const auto& entity2 : entityList) {
            if (entity == entity2) continue;

            if (CollisionComponent->CheckCollision(entity2)) {
                gameManager->ChangeActiveState("Won");
                return;
            }
        }
    }

    if (/* Player Collision with evil tile of hell ||*/ !IsOnScreen(gameManager->playerEntity->position) || gameManager->strokes == 3) {
        gameManager->ChangeActiveState("Lose");
        return;
    }

    gameManager->ChangeActiveState("Record");
}

PlayState::~PlayState() = default;
