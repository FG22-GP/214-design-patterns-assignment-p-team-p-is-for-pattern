//Using SDL and standard IO
#include <queue>
#include <SDL.h>
#include "Command.h"
#include "Input.h"
#include "GameWindow.h"
#include "Constants/Constants.h"
#include "TextureManager.h"
#include "GameManager.h"
#include "Level/Parser.h"
#include "Level/Tileset.h"

int main(int argc, char* args[]) {
    TheGameWindow::Instance()->Init(WindowSizeX, WindowSizeY, IMG_INIT_PNG);
    
    GameManager* gameManager = new GameManager();
    gameManager->Start();
    gameManager->RestartLevel(true);
    gameManager->ChangeActiveState("Record");

    

    bool quit = false;
    
    while (quit == false) {
        SDL_GetTicks();
        
        Input::UpdateInput();
        
        if (Input::GetKeyDown(SDLK_ESCAPE)) quit = true;
 
        TheGameWindow::Instance()->Clear();

        gameManager->Update();

        TheGameWindow::Instance()->Present();

        SDL_Delay(3); // can be used to wait for a certain amount of ms
    }

    gameManager->Stop();

    gameManager = nullptr;
    TheGameWindow::Instance()->CleanUpFunction();

    return 0;
}
