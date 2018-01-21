//#ifndef KALKULATOROSZCZEDNOSCI_PRODUKTSTRUKTURYZOWANY_H
//#define KALKULATOROSZCZEDNOSCI_PRODUKTSTRUKTURYZOWANY_H
//#endif KALKULATOROSZCZEDNOSCI_PRODUKTSTRUKTURYZOWANY_H
#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class ProduktStrukturyzowany : public JednostkaAktywow {
private:

public:
    ProduktStrukturyzowany(string nazwa, double wartosc, double wklad, double roi);

    ~ProduktStrukturyzowany();

    void obliczZmianeWartosci(int ileLat);
};