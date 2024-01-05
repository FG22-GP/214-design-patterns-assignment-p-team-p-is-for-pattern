#include "PauseState.h"

//const std::string PauseState::stateID = "Pause";

PauseState::PauseState()
{

}

void PauseState::Start()
{
    //State Start logic here

    printf("Start State Entered \n");
    //runs entity Start logic
    GameState::Start();

}

void PauseState::Stop()
{
    //State Stop logic here

    printf("Start State Stopped \n");
    //runs entity Stop logic
    GameState::Stop();

}

void PauseState::Update()
{
    //State Update logic here


    //runs entity Update logic
    GameState::Update();

}
