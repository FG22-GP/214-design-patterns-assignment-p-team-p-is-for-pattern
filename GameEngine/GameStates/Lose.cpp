#include "Lose.h"
#include "..\TextureManager.h"
#include "..\Input.h"
#include "..\GameManager.h"

Lose::Lose() {
    Color lostTextColor = {0xff, 0xff, 0xff};
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "lost", lostTextColor, 60, "Try again.", loseTextSize);
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "retry", lostTextColor, 30, "Press Backspace to Retry", restartTextSize);
}

void Lose::Start() {
    GameState::Start();
}

void Lose::Stop() {
    GameState::Stop();

    ClearRefs();
}

void Lose::Update() {
    GameState::Update();
    TheTextureManager::Instance()->Draw("lost", Vector2D(WindowSizeX / 4, WindowSizeY / 4), loseTextSize);
    TheTextureManager::Instance()->Draw("retry", Vector2D(WindowSizeX / 4, WindowSizeY / 4 + restartTextSize.GetY() * 2), restartTextSize);
    
    if (Input::GetKeyDown(SDLK_BACKSPACE)) {
        gameManager->RestartLevel(false);
        gameManager->ChangeActiveState("Record");
    }
}
