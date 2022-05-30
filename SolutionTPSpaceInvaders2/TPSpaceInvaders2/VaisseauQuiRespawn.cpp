#include "VaisseauQuiRespawn.h"
#include "UIKit.h"
#include <iostream>
VaisseauQuiRespawn::VaisseauQuiRespawn(char apparenceVaisseau, Coord c, Coord limiteGauche, Coord limiteDroite) : Vaisseau(apparenceVaisseau, c , limiteGauche, limiteDroite)
{
	this->afficher();
}

void VaisseauQuiRespawn::respawn(Coord coordInit)
{
	this->effacer();
	this->coord.setX(coordInit.getX());
	this->coord.setY(coordInit.getY());
	this->actif = true;
	this->afficher();
	//UIKit::gotoXY(coordInit.getX(), coordInit.getY());
	//std::cout << this->apparence;
}
