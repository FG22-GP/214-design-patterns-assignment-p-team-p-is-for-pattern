#include "Input.h"
#include <ranges>
#include <SDL_events.h>

Input::Input() = default;
Input::~Input() = default;

std::map<SDL_Keycode, std::shared_ptr<InputValue>> Input::keyboard;

void Input::RegisterKey(SDL_Keycode key) {
    keyboard.insert(std::make_pair(key, std::make_shared<InputValue>())); // memory leak, how do I manage these pointers
}

void Input::UpdateInput() {
    for (const auto val : keyboard | std::views::values) val->pressed = false;

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        SDL_Keycode InputCode = e.key.keysym.sym;
        if (!keyboard.contains(InputCode)) return;
        auto pair = keyboard.find(InputCode);
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

bool Input::GetKeyDown(SDL_Keycode key) {
    if (!keyboard.contains(key)) RegisterKey(key);

    return keyboard.find(key)->second->pressed;
}

bool Input::GetKey(SDL_Keycode key) {
    if (!keyboard.contains(key)) RegisterKey(key);

    return keyboard.find(key)->second->held;
}
