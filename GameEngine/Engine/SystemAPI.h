#pragma once
#include <map>
#include <memory>
#include <string>
#include <type_traits>

class Mono;

class SystemAPI {
    static inline std::map<std::string, std::shared_ptr<Mono>> mMonoLookup;
public:
    static std::shared_ptr<Mono> FindMono(const std::string& name);
};

inline std::shared_ptr<Mono> SystemAPI::FindMono(const std::string& name) {
    return mMonoLookup[name];
}
