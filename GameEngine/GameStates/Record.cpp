#include "Record.h"

#include <random>
#include "../GameManager.h"
#include "..\EventHandler.h"
#include "..\Input.h"
#include "..\Vector2D.h"
#include "../Level/Tileset.h"

Record::Record() {
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
    
    if (Input::GetKey(SDLK_w)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(0, -1), gameManager->playerEntity)));
    }
    if (Input::GetKey(SDLK_s)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(0, 1), gameManager->playerEntity)));
    }
    if (Input::GetKey(SDLK_a)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(-1, 0), gameManager->playerEntity)));
    }
    if (Input::GetKey(SDLK_d)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(1, 0), gameManager->playerEntity)));
    }
    if (!Input::GetKey(SDLK_w) && !Input::GetKey(SDLK_s) && !Input::GetKey(SDLK_a) && !Input::GetKey(SDLK_d)) {
        if (!EventHandler::Empty()) {
            gameManager->ChangeActiveState("Play");
        }
    }
    GameState::Update();
}

Record::~Record() {
}
