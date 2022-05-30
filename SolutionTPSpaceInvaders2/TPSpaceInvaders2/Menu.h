#pragma once
#include "NiveauDifficulte.h"
enum {
	START,
	INSTRUCTION,
	README,
	SCOREBOARD,
	QUITTER
};
class Menu {
	unsigned short choix;
public:
	void afficher();
	unsigned short getChoix() const;
	
};
