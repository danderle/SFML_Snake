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
