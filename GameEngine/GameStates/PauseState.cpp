#include "PauseState.h"

//const std::string PauseState::stateID = "Pause";

void PauseState::Start()
{
    //State Start logic here

    printf("Start State Entered");
    //runs entity Start logic
    GameState::Start();

}

void PauseState::Stop()
{
    //State Stop logic here

    printf("Start State Stopped");
    //runs entity Stop logic
    GameState::Stop();

}

void PauseState::Update()
{
    //State Update logic here


    //runs entity Update logic
    GameState::Update();

}

std::string PauseState::GetStateID()
{
    return stateID;
}
