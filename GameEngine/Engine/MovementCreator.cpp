#include "MovementCreator.h"
#include <memory>

#include "Entity.h"
#include "..\Components\Movement.h"

void MovementCreator::InitializeComponent(std::shared_ptr<IComponent> component)
{

}

std::shared_ptr<IComponent> MovementCreator::CreateComponent(std::shared_ptr<Entity> owner, float movementSpeed)
{
    auto entityComponent = std::make_shared<Movement>("MovementComponent",owner, movementSpeed);
    InitializeComponent(entityComponent);
    return entityComponent;
}
