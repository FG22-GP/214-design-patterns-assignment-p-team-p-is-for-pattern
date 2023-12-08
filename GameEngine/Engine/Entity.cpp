#include "Entity.h"

#include <ranges>

Entity::Entity() { position = Vector2D(); }
Entity::Entity(const Vector2D start_position) { position = start_position; }

Entity::Entity(const std::vector<std::shared_ptr<IComponent>>& attachedComponents) {
    position = Vector2D();
    for (const auto& component : attachedComponents) {
        AddComponent(component.get());
    }
}

Entity::Entity(const std::vector<IComponent*>& attachedComponents, const Vector2D startPosition) {
    position = startPosition;
    for (const auto component : attachedComponents) {
        AddComponent(component);
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
