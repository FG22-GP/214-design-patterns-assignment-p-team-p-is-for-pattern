#pragma once
#include <SDL_log.h>
#include <cvt/wstring>

#include "ComponentCreator.h"
#include "map"
#include "Mono.h"
#include "vector"
#include "../Vector2D.h"
#include "../Components/IComponent.h"


class ComponentCreator;

class Entity : Mono {
    std::string EntityName;

public:
    void AddComponent(IComponent* component) {
        if (components.contains(component->GetName())) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "You tried adding an already existing component!");
            return;
        }
        components.insert({component->GetName(), component});
    }

    void RemoveComponent(IComponent* component) {
        if (!components.contains(component->GetName())) {
            SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "You tried removing a component that doesn't exist!");
            return;
        }
        components.erase(component->GetName());
    }

    Entity();
    explicit Entity(Vector2D start_position);
    explicit Entity(const std::vector<std::shared_ptr<IComponent>>& attachedComponents);
    explicit Entity(const std::vector<IComponent*>& attachedComponents, Vector2D startPosition = Vector2D(0.f, 0.f));

    Vector2D position;
    std::map<std::string, IComponent*> components;

    void Start() override;
    void Update() override;
    void Stop() override;
    std::string GetEntityName();
};

class GameClass {
public:
    /**
     * \brief Don't use unless you want crash smile
     * \return Should return a functional Entity but doesn't rn ;-;
     */
    static std::shared_ptr<Entity> GetNewEntity() {
        auto newEntity = Entity();
        auto componentCreator = ComponentCreator();
        newEntity.AddComponent(componentCreator.CreateComponent());
        SDL_Log("New entity Added with ExampleComponent on it!");
        return std::make_shared<Entity>(newEntity);
    }
};
