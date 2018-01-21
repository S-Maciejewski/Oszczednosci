//#ifndef KALKULATOROSZCZEDNOSCI_LOKATA_H
//#define KALKULATOROSZCZEDNOSCI_LOKATA_H
//#endif KALKULATOROSZCZEDNOSCI_LOKATA_H
#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class Lokata : public JednostkaAktywow {
private:

public:
    Lokata(string nazwa, double wartosc, double wklad, double roi);

    ~Lokata();

    void obliczZmianeWartosci(int ileLat);
};