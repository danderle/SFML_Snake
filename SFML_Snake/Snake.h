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
	const std::vector<Segment>& GetBody();
	void IncreaseFruitEaten();
	bool IsDead() const;
	sf::Vector2f GetPosition() const;
	void CheckSelfCollision();
	void GetKeyboardInput(sf::Keyboard& kbd);

private:
	std::vector<Segment> body;
	sf::Vector2f currentVelocity;
	std::vector<sf::Color> bodyShades;
	int shadeIndex = 0;
	bool grow = false;
	float speed = 80;
	float lastDistance = 0;
	int numberOfFruitEaten = 0;
	bool isDead = false;

	static constexpr float moveThreashold = 20;
	static constexpr int speedIncreaseThreashold = 20;
	const sf::Color lightGreen = sf::Color(50, 205, 50);
	const sf::Color mediumGreen = sf::Color(34, 139, 34);
	const sf::Color darkGreen = sf::Color(85, 107, 47);
};

