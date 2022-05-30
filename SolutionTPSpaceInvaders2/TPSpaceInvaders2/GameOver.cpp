#include "GameOver.h"
#include <iostream>
#include "UIKit.h"
#include <fstream>
#include <string>
void GameOver::afficher(long long score)
{
    system("cls");
    cin.clear();
    fflush(stdin);
    PlaySound(TEXT("GameOverSoundEffect"), NULL, SND_ASYNC | SND_FILENAME);
    UIKit::color(10);
    UIKit::gotoXY(5,5);
    const int buffer = 820;
    std::cout << "   ________                                                   " << std::endl;
    UIKit::gotoXY(5, 6);
    Sleep(buffer);
    std::cout << "  /  _____/_____    _____   ____     _______  __ ___________  " << std::endl;
    UIKit::gotoXY(5, 7);
    Sleep(buffer);
    std::cout << " /   \\  ___\\__  \\  /     \\_/ __ \\   /  _ \\  \\/ // __ \\_  __ \\ " << std::endl;
    UIKit::gotoXY(5, 8);
    Sleep(buffer);
    std::cout << " \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  (  <_> )   /\\  ___/|  | \\/ " << std::endl;
    UIKit::gotoXY(5, 9);
    Sleep(buffer);
    std::cout << "  \\______  (____  /__|_|  /\\___  >  \\____/ \\_/  \\___  >__|    " << std::endl;
    UIKit::gotoXY(5, 10);
    Sleep(buffer);
    std::cout << "         \\/     \\/      \\/     \\/                   \\/        " << std::endl;
    Sleep(buffer);
    UIKit::gotoXY(30, 18);
    std::cout << "Score : " << score;
    UIKit::gotoXY(20, 20);
    system("pause");
}
 