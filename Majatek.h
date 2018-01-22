#include "stdafx.h"
#include <iostream>
#include <string>
#include "JednostkaAktywow.h"
#include "Lokata.h"
#include "ProduktStrukturyzowany.h"
#include "IKE.h"
#include "Nieruchomosc.h"
#include "Kontrakt.h"
#include "JednostkaFunduszu.h"
#include "Aktywa.h"

using namespace std;

class Majatek {
private:
	Aktywa<Lokata> *lokaty;
	Aktywa<ProduktStrukturyzowany> *produkty;
	Aktywa<IKE> *iki;
	Aktywa<Nieruchomosc> *nieruchomosci;
	Aktywa<Kontrakt> *kontrakty;
	Aktywa<JednostkaFunduszu> *jednostkiFunduszu;
	int maxElementow = 10;	//Wiêcej elementów dostêpnych jest w wersji "Oszczedzanie jak marzenie - Deluxe Premium Platinum"

	string podajNazwe();

	double podajWartosc();
public:
    Majatek();

    ~Majatek();

    double obliczWartoscMajatku();

    void dodajAktywa();

    void usunAktywa();

    void edytujAktywa();

    void wypiszAktywa();

    void przeprowadzSymulacje();
};