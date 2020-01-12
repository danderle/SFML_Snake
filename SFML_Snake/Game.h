#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Snake.h"
#include "Fruit.h"

class Game
{
public:
    Game() = delete;
    Game(const int width, const int height, const std::string& title);

    void Go();
    void UpdateModel();
    void DrawFrame();
    void GetKeyInput();

private:
    sf::RenderWindow window;
    Board board;
    Snake snake;
    Fruit fruit;
    sf::Clock clock;

    static constexpr int wndPaddingX = 100;
    static constexpr int wndPaddingY = 50;
};

