#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Score
{
public:
	Score();
	
	void Draw(sf::RenderWindow& wnd);

private:
	sf::Vector2f position;
	sf::Font scoreFont;
	sf::Text scoreText;
	int current;

};

