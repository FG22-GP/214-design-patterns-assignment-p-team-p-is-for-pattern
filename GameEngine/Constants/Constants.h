#pragma once
#include <random>
#include "..\Vector2D.h"

constexpr int WindowSizeX = 1056;
constexpr int WindowSizeY = 792;

constexpr int TilemapX = 32;
constexpr int TilemapY = 24;

constexpr int FrameRate = 144;

static bool IsOnScreen(Vector2D value)
{
    return value.GetX() > 0 && value.GetX() < WindowSizeX && value.GetY() > 0 && value.GetY() < WindowSizeY;
}

/**
 * \brief Returns a random position on the screen
 * \return 2D position with random values for x and y
 */
static Vector2D GenerateRandomPosition()
{
    constexpr int xRangeFrom = 0;
    constexpr int xRangeTo = WindowSizeX;
    constexpr int yRangeFrom = 0;
    constexpr int yRangeTo = WindowSizeY;
    std::mt19937 generator(std::_Random_device());
    std::uniform_int_distribution xDistribution(xRangeFrom, xRangeTo - 75);
    std::uniform_int_distribution yDistribution(yRangeFrom, yRangeTo - 75);
    return Vector2D(xDistribution(generator), yDistribution(generator));
}
