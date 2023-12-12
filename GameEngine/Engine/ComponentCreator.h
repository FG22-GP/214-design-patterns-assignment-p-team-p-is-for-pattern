#pragma once
#include "../Components/IComponentFactory.h"


class ComponentCreator final : IComponentFactory {
    void InitializeComponent(std::shared_ptr<IComponent> component) override;

public:
    ComponentCreator() = default;
    std::shared_ptr<IComponent> CreateComponent(std::shared_ptr<Entity> owner) override;
};
