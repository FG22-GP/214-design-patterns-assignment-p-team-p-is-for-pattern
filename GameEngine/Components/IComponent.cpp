#include "IComponent.h"


IComponent::IComponent(const std::shared_ptr<Entity>& Owner) {
    owner = Owner;
}



std::string IComponent::GetName() {
    return componentName;
}
