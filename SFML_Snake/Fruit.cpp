#include "Fruit.h"

Fruit::Fruit(const int columns, const int rows, sf::Vector2f brdPos, Snake& snake )
	:
	rng(rnd()),
	xPos(0, columns-1),
	yPos(0, rows-1),
    frt({Segment::Dimensions, Segment::Dimensions}),
    brdPos(brdPos)
{
	PlaceFruit(snake);
	frt.setFillColor({ maxWhite,maxWhite,maxWhite });
}

void Fruit::PlaceFruit(Snake& snake)
{
    bool placedOnSnake;
    do
    {
        placedOnSnake = false;
        frtGridPos.x = xPos(rng);
        frtGridPos.y = yPos(rng);

        for (auto seg : snake.GetBody())
        {
            auto pos = seg.GetPosition();
            if (pos.x == frtGridPos.x &&
                pos.y == frtGridPos.y)
            {
                placedOnSnake = true;
                break;
            }
        }
    } while (placedOnSnake);
    float x = frtGridPos.x * Segment::Dimensions + brdPos.x;
    float y = frtGridPos.y * Segment::Dimensions + brdPos.y;
    frt.setPosition({ x, y });
}

void Fruit::Draw(sf::RenderWindow& wnd)
{
    wnd.draw(frt);
}

bool Fruit::IsEaten(Snake& snake)
{
    for (auto seg : snake.GetBody())
    {
        auto pos = seg.GetPosition();
        auto frtPos = frt.getPosition();
        if (pos.x == frtPos.x &&
            pos.y == frtPos.y)
        {
            return true;
        }
    }
    return false;
}

void Fruit::Pulse(const float dt)
{
    lastPulse += dt;
    if (lastPulse > pulseTime)
    {
        auto curColor = frt.getFillColor();
        if (curColor.r >= maxWhite || curColor.r <= 0 ||
            curColor.g >= maxWhite || curColor.g <= 0)
        {
            pulser *= -1;
        }
        curColor.r += pulser;
        curColor.g += (pulser * 5);
        curColor.b += (pulser * 5);
        frt.setFillColor(curColor);
        lastPulse = 0;
    }
}
