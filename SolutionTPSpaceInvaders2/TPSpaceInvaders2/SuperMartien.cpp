#include "SuperMartien.h"
#include <time.h>
#include <stdlib.h>

SuperMartien::SuperMartien(Coord coord, char apparence, unsigned short valeursPoints) : Martien(coord, apparence, valeurPoints)
{
	this->valeurPoints = valeursPoints;
}

void SuperMartien::deplacer()
{
	const unsigned short MINLEFT = 11;
	const unsigned short MAXRIGHT = 59;
	const unsigned short MAXBELOW = 28;
	const unsigned short MINENEMYUP = 5;
	const unsigned short MAXENEMYDOWN = 20;
	const unsigned short BOND = 5;
	int randomG = rand() % 2;
	this->effacer();
	if ((this->getCoord().getX() < MAXRIGHT) && this->getCoord().getX() > MINLEFT && this->getCoord().getY() > MINENEMYUP && this->getCoord().getY() < MAXENEMYDOWN) {
		(randomG == 1 ? this->coord.setX(this->coord.getX() + (toggle ? rand() % BOND : -rand() % BOND)) : this->coord.setY(this->coord.getY() + (toggle ? rand() % BOND : -rand() % BOND)));
	}
	else {
		if (this->getCoord().getX() >= MAXRIGHT) {
			this->coord.setX(this->coord.getX() - BOND);
		}
		else if (this->getCoord().getX() <= MINLEFT) {
			this->coord.setX(this->coord.getX() + BOND);
		}
		else if (this->getCoord().getY() <= MINENEMYUP) {
			this->coord.setY(this->coord.getY() + BOND);
		}
		else if (this->getCoord().getY() >= MAXENEMYDOWN) {
			this->coord.setY(this->coord.getY() - BOND);
		}
	}
	toggle = !toggle;
	this->afficher();
}

