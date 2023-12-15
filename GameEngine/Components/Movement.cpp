#include "Movement.h"

#include "../Timer.h"


Movement::Movement(std::string name, const std::shared_ptr<Entity>& Owner, float movementSpeed) : IComponent(Owner) {
    componentName = name;
    MovementSpeed = movementSpeed;
}

void Movement::Translate(Vector2D Translation) {
    auto vectorMovement = Translation * Timer::Instance()->DeltaTime() * MovementSpeed;
    owner->position += vectorMovement;
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
