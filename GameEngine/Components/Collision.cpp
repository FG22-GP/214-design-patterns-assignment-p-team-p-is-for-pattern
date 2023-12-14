#include "Collision.h"
#include "../Level/Tileset.h"
#include "Tile.h"
#include "../Vector2D.h"
#include "../Constants/Constants.h"
#include "../Engine/Entity.h"


class TempTile //TODO replace with Tile class
{
public:
    // std::shared_ptr<Entity> Obstacle
    int tileType;
};

class TempGrid //TODO replace with real grid
{
public:
    static Entity tiles[32][24];
    static const int WindowSizeX = 1056, WindowSizeY = 792;


    static TempTile* GetTilesFromObject(float x, float y, float width, float height) {
        TempTile result[4];
        for (int i = 0; i < 4; i++) {
            result[i] = GetTile(x + (i % 2) * width, y + (i / 2) * height);
        }
        return result;
    }

    static TempTile GetTile(float x, float y) {
        return TempTile();
        // return TempGrid::tiles[static_cast<int>(x/WindowSizeX) * 32][static_cast<int>(y/WindowSizeY) * 24];
    }
};


// Collision::Collision(std::string name, float Range, const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {
//     range = Range;
//     componentName = name;
// }

Collision::Collision(std::string name, float Width, float Height, const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {
    width = Width;
    height = Height;
    componentName = name;
}

TileType Collision::CheckCollision() { // todo: change to correct grid, maybe pass it... and uncomment this
    for (auto element : CornorPositions) {
        // const auto HitTileComponent = TempGrid::tiles[element.GetX()][element.GetY()].GetComponent<Tile>(); 
        // if (HitTileComponent->TileType == TILE_UNWALKABLE) 
        //     return TempGrid::tiles[element.GetX()][element.GetY()].GetComponent<Tile>()->TileType;
        // if (HitTileComponent->TileType == TILE_GOAL) 
        //     return TempGrid::tiles[element.GetX()][element.GetY()].GetComponent<Tile>()->TileType;
        
    }
    return TILE_WALKABLE;

    //Distance collision
    // super temp solution, AABB collision toward, to get hitposition and entities hit, QUERY from engine, return
    // if (Vector2D::Distance(otherCollider->position, owner->position) < range) {
    //     printf("HIT");
    //     return true;
    // }
    // return false;

    // AABB collision // not being used
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


int Collision::CheckTileCollision() {
    float xmin = owner->position.GetX() - width / 2;
    float ymin = owner->position.GetY() - height / 2;
    TempTile* tilesPlayerIsOn;
    tilesPlayerIsOn = TempGrid::GetTilesFromObject(xmin, ymin, width, height); //Get tiles player is on
    int result = 0;
    for (int i = 0; i < 4; i++) {
        switch (tilesPlayerIsOn[i].tileType) {
        case 1: // Wall
            result = 1;
            break;
        case 2: // Goal
            result = result == 1 ? 1 : 2;
            break;
        default: //Empty and otherwise
            break;
        }
    }
    return result;
}


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
    TopLeftCornerGridPos.SetX(XPos2);
    TopLeftCornerGridPos.SetY(YPos2);

    float XVal3 = owner->position.GetX() - (width / 2);
    float YVal3 = owner->position.GetY() - (height / 2);
    int XPos3 = floor(XVal3 / 32);
    int YPos3 = floor(YVal3 / 24);
    TopLeftCornerGridPos.SetX(XPos3);
    TopLeftCornerGridPos.SetY(YPos3);

    float XVal4 = owner->position.GetX() + (width / 2);
    float YVal4 = owner->position.GetY() - (height / 2);
    int XPos4 = floor(XVal4 / 32);
    int YPos4 = floor(YVal4 / 24);
    TopLeftCornerGridPos.SetX(XPos4);
    TopLeftCornerGridPos.SetY(YPos4);
}
