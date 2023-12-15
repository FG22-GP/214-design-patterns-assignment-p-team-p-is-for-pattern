#pragma once
#include <iostream>
#include <fstream>
#include <array>
#include "../Components/Tile.h"
#include "../Constants/Constants.h"


class Parser
{


public :


	static void ReadFromFile(std::array<std::array<std::array<char, 32>, 24>, 7>& tileMaps);


	static TileType mapTileType(char toChange);

};

