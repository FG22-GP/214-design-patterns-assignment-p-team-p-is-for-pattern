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
		return TileType::Hazard;
		break;
	case 'o':
		return TileType::Walkable;
		break;
	case 'p':
		return TileType::Hazard; //TODO ADD A PLAYER Type
		break;
	case 'g':
		return TileType::Goal;
		break;
	default:
		return TileType::Hazard;
		break;
	}
}
