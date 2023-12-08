
#include <SDL_log.h>
#include <utility>

#include "IComponent.h"

EntityComponent::EntityComponent(std::string name) {
    componentName = std::move(name);
}

void EntityComponent::Start() {
    // First Frame code
}

void EntityComponent::Execute() {
    // Component Code
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
