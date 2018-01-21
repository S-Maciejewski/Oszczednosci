//#ifndef KALKULATOROSZCZEDNOSCI_NIERUCHOMOSC_H
//#define KALKULATOROSZCZEDNOSCI_NIERUCHOMOSC_H
//#endif KALKULATOROSZCZEDNOSCI_NIERUCHOMOSC_H
#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class Nieruchomosc : public JednostkaAktywow {
private:
    double przychodRoczny;


public:
    Nieruchomosc(string nazwa, double wartosc, double wklad, double roi);

    ~Nieruchomosc();

    void obliczZmianeWartosci(int ileLat);

    double getPrzychodRoczny();

    void setPrzychodRoczny(double przychodRoczny);

    double getPrzychod(int ileLat);
};