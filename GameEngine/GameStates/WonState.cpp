#include "WonState.h"
#include "..\TextureManager.h"
#include "..\Input.h"
#include "..\GameManager.h"

//const std::string WonState::stateID = "Won";

WonState::WonState() {
    Color wonTextColor = {0xff, 0xff, 0xff};
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "lazy", wonTextColor, 60, "Congratulations",
                                            wonTextSize);
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "wonNext", wonTextColor, 40, "Better time? Backspace",
                                            restartTextSize);
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "wonRetry", wonTextColor, 40, "Continue? Enter",
                                            continueTextSize);
}

void WonState::Start() {
    //State Start logic here


    //runs entity Start logic
    GameState::Start();
}

void WonState::Stop() {
    //State Stop logic here


    //runs entity Stop logic
    GameState::Stop();

    ClearRefs();
}

void WonState::Update() {
    TheTextureManager::Instance()->Draw("lazy", Vector2D(WindowSizeX / 8, WindowSizeY / 4), wonTextSize);
    TheTextureManager::Instance()->Draw("wonNext", Vector2D(WindowSizeX / 6, WindowSizeY / 4 + wonTextSize.GetY()),
                                        restartTextSize);
    TheTextureManager::Instance()->Draw("wonRetry", Vector2D(WindowSizeX / 6, WindowSizeY / 4.44f + wonTextSize.GetY() * 2),
                                        continueTextSize);
    if (Input::GetKeyDown(SDLK_BACKSPACE)) {
        gameManager->RestartLevel(false);
        gameManager->ChangeActiveState("Record");
    }

    if (Input::GetKeyDown(SDLK_RETURN)) {
        gameManager->RestartLevel(true);
        gameManager->ChangeActiveState("Record");
    }

    GameState::Update();
}
