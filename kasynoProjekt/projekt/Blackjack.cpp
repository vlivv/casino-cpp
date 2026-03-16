

#include "Blackjack.h"



 int Blackjack::randomKarta() {
        int losowa = rand() % 13 + 1;
        if (losowa >= 10) {
            return 10;
        } else if (losowa == 1) {
            return 11;
        } else {
            return losowa;
        }
    }

    void Blackjack::graWBlackjacka(int &pula, int &wygrana) {
        int wybor;
        do {
            int zaklad = podajZaklad(pula);

            int karta1Gracza = randomKarta();
            int karta2Gracza = randomKarta();
            int kartaKrupiera = randomKarta();

            int kartyGracza = karta1Gracza + karta2Gracza;
            int kartyKrupiera = kartaKrupiera;

            cout << "Twoje karty: " << karta1Gracza << " i " << karta2Gracza << " (Suma: " << kartyGracza << ")" << endl;
            cout << "Karta krupiera: " << kartaKrupiera << endl;

            if (kartyGracza == 21) {
                cout << "Masz blackjacka! Wygrywasz podwojny zaklad: " << zaklad * 2 << " zl." << endl;
                pula += zaklad * 2;
                wygrana += zaklad * 2;
                cout << "Wybierz opcje: \n1. Zagraj jeszcze raz\n2. Powrot do menu glownego" << endl;
                wybor = podajLiczbe(1, 2);
                if (wybor == 2) break;
                else continue;
            }


            while (true) {
                cout << "\nDobrac karte? (1 - tak, 0 - nie)" << endl;
                wybor = podajLiczbe(0, 1);

                if (wybor == 1) {
                    int nowaKarta = randomKarta();
                    kartyGracza += nowaKarta;

                    cout << "Dobrano karte: " << nowaKarta << " (suma: " << kartyGracza << ")" << endl;

                    if (kartyGracza > 21) {
                        cout << "Twoja suma przekroczyla 21 punktow, przegrales/as " << zaklad << " zl." << endl;
                        pula -= zaklad;
                        wygrana -= zaklad;
                        break;
                    }

                    if (kartyGracza == 21) {
                        break;
                    }
                } else {
                    break;
                }
            }

            if (kartyGracza <= 21) {
                while (kartyKrupiera < 17) {
                    int nowaKartaKrupiera = randomKarta();
                    kartyKrupiera += nowaKartaKrupiera;
                }

                cout << "Wynik krupiera: " << kartyKrupiera << endl;

                if (kartyKrupiera > 21 || kartyGracza > kartyKrupiera) {
                    cout << "Gratulacje, wygrales/as " << zaklad * 2 << " zl!" << endl;
                    pula += zaklad * 2;
                    wygrana += zaklad * 2;
                } else if (kartyGracza == kartyKrupiera) {
                    cout << "Remis! Twoja pula pozostaje bez zmian." << endl;
                } else {
                    cout << "Przeciwnik wygrywa, straciles/as: " << zaklad << " zl." << endl;
                    pula -= zaklad;
                    wygrana -= zaklad;
                }
            }

            cout << "Twoja obecna pula wynosi " << pula << " zl." << endl;
            if (pula <= 0) {
                cout << "Nie masz wystarczajacej ilosci pieniedzy, koniec gry!" << endl;
                break;
            }

            cout << "Wybierz opcje: \n1. Zagraj jeszcze raz\n2. Powrot do menu glownego" << endl;
            wybor = podajLiczbe(1, 2);
        } while (wybor == 1);
    }


