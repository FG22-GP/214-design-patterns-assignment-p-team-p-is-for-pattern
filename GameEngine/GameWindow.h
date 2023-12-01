#pragma once
// #include "Image.h"
#include <memory>
#include <SDL_render.h>
#include <SDL_video.h>
#include <SDL_image.h>

#include "IGameWindow.h"
#include "IImage.h"


class GameWindow : public IGameWindow {
    //The window we'll be rendering to
    SDL_Window* window_{};
    //The surface contained by the window
    SDL_Surface* screen_surface_{};
    //Whether Window Startup was successful
    bool b_success_;
    int img_flags_;

public:
    // dependency to the ImageLoader
    SDL_Renderer* renderer_;

    GameWindow(int screen_width, int screen_height, int image_flags = IMG_INIT_PNG);
    bool was_successful() override;
    void render(IImage* image);
    void clear() override;
    void present() override;
};
