#pragma once
#include <memory>
#include "Grid.h"
#include "Score.h"
#include "Vector2D.h"
#include "Constants/Constants.h"

class Level {
    Vector2D goalPosition;
    Vector2D startPosition;

public:
    explicit Level(std::unique_ptr<std::array<std::array<char, TilemapX>, TilemapY>>& gridData);
    std::shared_ptr<Grid> grid;

    bool bGenerateLevel;
    void GenerateRandomLevel();
    Vector2D GetStartPosition() const;
    Vector2D GetGoalPosition() const;
    std::shared_ptr<Score> mTime;
    float targetTime;
    int nextLevelIndex;

};
