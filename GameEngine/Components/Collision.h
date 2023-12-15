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
    
    
    
    Vector2DInt BottomLeftCorner;
    Vector2DInt BottomRightCorner;
    Vector2DInt TopLeftCorner;
    Vector2DInt TopRightCorner;
    void UpdateCornerPositions();

    Vector2DInt cornerPositions[4] = {
        BottomLeftCorner,
        BottomRightCorner,
        TopLeftCorner,
        TopRightCorner
    };

    void Start() override;
    void Execute() override;
    void Stop() override;
    std::string GetName() override;
    void InitializeComponent() override;
};
