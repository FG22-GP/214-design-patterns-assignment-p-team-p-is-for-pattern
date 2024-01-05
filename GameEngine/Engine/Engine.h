#pragma once


#include <map>
#include <string>
#include <memory>
#include "Mono.h"



struct Engine
{
    Engine();
    
    static inline std::map<std::string, std::shared_ptr<Mono>> monos;

    static void AddMono(std::string name, std::shared_ptr<Mono> mono); //todo: now in states?

    void Start();
    // template<typename T>
    // static std::queue<T> GetAllofType<T>();
};
