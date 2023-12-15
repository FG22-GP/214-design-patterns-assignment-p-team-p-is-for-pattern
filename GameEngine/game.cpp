//Using SDL and standard IO
#include <queue>
#include <SDL.h>
#include "Command.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "Input.h"
#include "TextureManager.h"
#include "Timer.h"
#include "Constants/Constants.h"
#include "Level/Parser.h"

int main(int argc, char* args[]) {
    TheGameWindow::Instance()->Init(WindowSizeX, WindowSizeY, IMG_INIT_PNG);

    auto gameManager = new GameManager();
    gameManager->Start();
    gameManager->RestartLevel(true);
    gameManager->ChangeActiveState("Record");

    Timer* timer = Timer::Instance();

    bool quit = false;

    while (quit == false) {
        timer->Update();

        Input::UpdateInput();

        if (Input::GetKeyDown(SDLK_ESCAPE)) quit = true;

        TheGameWindow::Instance()->Clear();


        if (timer->DeltaTime() >= 1.0f / FrameRate) {
            gameManager->Update();
            TheGameWindow::Instance()->Present();
            timer->Reset();
        }
    }

    Timer::Release();
    timer = nullptr;

    gameManager->Stop();
    gameManager = nullptr;
    TheGameWindow::Instance()->CleanUpFunction();

    return 0;
}
