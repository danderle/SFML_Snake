#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <vector>
#include "Segment.h"

class Snake
{
public:
	Snake() = delete;
	Snake(sf::Vector2i pos);

	void Draw(sf::RenderWindow& wnd);
	void Move(const float dt);
	void SetVelocity(const sf::Vector2f vel);
	void Grow(const sf::Vector2i pos);
	void SetToGrow(const bool grw);

private:
	std::vector<Segment> body;
	sf::Vector2f velocity;
	std::vector<sf::Color> bodyShades;
	int shadeIndex = 0;
	float dtPassed = 0;
	bool grow = false;

	const sf::Color lightGreen = sf::Color(50, 205, 50);
	const sf::Color mediumGreen = sf::Color(34, 139, 34);
	const sf::Color darkGreen = sf::Color(85, 107, 47);
	static constexpr float moveDt = 0.2f;
};

