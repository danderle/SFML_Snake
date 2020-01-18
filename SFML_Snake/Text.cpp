#include "Text.h"

Text::Text()
	:
	score({"Score: ", font }),
	currentPoint({std::to_string(startingScore), font }),
	pressToPlay({ "Press arrow\n keys to play", font }),
	gameOver({ "Game Over", font })
{
	Initialize();
}

void Text::DrawScore(sf::RenderWindow& wnd)
{
	wnd.draw(score);
	wnd.draw(currentPoint);
}

void Text::DrawPressToPlay(sf::RenderWindow& wnd)
{
	wnd.draw(pressToPlay);
}

void Text::UpdateScore(const int fruitEaten)
{
	currentPoint.setString(std::to_string(fruitEaten));
}

void Text::SetPressToPlay(const sf::Vector2f pos, const float width, const float height)
{
	sf::Vector2f centerPos(pos.x + width / 2, pos.y + height / 2);
	auto xPos = centerPos.x - pressToPlay.getGlobalBounds().width / 2;
	auto yPos = centerPos.y - pressToPlay.getGlobalBounds().height / 2;
	pressToPlay.setPosition({xPos, yPos - 9});
}


//// Private Methods

void Text::Initialize()
{
	try
	{
		font.loadFromFile("Resources\\Roboto-Bold.ttf");
	}
	catch (const std::ifstream::failure & e)
	{
		std::cout << "File loading exception: " << e.code() << std::endl;
		std::cout << "Resources\\LemonMilk.otf" << std::endl;
	}

	score.setPosition({ xStartPosition, yStartPosition });
	auto posTxt = score.getPosition();
	auto boundsTxt = score.getLocalBounds();
	currentPoint.setPosition(posTxt.x + boundsTxt.width + spaceWidth, yStartPosition);
}
