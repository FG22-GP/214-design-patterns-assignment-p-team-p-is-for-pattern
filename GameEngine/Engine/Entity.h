﻿#pragma once
#include <ranges>
#include <SDL_log.h>
#include <cvt/wstring>

#include "map"
#include "vector"
#include "../Vector2D.h"
#include "../Components/IComponent.h"

/**
 * \brief Temp Mono class until the real deal
 */


class FakeMono {
protected:
    FakeMono();

public:
    virtual ~FakeMono();

    virtual void Start();
    virtual void Update();
    virtual void Stop();
};

class IComponent;

class Entity : public FakeMono, std::enable_shared_from_this<Entity> {
    std::string EntityName;

protected:
    void AddComponent(std::shared_ptr<IComponent>& component) {
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

public:
    Entity();
    explicit Entity(Vector2D start_position);
    explicit Entity(std::vector<std::shared_ptr<IComponent>> attachedComponents, Vector2D startPosition = Vector2D(0.f, 0.f));

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
            return std::static_pointer_cast<T>(component);
        }
    }
    return std::shared_ptr<T>(); 
}

class GameClass {
    // Entity GetNewEntity() {
    //     auto newEntity = Entity(std::vector({static_cast<IComponent>(EntityComponent())}), Vector2D(0.f, 0.f));
    // }
};
