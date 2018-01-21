#include "stdafx.h"
#include "Nieruchomosc.h"
#include <time.h>

using namespace std;

Nieruchomosc::Nieruchomosc(string nazwa, double wartosc, double wklad, double roi) : JednostkaAktywow(nazwa, wartosc,
                                                                                                      wklad,
                                                                                                      roi) {
    setPrzychodRoczny(wklad * roi);
}
Nieruchomosc::Nieruchomosc() {};

// Dziedziczenie destruktora : ~JednostkaAktywow() {} nie działa?
Nieruchomosc::~Nieruchomosc() = default;


//Zakładam losową zmianę wartości nieruchomości
void Nieruchomosc::obliczZmianeWartosci(int ileLat) {
    srand(time(NULL));
    for (int i = 1; i <= ileLat; i++) {
        setWartosc(getWartosc() * (1 + (1. / (rand() % 100 + 1) - (1. / (rand() % 100 + 1)))));
    }
}

double Nieruchomosc::getPrzychodRoczny() {
    return przychodRoczny;
}

//Zakładam przychód roczny powiązany ze zwrotem z inwestycji
void Nieruchomosc::setPrzychodRoczny(double przychodRoczny) {
    Nieruchomosc::przychodRoczny = przychodRoczny;
}

double Nieruchomosc::getPrzychod(int ileLat) {
    return ileLat * getPrzychodRoczny();
};
