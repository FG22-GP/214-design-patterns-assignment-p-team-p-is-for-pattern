#pragma once
#include <ranges>
#include <SDL_log.h>
#include <cvt/wstring>
#include "map"
#include "Mono.h"
#include "vector"
#include "../Vector2D.h"
#include "../Components/IComponent.h"


class ComponentCreator;


class Entity : Mono, std::enable_shared_from_this<Entity> {

public:
    void AddComponent(std::shared_ptr<IComponent> component) {
        if (components.contains(component->GetName())) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "You tried adding an already existing component!");
            return;
        }
        components.insert({std::make_pair(component->GetName(), component)});
    }

    void RemoveComponent(const std::shared_ptr<IComponent>& component) {
        if (!components.contains(component->GetName())) {
            SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "You tried removing a component that doesn't exist!");
            return;
        }
        components.erase(component->GetName());
    }

    void SetName(const std::string& name) {
        monoName = name;
    }

    Entity(std::string name);
    explicit Entity(std::string name, Vector2D startPosition);
    explicit Entity(std::string name, const std::vector<std::shared_ptr<IComponent>>& attachedComponents, Vector2D startPosition = Vector2D(0.f, 0.f));
    explicit Entity(std::string name, const std::vector<std::shared_ptr<IComponent>>& attachedComponents);

    Vector2D position;
    std::map<std::string, std::shared_ptr<IComponent>> components;
    
    bool HasComponent(const std::string& key) const;

    template<typename T, std::enable_if_t<std::is_base_of_v<IComponent, T>, int> = 0>
    std::shared_ptr<T> GetComponent();
    
    void Start() override;
    void Update() override;
    void Stop() override;
    std::string GetEntityName();
};

template <typename T, std::enable_if_t<std::is_base_of_v<IComponent, T>, int>>
std::shared_ptr<T> Entity::GetComponent() {
    for (const auto& val : components | std::views::values) {
        const auto& component = val;
        if (typeid(*component) == typeid(T)) {
            return std::static_pointer_cast<T>(component); // should probably be shared pointer
        }
    }
    return std::shared_ptr<T>(); 
}
