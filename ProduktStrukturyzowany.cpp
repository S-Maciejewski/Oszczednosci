#include "stdafx.h"
#include "ProduktStrukturyzowany.h"
#include <string>

using namespace std;

ProduktStrukturyzowany::ProduktStrukturyzowany(string nazwa, double wartosc, double wklad, double roi)
        : JednostkaAktywow(nazwa, wartosc, wklad,
                           roi) {}
ProduktStrukturyzowany::ProduktStrukturyzowany() {};

// Dziedziczenie destruktora : ~JednostkaAktywow() {} nie działa?
ProduktStrukturyzowany::~ProduktStrukturyzowany() = default;

void ProduktStrukturyzowany::obliczZmianeWartosci(int ileLat) {
    for (int i = 1; i <= ileLat; i++) {
        setWartosc(getWartosc() * (1 + getRoi()));
    }
};
