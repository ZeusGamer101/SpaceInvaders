#include "Partie.h"
#include "VaisseauQuiRespawn.h"
#include "UIKit.h"
#include <iostream>
#include <conio.h>
#include "Enhancedlaser.h"
#include "TypeLaser.h"
#include "Martien.h"
#include "SuperMartien.h"
#include<time.h>
#include "GameOver.h"
#include "UnviersalBeings.h"
#include "Victory.h"
#include "Settings.h"
#include "NiveauDifficulte.h"
void Partie::debuter()
{
	//afficherMenuDifficulte();
	//return short diff;
	system("cls");
	Settings settings;
	short diff;
	afficherMenu();
	std::cin >> diff;
	system("cls");
	short seuilEnemyShot;
	bool play = true;
	if (diff == 0) {
		PlaySound(TEXT("EasyModeMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		seuilEnemyShot = 20;
	}
	if (diff == 1) {
		PlaySound(TEXT("EasyModeMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		seuilEnemyShot = 50;
	}
	if (diff == 2) {
		PlaySound(TEXT("EasyModeMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		seuilEnemyShot = 100;
	}
	if (diff == 3) {
		PlaySound(TEXT("LunaticModeMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		seuilEnemyShot = 200;
	}
	UIKit::curseurVisible(false);
	UIKit::cadre(0, 0, 70, 30, 12);
	bool partieTermine = false;
	//Faire apparaitre le vaisseau
	const unsigned short MINLEFT = 10;
	const unsigned short MAXRIGHT = 60;
	const unsigned short MAXBELOW = 28;
	const unsigned short MINENEMYUP = 4;
	const unsigned short MAXENEMYDOWN = 18;
	Coord coordonneesDepartVaisseau(35, MAXBELOW);
	Coord limiteMouvementGauche(MINLEFT - 1, MAXBELOW);
	Coord limiteMouvementDroite(MAXRIGHT + 1, MAXBELOW);
	UIKit::color(14);//rouge
	char apparenceDuVaisseau = 'A';
	VaisseauQuiRespawn vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite);
	UIKit::color(10);//vert
	int nbMartien = 3;
	int nbSuper = 1;
	int nbBoss = 0;
	Martien** enemy;
	SuperMartien** alien;
	UniversalBeings** boss;
	srand(time(0));
	settings.setSettings(diff);
	long long score = 0;
	enemy = new Martien * [settings.getMaxMartien()];
	alien = new SuperMartien * [settings.getMaxMartien()];
	boss = new UniversalBeings * [nbBoss];
	bool win;
	for (int i = 0; i < nbMartien; i++) {
		Coord spawnEnemyInit(rand() % (MAXRIGHT - MINLEFT + 1) + MINLEFT/*x*/, rand() % (MAXENEMYDOWN - MINENEMYUP + 1) + MINENEMYUP/*y*/);
		enemy[i] = new  Martien(spawnEnemyInit, 'M', settings.getScoreMartien());
	}
	for (int i = 0; i < nbSuper; i++) {
		Coord spawnEnemy(rand() % (MAXRIGHT - MINLEFT + 1) + MINLEFT, rand() % (MAXENEMYDOWN - MINENEMYUP + 1) + MINENEMYUP);
		alien[i] = new SuperMartien(spawnEnemy, 'S', settings.getScoreSuperMartien());
	}
	int nbLaser = 0;
	Enhancedlaser** lasers;
	int nbLaserBoss = 0;
	Enhancedlaser** lasersBoss;
	lasers = new Enhancedlaser * [500];
	lasersBoss = new Enhancedlaser * [500];
	int enemyShot = 0;
	do {
		//Récupérer la touche appuyée par l'utilisateur
		//Effectuer action en fonction de la touche appuyé par l'utilisateur
		//Ici on peut soit déplacer le vaiseau à gauche ou à droite, soit tirer un laser
		if (GetAsyncKeyState(VK_LEFT)) {
			UIKit::color(14);
			vaisseau.deplacer(Direction::GAUCHE);
			UIKit::color(10);
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			UIKit::color(14);
			vaisseau.deplacer(Direction::DROITE);
			UIKit::color(10);
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			lasers[nbLaser] = new Enhancedlaser(vaisseau.getCoord(), TypeLaser::JOUEUR);
			nbLaser++;
			//PlaySound(TEXT("shootsfx"), NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP);
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			UIKit::gotoXY(15, 15);
			system("pause");
			UIKit::gotoXY(15, 15);
			UIKit::gotoXY(15, 15);
			std::cout << "                                                 ";
		}
		//controller la music
		if (GetAsyncKeyState(0x4D)) {
			if (play == true) {
				play = false;
				PlaySound(NULL, NULL, SND_ASYNC);
			}
			else {
				play = true;
				if (nbBoss > 0) {
					if (diff == 1) {
						PlaySound(TEXT("BossMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
					}
					if (diff == 2) {
						PlaySound(TEXT("HardBossMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
					}
				}
				else {
					if (diff == 0) {
						PlaySound(TEXT("EasyModeMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
					}
					if (diff == 1) {
						PlaySound(TEXT("EasyModeMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
					}
					if (diff == 2) {
						PlaySound(TEXT("EasyModeMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
					}
					if (diff == 3) {
						PlaySound(TEXT("LunaticModeMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
					}
				}
			}
		}
		if (GetAsyncKeyState(0x41)) {
			if (settings.getBomb() > 0) {
				settings.BombUse();
				for (int i = 0; i < nbLaser; i++) {
					TypeLaser type = lasers[i]->getTypeLaser();
					if (type == TypeLaser::EXTRATERRESTRE) {
						lasers[i]->detruire();
					}
				}
				for (int i = 0; i < nbLaserBoss; i++) {
					TypeLaser type = lasersBoss[i]->getTypeLaser();
					if (type == TypeLaser::EXTRATERRESTRE) {
						lasersBoss[i]->detruire();
					}
				}
				Sleep(1000);
			}
		}
		//Déplacer les lasers du vaisseau et des extraterrestres
		for (int i = 0; i < nbLaser; i++) {
			UIKit::color(13);
			lasers[i]->deplacer();
			UIKit::color(10);
		}
		for (int i = 0; i < nbLaserBoss; i++) {
			UIKit::color(15);
			lasersBoss[i]->deplacerDiagonalePositif();
			i++;
			lasersBoss[i]->deplacer();
			i++;
			lasersBoss[i]->deplacerDiagonaleNegatif();
			UIKit::color(10);
		}
		//Déplacer les extraterrestres
		for (int i = 0; i < nbMartien; i++) {
			int moverate = rand() % settings.getControlMovement();
			if (moverate == 1) {
				enemy[i]->deplacer();
			}
		}
		for (int i = 0; i < nbSuper; i++) {
			int moveSuperRate = rand() % settings.getControlMovement();
			if (moveSuperRate == 1) {
				alien[i]->deplacer();
			}
		}
		for (int l = 0; l < nbBoss; l++) {
			int moveBossRate = rand() % settings.getControlBoss();
			if (moveBossRate == 1) {
				UIKit::color(15);
				boss[l]->deplacer();
				UIKit::color(10);
			}
		}
		//Faire tirer les extraterrestres
		for (int j = 0; j < nbMartien; j++) {
			int shootRate = rand() % settings.getControlLaser();
			if (shootRate == 1) {
				UIKit::color(13);
				lasers[nbLaser] = new Enhancedlaser(enemy[j]->getCoord(), TypeLaser::EXTRATERRESTRE);
				nbLaser++;
				UIKit::color(10);
			}
		}
		for (int j = 0; j < nbSuper; j++) {
			int shootRate = rand() % settings.getControlLaser();
			if (shootRate == 1) {
				UIKit::color(13);
				lasers[nbLaser] = new Enhancedlaser(alien[j]->getCoord(), TypeLaser::EXTRATERRESTRE);
				nbLaser++;
				UIKit::color(10);
			}
		}
		for (int i = 0; i < nbLaser; i++) {
			if (lasers[i]->isActif() == false) {
				delete lasers[i];
				lasers[i] = lasers[nbLaser - 1];
				nbLaser--;
				i--;
			}
		}
		if (nbBoss > 0) {
			for (int i = 0; i < nbBoss; i++) {
				int shootRate = rand() % settings.getControlLaserBoss();
				if (shootRate == 1) {
					UIKit::color(15);
					lasersBoss[nbLaserBoss] = new Enhancedlaser(boss[i]->getCoord(), TypeLaser::EXTRATERRESTRE);
					nbLaserBoss++;
					lasersBoss[nbLaserBoss] = new Enhancedlaser(boss[i]->getCoord(), TypeLaser::EXTRATERRESTRE);
					nbLaserBoss++;
					lasersBoss[nbLaserBoss] = new Enhancedlaser(boss[i]->getCoord(), TypeLaser::EXTRATERRESTRE);
					nbLaserBoss++;
					UIKit::color(10);
				}
			}
		}
		for (int i = 0; i < nbLaserBoss; i++) {
			if (lasersBoss[i]->isActif() == false) {
				delete lasersBoss[i];
				lasersBoss[i] = lasersBoss[nbLaserBoss - 1];
				nbLaserBoss--;
				i--;
			}
		}
		//Vérifier collision entre laser et joueur ou ennemis
		for (int j = 0; j < nbSuper; j++) {
			for (int i = 0; i < nbLaser; i++) {
				bool collision = lasers[i]->detecterCollision(*alien[j]);
				TypeLaser type = lasers[i]->getTypeLaser();
				if (collision == true && type == TypeLaser::JOUEUR) {
					alien[j]->detruire();
					lasers[i]->detruire();
					score += alien[j]->getValeurPoints();
					enemyShot++;
				}
			}
		}
		for (int j = 0; j < nbMartien; j++) {
			for (int i = 0; i < nbLaser; i++) {
				bool collision = lasers[i]->detecterCollision(*enemy[j]);
				TypeLaser type = lasers[i]->getTypeLaser();
				if (collision == true && type == TypeLaser::JOUEUR) {
					enemy[j]->detruire();
					lasers[i]->detruire();
					score += enemy[j]->getValeurPoints();
					enemyShot++;
				}
			}
		}
		for (int i = 0; i < nbLaser; i++) {
			bool collision = lasers[i]->detecterCollision(vaisseau);
			if (collision == true) {
				vaisseau.detruire();
				lasers[i]->detruire();
				score = score / 2;
				settings.hit();
			}
		}
		for (int i = 0; i < nbLaserBoss; i++) {
			bool collision = lasersBoss[i]->detecterCollision(vaisseau);
			if (collision == true) {
				vaisseau.detruire();
				lasersBoss[i]->detruire();
				score = score / 2;
				settings.hit();
			}
		}
		for (int i = 0; i < nbBoss; i++) {
			for (int l = 0; l < nbLaser; l++) {
				bool collision = lasers[l]->detecterCollision(*boss[i]);
				TypeLaser type = lasers[l]->getTypeLaser();
				if (collision == true && type == TypeLaser::JOUEUR) {
					UIKit::color(15);
					settings.bossHit();
					boss[i]->deplacer();
					lasers[l]->detruire();
					UIKit::color(10);
				}
				if (settings.getHpBoss() == 0) {
					boss[i]->detruire();
					score += boss[i]->getValeurPoints();
				}
			}
		}
		if (vaisseau.isActif() == false) {
			UIKit::color(14);
			for (int i = 0; i < nbLaser; i++) {
				TypeLaser type = lasers[i]->getTypeLaser();
				if (type == TypeLaser::EXTRATERRESTRE) {
					lasers[i]->detruire();
				}
			}
			for (int i = 0; i < nbLaserBoss; i++) {
				TypeLaser type = lasersBoss[i]->getTypeLaser();
				if (type == TypeLaser::EXTRATERRESTRE) {
					lasersBoss[i]->detruire();
				}
			}
			Sleep(1000);
			vaisseau.respawn(coordonneesDepartVaisseau);
			UIKit::color(10);

		}

		//Faire apparaitre nouveau extraterrestre
		int spawnrateSuper = rand() % settings.getControlSuperAlien();
		if (spawnrateSuper == 1) {
			//coord random que les aliens spawn
			Coord coord(rand() % (MAXRIGHT - MINLEFT + 1) + MINLEFT, rand() % (MAXENEMYDOWN - MINENEMYUP + 1) + MINENEMYUP);
			nbSuper++;
			alien[nbSuper - 1] = new SuperMartien(coord, 'S', settings.getScoreSuperMartien());
		}
		int spawnrate = rand() % settings.getControlAlien();
		if (spawnrate == 1) {
			//coord random que les aliens spawn
			Coord coord(rand() % (MAXRIGHT - MINLEFT + 1) + MINLEFT, rand() % (MAXENEMYDOWN - MINENEMYUP + 1) + MINENEMYUP);
			nbMartien++;
			enemy[nbMartien - 1] = new Martien(coord, 'M', settings.getScoreMartien());
		}
		//detruire un alien
		for (int i = 0; i < nbMartien; i++) {
			if (enemy[i]->isActif() == false) {
				delete enemy[i];
				enemy[i] = enemy[nbMartien - 1];
				nbMartien--;
				i--;
			}
		}
		for (int i = 0; i < nbSuper; i++) {
			if (alien[i]->isActif() == false) {
				delete alien[i];
				alien[i] = alien[nbSuper - 1];
				nbSuper--;
				i--;
			}
		}
		int nbEnemy = nbSuper + nbMartien;
		//Mettre à jour le score affiché
		UIKit::color(11);
		UIKit::gotoXY(4, 0);
		std::cout << "              ";
		UIKit::gotoXY(4, 0);
		std::cout << " Score: " << score;
		UIKit::gotoXY(50, 0);
		std::cout << "                ";
		UIKit::gotoXY(50, 0);
		std::cout << " Enemy Left: " << nbEnemy;
		if (diff > 1) {
			UIKit::gotoXY(50, 0);
			std::cout << "                ";
			UIKit::gotoXY(50, 0);
			std::cout << " Enemy shot: " << enemyShot;
		}
		if (nbBoss >= 1) {
			UIKit::gotoXY(50, 0);
			std::cout << "                   ";
			UIKit::gotoXY(50, 0);
			std::cout << "    HP Boss:   " << settings.getHpBoss();
		}
		UIKit::gotoXY(30, 30);
		std::cout << "            ";
		UIKit::gotoXY(30, 30);
		std::cout << " Life:  " << settings.getNbrVie();
		UIKit::gotoXY(15, 30);
		std::cout << "            ";
		UIKit::gotoXY(15, 30);
		std::cout << " Bomb:  " << settings.getBomb();
		UIKit::curseurVisible(false);
		UIKit::color(10);
		//Vérifier si on gagne (si le nombre d'extraterrestre est rendu à 0)
		if (diff < 2) {
			if ((nbEnemy == 0 || enemyShot >= seuilEnemyShot) && nbBoss == 0) {
				settings.bossAppear();
				for (int i = 0; i < nbMartien; i++) {
					enemy[i]->detruire();
				}
				for (int i = 0; i < nbSuper; i++) {
					alien[i]->detruire();
				}
				for (int i = 0; i < nbLaser; i++) {
					lasers[i]->detruire();
				}
				if (diff == 1) {
					PlaySound(TEXT("BossMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				Coord coordBoss(35, 15);
				nbBoss++;
				for (int i = 0; i < nbLaser; i++) {
					lasers[i]->detruire();
				}
				Sleep(2000);
				for (int i = 0; i < nbBoss; i++) {
					UIKit::color(15);
					boss[i] = new UniversalBeings(coordBoss, '@', settings.getScoreBoss(), "BOSS");
					Sleep(1000);
					boss[i]->deplacer();
					Sleep(750);
					boss[i]->deplacer();
					Sleep(500);
					boss[i]->deplacer();
					Sleep(200);
					boss[i]->deplacer();
					Sleep(1500);
					boss[i]->deplacer();
					UIKit::color(10);
				}
			}
		}
		else if (enemyShot >= seuilEnemyShot && nbBoss == 0) {
			settings.bossAppear();
			for (int i = 0; i < nbMartien;i++) {
				enemy[i]->detruire();
			}
			for (int i = 0; i < nbSuper; i++) {
				alien[i]->detruire();
			}
			for (int i = 0; i < nbLaser; i++) {
				lasers[i]->detruire();
			}
			if (diff == 2) {
				PlaySound(TEXT("HardBossMusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			}
			Coord coordBoss(35, 15);
			nbBoss++;
			Sleep(2000);
			for (int i = 0; i < nbBoss; i++) {
				UIKit::color(15);
				boss[i] = new UniversalBeings(coordBoss, '@', settings.getScoreBoss(), "BOSS");
				Sleep(1000);
				boss[i]->deplacer();
				Sleep(750);
				boss[i]->deplacer();
				Sleep(500);
				boss[i]->deplacer();
				Sleep(200);
				boss[i]->deplacer();
				Sleep(1500);
				boss[i]->deplacer();
				UIKit::color(10);
			}
		}
		if (settings.getHpBoss() <= 0) {
			partieTermine = true;
			win = true;
		}
		//Vérifier si on perd si le nombre d'extra terrestre est à 15+ ou 
		if (nbEnemy >= settings.getMaxMartien()) {
			partieTermine = true;
			win = false;
		}
		//qu'un laser extraterrestre nous a atteint
		else if (settings.getNbrVie() == 0) {
			partieTermine = true;
			win = false;
		}
		Sleep(35);
	} while (partieTermine == false);
	if (win == false) {
		score = 0;
		GameOver::afficher(score);
	}
	if (win == true) {
		score *= 2;
		Victory::afficher(score);
	}
	if (partieTermine == true) {
		PlaySound(TEXT("MainMenu"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	system("cls");
}