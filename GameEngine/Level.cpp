#include "Level.h"

#include "Constants/Constants.h"

Level::Level() = default;

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
