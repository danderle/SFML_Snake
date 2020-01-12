#pragma once
#include "SFML/Graphics.hpp"
#include "Segment.h"

class Board
{
public:
	Board(sf::Vector2f position, const int brdWidth, const int brdHeight);

	void Draw(sf::RenderWindow& wnd);
	void DrawCell(const sf::Vector2i poisition, const sf::Color c);
	const int NumOfColumns() const;
	const int NumOfRows() const;
	const sf::Vector2f GetPosition();
	bool CheckCollision(sf::Vector2i gridPos) const;

private:
	void SetupBoarder(const sf::Vector2f position);

private:
	sf::RectangleShape border;
	int columns;
	int rows;

	static constexpr int outlineThickness = 5;
};

