#pragma once
#include <SDL_render.h>
#include <SDL_video.h>


class IGameWindow {
    SDL_Window* window_{};
    SDL_Surface* screen_surface_{};
    bool bSuccess;
    SDL_Renderer* renderer_;

public:
    IGameWindow();
    virtual ~IGameWindow() = default;

    virtual bool WasSuccessful() = 0;
    virtual void Clear() = 0;
    virtual void Present() = 0;
};
