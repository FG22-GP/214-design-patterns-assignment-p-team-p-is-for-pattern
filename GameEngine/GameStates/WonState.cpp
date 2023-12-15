#include "WonState.h"
#include "..\TextureManager.h"
#include "..\Input.h"
#include "..\GameManager.h"

//const std::string WonState::stateID = "Won";

WonState::WonState(GameManager* manager) : GameState(manager)
{
    Color wonTextColor = { 0xff,0xff,0xff };
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "lazy", wonTextColor, 60 ,"You Won!!!",wonTextSize);
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "wonRestart", wonTextColor, 30, "Press Space to Play New Level", wonTextSize);
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "wonRetry", wonTextColor, 30, "Press Enter to Retry Current Level", wonTextSize);
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
    TheTextureManager::Instance()->Draw("lazy",Vector2D(WindowSizeX / 4, WindowSizeY / 4),wonTextSize);
    TheTextureManager::Instance()->Draw("wonRestart",Vector2D(WindowSizeX / 4, WindowSizeY / 4 + wonTextSize.GetY()), wonTextSize);
    TheTextureManager::Instance()->Draw("wonRetry",Vector2D(WindowSizeX / 4, WindowSizeY / 4 + wonTextSize.GetY() * 2), wonTextSize);
    if (Input::GetKeyDown(SDLK_RETURN))
    {
        gameManager->RestartLevel(false);
        gameManager->ChangeActiveState("Record");
    }

    if (Input::GetKeyDown(SDLK_SPACE)) {
        gameManager->RestartLevel(true);
        gameManager->ChangeActiveState("Record");
    }
    
    GameState::Update();
}

