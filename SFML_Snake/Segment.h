#pragma once
#include "SFML/Graphics.hpp"

class Segment
{
public:
	Segment(sf::Vector2i pos, const sf::Color c);
		
	sf::RectangleShape GetShape() const;
	void SetPosition(const sf::Vector2f pos)
	{
		shape.setPosition(pos);
	}
	const sf::Vector2f GetPosition()
	{
		return shape.getPosition();
	}

	void MoveBy(sf::Vector2f vel)
	{
		vel.x *= Dimensions;
		vel.y *= Dimensions;
		shape.move(vel);
	}
public:
	static constexpr int Dimensions = 20;
private:
	sf::RectangleShape shape;
	static constexpr int Margin = -1;
};

