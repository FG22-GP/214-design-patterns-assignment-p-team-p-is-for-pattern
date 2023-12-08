#include "IComponent.h"

IComponent::IComponent() = default;
IComponent::~IComponent() = default;

std::string IComponent::GetName() {
    return componentName;
}
