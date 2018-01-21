#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class ProduktStrukturyzowany : public JednostkaAktywow {
private:

public:
    ProduktStrukturyzowany(string nazwa, double wartosc, double wklad, double roi);

	ProduktStrukturyzowany();

    ~ProduktStrukturyzowany();

    void obliczZmianeWartosci(int ileLat);
};