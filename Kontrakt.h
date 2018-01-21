//#ifndef KALKULATOROSZCZEDNOSCI_KONTRAKT_H
//#define KALKULATOROSZCZEDNOSCI_KONTRAKT_H
//#endif KALKULATOROSZCZEDNOSCI_KONTRAKT_H
#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class Kontrakt : public JednostkaAktywow {
private:
    double okresTrwania;
public:
    double getOkresTrwania() const;

    void setOkresTrwania(double okresTrwania);

public:
    Kontrakt(string nazwa, double wartosc, double wklad, double roi, double okresTrwania);

    ~Kontrakt();

    void obliczZmianeWartosci(int ileLat);
};