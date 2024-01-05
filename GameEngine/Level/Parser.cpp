#include "Parser.h"

void Parser::ReadFromFile(std::array<std::array<std::array<char, 32>, 24>, 7>& tileMaps) {
    for (int i = 0; i < 7; i++) {
        std::string openFile = "TileMaps/Level" + std::to_string(i + 1) + ".txt";
        std::ifstream level(openFile);
        if (!level.is_open()) {
            printf("Error opening the level file");
            return;
        }
        size_t j = 0;
        size_t k = 0;
        while (j < TilemapY) {
            std::string line;
            level >> line;
            for (const auto c : line) {
                // TileType toMap = Parser::mapTileType(c);
                tileMaps[i].at(j).at(k) = c;
                k++;
            }
            k = 0;
            j++;
        }

        level.close();
    }
}

TileType Parser::mapTileType(char toChange) {
    switch (toChange) {
    case 'x':
        return TILE_UNWALKABLE;
    case 'o':
        return TILE_WALKABLE;
    case 'p':
        return TILE_PLAYERSTART; //TODO ADD A PLAYER Type
    case 'g':
        return TILE_GOAL;
    default:
        return TILE_WALKABLE;
    }
}
