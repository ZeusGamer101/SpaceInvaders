#include "Menu.h"
#include <iostream>
void Menu::afficher()
{
	std::cout << "Bienvenue au jeu de space invaders " << std::endl;
	std::cout << "Choissiez un niveau de difficulté : " << std::endl;
	std::cout << "(1) Facile " << std::endl;
	std::cout << "(2) Moyen " << std::endl;
	std::cout << "(3) Difficile " << std::endl;
	if (choixDifficulte == (unsigned short)NiveauDifficulte::FACILE) {
		getChoixDifficulte();
	}
	system("pause");
	system("cls");
}

unsigned short Menu::getChoixDifficulte() const
{
	return this->choixDifficulte;
}
