#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    
    Game theGame(800, 900, "Snake");
    theGame.Go();

    return 0;
}