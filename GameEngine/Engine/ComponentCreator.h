#pragma once
#include "../Components/IComponentFactory.h"


class ComponentCreator final : IComponentFactory {
    void InitializeComponent(IComponent* component) override;

public:
    ComponentCreator() = default;
    IComponent* CreateComponent() override;
};
