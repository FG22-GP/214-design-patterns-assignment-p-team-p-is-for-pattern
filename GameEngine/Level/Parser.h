#pragma once
#include <iostream>
#include <fstream>
#include <array>
#include "Tileset.h"
#include "../Constants/Constants.h"


class Parser
{


public :


	static void ReadFromFile(std::string fileName, std::array<std::array<TileType, TilemapX>, TilemapY>& tileMap);


	static TileType mapTileType(char toChange);

};

