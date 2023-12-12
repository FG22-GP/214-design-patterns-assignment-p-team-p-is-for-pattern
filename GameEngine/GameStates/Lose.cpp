#include "Lose.h"
#include "..\TextureManager.h"
#include "..\Input.h"
#include "..\GameManager.h"

Lose::Lose(GameManager* manager) : GameState(manager) {

    Color lostTextColor = { 0xff,0xff,0xff };
    TheTextureManager::Instance()->LoadText("font/lazy.ttf", "lost", lostTextColor, 80, "You Lost!!!", loseTextSize);
    TheTextureManager::Instance()->LoadText("font/lazy.ttf", "restart", lostTextColor, 60, "Press Enter to Start Again", restartTextSize);
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
    TheTextureManager::Instance()->Draw("restart", Vector2D(WindowSizeX / 8 , 
        WindowSizeY / 8 + loseTextSize.GetY()), restartTextSize);

    if (Input::GetKeyDown(SDLK_RETURN))
    {
        gameManager->ChangeActiveState("Record");
    }

}
