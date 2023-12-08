#include "ComponentCreator.h"

#include <memory>

void ComponentCreator::InitializeComponent(IComponent* component) {
    
}

IComponent* ComponentCreator::CreateComponent() {
    const auto entityComponent = std::make_shared<EntityComponent>(EntityComponent("EntityComponent")).get();
    InitializeComponent(entityComponent);
    return entityComponent;
}
