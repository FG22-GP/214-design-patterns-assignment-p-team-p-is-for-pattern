#pragma once
#include <SDL_video.h>


class IGameWindow {
    SDL_Window* window_{};
    SDL_Surface* screen_surface_{};
    bool bSuccess;
    // SDL_Renderer* renderer_;

public:
    IGameWindow();

    virtual bool was_successful();
    virtual void clear();
    virtual void present();
};
