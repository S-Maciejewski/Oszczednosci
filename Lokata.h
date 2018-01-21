#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class Lokata : public JednostkaAktywow {
private:

public:
    Lokata(string nazwa, double wartosc, double wklad, double roi);

	Lokata();

    ~Lokata();

    void obliczZmianeWartosci(int ileLat);
};