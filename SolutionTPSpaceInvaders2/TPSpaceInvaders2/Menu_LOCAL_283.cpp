#include "Menu.h"
#include <iostream>
void Menu::afficher()
{
	std::cout << "SPACE INVADERS" << std::endl;
	std::cout << "Appuyer sur ENTER pour START" << std::endl;
	std::cout << "INSTRUCTION (Spacebar)" << std::endl;
	std::cout << "README (ctrl)" << std::endl;
	std::cout << "QUITTER (Esc)" << std::endl;
}

unsigned short Menu::getChoixDifficulte() const
{
	return this->choixDifficulte;
}
