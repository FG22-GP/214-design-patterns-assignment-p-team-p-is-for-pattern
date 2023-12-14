#include "Collision.h"

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
    static TempTile tiles[32][24];
    static const int WindowSizeX = 1056, WindowSizeY = 792;
    
    static TempTile* GetTilesFromObject(float x, float y, float width, float height)
    {
        TempTile result[4];
        for(int i = 0; i < 4; i++)
        {
            result[i] = GetTile(x + (i % 2) * width, y + (i / 2) * height);    
        }
        return result;
    }

    static TempTile GetTile(float x,float y)
    {
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

bool Collision::CheckCollision(std::shared_ptr<Entity> otherEntity)
{
    //Distance collision
    // super temp solution, AABB collision toward, to get hitposition and entities hit, QUERY from engine, return
    // if (Vector2D::Distance(otherCollider->position, owner->position) < range) {
    //     printf("HIT");
    //     return true;
    // }
    // return false;

    // AABB collision // not being used
    std::shared_ptr<Collision> otherCollision = otherEntity->GetComponent<Collision>();
    float xmin = owner->position.GetX() - width / 2;
    float xmax = xmin + width;
    float ymin = owner->position.GetY() - height / 2;
    float ymax = ymin + height;
    float otherxmin = otherEntity->position.GetX() - otherCollision->width / 2;
    float otherxmax = otherxmin + otherCollision->width;
    float otherymin = otherEntity->position.GetY() - otherCollision->height / 2;
    float otherymax = otherymin + otherCollision->height;
    return xmin < otherxmax &&
        xmax > otherxmin &&
        ymin < otherymax &&
        ymax > otherymin;
}

int Collision::CheckTileCollision()
{
    
    float xmin = owner->position.GetX() - width / 2;
    float ymin = owner->position.GetY() - height / 2;
    TempTile* tilesPlayerIsOn;
    tilesPlayerIsOn = TempGrid::GetTilesFromObject(xmin,ymin,width,height); //Get tiles player is on
    int result = 0;
        for(int i = 0; i < 4; i++)
    {
        switch (tilesPlayerIsOn[i].tileType)
        {
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
}

void Collision::Stop() {
}

std::string Collision::GetName() {
    return IComponent::GetName();
}

void Collision::InitializeComponent() {
}
