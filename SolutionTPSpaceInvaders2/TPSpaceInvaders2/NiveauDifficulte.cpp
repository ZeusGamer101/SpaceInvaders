#include <iostream>
#include "NiveauDifficulte.h"
#include "UIKit.h"
void afficherMenu()
{
	UIKit::color(10);
	std::cout << "Choissiez un niveau de difficulty : " << std::endl;
	std::cout << "(" << (short)NiveauDifficulte::FACILE << ") EASY " << std::endl;
	std::cout << "(" << (short)NiveauDifficulte::MOYEN << ") NORMAL " << std::endl;
	std::cout << "(" << (short)NiveauDifficulte::DIFFICILE << ") HARD " << std::endl;
	std::cout << "(" << (short)NiveauDifficulte::INSANE << ") LUNATIC " << std::endl;
	std::cout << "Votre choix: ";
}
