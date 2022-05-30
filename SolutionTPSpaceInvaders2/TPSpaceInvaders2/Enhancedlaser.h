#pragma once
#include "Laser.h"
class Enhancedlaser : public Laser{
	bool toggle;
public :
	Enhancedlaser(Coord c, TypeLaser typeLaser);
	virtual void deplacer() override;
	void deplacerDiagonalePositif();
	void deplacerDiagonaleNegatif();
	void setToggle(bool toggle);
};
