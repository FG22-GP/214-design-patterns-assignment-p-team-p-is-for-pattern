#pragma once
#include <array>
#include <memory>
#include <sstream>

#include "Vector2DInt.h"
#include "Components/Tile.h"
#include "Engine/Entity.h"
#include "Engine/RenderCreator.h"
#include "Engine/TileCreator.h"

class TempTile;

class Grid {
    // new grid, 
    float goalTime;

public:
    static inline std::shared_ptr<Entity> tiles[32][24];
    static constexpr int WindowSizeX = 1056, WindowSizeY = 792;
    std::map<std::string, std::shared_ptr<Entity>> entitiesLookup;

    explicit Grid(std::unique_ptr<std::array<std::array<char, 32>, 24>>& gridData) {
        Vector2D StartPos;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 24; j++) {
                tiles[i][j] = nullptr;
            }
        }

        entitiesLookup.clear();
        std::stringstream ss;
        std::string goalParsed;
        for (int y = 0; y < gridData->size(); y++) {
            for (int x = 0; x < gridData->data()[y].size(); x++) {
                auto entity = std::make_shared<Entity>("", Vector2D(x * 32 + x, y * 32 + y));
                auto c = gridData->data()[y][x];
                switch (c) {
                case 'x':
                    entity->SetName("UnwalkableTile:" + std::to_string(x) + std::to_string(y));
                    entity->AddComponent(TileCreator().CreateComponent(entity, TILE_UNWALKABLE, Vector2DInt(x, y)));
                    entity->AddComponent(RenderCreator().CreateComponent(entity, Vector2D(32, 32), "NonWalkableTile"));
                    break;
                case 'o':
                    entity->SetName("Walkable:" + std::to_string(x) + std::to_string(y));
                    entity->AddComponent(TileCreator().CreateComponent(entity, TILE_WALKABLE, Vector2DInt(x, y)));
                    break;
                case 'g':
                    entity->SetName("GoalTile");
                    entity->AddComponent(TileCreator().CreateComponent(entity, TILE_GOAL, Vector2DInt(x, y)));
                    entity->AddComponent(RenderCreator().CreateComponent(entity, Vector2D(32, 32), "Goal"));
                    break;
                case 'p':
                    entity->SetName("PlayerStartTile");
                    entity->AddComponent(TileCreator().CreateComponent(entity, TILE_PLAYERSTART, Vector2DInt(x, y)));
                    break;
                default:
                    if (goalParsed.empty()) {
                        ss << gridData->data()[y][x] << gridData->data()[y][x + 1];
                        goalParsed = ss.str();
                        goalTime = std::stof(goalParsed);
                    }
                    entity->SetName("Walkable:" + std::to_string(x) + std::to_string(y));
                    entity->AddComponent(TileCreator().CreateComponent(entity, TILE_WALKABLE, Vector2DInt(x, y)));
                    break;
                }

                entitiesLookup.insert(std::make_pair(entity->GetEntityName(), entity));
                tiles[x][y] = entity;
            }
        }
    }

    float GetGoalTime() const {
        return goalTime;
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
        const int xValue = static_cast<int>(floor(position.GetX() / 33));
        const int yValue = static_cast<int>(floor(position.GetY() / 33));
        return {xValue, yValue};
    }

    static Vector2D GridToWorldPosition(Vector2DInt gridPosition) {
        return Vector2D(gridPosition.GetX() * 33, gridPosition.GetY() * 33);
    }
};
