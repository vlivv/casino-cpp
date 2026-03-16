
#include "Bandyta.h"


void Bandyta::graWBandyte(int &pula, int &wygrana) {
    int zaklad;
    int wybor;
    do {
        zaklad = podajZaklad(pula);


        int wynik1 = losuj(1,9);
        int wynik2 = losuj(1,9);
        int wynik3 = losuj(1,9);

        cout << "Wyniki losowania: " << wynik1 << " " << wynik2 << " " << wynik3 << endl;

        if (wynik1 == wynik2 && wynik2 == wynik3)
        {
            zaklad = zaklad*4;
            cout << "Gratulacje! Wygrales/as " << zaklad << "zl!" << endl;
            pula += zaklad;
            wygrana += zaklad;
        }
        else
        {
            cout << "Niestety, przegrales/as " << zaklad << "zl." << endl;
            pula -= zaklad;
            wygrana -= zaklad;
        }


        cout << "Twoja obecna pula wynosi " << pula << "zl." << endl;
        if (pula <= 0) {
            break;
        }


        cout << "Wybierz opcje: \n1. Zakrec jeszcze raz\n2. Powrot do menu glownego " << endl;
        wybor = podajLiczbe(1,2);
        if (wybor == 2) {
            break;
        }


    } while (wybor == 1);
}

