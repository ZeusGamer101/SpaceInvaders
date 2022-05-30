#include <iostream>
#include "Partie.h"
#include "Menu.h"
#include "UIKit.h"
#include "Instruction.h"
#include <conio.h>
#include "README.h"
#include "ScoreBoard.h"
using namespace std;
int main() {
	//Démare une seule partie, la joue et la supprime immédiatement lorsqu'elle est terminée
	Menu menu;
	bool play = true;
	PlaySound(TEXT("MainMenu"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	do {
		UIKit::setDimensionFenetre(0, 0, 71, 31);
		UIKit::setDimensionFenetre(0, 0, 71, 31);
		menu.afficher();
		system("pause");
		system("cls");
		if (GetAsyncKeyState(VK_RETURN)) {
			Partie* partie = new Partie();
			partie->debuter();
			delete partie;
		}
		if (GetAsyncKeyState(0x4D)) {
			if (play == true) {
				play = false;
				PlaySound(NULL, NULL, SND_SYNC);
			}
			else {
				play = true;
				PlaySound(TEXT("MainMenu"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			}
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			Instruction::afficher();
		}
		if (GetAsyncKeyState(VK_BACK)) {
			README::afficher();
		}
		if (GetAsyncKeyState(0x53)) {
			ScoreBoard::afficher();
		}
	} while (!GetAsyncKeyState(VK_ESCAPE));
	return 0;
}