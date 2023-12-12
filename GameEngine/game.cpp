//Using SDL and standard IO
#include <queue>
#include <SDL.h>
#include <stdio.h>

#include "Command.h"
#include "Input.h"
#include "IGameWindow.h"
#include "GameWindow.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "GameManager.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char* args[]) {
    TheGameWindow::Instance()->Init(1024, 768, IMG_INIT_PNG);
    
    GameManager* gameManager = new GameManager();

    gameManager->Start();
    gameManager->ChangeActiveState("Record");

    bool quit = false;
    
    // while the user doesn't want to quit
    while (quit == false) {
        SDL_GetTicks();
        Input::UpdateInput();
        
        //if (Input::GetKey(SDLK_SPACE)) {
        //    const std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        // //   CommandQueue.push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(1, 1), this))); // logic, 
        //}
        // if (Input::GetKeyDown(SDLK_RETURN)) {
        //    // while (!CommandQueue.empty()) {
        //    //     CommandQueue.back()->Execute();
        //    //     CommandQueue.pop();
        //    // }
        //}
        if (Input::GetKeyDown(SDLK_ESCAPE)) {
            quit = true;
        }

        // clear the screen
        TheGameWindow::Instance()->Clear();

        gameManager->Update();

        // present screen (switch buffers)
        TheGameWindow::Instance()->Present();

        SDL_Delay(3); // can be used to wait for a certain amount of ms
    }

    gameManager->Stop();

    gameManager = nullptr;
    TheGameWindow::Instance()->CleanUpFunction();

    return 0;
}
