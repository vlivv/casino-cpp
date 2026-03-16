
#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Gra.h"



class Blackjack : public Gra {
public:
    int randomKarta();
    void graWBlackjacka(int &pula, int &wygrana);

};



#endif //BLACKJACK_H
