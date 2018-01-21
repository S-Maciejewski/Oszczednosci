#include "stdafx.h"
#include "JednostkaFunduszu.h"
#include <time.h>
#include <math.h>

using namespace std;

JednostkaFunduszu::JednostkaFunduszu(string nazwa, double wartosc, double wklad, double roi)
        : JednostkaAktywow(nazwa, wartosc, wklad,
                           roi) {
    setDywidenda(roi);
}
JednostkaFunduszu::JednostkaFunduszu() {};

// Dziedziczenie destruktora : ~JednostkaAktywow() {} nie działa?
JednostkaFunduszu::~JednostkaFunduszu() = default;


// Zakładam losowe zmiany wartości jednostek uczestnictwa i kapitalizację dywidend w postaci nowych jednostek uczestnictwa
void JednostkaFunduszu::obliczZmianeWartosci(int ileLat) {
    srand(time(NULL));
    for (int i = 1; i <= ileLat; i++) {
        setWartosc(getWartosc() * (1 + (1. / (rand() % 100 + 1) - (1. / (rand() % 100 + 1)))));
        setWartosc(getWartosc() + (1. + getWartosc() * getDywidenda()));
    }
}

double JednostkaFunduszu::getDywidenda() {
    return dywidenda;
}

void JednostkaFunduszu::setDywidenda(double dywidenda) {
    JednostkaFunduszu::dywidenda = dywidenda;
}

//double JednostkaFunduszu::obliczDywidendy(int ileLat) {
//    return getWklad() * pow(1. + getDywidenda(), ileLat);
//};

