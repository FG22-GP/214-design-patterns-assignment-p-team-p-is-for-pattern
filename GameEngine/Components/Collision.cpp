#include "Collision.h"
#include "../Level/Tileset.h"
#include "Tile.h"
#include "../Vector2D.h"
#include "../Constants/Constants.h"
#include "../Engine/Entity.h"
#include "../Grid.h"


// Collision::Collision(std::string name, float Range, const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {
//     range = Range;
//     componentName = name;
// }

Collision::Collision(std::string name, float Width, float Height, const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {
    width = Width;
    height = Height;
    componentName = name;
}


TileType Collision::CheckCollision() {
    // todo: change to correct grid, maybe pass it... and uncomment this
    for (auto element : cornerPositions) {
        const auto notNulLTile = Grid::tiles[element.GetX()][element.GetY()];
        if (notNulLTile) {
            const auto hitTileComponent = notNulLTile->GetComponent<Tile>();
            if (hitTileComponent->TileType == TILE_UNWALKABLE)
                return Grid::tiles[element.GetX()][element.GetY()]->GetComponent<Tile>()->TileType;
            if (hitTileComponent->TileType == TILE_GOAL)
                return Grid::tiles[element.GetX()][element.GetY()]->GetComponent<Tile>()->TileType;
        }
    }
    return TILE_WALKABLE;


    //Distance collision
    //super temp solution, AABB collision toward, to get hitposition and entities hit, QUERY from engine, return
    // if (Vector2D::Distance(otherCollider->position, owner->position) < 100) {
    //     printf("HIT");
    //     return TILE_GOAL;
    // }
    // return TILE_WALKABLE;

    // ========================= AA BB ==================================================================
    // std::shared_ptr<Collision> otherCollision = otherEntity->GetComponent<Collision>();
    // float xmin = owner->position.GetX() - width / 2;
    // float xmax = xmin + width;
    // float ymin = owner->position.GetY() - height / 2;
    // float ymax = ymin + height;
    // float otherxmin = otherEntity->position.GetX() - otherCollision->width / 2;
    // float otherxmax = otherxmin + otherCollision->width;
    // float otherymin = otherEntity->position.GetY() - otherCollision->height / 2;
    // float otherymax = otherymin + otherCollision->height;
    // return xmin < otherxmax &&
    //     xmax > otherxmin &&
    //     ymin < otherymax &&
    //     ymax > otherymin;
}

// int Collision::CheckTileCollision() {
//     float xmin = owner->position.GetX() - width / 2;
//     float ymin = owner->position.GetY() - height / 2;
//     TempTile* tilesPlayerIsOn;
//     tilesPlayerIsOn = Grid::GetTilesFromObject(xmin, ymin, width, height); //Get tiles player is on
//     int result = 0;
//     for (int i = 0; i < 4; i++) {
//         switch (tilesPlayerIsOn[i].tileType) {
//         case 1: // Wall
//             result = 1;
//             break;
//         case 2: // Goal
//             result = result == 1 ? 1 : 2;
//             break;
//         default: //Empty and otherwise
//             break;
//         }
//     }
//     return result;
// }

void Collision::Start() {
}

void Collision::Execute() {
    UpdateCornerPositions();
}

void Collision::Stop() {
}

std::string Collision::GetName() {
    return IComponent::GetName();
}

void Collision::InitializeComponent() {
}

void Collision::UpdateCornerPositions() {
    Vector2DInt gridPos = Grid::WorldToGridPosition(Vector2D(owner->position.GetX(), owner->position.GetY() + height));
    TopLeftCornerGridPos.SetX(gridPos.GetX());
    TopLeftCornerGridPos.SetY(gridPos.GetY());

    gridPos = Grid::WorldToGridPosition(Vector2D(owner->position.GetX() + width, owner->position.GetY() + height));
    TopRightCornerGridPos.SetX(gridPos.GetX());
    TopRightCornerGridPos.SetY(gridPos.GetY());

    gridPos = Grid::WorldToGridPosition(Vector2D(owner->position.GetX(), owner->position.GetY()));
    BottomLeftCornerGridPos.SetX(gridPos.GetX());
    BottomLeftCornerGridPos.SetY(gridPos.GetY());

    gridPos = Grid::WorldToGridPosition(Vector2D(owner->position.GetX() + width, owner->position.GetY()));
    BottomRightCornerGridPos.SetX(gridPos.GetX());
    BottomRightCornerGridPos.SetY(gridPos.GetY());

    cornerPositions[0] = TopLeftCornerGridPos;
    cornerPositions[1] = TopRightCornerGridPos;
    cornerPositions[2] = BottomLeftCornerGridPos;
    cornerPositions[3] = BottomRightCornerGridPos;
}
