
#include <SDL_log.h>
#include <utility>

#include "ExampleEntityComponent.h"
#include "IComponent.h"

EntityComponent::EntityComponent(std::string name) {
    componentName = std::move(name);
}

void EntityComponent::Start() {
    // First Frame logic
}

void EntityComponent::Execute() {
    // Component Update loop logic
}

void EntityComponent::Stop() {
    // Last frame logic
}

void EntityComponent::InitializeComponent() {
    SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "Entity Component Initialized!");
}

std::string EntityComponent::GetName() {
    return IComponent::GetName();
}
