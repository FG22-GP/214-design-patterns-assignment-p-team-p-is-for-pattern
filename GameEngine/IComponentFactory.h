#pragma once
#include "IComponent.h"

class IComponentFactory {
protected:
    IComponentFactory() = default;
    virtual ~IComponentFactory() = default;

public:
    virtual IComponent CreateComponent() = 0;
    virtual void InitializeComponent() = 0;
};
