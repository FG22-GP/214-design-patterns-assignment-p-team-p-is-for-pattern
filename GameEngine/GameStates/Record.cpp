#include "Record.h"
#include "..\Vector2D.h"

#include "..\Components\Render.h"
#include "..\Engine\RenderCreator.h"
#include "..\Engine\MovementCreator.h"
#include "..\Input.h"
#include "..\EventHandler.h"
#include "..\GameManager.h"


Record::Record(GameManager* manager) : GameState(manager)
{
    player = std::make_shared<Entity>(Vector2D(200, 200));
    auto renderComponentCreator = RenderCreator();
    auto movementComponentCreator = MovementCreator();
    player->AddComponent(renderComponentCreator.CreateComponent(player, Vector2D(200, 200), "pikachu"));
    player->AddComponent(movementComponentCreator.CreateComponent(player));
    entityList.push_back(player);
}

void Record::Start()
{

    GameState::Start();
}

void Record::Stop()
{

    GameState::Stop();
}

void Record::Update()
{

    if (Input::GetKeyDown(SDLK_w)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(0, 1), player)));
    }
    if (Input::GetKeyDown(SDLK_s)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(0, -1), player))); 
    }
    if (Input::GetKeyDown(SDLK_a)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(-1, 0), player))); 
    }
    if (Input::GetKeyDown(SDLK_d)) {
        EventHandler::Push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(1, 0), player))); 
    }
    if (Input::GetKeyDown(SDLK_RETURN)) {
        gameManager->ChangeActiveState("Play", true);
    }
    GameState::Update();
}

Record::~Record()
{
}

