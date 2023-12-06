#pragma once


#include <map>
#include <queue>
#include <string>

#include "Mono.h"



struct Engine
{
    Engine();
    
    static inline std::map<std::string,Mono*> monos;

    static void AddMono(std::string name, Mono* mono);

    void Start();
    // template<typename T>
    // static std::queue<T> GetAllofType<T>();
};
