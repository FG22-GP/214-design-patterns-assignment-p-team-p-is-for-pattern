#include "WonState.h"

//const std::string WonState::stateID = "Won";

void WonState::Start()
{
    //State Start logic here


    //runs entity Start logic
    GameState::Start();
}

void WonState::Stop()
{
    //State Stop logic here


    //runs entity Stop logic
    GameState::Stop();
}

void WonState::Update()
{
    //State Update logic here


    //runs entity Update logic
    GameState::Update();
}

std::string WonState::GetStateID()
{
    return stateID;
}
