#include "Parser.h"

void Parser::ReadFromFile(std::string fileName, std::array<std::array<TileType, TilemapX>, TilemapY> &tileMap)
{
	std::string openFile = "TileMaps/" + fileName + ".txt";
	std::ifstream level(openFile);
	if (!level.is_open())
	{
		printf("Error opening the level file");
		return;
	}
	size_t j = 0;
	size_t i = 0;
	while(j<TilemapY)
	{
		std::string line;
		level >> line;
		for (auto c : line)
		{
			TileType toMap = Parser::mapTileType(c);
			tileMap.at(j).at(i) = toMap;
			i++;
		}
		i = 0;
		j++;
	}
}

TileType Parser::mapTileType(char toChange)
{
	switch (toChange)
	{
	case 'x':
		return TileType::TILE_UNWALKABLE;
		break;
	case 'o':
		return TileType::TILE_WALKABLE;
		break;
	case 'p':
		return TileType::TILE_PLAYER;
		break;
	case 'g':
		return TileType::TILE_GOAL;
		break;
	default:
		return TileType::TILE_UNWALKABLE;
		break;
	}
}
