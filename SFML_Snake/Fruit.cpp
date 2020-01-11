#include "Fruit.h"

Fruit::Fruit(const int columns, const int rows)
	:
	rng(rnd()),
	xPos(0, columns-1),
	yPos(0, rows-1)
{

}
