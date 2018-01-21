#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class Kontrakt : public JednostkaAktywow {
private:
    double okresTrwania;

public:
    Kontrakt(string nazwa, double wartosc, double wklad, double roi, double okresTrwania);

	Kontrakt();

    ~Kontrakt();

    void obliczZmianeWartosci(int ileLat);

	double getOkresTrwania() const;

	void setOkresTrwania(double okresTrwania);
};