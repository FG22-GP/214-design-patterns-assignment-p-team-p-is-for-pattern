#pragma once
#include <map>
#include <memory>
#include <string>
#include "Mono.h"


//todo: circular dependency

class SystemAPI {
    //static std::map<std::string, Mono*> mMonoLookup;

public:
    SystemAPI() = default;
    ~SystemAPI() = default;
    // static Mono* FindMono(const std::string& name) {
    //     return mMonoLookup[name];
    // }

    // static void AddMono(Mono* mono) {
    //     if (!mMonoLookup.contains(mono->monoName)) {
    //         mMonoLookup.insert({mono->monoName, mono});
    //     }
    // }
    
};
