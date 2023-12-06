﻿#pragma once
#include <SDL_log.h>
#include <cvt/wstring>

#include "IComponent.h"
#include "Vector2D.h"
#include "vector"
#include "map"

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

class Entity : FakeMono {
protected:
    void AddComponent(IComponent component) {
        if (components.contains(component.GetName())) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "You tried adding an already existing component!");
            return;
        }
        components.insert({component.GetName(), component});
    }

    void RemoveComponent(IComponent component) {
        if (!components.contains(component.GetName())) {
            SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "You tried removing a component that doesn't exist!");
            return;
        }
        components.erase(component.GetName());
    }

public:
    Entity();
    explicit Entity(Vector2D start_position);
    explicit Entity(std::vector<IComponent> attachedComponents, Vector2D startPosition = Vector2D(0.f, 0.f));

    Vector2D position;
    std::map<std::string, IComponent> components;

    void Start() override;
    void Update() override;
    void Stop() override;
};