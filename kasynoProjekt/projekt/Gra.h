
#ifndef GRA_H
#define GRA_H
#include <iostream>
#include <limits>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "Menu.h"

using namespace std;

class Gra : public Menu {
public:
    int podajZaklad(int pula);
    int podajLiczbe(int min, int max);
    int losuj(int min, int max);

};



#endif //GRA_H
