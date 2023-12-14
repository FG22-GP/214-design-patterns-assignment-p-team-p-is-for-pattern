#pragma once
#include <array>
#include <memory>

#include "Vector2DInt.h"
#include "Engine/Entity.h"
#include "Engine/TileCreator.h"
#include "Components/Tile.h"
#include "Engine/RenderCreator.h"

class TempTile;

class Grid {
public:
    static inline std::shared_ptr<Entity> tiles[32][24];
    static const int WindowSizeX = 1056, WindowSizeY = 792;
    std::vector<std::shared_ptr<Entity>> entities;

    
    explicit Grid(std::array<std::array<char, 32>, 24>& gridData) {

        // for (int i = 0; i < 32; i++) {
        //     for (int j = 0; j < 24; j++) {
        //         auto entity = std::make_shared<Entity>("Tile", Vector2D(i * 32 + i, j * 32 + j));
        //         tiles[i][j] = entity;
        //         entity->AddComponent(TileCreator().CreateComponent(entity, TILE_WALKABLE, Vector2DInt(i, j)));
        //         entity->AddComponent(RenderCreator().CreateComponent(entity, Vector2D(32, 32), "NonWalkableTile"));
        //         entities.push_back(entity);
        //     }
        // }
        
  
        for (int y = 0; y < gridData.size(); y++) {
            for (int x = 0; x < gridData[y].size(); x++) {
                std::shared_ptr<Entity> entity = std::make_shared<Entity>("", Vector2D(x * 32 + x, y* 32 + y));
                auto c = gridData[y][x];
                switch (c) {
                case 'x':
                    entity->SetName("UnwalkableTile");
                    entity->AddComponent(TileCreator().CreateComponent(entity, TILE_UNWALKABLE, Vector2DInt(x, y)));
                    entity->AddComponent(RenderCreator().CreateComponent(entity, Vector2D(32, 32), "NonWalkableTile"));
                    break;
                case 'o':
                    entity->SetName("WalkableTile");
                    entity->AddComponent(TileCreator().CreateComponent(entity, TILE_WALKABLE, Vector2DInt(x, y)));
                    break;
                case 'g':
                    entity->SetName("GoalTile");
                    entity->AddComponent(TileCreator().CreateComponent(entity, TILE_GOAL, Vector2DInt(x, y)));
                    entity->AddComponent(RenderCreator().CreateComponent(entity, Vector2D(32,32), "Goal"));
                    break;
                case 'u':
                    entity->SetName("PlayerStartTile");
                    entity->AddComponent(TileCreator().CreateComponent(entity, TILE_PLAYERSTART, Vector2DInt(x, y)));
                    break;
                default:
                    break;
                }
                entities.push_back(entity);
             
            }
          
        }
    }

    static std::shared_ptr<Tile> GetTile(Vector2DInt gridPosition) {
        return tiles[gridPosition.GetX()][gridPosition.GetY()]->GetComponent<Tile>();
    }

    static void SetTile(TileType tileType, Vector2D position) {
        auto gridPos = WorldToGridPosition(position);
        tiles[gridPos.GetX()][gridPos.GetY()]->GetComponent<Tile>()->TileType = tileType;
    }

    static void SetTile(TileType tileType, Vector2DInt position) {
        tiles[position.GetX()][position.GetY()]->GetComponent<Tile>()->TileType = tileType;
    }

    static Vector2DInt WorldToGridPosition(Vector2D position) {
        const int xValue = static_cast<int>(floor(position.GetX() / 32));
        const int yValue = static_cast<int>(floor(position.GetY() / 24));
        return {xValue, yValue};
    }

    static Vector2D GridToWorldPosition(Vector2DInt gridPosition) {
        return Vector2D(gridPosition.GetX() * 32, gridPosition.GetY() * 24);
    }
};
