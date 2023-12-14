#pragma once
#include <memory>
#include "../Engine/Entity.h"
#include "../Vector2D.h"

typedef enum 
{
	TILE_WALKABLE   = 0x00000000,   // WalkableTile
	TILE_UNWALKABLE = 0x00000001,	// Unwalkable Tile
	TILE_PLAYER     = 0x00000002,	// Player Tile
	TILE_GOAL       = 0x00000003,   // Goal Tile
	TILE_PLAYERSTART = 0x00000004
}TileType;



struct Tileset
{
	Vector2D tilePos;
	TileType tileType;
};