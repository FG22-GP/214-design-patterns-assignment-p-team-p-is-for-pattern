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
    for (const auto& entity : entityList) {
        if (entity->GetComponent<Movement>()) {
            // player entity collision;
            playerCollision = entity->GetComponent<Collision>();
            break;
        }
    }
}

void PlayState::Stop() {
    GameState::Stop();
}

void PlayState::Update() {
    GameState::Update();
    if (!EventHandler::Empty()) {
        EventHandler::TryPop();
        gameManager->activeLevel->score->UpdateScore(); // Update those points of yours
        return;
    }
    
    for (const auto& entity : entityList) {
        //cursed refactor
        const auto CollisionComponent = entity->GetComponent<Collision>();
        if (!CollisionComponent) continue;

        // TextureManager::Instance()->SetAlpha(entity->GetComponent<Render>()->imageName, 1); // TODO: Makes Entity invisible lol -Petter

        for (const auto& entity2 : entityList) {
            if (entity == entity2) continue;

            if (CollisionComponent->CheckCollision(entity2) == TILE_GOAL) {
                gameManager->ChangeActiveState("Won");
                SDL_Log("Score %i", gameManager->activeLevel->score->GetScore());
                return;
            }
        }
    }
    if (/* Player Collision with evil tile of hell ||*/ !IsOnScreen(gameManager->playerEntity->position) || gameManager->strokes == 3) {
        gameManager->ChangeActiveState("Lose");
        SDL_Log("Score %i", gameManager->activeLevel->score->GetScore());
        return;
    }
    gameManager->ChangeActiveState("Record");
    SDL_Log("Score %i", gameManager->activeLevel->score->GetScore());
}

PlayState::~PlayState() = default;
