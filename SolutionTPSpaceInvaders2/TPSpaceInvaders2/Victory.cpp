#include "Victory.h"
#include <iostream>
#include "UIKit.h"
#include <fstream>
#include <string>
#include<vector>
#include <algorithm>    
void Victory::afficher(long long score)
{
	system("cls");
	cin.clear();
	fflush(stdin);
	PlaySound(TEXT("Victory"), NULL, SND_ASYNC | SND_FILENAME);
	UIKit::color(11);
	const int buffer = 500;
	UIKit::gotoXY(2, 5);
	Sleep(buffer);
	std::cout << "          _________ _______ _________ _______  _______           _  " << std::endl;
	UIKit::gotoXY(2, 6);
	Sleep(buffer);
	std::cout << " |\\     /|\\__   __/(  ____ \\\\__   __/(  ___  )(  ____ )|\\     /|( ) " << std::endl;
	UIKit::gotoXY(2, 7);
	Sleep(buffer);
	std::cout << " | )   ( |   ) (   | (    \\/   ) (   | (   ) || (    )|( \\   / )| |" << std::endl;
	UIKit::gotoXY(2, 8);
	Sleep(buffer);
	std::cout << " | |   | |   | |   | |         | |   | |   | || (____)| \\ (_) / | | " << std::endl;
	UIKit::gotoXY(2, 9);
	Sleep(buffer);
	std::cout << " ( (   ) )   | |   | |         | |   | |   | ||     __)  \\   /  | | " << std::endl;
	UIKit::gotoXY(2, 10);
	Sleep(buffer);
	std::cout << "  \\ \\_/ /    | |   | |         | |   | |   | || (\\ (      ) (   (_) " << std::endl;
	UIKit::gotoXY(2, 11);
	Sleep(buffer);
	std::cout << "   \\   /  ___) (___| (____/\\   | |   | (___) || ) \\ \\__   | |    _  " << std::endl;
	UIKit::gotoXY(2, 12);
	Sleep(buffer);
	std::cout << "    \\_/   \\_______/(_______/   )_(   (_______)|/   \\__/   \\_/   (_) " << std::endl;
	UIKit::gotoXY(30, 18);
	std::cout << "Score : " << score;
	std::string const scoreboard("Score.txt");
	ofstream file(scoreboard.c_str(), ios::app);
	if (file) {
		file << "Score : " << score << endl;
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
	//}
	//std::string line;
	//ifstream fileToRead(scoreboard.c_str());
	//vector<int> scoresFromText;
	//if (file.is_open())
	//{
	//	while (getline(fileToRead, line))
	//	{
	//		int s = line.find(":");
	//		string sub = line.substr(s + 1);
	//		int score = std::atoi(sub.c_str());
	//		/*cout << line.size() << '\n';*/
	//		scoresFromText.push_back(score);
	//	}
	//	fileToRead.close();
	//}

	//else cout << "Unable to open file";

	//std::sort(scoresFromText.begin(), scoresFromText.end(), greater <>());
	//for (int i = 0; i < scoresFromText.size(); i++) {
	//	cout << scoresFromText[i] << '\n';
	//}
	UIKit::gotoXY(20, 20);
	system("pause");


}
