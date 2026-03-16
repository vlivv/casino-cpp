

#include "Ruletka.h"
using namespace std;
  void Ruletka::graWRuletke(int &pula, int &wygrana) {
      int zaklad, liczba, wybor;


    do {
        cout << "Wybierz rodzaj zakladu:\n1. Liczba\n2. Kolor (czerwony/czarny)\n3. Parzyste/Nieparzyste" << endl;
        cout << "4. Niskie/Wysokie\n5. Tuzin\n6. Kolumna\n0. Wyjdz" << endl;
        int decyzja = podajLiczbe(0,6);
        if (decyzja == 1) {
            zaklad = podajZaklad(pula);
            int pole = losuj(0, 36);
            cout << "Podaj liczbe od 0 do 36:\n";
            liczba = podajLiczbe(0,36);
            if(liczba==pole)
            {
                zaklad = zaklad * 36;
                cout << "Kulka wyladowala na " << pole << ".\n";
                cout << "Gratulacje! Wygrales/as " << zaklad << "zl!" << endl;
                pula += zaklad;
                wygrana += zaklad;
            }
            else
            {
                cout << "Kulka wyladowala na " << pole << ".\n";
                cout << "Niestety, przegrales/as " << zaklad << "zl." << endl;
                pula -= zaklad;
                wygrana -= zaklad;
            }
        }

        else if (decyzja == 2) {
            zaklad = podajZaklad(pula);
            int kolor = losuj(1,2);
            cout << "Wybierz kolor (1 = czerwony, 2 = czarny):\n";
            liczba = podajLiczbe(1,2);
            if(liczba==kolor) {
                cout << "Gratulacje! Wygrales/as " << zaklad << "zl!" << endl;
                pula += zaklad;
                wygrana += zaklad;;
            }
            else
            {
                cout << "Niestety, przegrales/as " << zaklad << "zl." << endl;
                pula -= zaklad;
                wygrana -= zaklad;
            }
        }



        else if (decyzja == 3) {
            zaklad = podajZaklad(pula);
            int parzystosc = losuj(1,2);
            cout << "Wybierz opcje (1 = parzyste, 2 = nieparzyste):\n";
            liczba = podajLiczbe(1,2);
            if(liczba==parzystosc) {
                cout << "Gratulacje! Wygrales/as " << zaklad << "zl!" << endl;
                pula += zaklad;
                wygrana += zaklad;;
            }
            else
            {
                cout << "Niestety, przegrales/as " << zaklad << "zl." << endl;
                pula -= zaklad;
                wygrana -= zaklad;
            }
        }

        else if (decyzja == 4) {
            zaklad = podajZaklad(pula);
            int wynik = losuj(1,2);
            cout << "Wybierz opcje (1 = niskie (1-18), 2 = wysokie (19-36): " << endl;
            liczba = podajLiczbe(1,2);
            if(liczba==wynik) {
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
        }



        else if (decyzja == 5)
        {
            zaklad = podajZaklad(pula);
            int wynik = losuj(1,3);
            cout << "Wybierz tuzin (1 = 1-12, 2 = 13-24, 3 = 25-36): " << endl;
            liczba = podajLiczbe(1,3);
            if(wynik==liczba) {
                zaklad = 2 * zaklad;
                cout << "Gratulacje! Wygrales/as " << zaklad << "zl!" << endl;
                pula += zaklad;
                wygrana += zaklad;;
            }
            else
            {
                cout << "Niestety, przegrales/as " << zaklad << "zl." << endl;
                pula -= zaklad;
                wygrana -= zaklad;
            }
        }


        else if (decyzja == 6)
        {
            zaklad = podajZaklad(pula);
            int kolumna = losuj(1,3);
            cout << "Wybierz kolumne (1, 2, 3): " << endl;
            liczba = podajLiczbe(1,3);
            if(kolumna==liczba) {
                zaklad = 2 * zaklad;
                cout << "Gratulacje! Wygrales/as " << zaklad << "zl!" << endl;
                pula += zaklad;
                wygrana += zaklad;;
            }
            else
            {
                cout << "Niestety, przegrales/as " << zaklad << "zl." << endl;
                pula -= zaklad;
                wygrana -= zaklad;
            }
        }


        else if (decyzja == 0)
        {
            break;
        }

        cout << "Twoja obecna pula wynosi " << pula << "zl." << endl;
        if (pula <= 0) {
            break;
        }

            cout << "Wybierz opcje: \n1. Zagraj jeszcze raz\n2. Powrot do menu glownego " << endl;
            wybor = podajLiczbe(1,2);

        if(wybor==2) {
            break;
        }




    } while (wybor == 1);
}

