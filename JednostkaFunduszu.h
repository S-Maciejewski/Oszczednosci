#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class JednostkaFunduszu : public JednostkaAktywow {
private:
	double dywidenda;

public:
    JednostkaFunduszu(string nazwa, double wartosc, double wklad, double roi);

	JednostkaFunduszu();

    ~JednostkaFunduszu();

    void obliczZmianeWartosci(int ileLat);

    double getDywidenda();

    void setDywidenda(double dywidenda);

};
