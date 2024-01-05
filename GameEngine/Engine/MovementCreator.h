#pragma once
#include "../Components/IComponentFactory.h"


class MovementCreator final : IComponentFactory
{
    void InitializeComponent(std::shared_ptr<IComponent> component) override;

public:
    MovementCreator() = default;
    std::shared_ptr<IComponent> CreateComponent(std::shared_ptr<Entity> owner, float movementSpeed);

    ~MovementCreator() {}
};

