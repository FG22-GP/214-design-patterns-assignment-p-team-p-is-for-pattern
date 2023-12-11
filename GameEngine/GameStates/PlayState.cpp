#include "PlayState.h"
#include "..\Vector2D.h"

//const std::string PlayState::stateID = "Play";

void PlayState::Start()
{
    //State Start logic here
    TheTextureManager::Instance()->LoadImage("img/pikachu.png","pikachu");
    printf("Play State Entered \n");
    //runs entity Start logic
    GameState::Start();

}

void PlayState::Stop()
{
    //State Stop logic here
    TheTextureManager::Instance()->ClearFromTextureMap("pikachu");
    printf("Play Stopped Entered \n");
    //runs entity Stop logic
    GameState::Stop();
}

void PlayState::Update()
{
    ++pos_x;
    ++pos_y;
    //State Update logic here
    TheTextureManager::Instance()->Draw("pikachu", Vector2D(pos_x, pos_y), Vector2D(200, 200));
    //runs entity Update logic
    GameState::Update();
}
