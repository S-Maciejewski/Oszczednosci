//#ifndef KALKULATOROSZCZEDNOSCI_JEDNOSTKIFUNDUSZU_H
//#define KALKULATOROSZCZEDNOSCI_JEDNOSTKIFUNDUSZU_H
//#endif KALKULATOROSZCZEDNOSCI_JEDNOSTKIFUNDUSZU_H
#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class JednostkaFunduszu : public JednostkaAktywow {
private:
    double dywidenda;   //0.0....1.0

public:
    JednostkaFunduszu(string nazwa, double wartosc, double wklad, double roi);

    ~JednostkaFunduszu();

    void obliczZmianeWartosci(int ileLat);

    double getDywidenda();

    void setDywidenda(double dywidenda);

    //double obliczDywidendy(int ileLat);
};
