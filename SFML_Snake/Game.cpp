#include "Game.h"

Game::Game(const int width, const int height, const std::string& title)
    :
    window(sf::VideoMode(width, height), title),
    board({ wndPaddingX, wndPaddingY } , width - (2*wndPaddingX), height - (2*wndPaddingY) ),
    snake({ width/2, height/2}),
    fruit(board.NumOfColumns(), board.NumOfRows(), board.GetTopLeftPosition(), snake)
{}

void Game::Go()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        UpdateModel();
        DrawFrame();
        window.display();
    }
}

void Game::UpdateModel()
{
    if (!snake.IsDead())
    {
        GetKeyInput();
        auto dt = clock.restart().asSeconds();
        snake.Move(dt);
        snake.CheckSelfCollision();
        board.CheckCollision(snake.GetPosition());
        fruit.Pulse(dt);
        if (fruit.IsEaten(snake))
        {
            fruit.PlaceFruit(snake);
            snake.SetToGrow(true);
            snake.IncreaseFruitEaten();
        }
    }
}

void Game::DrawFrame()
{
    board.Draw(window);
    snake.Draw(window);
    fruit.Draw(window);
}


void Game::GetKeyInput()
{
    sf::Vector2f vel(0, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        vel.x = -1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vel.x = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        vel.y = -1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        vel.y = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        vel.y = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        snake.SetToGrow(true);
        snake.IncreaseFruitEaten();
    }
    if (vel.x != 0 || vel.y != 0)
    {
        snake.SetVelocity(vel);
    }
}

