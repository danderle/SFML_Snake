#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Score
{
public:
	Score();
	
	void Draw(sf::RenderWindow& wnd);
	void Update(const int fruitEaten);

private:
	void Initialize();

private:
	sf::Vector2f position;
	sf::Font font;
	sf::Text scoreText;
	sf::Text currentPointText;
	static constexpr int startingScore = 0;
	static constexpr float xStartPosition = 10;
	static constexpr float yStartPosition = 5;
	static constexpr float spaceWidth = 5;
};

