#pragma once
#include <memory>

#include "Entity.h"

class IComponent;

class CollisionCreator final : IComponentFactory
{
    void InitializeComponent(std::shared_ptr<IComponent> component) override;

public:
    CollisionCreator() = default;
    std::shared_ptr<IComponent> CreateComponent(std::shared_ptr<Entity> owner, float Range);

    ~CollisionCreator() {}
};

