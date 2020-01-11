#pragma once
#include <random>

class Fruit
{
public:
    Fruit() = delete;
    Fruit(const int columns, const int rows);

private:
    std::random_device rnd;
    std::mt19937 rng;
    std::uniform_int_distribution<int> xPos;
    std::uniform_int_distribution<int> yPos;
};

