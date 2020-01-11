#include "Board.h"
#include <cassert>

Board::Board(sf::Vector2f position, const int brdWidth, const int brdHeight)
	:
	border({ (float)brdWidth , (float)brdHeight }),
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

////Private Methods
void Board::SetupBoarder(const sf::Vector2f position)
{
	border.setPosition(position);
	border.setOutlineThickness(outlineThickness);
	border.setOutlineColor(sf::Color::Blue);
	border.setFillColor(sf::Color::Transparent);
}