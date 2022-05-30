#include "ScoreBoard.h"
#include <fstream>
#include "UIKit.h"
#include <string>
#include<vector>
#include <algorithm>   
void ScoreBoard::afficher()
{
	system("cls");
	UIKit::color(11);
	//ifstream ScoreBoard("Score.txt");
	//if (ScoreBoard)
	//{
	//	string ligne;
	//	while (std::getline(ScoreBoard, ligne))
	//	{
	//		std::cout << ligne << endl;
	//	}
	//}

	// declaring variables
	std::string const scoreboard("Score.txt");
	std::string line;

	// putting hand on file to read
	ifstream fileToRead(scoreboard.c_str());

	//  list of int (scores)
	vector<int> scoresFromText;

	// itirate trough file if you have lines 
	if (fileToRead.is_open())
	{
		while (getline(fileToRead, line))
		{
			int s = line.find(":");
			string sub = line.substr(s + 1);
			int score = std::atoi(sub.c_str());
			/*cout << line.size() << '\n';*/
			scoresFromText.push_back(score);
		}
		fileToRead.close();
	}

	else cout << "Unable to open file";

	// sort list descending
	std::sort(scoresFromText.begin(), scoresFromText.end(), greater <>());

	// show top 10 scores on screen
	for (int i = 0; i < 10; i++) {
		cout << "Score : " << scoresFromText[i] << '\n';
	}
	UIKit::gotoXY(0, 30);
	system("pause");
	system("cls");
	std::cin.clear();
}
