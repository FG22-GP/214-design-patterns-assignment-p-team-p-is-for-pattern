#pragma once
#include "IComponent.h"
#include "IEntity.h"
#include "Vector2D.h"
#include "vector"

/**
 * \brief Temporary fake Mono class until we implement the real deal
 */
class FakeMono {
protected:
    FakeMono();

public:
    virtual ~FakeMono();

    virtual void Start() {
    }

    virtual void Update() {
    }

    virtual void Stop() {
    }
};

class Entity : IEntity {
protected:
    void AddComponent() {
        // TODO: Add components to the Entity
    }

    void RemoveComponent() {
        // TODO: Remove components from the Entity
    }

public:
    Entity();
    explicit Entity(Vector2D start_position);

    void Start() override {
        IEntity::Start();
        for (auto component : components) {
            component.Start();
        }
    }

    void Update() override {
        IEntity::Update();
        for (auto component : components) {
            component.Execute();
        }
    }

    void Stop() override {
        IEntity::Stop();
        for (auto component : components) {
            component.Stop();
        }
    }
};
