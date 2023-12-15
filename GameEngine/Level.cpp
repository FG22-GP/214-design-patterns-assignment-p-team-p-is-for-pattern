#include "Level.h"

#include <array>

#include "Constants/Constants.h"

Level::Level(std::array<std::array<char, TilemapX>, TilemapY> gridData): bGenerateLevel(false) {
    mTime = std::make_shared<Score>();
    grid = std::make_shared<Grid>(gridData);
}

void Level::GenerateRandomLevel() {
    startPosition = GenerateRandomPosition();
    goalPosition = GenerateRandomPosition();
}

Vector2D Level::GetStartPosition() const {
    return startPosition;
}

Vector2D Level::GetGoalPosition() const {
    return goalPosition;
}
