#include "Settings.h"

Settings::Settings()
{

}
void Settings::setSettings(unsigned short diff)
{
	if (diff == 0) {
		this->controlSuperAlien = 80;
		this->controlAlien = 60;
		this->controlLaser = 100;
		this->controlLaserBoss = 70;
		this->controlMovement = 15;
		this->controlBoss = 100;
		this->bomb = 10;
		this->scoreSuperMartien = 15;
		this->scoreMartien = 10;
		this->scoreBoss = 100;
		this->maxMartien = 15;
		this->nbrVie = 10;
		this->hpBoss = 10;
	}
	if (diff == 1) {
		this->controlSuperAlien = 50;
		this->controlAlien = 40;
		this->controlLaser = 70;
		this->controlLaserBoss = 50;
		this->controlMovement = 25;
		this->controlBoss = 80;
		this->bomb = 3;
		this->scoreSuperMartien = 150;
		this->scoreMartien = 100;
		this->scoreBoss = 1000;
		this->maxMartien = 15;
		this->nbrVie = 3;
		this->hpBoss = 15;
	}
	if (diff == 2) {
		this->controlSuperAlien = 20;
		this->controlAlien = 15;
		this->controlLaser = 50;
		this->controlLaserBoss = 35;
		this->controlMovement = 15;
		this->controlBoss = 50;
		this->bomb = 5;
		this->scoreSuperMartien = 500;
		this->scoreMartien = 250;
		this->scoreBoss = 2000;
		this->maxMartien = 1500;
		this->nbrVie = 5;
		this->hpBoss = 15;
	}
	if (diff == 3) {
		this->controlSuperAlien = 20;
		this->controlAlien = 15;
		this->controlLaser = 25;
		this->controlLaserBoss = 25;
		this->controlMovement = 5;
		this->controlBoss = 30;
		this->bomb = 5;
		this->scoreSuperMartien = 1000;
		this->scoreMartien = 500;
		this->scoreBoss = 5000;
		this->maxMartien = 15000;
		this->nbrVie = 5;
		this->hpBoss = 20;
	}
}

unsigned short Settings::getControlSuperAlien() const
{
	return this->controlSuperAlien;
}
unsigned short Settings::getControlAlien() const
{
	return this->controlAlien;
}
unsigned short Settings::getControlLaser() const
{
	return this->controlLaser;
}
unsigned short Settings::getControlMovement() const
{
	return this->controlMovement;
}
unsigned short Settings::getControlBoss() const
{
	return this->controlBoss;
}
unsigned short Settings::getControlLaserBoss() const
{
	return this->controlLaserBoss;
}
unsigned short Settings::getBomb() const
{
	return this->bomb;
}
unsigned short Settings::getMaxMartien() const
{
	return this->maxMartien;
}
unsigned short Settings::getScoreMartien() const
{
	return this->scoreMartien;
}
unsigned short Settings::getScoreSuperMartien() const
{
	return this->scoreSuperMartien;
}
unsigned short Settings::getScoreBoss() const
{
	return this->scoreBoss;
}
unsigned short Settings::getHpBoss() const
{
	return this->hpBoss;
}
unsigned short Settings::getNbrVie() const
{
	return this->nbrVie;
}
void Settings::BombUse()
{
	this->bomb--;
}
void Settings::hit()
{
	this->nbrVie--;
}
void Settings::bossHit()
{
	this->hpBoss--;
}
void Settings::bossAppear()
{
	this->controlSuperAlien /= 2;
	this->controlAlien /= 2;
	this->controlLaser *= 0.75;
	this->controlMovement /= 2;
	this->maxMartien = 1500;
}
/*unsigned short controlSuperAlien, unsigned short controlAlien, unsigned short controlLaser, unsigned short controlMovement, unsigned short controlBoss, unsigned short controlLaserBoss, unsigned short bomb, unsigned short maxMartien, unsigned short nbBoss, unsigned short scoreMartien, unsigned short scoreSuperMartien, unsigned short scoreBoss, unsigned short hpBoss, short nbrVie):
controlAlien(controlAlien), controlSuperAlien(controlSuperAlien), controlLaser(controlLaser), controlMovement(controlMovement), controlBoss(controlBoss), controlLaserBoss(controlLaserBoss), bomb(bomb), maxMartien(maxMartien), nbBoss(nbBoss), scoreMartien(scoreMartien), scoreSuperMartien(scoreSuperMartien), scoreBoss(scoreBoss), hpBoss(hpBoss), nbrVie(nbrVie)
*/