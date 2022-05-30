#include "Menu.h"
#include <iostream>
#include "Partie.h"
void Menu::afficher()
{
<<<<<<< HEAD
	std::cout << "SPACE INVADERS" << std::endl;
	std::cout << "Appuyer sur ENTER pour START" << std::endl;
	std::cout << "INSTRUCTION (Spacebar)" << std::endl;
	std::cout << "README (ctrl)" << std::endl;
	std::cout << "QUITTER (Esc)" << std::endl;
=======
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
>>>>>>> f05e0a9beaaae8a98b955d3a4601c71b2c373ab9
}

unsigned short Menu::getChoix() const
{
	return this->choix;
}
