#include "Collision.h"

#include "../Vector2D.h"
#include "../Engine/Entity.h"

Collision::Collision(std::string name, float Range, const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {
    range = Range;
    componentName = name;
}

bool Collision::CheckCollision(std::shared_ptr<Entity> otherCollider) { // super temp solution, AABB collision toward, to get hitposition and entities hit, QUERY from engine, return
    if (Vector2D::Distance(otherCollider->position, owner->position) < range) {
        printf("HIT");
        return true;
    }
    return false;
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
