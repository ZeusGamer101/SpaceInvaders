#include "Menu.h"
#include <iostream>
#include "Partie.h"
void Menu::afficher()
{
	std::cout << "Bienvenue au jeu de space invaders " << std::endl;
	std::cout << "Choissiez un niveau de difficulté : " << std::endl;
	std::cout << "(1) Facile " << std::endl;
	std::cout << "(2) Moyen " << std::endl;
	std::cout << "(3) Difficile " << std::endl;
	if (choix == (unsigned short)NiveauDifficulte::FACILE) {
		Partie p;
	}
	system("pause");
	system("cls");
}

unsigned short Menu::getChoix() const
{
	return this->choix;
}
