#pragma once
#include "SFML/Graphics.hpp"
#include "Snake.h"

class Board
{
public:
	Board(sf::Vector2f position, const int brdWidth, const int brdHeight);

	void Draw(sf::RenderWindow& wnd);
	void DrawCell(const sf::Vector2i poisition, const sf::Color c);
	const int NumOfColumns() const;
	const int NumOfRows() const;
	sf::Vector2f GetTopLeftPosition();
	sf::Vector2f GetBottomRightPosition();
	void CheckCollision(Snake& snake);

private:
	void SetupBoarder(const sf::Vector2f position);

private:
	sf::RectangleShape border;
	sf::Vector2f bottomRightPosition;
	int columns;
	int rows;

	static constexpr int outlineThickness = 5;
};

