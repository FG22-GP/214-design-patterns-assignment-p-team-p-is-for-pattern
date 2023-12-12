#include "ComponentCreator.h"

#include <memory>

#include "Entity.h"
#include "../Components/ExampleEntityComponent.h"

void ComponentCreator::InitializeComponent(std::shared_ptr<IComponent> component) {
    
}

std::shared_ptr<IComponent> ComponentCreator::CreateComponent(std::shared_ptr<Entity> owner) {
    auto entityComponent = std::make_shared<EntityComponent>("ExampleComponent", owner);
    InitializeComponent(entityComponent);
    return entityComponent;
}
