#include "Menu.h"
#include <iostream>
#include "Partie.h"
#include "UIKit.h"
#include <windows.h>
void Menu::afficher()
{
	UIKit::color(10);
	UIKit::curseurVisible(false);
	UIKit::gotoXY(10, 4);
	std::cout << "   ___________________  _____  _________ ___________ " << std::endl;
	UIKit::gotoXY(10, 5);
	std::cout << "  /   _____/\\______   \\/  _  \\ \\_   ___ \\\\_   _____/ " << std::endl;
	UIKit::gotoXY(10, 6);
	std::cout << "  \\_____  \\  |     ___/  /_\\  \/    \\  \\/ |    __)_  " << std::endl;
	UIKit::gotoXY(10, 7);
	std::cout << "  /        \\ |    |  /    |    \\     \\____|       \\ " << std::endl;
	UIKit::gotoXY(10, 8);
	std::cout << " /_______  / |____|  \\____|__  /\\______  /_______  / " << std::endl;
	UIKit::gotoXY(10, 9);
	std::cout << "         \\/                  \\/        \\/        \\/  " << std::endl;
	UIKit::gotoXY(0, 11);
	std::cout << " .___ ___________   _________  ________  _____________________  _________ " << std::endl;
	UIKit::gotoXY(0, 12);
	std::cout << " |   |\\      \\   \\ /   /  _  \\ \\______ \\ \\_   _____/\\______   \\/   _____/ " << std::endl;
	UIKit::gotoXY(0, 13);
	std::cout << " |   |/   |   \\   Y   /  /_\\  \\ |    |  \\ |    __)_  |       _/\\_____  \\  " << std::endl;
	UIKit::gotoXY(0, 14);
	std::cout << " |   /    |    \\     /    |    \\|    `   \\|        \\ |    |   \\/        \\ " << std::endl;
	UIKit::gotoXY(0, 15);
	std::cout << " |___\\____|__  /\\___/\\____|__  /_______  /_______  / |____|_  /_______  / " << std::endl;
	UIKit::gotoXY(0, 16);
	std::cout << "             \\/              \\/        \\/        \\/         \\/        \\/  " << std::endl;
	UIKit::gotoXY(25, 20);
	UIKit::color(12);
	std::cout << "START (Enter)" << std::endl;
	UIKit::gotoXY(25, 21);
	std::cout << "INSTRUCTION (Spacebar)" << std::endl;
	UIKit::gotoXY(25, 22);
	std::cout << "README (BackSpace)" << std::endl;
	UIKit::gotoXY(25, 23);
	std::cout << "SCOREBOARD W.I.P (S)" << std::endl;
	UIKit::gotoXY(25, 24);
	std::cout << "QUITTER (Esc)" << std::endl;
	UIKit::color(8);
}

unsigned short Menu::getChoix() const
{
	return this->choix;
}
