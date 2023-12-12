#include "WonState.h"
#include "..\TextureManager.h"

//const std::string WonState::stateID = "Won";

WonState::WonState(GameManager* manager) : GameState(manager)
{
    Color wonTextColor = { 0xff,0xff,0xff };
    TheTextureManager::Instance()->LoadText("font/lazy.ttf", "lazy", wonTextColor, 120 ,"You Won!!!",wonTextSize);
}

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

    TheTextureManager::Instance()->Draw("lazy",Vector2D(200,200),wonTextSize);
    //runs entity Update logic
    GameState::Update();
}

