#pragma once
#include <map>
#include <memory>
#include <SDL_keycode.h>

#include "Vector2D.h"

struct InputValue;

class Input {
public:
    Input();
    ~Input();

    static inline  std::map<SDL_Keycode, std::shared_ptr<InputValue>> keyboard;
    
    void static UpdateInput();
   
    /**
     * \brief static method for reading input
     * \param key requested key as a string, not case sensitive
     * \return return true for one frame
     */
    bool static GetKeyDown(SDL_Keycode key);

    /**
     * \brief static method for reading input
     * \param key Requested key as SDL_Keycode
     * \return returns true while the button is pressed
     */
    bool static GetKey(SDL_Keycode key);

private:
    
    void static RegisterKey(SDL_Keycode key);
};


struct InputValue : std::enable_shared_from_this<InputValue> {
    bool pressed{};
    bool held{};
};

