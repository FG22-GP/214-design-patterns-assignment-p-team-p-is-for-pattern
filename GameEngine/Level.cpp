#include "Level.h"

#include "Constants/Constants.h"

Level::Level(): bGenerateLevel(false) {
    score = std::make_shared<Score>(Score());
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
