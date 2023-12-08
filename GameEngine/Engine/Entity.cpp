#include "Entity.h"

#include <ranges>

Entity::Entity() = default;
Entity::Entity(const Vector2D start_position) { position = start_position; }

Entity::Entity(const std::vector<IComponent*>& attachedComponents, const Vector2D startPosition) {
    position = startPosition;
    for (auto component : attachedComponents) {
        if (components.contains(component->GetName())) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "You tried adding an already existing component on this Entity!");
        }
        components.insert({component->GetName(), component});
    }
}

void Entity::Start() {
    for (const auto val : components | std::views::values) {
        val->Start();
    }
}

void Entity::Update() {
    for (const auto val : components | std::views::values) {
        val->Execute();
    }
}

void Entity::Stop() {
    for (const auto val : components | std::views::values) {
        val->Stop();
    }
}

std::string Entity::GetEntityName() {
    return EntityName;
}
