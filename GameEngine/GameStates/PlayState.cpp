#include "PlayState.h"

#include "../GameManager.h"
#include "../Timer.h"
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
        if (entity.second->GetComponent<Movement>()) {
            // player entity collision;
            playerCollision = entity.second->GetComponent<Collision>();
            break;
        }
    }
    gameManager->activeLevel->mTime->GiveScoreValue(1.0f);
}

void PlayState::Stop() {
    GameState::Stop();
}

void PlayState::Update() {
    GameState::Update();
    if (!EventHandler::Empty()) {
        EventHandler::TryPop();
        gameManager->activeLevel->mTime->UpdateScore(Timer::Instance()->DeltaTime()); // Update those points of yours
        printf("YO TIME IS: %s,\n", gameManager->activeLevel->mTime->GetScoreAsString().c_str());
    }


    // for (const auto& entity : entityList) {
    //     //cursed refactor
    //     const auto CollisionComponent = entity->GetComponent<Collision>();
    //     if (!CollisionComponent) continue;
    //
    //     // TextureManager::Instance()->SetAlpha(entity->GetComponent<Render>()->imageName, 1); // TODO: Makes Entity invisible lol -Petter
    //
    //     for (const auto& entity2 : entityList) {
    //         if (entity == entity2) continue;
    //
    //         if (CollisionComponent->CheckCollision(entity2) == TILE_GOAL) {
    //             gameManager->ChangeActiveState("Won");
    //             SDL_Log("Score %i", gameManager->activeLevel->score->GetScore());
    //             return;
    //         }
    //     }
    // }


    switch (playerCollision->CheckCollision()) {
    case TILE_UNWALKABLE:
        gameManager->ChangeActiveState("Lose", true);
        break;
    case TILE_GOAL:
        if (gameManager->activeLevel->mTime->GetScore() < gameManager->activeLevel->targetTime)
            gameManager->ChangeActiveState("Won", true);
        else gameManager->ChangeActiveState("Lose", true);
        
        break;
    default:
        if (EventHandler::Empty()) {
            gameManager->ChangeActiveState("Record", true);
        }
        break;
    }


    // if (/* Player Collision with evil tile of hell ||*/ !IsOnScreen(gameManager->playerEntity->position) || gameManager->strokes == 3) {
    //     gameManager->ChangeActiveState("Lose");
    //     SDL_Log("Score %i", gameManager->activeLevel->score->GetScore());
    //     return;
    // }
    // gameManager->ChangeActiveState("Record");
    // SDL_Log("Score %i", gameManager->activeLevel->score->GetScore());
}

PlayState::~PlayState() = default;
