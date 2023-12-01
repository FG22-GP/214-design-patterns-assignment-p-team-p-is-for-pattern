#pragma once
#include <map>
#include <string>


struct InputValue;

class Input {
public:
    Input();
    ~Input();

    static std::map<std::string, InputValue*> keyboard;

    void static register_keys(std::string values[], size_t size);
    void static update_input();
    bool static GetKeyDown(std::string key);
    bool static GetKey(std::string key);

private:
    static std::string ToLower(std::string inputString);
};


struct InputValue {
public:
    bool pressed;
    bool held;
};
