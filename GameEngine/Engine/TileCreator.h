#pragma once
#include <memory>

#include "CollisionCreator.h"
#include "../Components/Tile.h"

class TileCreator final : IComponentFactory {
public:
    void InitializeComponent(std::shared_ptr<IComponent> component) override;

public:
    TileCreator() = default;
    std::shared_ptr<IComponent> CreateComponent(const std::shared_ptr<Entity>& Owner, TileType tileType, Vector2DInt gridPosition);
};
