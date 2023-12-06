#include "IComponent.h"

IComponent::IComponent() = default;
IComponent::~IComponent() = default;

void IComponent::Start() {
}

void IComponent::Execute() {
}

void IComponent::Stop() {
}

void EntityComponent::Start() {
    IComponent::Start();
}

void EntityComponent::Execute() {
    // Component Code
}

void EntityComponent::Stop() {
    IComponent::Stop();
}
