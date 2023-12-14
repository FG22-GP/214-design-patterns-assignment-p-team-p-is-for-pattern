#include "Lose.h"
#include "..\TextureManager.h"
#include "..\Input.h"
#include "..\GameManager.h"

Lose::Lose(GameManager* manager) : GameState(manager) {
    Color lostTextColor = {0xff, 0xff, 0xff};
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "lost", lostTextColor, 80, "You Lost!!!", loseTextSize);
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "restart", lostTextColor, 60, "Press Space to Play New Level", restartTextSize);
    TheTextureManager::Instance()->LoadText("font/Silkscreen-Regular.ttf", "retry", lostTextColor, 60, "Press Enter to Retry Current Level", restartTextSize);
}

void Lose::Start() {
    GameState::Start();
}

void Lose::Stop() {
    GameState::Stop();
}

void Lose::Update() {
    GameState::Update();
    TheTextureManager::Instance()->Draw("lost", Vector2D(WindowSizeX / 8, WindowSizeY / 8), loseTextSize);
    TheTextureManager::Instance()->Draw("restart", Vector2D(WindowSizeX / 8, WindowSizeY / 8 + restartTextSize.GetY()), restartTextSize);
    TheTextureManager::Instance()->Draw("retry", Vector2D(WindowSizeX / 8, WindowSizeY / 8 + restartTextSize.GetY() * 2), restartTextSize);

    if (Input::GetKeyDown(SDLK_RETURN)) {
        gameManager->RestartLevel(false);
        gameManager->ChangeActiveState("Record");
    }

    if (Input::GetKeyDown(SDLK_SPACE)) {
        gameManager->RestartLevel(true);
        gameManager->ChangeActiveState("Record");
    }
}
