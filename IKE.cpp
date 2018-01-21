#include "stdafx.h"
#include "IKE.h"
#include <string>

using namespace std;

IKE::IKE() {};

IKE::IKE(string nazwa, double wartosc, double wklad, double roi) : JednostkaAktywow(nazwa, wartosc, wklad, roi) {};

// Dziedziczenie destruktora : ~JednostkaAktywow() {} nie działa?
IKE::~IKE() = default;

void IKE::obliczZmianeWartosci(int ileLat) {
    for (int i = 1; i <= ileLat; i++) {
        setWartosc(getWartosc() * (1 + getRoi()));
    }
};
