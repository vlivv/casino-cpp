#include <ctime>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Bandyta.h"
#include "Menu.h"
#include "Gra.h"
using namespace std;



int main() {

    srand(time(0));
    Gra gra;
    Menu menu;
    string imie;
    int wygrana = 0;
    int pula = gra.losuj(50, 300);
    cout << "Prosze podac imie: " << endl;
    do {
        cin >> imie;
        bool poprawneImie = true;

        for (char c : imie) {
            if (!isalpha(c)) {
                poprawneImie = false;
                break;
            }
        }

        if (!poprawneImie) {
            cout << "Wprowadzono nieprawidlowe dane. Prosze podac imie:" << endl;
        }
        else {
            break;
        }
    } while (true);

    cout << "Witaj " << imie << ". Twoja pula pieniedzy to: " << pula << "zl." << endl;


    while (true) {
        bool zakonczProgram = menu.menuGlowne(pula, wygrana);
        if (zakonczProgram) {
            break;
        }
    }

    menu.zapiszDoPliku(imie, wygrana);

}

