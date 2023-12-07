#include "PlayState.h"

//const std::string PlayState::stateID = "Play";

void PlayState::Start()
{
    //State Start logic here

    printf("Play State Entered");
    //runs entity Start logic
    GameState::Start();

}

void PlayState::Stop()
{
    //State Stop logic here

    printf("Play Stopped Entered");
    //runs entity Stop logic
    GameState::Stop();
}

void PlayState::Update()
{
    //State Update logic here


    //runs entity Update logic
    GameState::Update();
}

std::string PlayState::GetStateID()
{
    return stateID;
}
