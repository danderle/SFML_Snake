#include "Snake.h"

Snake::Snake(sf::Vector2i pos)
	:
	velocity(0,1)
{
	Segment head(pos, sf::Color::Yellow);
	body.push_back(head);
	bodyShades.emplace_back(lightGreen);
	bodyShades.emplace_back(mediumGreen);
	bodyShades.emplace_back(darkGreen);
}

void Snake::Draw(sf::RenderWindow& wnd)
{
	for (auto segment : body)
	{
		auto shape = segment.GetShape();
		wnd.draw(shape);
	}
}

void Snake::SetVelocity(const sf::Vector2f vel)
{
	velocity.x = vel.x;
	velocity.y = vel.y;
}

void Snake::Grow(const sf::Vector2i pos)
{
	Segment tail(pos, bodyShades[shadeIndex]);
	body.push_back(tail);
	shadeIndex += shadeIndex >= 2 ? -2 : 1;
}

void Snake::SetToGrow(const bool grw)
{
	grow = grw;
}

const std::vector<Segment>& Snake::GetBody()
{
	return body;
}

void Snake::IncreaseFruitEaten()
{
	numberOfFruitEaten++;
	speed += numberOfFruitEaten % speedIncreaseThreashold == 0 ? 1 : 0;
}

sf::Vector2f Snake::GetPosition() const
{

	return body[0].;
}

void Snake::Move(const float dt)
{
	lastDistance += dt * speed;
	if (lastDistance > moveThreashold)
	{
		int length = body.size()-1;
		auto tailPos = body[length].GetPosition();
		for (; length > 0; length--)
		{
			auto pos = body[length - 1].GetPosition();
			body[length].SetPosition(pos);
		}
		body[0].MoveBy(velocity);
		if (grow)
		{
			Grow((sf::Vector2i)tailPos);
			grow = false;
		}
		lastDistance = 0;
	}
}
