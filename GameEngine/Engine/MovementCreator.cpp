#include "MovementCreator.h"
#include <memory>

#include "Entity.h"
#include "..\Components\Movement.h"

void MovementCreator::InitializeComponent(std::shared_ptr<IComponent> component)
{

}

std::shared_ptr<IComponent> MovementCreator::CreateComponent(std::shared_ptr<Entity> owner)
{
    auto entityComponent = std::make_shared<Movement>("MovementComponent",owner);
    InitializeComponent(entityComponent);
    return entityComponent;
}
