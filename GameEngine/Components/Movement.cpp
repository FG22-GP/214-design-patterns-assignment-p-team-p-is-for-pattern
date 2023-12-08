#include "Movement.h"


Movement::Movement(const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {}   

void Movement::Translate(Vector2D Translation) const {
    //owner->position += Translation;
}

void Movement::Start() {
}

void Movement::Execute() {
}

void Movement::Stop() {
}

std::string Movement::GetName() {
    return IComponent::GetName();
}

void Movement::InitializeComponent() {
}
