#include "stdafx.h"
#include "JednostkaAktywow.h"
#include <string>

using namespace std;

class IKE : public JednostkaAktywow {
private:

public:
    IKE();

    IKE(string nazwa, double wartosc, double wklad, double roi);

    ~IKE();

    void obliczZmianeWartosci(int ileLat);
};