#include "Snake.h"

Snake::Snake(sf::Vector2i pos)
	:
	startPos(pos),
	currentVelocity(0,0)
{
	MakeHead();
	bodyShades.emplace_back(lightGreen);
	bodyShades.emplace_back(mediumGreen);
	bodyShades.emplace_back(darkGreen);
}

void Snake::Draw(sf::RenderWindow& wnd)
{
	int length = body.size() - 1;
	for (; length >= 0; length--)
	{
		auto segment = body[length].GetShape();
		wnd.draw(segment);
	}
}

void Snake::SetVelocity(const sf::Vector2f vel)
{
	currentVelocity.x = vel.x;
	currentVelocity.y = vel.y;
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

bool Snake::IncreaseFruitEaten()
{
	numberOfFruitEaten++;
	bool increase = numberOfFruitEaten % speedIncreaseThreashold == 0 ? true : false;
	speed += increase ? 1 : 0;
	return increase;
}

bool Snake::IsDead() const
{
	return isDead;
}

void Snake::Collision(const bool collision)
{
	isDead = collision;
}

sf::Vector2f Snake::GetPosition() const
{
	return body[0].GetPosition();
}

void Snake::CheckSelfCollision()
{
	auto headPos = body[0].GetPosition();
	for (int seg = 1; seg < body.size(); seg++)
	{
		auto segPos = body[seg].GetPosition();
		if (headPos.x == segPos.x && headPos.y == segPos.y)
		{
			isDead = true;
			break;
		}
	}
}

void Snake::GetKeyboardInput(sf::Keyboard& kbd)
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
	else if (kbd.isKeyPressed(sf::Keyboard::Enter))
	{
		SetToGrow(true);
		IncreaseFruitEaten();
	}
	if (vel.x != 0 || vel.y != 0)
	{
		if (body.size() > 2)
		{
			if (vel.x * -1 != currentVelocity.x &&
				vel.y * -1 != currentVelocity.y)
			{
				SetVelocity(vel);
			}
		}
		else
		{
			SetVelocity(vel);
		}
	}
}

int Snake::GetFruitEaten() const
{
	return numberOfFruitEaten;
}

void Snake::Restart()
{
	shadeIndex = 0;
	grow = false;
	speed = 80;
	lastDistance = 0;
	numberOfFruitEaten = 0;
	isDead = false;
	body.clear();
	MakeHead();
}

void Snake::MakeHead()
{
	Segment head(startPos, sf::Color::Yellow);
	body.push_back(head);
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
		body[0].MoveBy(currentVelocity);
		if (grow)
		{
			Grow((sf::Vector2i)tailPos);
			grow = false;
		}
		lastDistance = 0;
	}
}
