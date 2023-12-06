#pragma once
// #include "Image.h"
#include <memory>
#include <SDL_render.h>
#include <SDL_video.h>
#include <SDL_image.h>

#include "IGameWindow.h"


class GameWindow : public IGameWindow {
    //The window we'll be rendering to
    SDL_Window* window_{};
    //The surface contained by the window
    SDL_Surface* screen_surface_{};
    SDL_Renderer* renderer;
    bool b_success_;
    int img_flags_;

protected:
    GameWindow() {}

public:

    bool Init() override;
    bool Init(int screen_width, int screen_height, int image_flags = IMG_INIT_PNG);

    //Whether Window Startup was successful
    bool WasSuccessful() override;
    void Clear() override;
    void Present() override;
    void CleanUpFunction() override;
    SDL_Renderer* GetRenderer() const;

    static GameWindow* pInstance;

    static GameWindow* Instance()
    {
        if (pInstance == 0)
        {
            pInstance = new GameWindow();
            return pInstance;
        }
        return pInstance;
    }

};

typedef GameWindow TheGameWindow;