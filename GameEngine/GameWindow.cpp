#include "GameWindow.h"
#include <SDL_image.h>
#include <SDL_ttf.h>

bool GameWindow::Init()
{
    return false;
}

bool GameWindow::Init(const int width, const int height, int image_flags) {
    img_flags_ = image_flags;
    // renderer_ = SDL_CreateRenderer(window_, -1, 0);

    if (!GameWindow::WasSuccessful()) {
        return false;
    }
    SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window_, &renderer);
    if (!window_) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, width, height);
    return true;
}

bool GameWindow::WasSuccessful() {
    if (!(IMG_Init(img_flags_) & img_flags_)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    return true;
}

void GameWindow::Clear() {
    SDL_SetRenderDrawColor(renderer, 6, 6, 15, 255);
    SDL_RenderClear(renderer);
}

void GameWindow::Present() {
    SDL_RenderPresent(renderer);
}

void GameWindow::CleanUpFunction()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer);
    pInstance = nullptr;
    SDL_Quit();
}

SDL_Renderer* GameWindow::GetRenderer() const {
    return renderer;
}

GameWindow* GameWindow::pInstance = 0 ;