
#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;

class Menu {
public:
    void wyswietlTop100();
    void zapiszDoPliku(const string &imie, int wygrana);
    bool menuGlowne(int &pula, int &wygrana);

};



#endif //MENU_H
