#pragma once
// #include "Image.h"
#include <memory>
#include <SDL_render.h>
#include <SDL_video.h>
#include <SDL_image.h>

#include "IGameWindow.h"


class GameWindow : public IGameWindow {
    //The window we'll be rendering to
    SDL_Window* window{};
    //The surface contained by the window
    SDL_Surface* screenSurface{};
    SDL_Renderer* renderer;
    bool bSuccess;
    int imgFlags;

public:
    GameWindow(int screen_width, int screen_height, int image_flags = IMG_INIT_PNG);
    bool WasSuccessful() override;
    void Clear() override;
    void Present() override;
    SDL_Renderer* GetRenderer() const;
};
