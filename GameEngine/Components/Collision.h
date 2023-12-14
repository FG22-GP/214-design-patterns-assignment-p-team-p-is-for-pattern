#pragma once
#include "IComponent.h"
#include "../Vector2DInt.h"
#include "../Level/Tileset.h"

class Collision final : public IComponent, std::enable_shared_from_this<Collision> {
public:
    // explicit Collision(std::string name, float Range, const std::shared_ptr<Entity>& Owner);
    explicit Collision(std::string name, float Width, float Height, const std::shared_ptr<Entity>& Owner);
    TileType CheckCollision();

    // int CheckTileCollision(); // Udit <3
    // float range;
    float width;
    float height;
    
    
    
    std::shared_ptr<Vector2DInt> TopLeftCornerGridPos;
    std::shared_ptr<Vector2DInt> TopRightCornerGridPos;
    std::shared_ptr<Vector2DInt> BottomLeftCornerGridPos;
    std::shared_ptr<Vector2DInt> BottomRightCornerGridPos;
    void UpdateCornerPositions();

    std::shared_ptr<Vector2DInt> CornerPositions[4] = {
        TopLeftCornerGridPos,
        TopRightCornerGridPos,
        BottomLeftCornerGridPos,
        BottomRightCornerGridPos
    };

    void Start() override;
    void Execute() override;
    void Stop() override;
    std::string GetName() override;
    void InitializeComponent() override;
};
