#include "Game.h"

Game::Game(const int width, const int height, const std::string& title)
    :
    window(sf::VideoMode(width, height), title),
    board({ wndPaddingX, wndPaddingY } , width - (2*wndPaddingX), height - (2*wndPaddingY) ),
    snake({width/2, height/2}),
    fruit(board.NumOfColumns(), board.NumOfRows())
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
    GetKeyInput();
    auto dt = clock.restart().asSeconds();
    snake.Move(dt);
}

void Game::DrawFrame()
{
    board.Draw(window);
    snake.Draw(window);
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
    }
    if (vel.x != 0 || vel.y != 0)
    {
        snake.SetVelocity(vel);
    }
}

