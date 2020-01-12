#include "Segment.h"

Segment::Segment(sf::Vector2i pos, const sf::Color c)
	:
	shape({ Dimensions, Dimensions })
{
	shape.setPosition((sf::Vector2f)pos);
	shape.setFillColor(c);
	shape.setOutlineThickness(Margin);
	shape.setOutlineColor({ 0,0,0 });
}

sf::RectangleShape Segment::GetShape() const
{
	return shape;
}

void Segment::SetPosition(const sf::Vector2f pos)
{
	shape.setPosition(pos);
}

sf::Vector2f Segment::GetPosition() const
{
	return shape.getPosition();
}

void Segment::MoveBy(sf::Vector2f vel)
{
	vel.x *= Dimensions;
	vel.y *= Dimensions;
	shape.move(vel);
}
