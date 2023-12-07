#include "Entity.h"

#include <ranges>

// FakeMono::FakeMono() = default;
// FakeMono::~FakeMono() = default;
//
// void FakeMono::Start() {
// }
//
// void FakeMono::Update() {
// }
//
// void FakeMono::Stop() {
// }

Entity::Entity() = default;
Entity::Entity(const Vector2D start_position) { position = start_position; }

Entity::Entity(std::vector<IComponent> attachedComponents, const Vector2D startPosition) {
    position = startPosition;
    for (auto component : attachedComponents) {
        if (components.contains(component.GetName())) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "You tried adding an already existing component on this Entity!");
        }
        components.insert({component.GetName(), component});
    }
}

void Entity::Start() {
    Mono::Start();
    for (auto val : components | std::views::values) {
        val.Start();
    }
}

void Entity::Update() {
    Mono::Update();
    for (auto val : components | std::views::values) {
        val.Execute();
    }
}

void Entity::Stop() {
    Mono::Stop();
    for (auto val : components | std::views::values) {
        val.Stop();
    }
}
