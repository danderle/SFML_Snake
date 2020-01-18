#include "Score.h"

Score::Score()
	:
	scoreText({"Score: ", scoreFont})
{
	try
	{
		scoreFont.loadFromFile("Resources\\LemonMilk.otf");
	}
	catch (const std::ifstream::failure& e)
	{
		std::cout << "File loading exception: " << e.code() << std::endl;
		std::cout << "Resources\\LemonMilk.otf" << std::endl;
	}
}

void Score::Draw(sf::RenderWindow& wnd)
{
	wnd.draw(scoreText);
}
