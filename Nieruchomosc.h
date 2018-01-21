#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class Nieruchomosc : public JednostkaAktywow {
private:
    double przychodRoczny;


public:
    Nieruchomosc(string nazwa, double wartosc, double wklad, double roi);

	Nieruchomosc();

    ~Nieruchomosc();

    void obliczZmianeWartosci(int ileLat);

    double getPrzychodRoczny();

    void setPrzychodRoczny(double przychodRoczny);

    double getPrzychod(int ileLat);
};