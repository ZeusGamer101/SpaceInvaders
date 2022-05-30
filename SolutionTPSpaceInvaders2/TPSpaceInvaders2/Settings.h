#pragma once
class Settings {
	unsigned short controlSuperAlien;
	unsigned short controlAlien;
	unsigned short controlLaser;
	unsigned short controlMovement;
	unsigned short controlBoss;
	unsigned short controlLaserBoss;
	unsigned short bomb;
	unsigned short maxMartien;
	unsigned short scoreMartien;
	unsigned short scoreSuperMartien;
	unsigned short scoreBoss;
	unsigned short hpBoss;
	unsigned short nbrVie;
public:
	Settings();
	void setSettings(unsigned short diff);
	unsigned short getControlSuperAlien() const;
	unsigned short getControlAlien() const;
	unsigned short getControlLaser() const;
	unsigned short getControlMovement() const;
	unsigned short getControlBoss() const;
	unsigned short getControlLaserBoss() const;
	unsigned short getBomb() const;
	unsigned short getMaxMartien() const;
	unsigned short getScoreMartien() const;
	unsigned short getScoreSuperMartien() const;
	unsigned short getScoreBoss() const;
	unsigned short getHpBoss() const;
	unsigned short getNbrVie() const;
	void BombUse();
	void hit();
	void bossHit();
	void bossAppear();
};
//unsigned short controlSuperAlien, unsigned short controlAlien, unsigned short controlLaser, unsigned short controlMovement, unsigned short controlBoss, unsigned short controlLaserBoss, unsigned short bomb, unsigned short maxMartien, unsigned short nbBoss, unsigned short scoreMartien, unsigned short scoreSuperMartien, unsigned short scoreBoss, unsigned short hpBoss, short nbrVie