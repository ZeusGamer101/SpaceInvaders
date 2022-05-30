#include "UnviersalBeings.h"
#include <time.h>
#include <stdlib.h>
UniversalBeings::UniversalBeings(Coord coord, char apparence, unsigned short valeurPoints, std::string trueApparence) : Martien(coord, apparence, valeurPoints), trueApparence(trueApparence)
{

}

void UniversalBeings::deplacer()
{
	this->effacer();
	const unsigned short MINLEFT = 11;
	const unsigned short MAXRIGHT = 59;
	const unsigned short MINENEMYUP = 5;
	const unsigned short MAXENEMYDOWN = 15;
	this->coord.setX((rand() % (MAXRIGHT - MINLEFT + 1) + MINLEFT));
	this->coord.setY(rand() % (MAXENEMYDOWN - MINENEMYUP + 1) + MINENEMYUP);
	this->afficher();

}
