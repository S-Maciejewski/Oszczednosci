#include "stdafx.h"
#include "Lokata.h"

using namespace std;

Lokata::Lokata(string nazwa, double wartosc, double wklad, double roi) : JednostkaAktywow(nazwa, wartosc, wklad,
                                                                                          roi) {}
Lokata::Lokata() {};

// Dziedziczenie destruktora : ~JednostkaAktywow() {} nie działa?
Lokata::~Lokata() = default;

void Lokata::obliczZmianeWartosci(int ileLat) {
    for (int i = 1; i <= ileLat; i++) {
        setWartosc(getWartosc()*(1+getRoi()));
    }
};
