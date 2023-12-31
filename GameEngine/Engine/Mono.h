#pragma once
#include <memory>
#include <type_traits>


#include "SystemAPI.h"


class Mono : std::enable_shared_from_this<Mono> 
{
public:
    virtual ~Mono() = default;
    std::string monoName;
    template <typename T, std::enable_if_t<std::is_base_of_v<Mono, T>, T*>>
    explicit Mono(T* Mono);
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Stop() = 0;
};

template <typename T, std::enable_if_t<std::is_base_of_v<Mono, T>, T*>>
 Mono::Mono(T* Mono) {
  //  SystemAPI::AddMono(std::make_shared<T>(Mono)); 
}
