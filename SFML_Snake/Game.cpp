#include "Game.h"

Game::Game(const int width, const int height, const std::string& title)
    :
    window(sf::VideoMode(width, height), title),
    board({ wndPaddingX, wndPaddingY } , width - (2*wndPaddingX), height - (2*wndPaddingY) ),
    snake({ wndPaddingX + (board.NumOfColumns() / 2 * Segment::Dimensions), wndPaddingY + (board.NumOfRows() / 2 * Segment::Dimensions)}),
    fruit(board.NumOfColumns(), board.NumOfRows(), board.GetTopLeftPosition(), snake)
{}

void Game::Go()
{
    sound.PlayTitle();
    sound.PlayMusic();
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
        auto dt = clock.restart().asSeconds();
        snake.GetKeyboardInput(kbd);
        snake.CheckSelfCollision();
        board.CheckCollision(snake);
        snake.Move(dt);
        fruit.Pulse(dt);
        if (fruit.IsEaten(snake))
        {
            fruit.PlaceFruit(snake);
            snake.SetToGrow(true);
            if (snake.IncreaseFruitEaten())
                sound.PlayEat();
            score.Update(snake.GetFruitEaten());
            sound.PlayFart();
        }
    }
}

void Game::DrawFrame()
{
    board.Draw(window);
    snake.Draw(window);
    fruit.Draw(window);
    score.Draw(window);
}
