#include "Collision.h"

Collision::Collision(std::string name, const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {
    componentName = name;
}

void Collision::Start() {
}

void Collision::Execute() {
}

void Collision::Stop() {
}

std::string Collision::GetName() {
    return IComponent::GetName();
}

void Collision::InitializeComponent() {
}
