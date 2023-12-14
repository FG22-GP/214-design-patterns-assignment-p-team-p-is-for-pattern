#pragma once
#include <memory>

#include "Score.h"
#include "Vector2D.h"

class Level {
    Vector2D goalPosition;
    Vector2D startPosition;

public:
    Level();

    bool bGenerateLevel;
    void GenerateRandomLevel();
    Vector2D GetStartPosition() const;
    Vector2D GetGoalPosition() const;
    std::shared_ptr<Score> score;
};
