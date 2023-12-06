//Using SDL and standard IO
#include <queue>
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Command.h"
#include "Input.h"
#include "IGameWindow.h"
#include "GameWindow.h"
#include "TextureManager.h"


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
    // load font
    auto font = TTF_OpenFont("font/lazy.ttf", 100);
    if (font == NULL) {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        return -1;
    }

    // create text from font
    SDL_Color textColor = {0xff, 0xff, 0xff};
    //Render text surface
    SDL_Texture* textTexture; // The final optimized image

    // render the text into an unoptimized CPU surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "The lazy fox, blah blah", textColor);
    int textWidth, textHeight;
    if (textSurface == NULL) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return -1;
    }
    else {
        // Create texture GPU-stored texture from surface pixels
        textTexture = SDL_CreateTextureFromSurface(TheGameWindow::Instance()->GetRenderer(), textSurface);
        if (textTexture == NULL) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
            return -1;
        }
        // Get image dimensions
        auto width = textSurface->w;
        auto height = textSurface->h;
        textWidth = textSurface->w;
        textHeight = textSurface->h;
        //Get rid of old loaded surface
        SDL_FreeSurface(textSurface);
    }

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

        // render the text
        targetRectangle = SDL_Rect{
            500,
            500,
            textWidth,
            textHeight
        };
        SDL_RenderCopy(TheGameWindow::Instance()->GetRenderer(), textTexture, NULL, &targetRectangle);

        // present screen (switch buffers)
        TheGameWindow::Instance()->Present();

        SDL_Delay(3); // can be used to wait for a certain amount of ms
    }

    TheGameWindow::Instance()->CleanUpFunction();

    return 0;
}
