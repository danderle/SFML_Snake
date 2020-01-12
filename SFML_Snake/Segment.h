#pragma once
#include "SFML/Graphics.hpp"

class Segment
{
public:
	Segment(sf::Vector2i pos, const sf::Color c);
		
	sf::RectangleShape GetShape() const;
	void SetPosition(const sf::Vector2f pos);
	sf::Vector2f GetPosition() const;
	void MoveBy(sf::Vector2f vel);
	
public:
	static constexpr int Dimensions = 20;
private:
	sf::RectangleShape shape;
	static constexpr int Margin = -1;
};

