#include "stdafx.h"
#include "Kontrakt.h"
#include <string>
#include <math.h>

using namespace std;

Kontrakt::Kontrakt(string nazwa, double wartosc, double wklad, double roi, double okresTrwania) : JednostkaAktywow(
        nazwa, wartosc, wklad,
        roi) {
    setOkresTrwania(okresTrwania);
}
Kontrakt::Kontrakt() {};
// Dziedziczenie destruktora : ~JednostkaAktywow() {} nie działa?
Kontrakt::~Kontrakt() = default;

void Kontrakt::obliczZmianeWartosci(int ileLat) {
    if (ileLat >= (int) getOkresTrwania())
        setWartosc(getWartosc() * pow((1 + getRoi()), getOkresTrwania()));
    else {

    }
}

double Kontrakt::getOkresTrwania() const {
    return okresTrwania;
}

void Kontrakt::setOkresTrwania(double okresTrwania) {
    Kontrakt::okresTrwania = okresTrwania;
};