#pragma once
#include "Vaisseau.h"
#include "ObjetDeJeu.h"
#include "TypeObjetDeJeu.h"
class VaisseauQuiRespawn : public Vaisseau {
public :
	VaisseauQuiRespawn(char apparenceVaisseau, Coord c, Coord limiteGauche, Coord limiteDroite);
	void respawn(Coord coordInit);
};