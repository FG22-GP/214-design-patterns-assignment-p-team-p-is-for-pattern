#include "Entity.h"

#include <ranges>

FakeMono::FakeMono() = default;
FakeMono::~FakeMono() = default;

void FakeMono::Start() {
}

void FakeMono::Update() {
}

void FakeMono::Stop() {
}

Entity::Entity() = default; // always have to take a state(owningState)
Entity::Entity(const Vector2D start_position) { position = start_position; }

Entity::Entity(std::vector<std::shared_ptr<IComponent>> attachedComponents, Vector2D startPosition) {
    position = startPosition;
    for (auto component : attachedComponents) {
        if (components.contains(component->GetName())) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "You tried adding an already existing component on this Entity!");
        }
        components.insert({component->GetName(), component});
    }
}


bool Entity::HasComponent(const std::string& key) const {
    return components.contains(key);
}



void Entity::Start() {
    FakeMono::Start();
    for (const auto val : components | std::views::values) {
        val->Start();
    }
}

void Entity::Update() {
    FakeMono::Update();
    for (const auto val : components | std::views::values) {
        val->Execute();
    }
}

void Entity::Stop() {
    FakeMono::Stop();
    for (const auto val : components | std::views::values) {
        val->Stop();
    }
}

std::string Entity::GetEntityName() {
    return EntityName;
}
