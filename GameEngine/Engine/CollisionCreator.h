#pragma once
#include <memory>
#include "..\Components/IComponentFactory.h"
#include "Entity.h"

class IComponent;

class CollisionCreator final : IComponentFactory
{
    void InitializeComponent(std::shared_ptr<IComponent> component) override;

public:
    CollisionCreator() = default;
    virtual std::shared_ptr<IComponent> CreateComponent(std::shared_ptr<Entity>& owner, float width, float height);

    ~CollisionCreator() {}
};

