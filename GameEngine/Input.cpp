#include "Input.h"
#include <ranges>
#include <SDL_events.h>

Input::Input() = default;
Input::~Input() = default;

void Input::RegisterKey(SDL_Keycode key) {
    keyboard.insert(std::make_pair(key, std::make_shared<InputValue>()));
}

//Called from Engine to register key events.
void Input::UpdateInput() {
    for (const auto& val : keyboard | std::views::values) val->pressed = false;
    
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
        const SDL_Keycode InputCode = e.key.keysym.sym;
        if (!keyboard.contains(InputCode)) return;
        const auto pair = keyboard.find(InputCode);
        switch (e.type) {
        case SDL_KEYDOWN:
            if (pair != keyboard.end()) {
                pair->second->held = true;
                pair->second->pressed = true;
            }
            break;
        case SDL_KEYUP:
            if (pair != keyboard.end()) pair->second->held = false;
            break;
        default: ;
        }
    }
}


/**
 * \brief Get the key event the frame requested.
 * \param key SDL_Keycode that is read
 * \return true the frame that the key is pressed
 */
bool Input::GetKeyDown(SDL_Keycode key) {
    if (!keyboard.contains(key)) RegisterKey(key);  // Will register any key requested

    return keyboard.find(key)->second->pressed;
}

/**
 * \brief Get the key event the frame requested.
 * \param key SDL_Keycode that is read
 * \return true the frame that the key is pressed
 */
bool Input::GetKey(SDL_Keycode key) {
    if (!keyboard.contains(key)) RegisterKey(key);

    return keyboard.find(key)->second->held;
}
