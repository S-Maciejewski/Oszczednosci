#include "stdafx.h"
#include "Majatek.h"

using namespace std;

Majatek::Majatek() {
	Aktywa<Lokata> *lokaty = new Aktywa<Lokata>(maxElementow);
	Aktywa<ProduktStrukturyzowany> *produkty = new Aktywa<ProduktStrukturyzowany>(maxElementow);
	Aktywa<IKE> *iki = new Aktywa<IKE>(maxElementow);
	Aktywa<Nieruchomosc> *nieruchomosci = new Aktywa<Nieruchomosc>(maxElementow);
	Aktywa<Kontrakt> *kontrakty = new Aktywa<Kontrakt>(maxElementow);
	Aktywa<JednostkaFunduszu> *jednostkiFunduszu = new Aktywa<JednostkaFunduszu>(maxElementow);
}

Majatek::~Majatek() = default;

//Majatek::~Majatek() {
//	delete lokaty;
//	delete produkty;
//	delete iki;
//	delete nieruchomosci;
//	delete kontrakty;
//	delete jednostkiFunduszu;
//}

double Majatek::obliczWartoscMajatku() {
    return 0;
}

void Majatek::dodajAktywa() {
	cout << "Wybierz rodzaj aktywow\n---------Aktywa---------\n1. Lokata\n2. Produkt strukturyzowany\n3. IKE\n4. Nieruchomosc\n5. Kontrakt terminowy\n6. Jednostka funduszu inwestycyjnego\n";
	int wybor;
	cin >> wybor;
	switch (wybor) {
	case 1:	break;
	case 2:	break;
	case 3:	break;
	case 4:	break;
	case 5:	break;
	case 6:	break;
	default: break;
	}

}

void Majatek::usunAktywa() {

}

void Majatek::edytujAktywa() {

}

void Majatek::wypiszAktywa() {

}

void Majatek::przeprowadzSymulacje() {

}
