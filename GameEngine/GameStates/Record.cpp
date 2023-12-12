#include "Record.h"

#include <fstream>
#include <random>

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

    
    player = std::make_shared<Entity>(Vector2D(200, 200));
    player->AddComponent(RenderCreator().CreateComponent(player, Vector2D(75, 75), "pikachu"));
    player->AddComponent(MovementCreator().CreateComponent(player));
    
    theEnd = std::make_shared<Entity>(GenerateRandomPosition());
    theEnd->AddComponent(RenderCreator().CreateComponent(theEnd, Vector2D(150, 150), "pikachu"));
    theEnd->AddComponent(CollisionCreator().CreateComponent(theEnd, 100.0f));
    
    entityList.push_back(player);
    entityList.push_back(theEnd);
}


Vector2D Record::GenerateRandomPosition()
{
    int xRangeFrom = 0;
    int xRangeTo = WindowSizeX;
    int yRangeFrom = 0;
    int yRangeTo = WindowSizeY;
    std::mt19937 generator(std::_Random_device());
    std::uniform_int_distribution xDistribution(xRangeFrom, xRangeTo - 75);
    std::uniform_int_distribution yDistribution(yRangeFrom, yRangeTo - 75);
    return Vector2D(xDistribution(generator), yDistribution(generator));
}

void Record::Initilize()
{

}


void Record::Start() {
    GameState::Start();
    player->position = Vector2D(200,200);
    theEnd->position = GenerateRandomPosition();

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
