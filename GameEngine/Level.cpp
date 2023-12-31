#include "Level.h"
#include <array>
#include "Constants/Constants.h"

Level::Level(std::unique_ptr<std::array<std::array<char, TilemapX>, TilemapY>>& gridData): bGenerateLevel(false), goalTime(20.f) {
    mTime = std::make_shared<Score>();
    grid = std::make_shared<Grid>(gridData);
    levelIndex = 0;
    goalTime = grid->GetGoalTime();
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
