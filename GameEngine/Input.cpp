#include "Input.h"
#include <ranges>
#include <SDL_events.h>

#include "Vector2D.h"

Input::Input() = default;
Input::~Input() = default;

std::map<SDL_Keycode, std::shared_ptr<InputValue>> Input::keyboard;

class Apple;

void Input::RegisterKey(SDL_Keycode key) {
    keyboard.insert(std::make_pair(key, std::make_shared<InputValue>()));
    
}

void Input::UpdateInput() {
    for (const auto val : keyboard | std::views::values) val->pressed = false;

    SDL_Event e;
    if (SDL_PollEvent(&e)) {
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
        case SDL_MOUSEBUTTONDOWN:
           // e.button.button
            break;
        case SDL_MOUSEBUTTONUP:
            break;
        case SDL_MOUSEMOTION:
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

// bool Input::GetKey(SDL_Keycode key) {
//     if (!keyboard.contains(key)) RegisterKey(key);
//
//     return keyboard.find(key)->second->held;
// }

Vector2D Input::GetMousePosition() {
     int x;
     int y;
     SDL_GetMouseState(&x, &y);
    return Vector2D().SetX(static_cast<float>(x)).SetY(static_cast<float>(y));
}
