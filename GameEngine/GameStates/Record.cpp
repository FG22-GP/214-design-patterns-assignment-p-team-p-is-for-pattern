#include "Record.h"

#include <random>
#include "../GameManager.h"
#include "../TextureManager.h"
#include "../EventHandler.h"
#include "../Input.h"
#include "../Vector2D.h"

Record::Record() {
    TextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "Recording", scoreTextColour, 60, "Recording Input", recordingTextSize);
    // player = std::make_shared<Entity>("Player", Vector2D(200, 200));
    // player->AddComponent(RenderCreator().CreateComponent(player, Vector2D(32, 32), "MainCharacterSolo"));
    // player->AddComponent(MovementCreator().CreateComponent(player, 100.f));
    // player->AddComponent(CollisionCreator().CreateComponent(player, 32.0f, 32.0f));
    //
    // auto Position = GenerateRandomPosition();
    // // theEnd = std::make_shared<Entity>("Goal", Position);
    // //theEnd->AddComponent(RenderCreator().CreateComponent(theEnd, Vector2D(32, 32), "Goal"));
    // // // theEnd->AddComponent(CollisionCreator().CreateComponent(theEnd, 100.0f));
    // // theEnd->AddComponent(TileCreator().CreateComponent(theEnd, TILE_GOAL, Grid::WorldToGridPosition(Position)));
    // //
    //  entityList.push_back(player);
    // //entityList.push_back(theEnd);
    // gameManager->playerEntity = player;
}

void Record::Initilize() {
}


void Record::Start() {
    GameState::Start();
    //theEnd->position = gameManager->activeLevel->GetGoalPosition(); // Player position gets set on game manager when its needed
}

void Record::Stop() {
    GameState::Stop();
}

void Record::Update() {
    // pixels per frame movement
    Vector2D inputVector;
    if (Input::GetKey(SDLK_w)) {
        inputVector = inputVector + Vector2D(0.f, -1.f);
    }

    if (Input::GetKey(SDLK_s)) {
        inputVector = inputVector + Vector2D(0.f, 1.f);
    }

    if (Input::GetKey(SDLK_a)) {
        inputVector = inputVector + Vector2D(-1.f, 0.f);
    }

    if (Input::GetKey(SDLK_d)) {
        inputVector = inputVector + Vector2D(1.f, 0.f);
    }

    if (inputVector.GetX() != 0.f || inputVector.GetY() != 0.f) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(inputVector, gameManager->playerEntity)));
    }

    if (!Input::GetKey(SDLK_w) && !Input::GetKey(SDLK_s) && !Input::GetKey(SDLK_a) && !Input::GetKey(SDLK_d)) {
        if (!EventHandler::Empty()) {
            gameManager->ChangeActiveState("Play");
        }
    }
    TextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "PlayScore",
                                         gameManager->activeLevel->goalTime > gameManager->activeLevel->mTime->GetScore()
                                             ? scoreGreenTextColour
                                             : scoreRedTextColour,
                                         60,
                                         gameManager->activeLevel->mTime->GetScoreAsString(),
                                         scoreTextSize);
    TextureManager::Instance()->Draw("PlayScore", Vector2D(WindowSizeX / 20, WindowSizeY / 32), scoreTextSize);
    TextureManager::Instance()->Draw("Recording", Vector2D(WindowSizeX / 4.5, WindowSizeY / 32), recordingTextSize);

    GameState::Update();
}

Record::~Record() {
}
