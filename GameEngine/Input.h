#pragma once
#include <map>
#include <memory>#
#include <SDL_keycode.h>
#include <string>

#include "Vector2D.h"

struct InputValue;

class Input {
public:
    Input();
    ~Input();

    static std::map<SDL_Keycode, std::shared_ptr<InputValue>> keyboard;
    /**
     * \brief Has to be put main game loop loop to register input
     */
    void static UpdateInput();
    void Clean();
    /**
     * \brief static method for reading input
     * \param key requested key as a string, not case sensitive
     * \return return true for one frame
     */
    bool static GetKeyDown(SDL_Keycode key);
    /**
     * \brief static method for reading input
     * \param key requested key as a string, not case sensitive
     * \return returns true while the button is pressed
     */
    bool static GetKey(SDL_Keycode key);
    static Vector2D GetMousePosition();


private:
    /**
     * \brief Static method to register input keys
     * \param values Array of strings to be registered
     * \param size Size of the array
     */
    void static RegisterKey(SDL_Keycode key);
};


struct InputValue : std::enable_shared_from_this<InputValue> {
    bool pressed;
    bool held;
};

