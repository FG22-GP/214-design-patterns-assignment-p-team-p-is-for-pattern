#pragma once
#include "../Components/IComponentFactory.h"


class ComponentCreator final : IComponentFactory {
    ComponentCreator() = default;
    void InitializeComponent(IComponent* component) override;

public:
    IComponent* CreateComponent() override;
};
