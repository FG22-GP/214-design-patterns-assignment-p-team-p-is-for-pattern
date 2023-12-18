#include "PlayState.h"

#include "../GameManager.h"
#include "../TextureManager.h"
#include "../Timer.h"
#include "..\EventHandler.h"
#include "../Components/Collision.h"

//const std::string PlayState::stateID = "Play";

PlayState::PlayState() {
    
}

void PlayState::Start() {
    GameState::Start();
    const auto playerEntity = gameManager->GetEntity("Player");
    if (playerEntity->GetComponent<Movement>()) {
        // player entity collision;
        playerCollision = playerEntity->GetComponent<Collision>();
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
        gameManager->ChangeActiveState("Lose");
        break;
    case TILE_GOAL:
        if (gameManager->activeLevel->mTime->GetScore() < gameManager->activeLevel->goalTime) gameManager->ChangeActiveState("Won");
        else gameManager->ChangeActiveState("Lose");

        break;
    default:
        if (EventHandler::Empty()) {
            gameManager->ChangeActiveState("Record");
        }
        break;
    }

    
    TextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "PlayScore",
        gameManager->activeLevel->goalTime > gameManager->activeLevel->mTime->GetScore() ? scoreGreenTextColour : scoreRedTextColour,
        60,
        gameManager->activeLevel->mTime->GetScoreAsString(),
        recordingTextSize);
    
    TextureManager::Instance()->Draw("PlayScore", Vector2D(WindowSizeX / 20, WindowSizeY / 32), recordingTextSize);


    // if (/* Player Collision with evil tile of hell ||*/ !IsOnScreen(gameManager->playerEntity->position) || gameManager->strokes == 3) {
    //     gameManager->ChangeActiveState("Lose");
    //     SDL_Log("Score %i", gameManager->activeLevel->score->GetScore());
    //     return;
    // }
    // gameManager->ChangeActiveState("Record");
    // SDL_Log("Score %i", gameManager->activeLevel->score->GetScore());
}

PlayState::~PlayState() = default;
