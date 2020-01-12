#include "Board.h"
#include <cassert>

Board::Board(sf::Vector2f position, const int brdWidth, const int brdHeight)
	:
	border({ (float)brdWidth , (float)brdHeight }),
	bottomRightPosition({position.x + (float)brdWidth, position.y + (float)brdHeight}),
	columns(brdWidth / Segment::Dimensions),
	rows(brdHeight / Segment::Dimensions)
{
	assert(brdWidth % Segment::Dimensions == 0 && brdHeight % Segment::Dimensions == 0);
	SetupBoarder(position);
}

void Board::Draw(sf::RenderWindow& wnd)
{
	wnd.draw(border);
}

void Board::DrawCell(const sf::Vector2i poisition, const sf::Color c)
{

}

const int Board::NumOfColumns() const
{
	return columns;
}

const int Board::NumOfRows() const
{
	return rows;
}

sf::Vector2f Board::GetTopLeftPosition()
{
	return border.getPosition();
}

sf::Vector2f Board::GetBottomRightPosition()
{
	return bottomRightPosition;
}

void Board::CheckCollision(Snake& snake)
{
	auto pos = snake.GetPosition();
	auto brdPos = GetTopLeftPosition();
	sf::Vector2f maxPos(pos.x + Segment::Dimensions, pos.y + Segment::Dimensions );
	bool collision = pos.x < brdPos.x || maxPos.x > bottomRightPosition.x ||
		pos.y < brdPos.y || maxPos.y > bottomRightPosition.y;
	snake.Collision(collision);
}

////Private Methods
void Board::SetupBoarder(const sf::Vector2f position)
{
	border.setPosition(position);
	border.setOutlineThickness(outlineThickness);
	border.setOutlineColor(sf::Color::Blue);
	border.setFillColor(sf::Color::Transparent);
}