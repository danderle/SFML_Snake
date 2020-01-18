#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Text
{
public:
	Text();
	
	void DrawScore(sf::RenderWindow& wnd);
	void DrawPressToPlay(sf::RenderWindow& wnd);
	void UpdateScore(const int fruitEaten);
	void SetPressToPlay(const sf::Vector2f posn, const float width, const float height);

private:
	void Initialize();

private:
	sf::Vector2f positionScore;
	sf::Font font;
	sf::Text score;
	sf::Text currentPoint;
	sf::Text pressToPlay;
	sf::Text gameOver;

	static constexpr int startingScore = 0;
	static constexpr float xStartPosition = 10;
	static constexpr float yStartPosition = 5;
	static constexpr float spaceWidth = 5;
};

