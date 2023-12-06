#include "Engine.h"


// std::map<std::string,Mono*> Engine::monos; //Added inline to header

Engine::Engine()
{
    //TODO
    monos = std::map<std::string, Mono*>();
}

void Engine::AddMono(std::string name, Mono* mono)
{
    monos[name] = mono;
}

void Engine::Start()
{
    //TODO super scuffed
    while(true)
    {
        for (auto element : monos)
        {
            element.second->Update();
        }

        //Input Calls

        //Render Calls
        
        //Audio Calls
        //Physics Calls
        //etc
    }
}
