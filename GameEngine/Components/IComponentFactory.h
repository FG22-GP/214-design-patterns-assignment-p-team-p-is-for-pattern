#pragma once

#include "IComponent.h"

class IComponentFactory {
protected:
    IComponentFactory() = default;
    virtual ~IComponentFactory() = default;

public:
    virtual std::shared_ptr<IComponent> CreateComponent(std::shared_ptr<Entity> owner) { return nullptr; }
    virtual void InitializeComponent(std::shared_ptr<IComponent> component) = 0;
};
