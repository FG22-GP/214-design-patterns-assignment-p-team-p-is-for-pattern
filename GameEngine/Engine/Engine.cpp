#include "Engine.h"


// std::map<std::string,Mono*> Engine::monos; //Added inline to header

Engine::Engine()
{
    //TODO
    monos = std::map<std::string, std::shared_ptr<Mono>>();
}

void Engine::AddMono(std::string name, std::shared_ptr<Mono> mono)
{
    monos[name] = mono;
}

void Engine::Start()
{
    //TODO super scuffed, why is there a while always true loop here, this supposed to be a startcall from game.cpp?
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
