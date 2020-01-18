#include "Score.h"

Score::Score()
	:
	scoreText({"Score: ", font }),
	currentPointText({std::to_string(startingScore), font })
{
	Initialize();
}

void Score::Draw(sf::RenderWindow& wnd)
{
	wnd.draw(scoreText);
	wnd.draw(currentPointText);
}

void Score::Update(const int fruitEaten)
{
	currentPointText.setString(std::to_string(fruitEaten));
}


//// Private Methods

void Score::Initialize()
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

	scoreText.setPosition({ xStartPosition, yStartPosition });
	auto posTxt = scoreText.getPosition();
	auto boundsTxt = scoreText.getLocalBounds();
	currentPointText.setPosition(posTxt.x + boundsTxt.width + spaceWidth, yStartPosition);
}
