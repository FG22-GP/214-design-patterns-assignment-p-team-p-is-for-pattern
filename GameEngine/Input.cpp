#include "Input.h"

#include <ranges>
#include <SDL_events.h>

Input::Input() = default;

Input::~Input() = default;

std::map<std::string, InputValue*> Input::keyboard;

void Input::RegisterKeys(std::string values[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        keyboard.insert(std::make_pair( ToLower(values[i]), new InputValue()));
    }
}

void Input::UpdateInput() {
    for (const auto val : keyboard | std::views::values) {
        val->pressed = false;
    }

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_KEYDOWN:
            {
                if (e.key.keysym.sym == SDLK_LEFT) {
                    if (keyboard.contains(ToLower("LEFT"))) {
                        keyboard.find(ToLower("LEFT"))->second->held = true;
                        keyboard.find(ToLower("LEFT"))->second->pressed = true;
                    }
                }
               
                if (e.key.keysym.sym == SDLK_RIGHT) {
                    if (keyboard.contains(ToLower("RIGHT"))) {
                        keyboard.find(ToLower("RIGHT"))->second->held = true;
                        keyboard.find(ToLower("RIGHT"))->second->pressed = true;
                    }
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
               
                if (e.key.keysym.sym == SDLK_RETURN) {
                    if (keyboard.contains(ToLower("RETURN"))) {
                        keyboard.find(ToLower("RETURN"))->second->held = true;
                        keyboard.find(ToLower("RETURN"))->second->pressed = true;
                    }
                }

                if (e.key.keysym.sym == SDLK_a) {
                    if (keyboard.contains(ToLower("A"))) {
                        keyboard.find(ToLower("A"))->second->held = true;
                        keyboard.find(ToLower("A"))->second->pressed = true;
                    }
                }
               
                if (e.key.keysym.sym == SDLK_d) {
                    if (keyboard.contains(ToLower("D"))) {
                        keyboard.find(ToLower("D"))->second->held = true;
                        keyboard.find(ToLower("D"))->second->pressed = true;
                    }
                }

                if (e.key.keysym.sym == SDLK_w) {
                    if (keyboard.contains(ToLower("W"))) {
                        keyboard.find(ToLower("W"))->second->held = true;
                        keyboard.find(ToLower("W"))->second->pressed = true;
                    }
                }

                if (e.key.keysym.sym == SDLK_s) {
                    if (keyboard.contains(ToLower("S"))) {
                        keyboard.find(ToLower("S"))->second->held = true;
                        keyboard.find(ToLower("S"))->second->pressed = true;
                    }
                }

                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    if (keyboard.contains(ToLower("ESCAPE"))) {
                        keyboard.find(ToLower("ESCAPE"))->second->held = true;
                        keyboard.find(ToLower("ESCAPE"))->second->pressed = true;
                    }
                }
            }
            break;
        case SDL_KEYUP:
            if (e.key.keysym.sym == SDLK_LEFT) {
                if (keyboard.contains(ToLower("LEFT"))) {
                    keyboard.find(ToLower("LEFT"))->second->held = false;
                }
            }
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
            if (e.key.keysym.sym == SDLK_RETURN) {
                if (keyboard.contains(ToLower("RETURN"))) {
                    keyboard.find(ToLower("RETURN"))->second->held = false;
                }
            }

            if (e.key.keysym.sym == SDLK_a) {
                if (keyboard.contains(ToLower("A"))) {
                    keyboard.find(ToLower("A"))->second->held = false;
                }
            }
               
            if (e.key.keysym.sym == SDLK_d) {
                if (keyboard.contains(ToLower("D"))) {
                    keyboard.find(ToLower("D"))->second->held = false;
                }
            }

            if (e.key.keysym.sym == SDLK_w) {
                if (keyboard.contains(ToLower("W"))) {
                    keyboard.find(ToLower("W"))->second->held = false;
                }
            }

            if (e.key.keysym.sym == SDLK_s) {
                if (keyboard.contains(ToLower("S"))) {
                    keyboard.find(ToLower("S"))->second->held = false;
                }
            }
            break;
        default: ;
        }
    }
}

bool Input::GetKeyDown(std::string key) {
    if (keyboard.contains(ToLower(key))) return keyboard.find(ToLower(key))->second->pressed;
    printf("Key is not registered, register it using registerKey, will return nullptr");
    return false;
}

bool Input::GetKey(std::string key) {
    if (keyboard.contains(ToLower(key))) return keyboard.find(ToLower(key))->second->held;
    printf("Key is not registered, register it using registerKey, will return nullptr");
    return false;
}

std::string Input::ToLower(std::string inputString) {
    for (auto& character : inputString) {
        character = tolower(character); // NOLINT(bugprone-narrowing-conversions)
    }
    return inputString;
}
