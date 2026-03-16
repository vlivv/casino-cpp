
#include "Gra.h"
using namespace std;


int Gra::podajZaklad(int pula) {
        int zaklad;
        do {
            cout << "Podaj wartosc zakladu:" << endl;

            if (!(cin >> zaklad)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Wprowadzono zla wartosc. Sprobuj jeszcze raz." << endl;
                continue;
            }

            if (zaklad <= 0) {
                cout << "Wprowadzono zla wartosc. Sprobuj jeszcze raz." << endl;
            } else if (zaklad > pula) {
                cout << "Nie masz wystarczajaco pieniedzy, podaj nizsza kwote." << endl;
            }

        } while (zaklad <= 0 || zaklad > pula);

        return zaklad;
    }



    int Gra::podajLiczbe(int min, int max) {
        int liczba;
        while (true) {
            if (cin >> liczba && liczba >= min && liczba <= max) {
                return liczba;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Wprowadzono nieprawidlowe dane. Sprobuj jeszcze raz.\n";
            }
        }
    }

    int Gra::losuj(int min, int max) {

        return rand() % (max - min + 1) + min;
    }
