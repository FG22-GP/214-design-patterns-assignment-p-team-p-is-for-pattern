#include "CollisionCreator.h"

#include "../Components/Collision.h"

void CollisionCreator::InitializeComponent(std::shared_ptr<IComponent> component)
{

}

std::shared_ptr<IComponent> CollisionCreator::CreateComponent(std::shared_ptr<Entity> owner, float width, float height) {
    auto entityComponent = std::make_shared<Collision>("CollisionComponent",width,height,owner);
    InitializeComponent(entityComponent);
    return entityComponent;
}


