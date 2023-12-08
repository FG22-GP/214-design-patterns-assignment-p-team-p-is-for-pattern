#pragma once
#include "../Components/IComponentFactory.h"


class ComponentCreator final : IComponentFactory {
    void InitializeComponent(IComponent* component) override;

public:
    ComponentCreator() = default;
    std::shared_ptr<IComponent> CreateComponent() override;
};
