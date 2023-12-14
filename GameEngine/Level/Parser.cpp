#include "Parser.h"

void Parser::ReadFromFile(std::string fileName, std::array<std::array<char, TilemapX>, TilemapY> &tileMap)
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
		for (const auto c : line)
		{
			// TileType toMap = Parser::mapTileType(c);
			tileMap.at(j).at(i) = c;
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
		return TILE_UNWALKABLE;
		break;
	case 'o':
		return TILE_WALKABLE;
		break;
	case 'p':
		return TILE_PLAYERSTART; //TODO ADD A PLAYER Type
		break;
	case 'g':
		return TILE_GOAL;
		break;
	default:
		return TILE_WALKABLE;
		break;
	}
}
