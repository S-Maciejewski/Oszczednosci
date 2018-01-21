//#ifndef KALKULATOROSZCZEDNOSCI_JEDNOSTKAAKTYWOW_H
//#define KALKULATOROSZCZEDNOSCI_JEDNOSTKAAKTYWOW_H
//#endif //KALKULATOROSZCZEDNOSCI_JEDNOSTKAAKTYWOW_H
#include "stdafx.h"
#pragma once

#include<string>

using namespace std;

class JednostkaAktywow {
private:
    string nazwa;
    double wartosc, wklad;
    double roi;    //return on investment 0.0....1.0

public:
    JednostkaAktywow();

    JednostkaAktywow(string nazwa, double wartosc, double wklad, double roi);

    ~JednostkaAktywow();

    string getNazwa();

    double getWartosc();

    double getWklad();

    void setWartosc(double wartosc);

    double getRoi();

    virtual void obliczZmianeWartosci(int ileLat) = 0;

};
