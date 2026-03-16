

#include "Menu.h"

#include "Bandyta.h"
#include "Blackjack.h"
#include "Ruletka.h"
using namespace std;

string imie;
int wygrana;

void Menu::zapiszDoPliku(const string &imie, int wygrana) {
    ofstream plik("topGracze.txt", ios::app);
    if (plik.is_open()) {
        plik << imie << " " << wygrana << endl;
        plik.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku do zapisu." << endl;
    }
}

void Menu::wyswietlTop100() {
    ifstream plik("topGracze.txt");
    vector<pair<int, string>> gracze;

    if (plik.is_open()) {
        while (plik >> imie >> wygrana) {
            gracze.emplace_back(wygrana, imie);
        }
        plik.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku do odczytu." << endl;
        return;
    }

    sort(gracze.rbegin(), gracze.rend());

    cout << "TOP 100 Graczy:" << endl;
    for (size_t i = 0; i < min(gracze.size(), size_t(100)); ++i) {
        cout << i + 1 << ". " << gracze[i].second << " - " << gracze[i].first << " zl" << endl;
    }
}


bool Menu::menuGlowne(int &pula, int &wygrana) {


    Bandyta bandyta;
    Blackjack blackjack;
    Ruletka ruletka;
    Gra gra;
    int numer;
    if (pula == 0) {
        cout << "Nie masz srodkow, aby grac dalej." << endl;
        do {
            cout << "Wybierz jedna z ponizszych opcji:\n1. Wyswietl TOP 100 graczy\n0. Wyjscie" << endl;
            numer = gra.podajLiczbe(0,1);

            switch (numer) {
                case 1:
                    gra.wyswietlTop100();
                break;
                case 0:
                    cout << "Do zobaczenia!" << endl;
                return true;
                default:
                    cout << "Wybierz jedna z ponizszych opcji!" << endl;
                break;
            }
        } while (numer != 0);
    }


    cout << "Wybierz stanowisko:\n1. Stanowisko do Blackjacka\n2. Stanowisko do jednorekiego bandyty\n3. Stanowisko do ruletki\n4. Wyswietl TOP 100 graczy\n0. Wyjscie" << endl;



    numer = gra.podajLiczbe(0,4);



    switch (numer) {
        case 1:
            cout << "Wybrales/as stanowisko do Blackjacka." << endl;
        blackjack.graWBlackjacka(pula, wygrana);
        break;
        case 2:
            cout << "Wybrales/as stanowisko do jednorekiego bandyty." << endl;
        bandyta.graWBandyte(pula, wygrana);
        break;
        case 3:
            cout << "Wybrales/as stanowisko do ruletki." << endl;
        ruletka.graWRuletke(pula, wygrana);
        break;
        case 4:
            wyswietlTop100();
        break;
        case 0:
            cout << "Do zobaczenia!" << endl;
        return true;
        default:
            cout << "Wybierz jedna z ponizszych opcji!" << endl;
        break;
    } return false;

}
