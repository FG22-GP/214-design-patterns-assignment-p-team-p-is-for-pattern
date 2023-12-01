#include "Input.h"

#include <ranges>
#include <SDL_events.h>

Input::Input() = default;

Input::~Input() = default;

std::map<std::string, InputValue*> Input::keyboard;

void Input::register_keys(std::string values[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        keyboard.insert(std::pair<std::string, InputValue*>{values[i], new InputValue()});
    }
    for (size_t i = 0; i < size; ++i) {
        printf(keyboard.find(values[i])->first);
    }
}

void Input::update_input() {
    for (const auto val : keyboard | std::views::values) {
        val->pressed = false;
    }

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        // check, if it's an event we want to react to:
        switch (e.type) {
        // This is an example on how to use input events:
        case SDL_KEYDOWN:
            {
                // input example: if left, then make pikachu move left
                if (e.key.keysym.sym == SDLK_LEFT) {
                    if (keyboard.contains(ToLower("LEFT"))) {
                        keyboard.find(ToLower("LEFT"))->second->held = true;
                        keyboard.find(ToLower("LEFT"))->second->pressed = true;
                    }
                }
                // if right, then make pikachu move right
                if (e.key.keysym.sym == SDLK_RIGHT) {
                    if (keyboard.contains(ToLower("RIGHT"))) {
                        keyboard.find(ToLower("RIGHT"))->second->held = true;
                        keyboard.find(ToLower("RIGHT"))->second->pressed = true;
                    }
                    //printf("We do be pressing right");
                }

                if (e.key.keysym.sym == SDLK_UP) {
                    if (keyboard.contains(ToLower("UP"))) {
                        keyboard.find(ToLower("UP"))->second->held = true;
                        keyboard.find(ToLower("UP"))->second->pressed = true;
                    }
                    
                }

                if (e.key.keysym.sym == SDLK_DOWN) {
                    if (keyboard.contains(ToLower("DOWN"))) {
                        keyboard.find(ToLower("DOWN"))->second->held = true;
                        keyboard.find(ToLower("DOWN"))->second->pressed = true;
                    }
                    
                }

                if (e.key.keysym.sym == SDLK_SPACE) {
                    if (keyboard.contains(ToLower("SPACE"))) {
                        keyboard.find(ToLower("SPACE"))->second->held = true;
                        keyboard.find(ToLower("SPACE"))->second->pressed = true;
                    }
                }
                // if right, then make pikachu move right
                if (e.key.keysym.sym == SDLK_RETURN) {
                    if (keyboard.contains(ToLower("RETURN"))) {
                        keyboard.find(ToLower("RETURN"))->second->held = true;
                        keyboard.find(ToLower("RETURN"))->second->pressed = true;
                    }
                    //printf("We do be pressing right");
                }
                
            }
            break;
        case SDL_KEYUP:
            // input example: if left, then make pikachu move left
            if (e.key.keysym.sym == SDLK_LEFT) {
                if (keyboard.contains(ToLower("LEFT"))) {
                    keyboard.find(ToLower("LEFT"))->second->held = false;
                }
            }
            // if right, then make pikachu move right
            if (e.key.keysym.sym == SDLK_RIGHT) {
                if (keyboard.contains(ToLower("RIGHT"))) {
                    keyboard.find(ToLower("RIGHT"))->second->held = false;
                }
            }

            if (e.key.keysym.sym == SDLK_UP) {
                if (keyboard.contains(ToLower("UP"))) {
                    keyboard.find(ToLower("UP"))->second->held = false;
                }
            }

            if (e.key.keysym.sym == SDLK_DOWN) {
                if (keyboard.contains(ToLower("DOWN"))) {
                    keyboard.find(ToLower("DOWN"))->second->held = false;
                }
            }

            if (e.key.keysym.sym == SDLK_SPACE) {
                if (keyboard.contains(ToLower("SPACE"))) {
                    keyboard.find(ToLower("SPACE"))->second->held = false;
                }
            }
            // if right, then make pikachu move right
            if (e.key.keysym.sym == SDLK_RETURN) {
                if (keyboard.contains(ToLower("RETURN"))) {
                    keyboard.find(ToLower("RETURN"))->second->held = false;
                }
                //printf("We do be pressing right");
            }
            break;
        default: ;
        }
    }
}

bool Input::GetKeyDown(std::string key) {
    if (keyboard.contains(ToLower(key))) {
        return keyboard.find(ToLower(key))->second->pressed;
    }
    else printf("Key does not exist, register it using registerKey, will return nullptr");
    return false;
}

bool Input::GetKey(std::string key) {
    if (keyboard.contains(ToLower(key))) {
        return keyboard.find(ToLower(key))->second->held;
    }
    else printf("Key does not exist, register it using registerKey, will return nullptr");
    return false;
}

std::string Input::ToLower(std::string inputString) {
    for (auto& character : inputString) {
        character = tolower(character); // NOLINT(bugprone-narrowing-conversions)
    }
    return inputString;
}
