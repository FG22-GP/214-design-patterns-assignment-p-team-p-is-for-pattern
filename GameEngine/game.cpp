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


//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

const char* pikachuImagePath{"img/pikachu.png"};

int main(int argc, char* args[]) {
    TheGameWindow::Instance()->Init(1024, 768, IMG_INIT_PNG);
    // All data related to pikachu
    SDL_Texture* pikachu = NULL; // The final optimized image
    bool pikachuMoveRight = false;
    int pik_x, pik_y;
    pik_x = pik_y = 0;
    int pik_w, pik_h;
    pik_w = pik_h = 200;

    //Load image at specified path

    TheTextureManager::Instance()->LoadImage(pikachuImagePath, "pikachu");
   
    Color textColor = {0xff, 0xff, 0xff};
    Vector2D dimensions;
    TheTextureManager::Instance()->LoadText("font/lazy.ttf", "lazy", textColor, 100, "The lazy fox, blah blah", dimensions);
    
    bool quit = false;

    std::queue<std::shared_ptr<Command>> CommandQueue;
    // while the user doesn't want to quit
    while (quit == false) {
        SDL_GetTicks();
        Input::UpdateInput();

        if (Input::GetKey(SDLK_UP)) pik_y--;
        if (Input::GetKey(SDLK_DOWN)) pik_y++;
        if (Input::GetKey(SDLK_d)) pik_x++;
        if (Input::GetKey(SDLK_a)) pik_x--;

        if (Input::GetKeyDown(SDLK_SPACE)) {
            const std::shared_ptr<Entity> entity = std::make_shared<Entity>();
            CommandQueue.push(std::make_shared<MoveCommand>(MoveCommand(Vector2D(1, 1), entity)));
        }
        if (Input::GetKeyDown(SDLK_RETURN)) {
            while (!CommandQueue.empty()) {
                CommandQueue.back()->Execute();
                CommandQueue.pop();
            }
        }
        if (Input::GetKeyDown(SDLK_ESCAPE))
        {
            quit = true;
        }

        // clear the screen
        TheGameWindow::Instance()->Clear();

        // render Pikachu
        SDL_Rect targetRectangle{
            pik_x,
            pik_y,
            pik_w,
            pik_h
        };
        TheTextureManager::Instance()->Draw("pikachu", Vector2D(pik_x,pik_y), Vector2D(pik_w, pik_h));
        TheTextureManager::Instance()->Draw("lazy", Vector2D(500, 500), dimensions);

        // present screen (switch buffers)
        TheGameWindow::Instance()->Present();

        SDL_Delay(3); // can be used to wait for a certain amount of ms
    }

    TheGameWindow::Instance()->CleanUpFunction();

    return 0;
}
