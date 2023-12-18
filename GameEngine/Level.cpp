#include "Level.h"
#include <array>
#include "Constants/Constants.h"

Level::Level(std::unique_ptr<std::array<std::array<char, TilemapX>, TilemapY>>& gridData): bGenerateLevel(false), targetTime(20.f) {
    mTime = std::make_shared<Score>();
    grid = std::make_shared<Grid>(gridData);
    nextLevelIndex = 0;
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
