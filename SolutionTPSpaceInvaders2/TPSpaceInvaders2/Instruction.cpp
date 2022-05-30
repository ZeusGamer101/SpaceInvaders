#include "Instruction.h"
#include "UIKit.h"
#include <iostream>
#include <fstream>
#include <string>
void Instruction::afficher()
{
	system("cls");
	UIKit::color(12);
	ifstream Instruction("Instruction.txt");
	if (Instruction)
	{
		string ligne;
		while (std::getline(Instruction, ligne)) 
		{
			std::cout << ligne << endl;
		}
	}
	UIKit::gotoXY(0, 30);
	system("pause");
	system("cls");
	std::cin.clear();
}
