#pragma once
#include <map>
#include <string>


struct InputValue;

class Input {
public:
    Input();
    ~Input();

    static std::map<std::string, InputValue*> keyboard;
    /**
     * \brief Has to be put main game loop loop to register input
     */
    void static UpdateInput();
    /**
     * \brief static method for reading input
     * \param key requested key as a string, not case sensitive
     * \return return true for one frame
     */
    bool static GetKeyDown(std::string key);
    /**
     * \brief static method for reading input
     * \param key requested key as a string, not case sensitive
     * \return returns true while the button is pressed
     */
    bool static GetKey(std::string key);
    /**
     * \brief Static method to register input keys
     * \param values Array of strings to be registered
     * \param size Size of the array
     */
    void static RegisterKeys(std::string values[], size_t size);

private:
    static std::string ToLower(std::string inputString);
};


struct InputValue {
public:
    bool pressed;
    bool held;
};
