#pragma once
#include <random>
#include "Snake.h"

class Fruit
{
public:
    Fruit() = delete;
    Fruit(const int columns, const int rows, sf::Vector2f brdPos, Snake& snake);

    void PlaceFruit(Snake& snake);
    void Draw(sf::RenderWindow& wnd);
    bool IsEaten(Snake& snake);
    void Pulse(const float dt);

private:
    std::random_device rnd;
    std::mt19937 rng;
    std::uniform_int_distribution<int> xPos;
    std::uniform_int_distribution<int> yPos;

    sf::RectangleShape frt;
    sf::Vector2f brdPos;
    sf::Vector2i frtGridPos;
    int pulser = 1;
    float lastPulse = 0;
    static constexpr int maxWhite = 200;
    static constexpr float pulseTime = 0.01f;
};

