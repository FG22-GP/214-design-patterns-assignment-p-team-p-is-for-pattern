#pragma once
#include "IComponent.h"
#include "../Vector2DInt.h"
#include "../Level/Tileset.h"
#include <cmath>
#include "../Vector2D.h"
// enum TileType { //todo add a player enum
//     Walkable,
//     Hazard,
//     Goal
// };


class Tile final : public IComponent, std::enable_shared_from_this<Tile> {
public:
    explicit Tile(std::string name ,const std::shared_ptr<Entity>& Owner, TileType tileType, Vector2D WorldPosition) // todo: when fed need to be fed with the pixeloffsett. 
        : IComponent(Owner), TileType(tileType) {
        componentName = name;
        GridPosition.SetX(static_cast<int>(std::floor(WorldPosition.GetX() / 32))); //this correct?
        GridPosition.SetY(static_cast<int>(std::floor(WorldPosition.GetY() / 24))); //this correct?
    }

    Vector2DInt GridPosition;
    TileType TileType;
    
    void Start() override;
    void Execute() override;
    void Stop() override;
    void InitializeComponent() override;
};
