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
    float XVal1 = owner->position.GetX() - (width / 2);
    float YVal1 = owner->position.GetY() + (height / 2);
    int XPos1 = floor(XVal1 / 32);
    int YPos1 = floor(YVal1 / 24);
    TopLeftCornerGridPos.SetX(XPos1);
    TopLeftCornerGridPos.SetY(YPos1);

    float XVal2 = owner->position.GetX() + (width / 2);
    float YVal2 = owner->position.GetY() + (height / 2);
    int XPos2 = floor(XVal2 / 32);
    int YPos2 = floor(YVal2 / 24);
    TopRightCornerGridPos.SetX(XPos2);
    TopRightCornerGridPos.SetY(YPos2);

    float XVal3 = owner->position.GetX() - (width / 2);
    float YVal3 = owner->position.GetY() - (height / 2);
    int XPos3 = floor(XVal3 / 32);
    int YPos3 = floor(YVal3 / 24);
    BottomLeftCornerGridPos.SetX(XPos3);
    BottomLeftCornerGridPos.SetY(YPos3);

    float XVal4 = owner->position.GetX() + (width / 2);
    float YVal4 = owner->position.GetY() - (height / 2);
    int XPos4 = floor(XVal4 / 32);
    int YPos4 = floor(YVal4 / 24);
    BottomRightCornerGridPos.SetX(XPos4);
    BottomRightCornerGridPos.SetY(YPos4);

    cornerPositions[0] = TopLeftCornerGridPos;
    cornerPositions[1] = TopRightCornerGridPos;
    cornerPositions[2] = BottomLeftCornerGridPos;
    cornerPositions[3] = BottomRightCornerGridPos;
}
