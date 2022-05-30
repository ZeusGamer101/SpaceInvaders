#include "enhancedlaser.h"
#include "UIKit.h"
Enhancedlaser::Enhancedlaser(Coord c, TypeLaser typeLaser) : Laser(c, typeLaser)
{
	toggle = true;
}

void Enhancedlaser::deplacer()
{
	this->effacer();
	switch (this->typeLaser)
	{
	case TypeLaser::JOUEUR:
		this->coord.setY(this->coord.getY() - 1);
		break;
	case TypeLaser::EXTRATERRESTRE:
		this->coord.setY(this->coord.getY() + 1);
		break;
	}

	if ((this->coord.getY() <= 2 && this->typeLaser == TypeLaser::JOUEUR) || (this->coord.getY() >= 29 && this->typeLaser == TypeLaser::EXTRATERRESTRE)) {
		this->detruire();
	}

	if (this->isActif()) {
		this->afficher();
	}
}

void Enhancedlaser::deplacerDiagonalePositif()
{
	this->effacer();
	(toggle ? this->coord.setX(this->coord.getX() + 1) : this->coord.setX(this->coord.getX() - 1));
	this->coord.setY(this->coord.getY() + 1);
	if (this->coord.getX() >= 68 && this->typeLaser == TypeLaser::EXTRATERRESTRE) {
		this->setToggle(false);
	}
	if (this->coord.getY() >= 29 && this->typeLaser == TypeLaser::EXTRATERRESTRE) {
		this->detruire();
	}
	if (this->isActif()) {
		this->afficher();
	}
}

void Enhancedlaser::deplacerDiagonaleNegatif()
{
	this->effacer();
	(toggle ? this->coord.setX(this->coord.getX() - 1) : this->coord.setX(this->coord.getX() + 1));
	this->coord.setY(this->coord.getY() + 1);
	if (this->coord.getX() <= 2 && this->typeLaser == TypeLaser::EXTRATERRESTRE) {
		toggle = false;
	}
	if (this->coord.getY() >= 29 && this->typeLaser == TypeLaser::EXTRATERRESTRE) {
		this->detruire();
	}
	if (this->isActif()) {
		this->afficher();
	}
}

void Enhancedlaser::setToggle(bool toggle)
{
	this->toggle = toggle;
}

