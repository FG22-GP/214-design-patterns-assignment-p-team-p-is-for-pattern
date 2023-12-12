#include "Record.h"

#include <fstream>

#include "..\Vector2D.h"
#include "..\Engine/CollisionCreator.h"
#include "..\Components\Render.h"
#include "..\Engine\RenderCreator.h"
#include "..\Engine\MovementCreator.h"
#include "..\Input.h"
#include "..\Constants/Constants.h"
#include "..\EventHandler.h"
#include "..\GameManager.h"


Record::Record(GameManager* manager) : GameState(manager) {
    int rangeX = WindowSizeX - 0 + 1;
    int numX = rand() % rangeX + 0;
    int rangeY = WindowSizeY - 0 + 1;
    int numY = rand() % rangeY + 0;
    player = std::make_shared<Entity>(Vector2D(200, 200));
    player->AddComponent(RenderCreator().CreateComponent(player, Vector2D(75, 75), "pikachu"));
    player->AddComponent(MovementCreator().CreateComponent(player));
    
    theEnd = std::make_shared<Entity>(Vector2D(numX, numY));
    theEnd->AddComponent(RenderCreator().CreateComponent(theEnd, Vector2D(150, 150), "pikachu"));
    theEnd->AddComponent(RenderCreator().CreateComponent(theEnd, Vector2D(150, 150), "pikachu"));
    theEnd->AddComponent(CollisionCreator().CreateComponent(theEnd, 100.0f));
    
    entityList.push_back(player);
    entityList.push_back(theEnd);
}

void Record::Start() {
    GameState::Start();
}

void Record::Stop() {
    GameState::Stop();
}

void Record::Update() {
    // pixels per frame movement
    if (Input::GetKey(SDLK_w)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(0, -1), player)));
    }
    if (Input::GetKey(SDLK_s)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(0, 1), player)));
    }
    if (Input::GetKey(SDLK_a)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(-1, 0), player)));
    }
    if (Input::GetKey(SDLK_d)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(1, 0), player)));
    }
    if (Input::GetKeyDown(SDLK_RETURN)) {
        gameManager->ChangeActiveState("Play", true);
    }
    GameState::Update();
}

Record::~Record() {
}
