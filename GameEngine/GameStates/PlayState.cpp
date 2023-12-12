#include "PlayState.h"

#include "..\EventHandler.h"

//const std::string PlayState::stateID = "Play";

PlayState::PlayState(GameManager* manager) : GameState(manager)
{

}

void PlayState::Start()
{
    //State Start logic here

    
    printf("Play State Entered \n");
    //runs entity Start logic
    GameState::Start();

}

void PlayState::Stop()
{
    //State Stop logic here

    printf("Play Stopped Entered \n");
    //runs entity Stop logic
    GameState::Stop();
}

void PlayState::Update()
{
    auto player = entityList[0];
    //State Update logic here
    if (!EventHandler::Empty())
    {
        EventHandler::TryPop();
        printf("Positon : %f , %f" , player->position.GetX() , player->position.GetY());
    }
    else
    {

    }
    //runs entity Update logic
    GameState::Update();
}

PlayState::~PlayState()
{
 
}
