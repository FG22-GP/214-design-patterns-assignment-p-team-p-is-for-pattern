#include "GameWindow.h"
#include <SDL_image.h>
#include <SDL_ttf.h>


GameWindow::GameWindow(const int width, const int height, int image_flags) {
    img_flags_ = image_flags;
    // renderer_ = SDL_CreateRenderer(window_, -1, 0);

    if (!GameWindow::WasSuccessful()) {
        return;
    }
    SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window_, &renderer);
    if (!window_) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, width, height);
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
    SDL_SetRenderDrawColor(renderer, 120, 60, 255, 255);
    SDL_RenderClear(renderer);
}

void GameWindow::Present() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer* GameWindow::GetRenderer() const {
    return renderer;
}
