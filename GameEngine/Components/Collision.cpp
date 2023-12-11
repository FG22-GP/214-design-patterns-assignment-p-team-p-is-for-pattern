#include "Collision.h"

Collision::Collision(const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {
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
