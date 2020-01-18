#include "Game.h"

Game::Game(const int width, const int height, const std::string& title)
    :
    window(sf::VideoMode(width, height), title),
    start({ 200,100 }),
    board({ wndPaddingX, wndPaddingY } , width - (2*wndPaddingX), height - (2*wndPaddingY) ),
    snake({ wndPaddingX + (board.NumOfColumns() / 2 * Segment::Dimensions), wndPaddingY + (board.NumOfRows() / 2 * Segment::Dimensions)}),
    fruit(board.NumOfColumns(), board.NumOfRows(), board.GetTopLeftPosition(), snake)
{
    start.setPosition({(float)width / 2 - 100, (float)height / 2 - 200});
    start.setFillColor(sf::Color::Green);
    text.SetPressToPlay(start.getPosition(), start.getGlobalBounds().width, start.getGlobalBounds().height);
}

void Game::Go()
{
    sound.PlayTitle();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if (!gameOver)
            UpdateModel();
        else
            CheckForStart();
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
            text.UpdateScore(snake.GetFruitEaten());
            sound.PlayFart();
        }
        gameOver = snake.IsDead();
    }
}

void Game::DrawFrame()
{
    board.Draw(window);
    snake.Draw(window);
    fruit.Draw(window);
    text.DrawScore(window);
    if (gameOver)
    {
        window.draw(start);
        text.DrawPressToPlay(window);
        sound.StopMusic();
        if (snake.IsDead())
        {
            
        }
    }
}

void Game::CheckForStart()
{
    sf::Vector2f vel(0, 0);
    if (kbd.isKeyPressed(sf::Keyboard::Left))
    {
        vel.x = -1;
    }
    else if (kbd.isKeyPressed(sf::Keyboard::Right))
    {
        vel.x = 1;
    }
    else if (kbd.isKeyPressed(sf::Keyboard::Up))
    {
        vel.y = -1;
    }
    else if (kbd.isKeyPressed(sf::Keyboard::Down))
    {
        vel.y = 1;
    }
    else if (kbd.isKeyPressed(sf::Keyboard::Down))
    {
        vel.y = 1;
    }
    if (vel.x != 0 || vel.y != 0)
    {
        snake.SetVelocity(vel);
        gameOver = false;
        sound.PlayMusic();
    }
}
