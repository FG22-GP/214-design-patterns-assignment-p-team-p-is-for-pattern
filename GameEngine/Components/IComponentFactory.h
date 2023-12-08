#pragma once

#include "IComponent.h"

class IComponentFactory {
protected:
    IComponentFactory() = default;
    virtual ~IComponentFactory() = default;

public:
    virtual std::shared_ptr<IComponent> CreateComponent() = 0;
    virtual void InitializeComponent(IComponent* component) = 0;
};
