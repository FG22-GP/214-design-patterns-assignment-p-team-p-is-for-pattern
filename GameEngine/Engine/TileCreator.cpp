#include "TileCreator.h"
#include "../Components/Tile.h"


void TileCreator::InitializeComponent(std::shared_ptr<IComponent> component)
{
}

std::shared_ptr<IComponent> TileCreator::CreateComponent(const std::shared_ptr<Entity>& Owner, TileType tileType, Vector2D WorldPosition) {
    auto entityComponent = std::make_shared<Tile>("TileComponent" , Owner, tileType, WorldPosition);
    InitializeComponent(entityComponent);
    return entityComponent;
}