#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Snake.h"
#include "Fruit.h"
#include "Text.h"
#include "Sound.h"

class Game
{
public:
    Game() = delete;
    Game(const int width, const int height, const std::string& title);

    void Go();
    void UpdateModel();
    void DrawFrame();
    void CheckForStart();

private:
    sf::RenderWindow window;
    sf::RectangleShape start;
    Board board;
    Snake snake;
    Fruit fruit;
    Text text;
    Sound sound;

    sf::Keyboard kbd;
    sf::Clock clock;
    bool gameOver = true;
    
    static constexpr int wndPaddingX = 100;
    static constexpr int wndPaddingY = 100;
};

