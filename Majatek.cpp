#include "stdafx.h"
#include "Majatek.h"

using namespace std;


Majatek::Majatek() {
	lokaty = new Aktywa<Lokata>(maxElementow);
	produkty = new Aktywa<ProduktStrukturyzowany>(maxElementow);
	iki = new Aktywa<IKE>(maxElementow);
	nieruchomosci = new Aktywa<Nieruchomosc>(maxElementow);
	kontrakty = new Aktywa<Kontrakt>(maxElementow);
	jednostkiFunduszu = new Aktywa<JednostkaFunduszu>(maxElementow);
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

string Majatek::podajNazwe()
{
	string nazwa;
	cin >> nazwa;
	return nazwa;
}

double Majatek::podajWartosc()
{
	double wartosc;
	cin >> wartosc;
	return wartosc;
}

double Majatek::obliczWartoscMajatku() {
    return 0;
}

void Majatek::dodajAktywa() {
	cout << "Wybierz rodzaj aktywow\n---------Aktywa---------\n1. Lokata\n2. Produkt strukturyzowany\n3. IKE\n4. Nieruchomosc\n5. Kontrakt terminowy\n6. Jednostka funduszu inwestycyjnego\n";
	string nazwa;
	double wklad, roi;
	int wybor;
	cin >> wybor;
	switch (wybor) {
	case 1: {	cout << "Podaj nazwe, wklad poczatkowy i zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) swojej lokaty\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		Lokata *lokata = new Lokata(nazwa, wklad, wklad, roi);
		lokaty->dodaj(lokata);
		break; }
	case 2: {	cout << "Podaj nazwe, wklad poczatkowy i zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) swojego pakiety instrumentow\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		ProduktStrukturyzowany *produkt = new ProduktStrukturyzowany(nazwa, wklad, wklad, roi);
		produkty->dodaj(produkt);
		break; }
	case 3: {	cout << "Podaj nazwe, wklad poczatkowy i zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) swojego indywidualnego konta emerytalnego\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		IKE *ike = new IKE(nazwa, wklad, wklad, roi);
		iki->dodaj(ike);
		break; }
	case 4: {	cout << "Podaj nazwe, wklad poczatkowy i zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) swojej nieruchomosci\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		Nieruchomosc *nieruchomosc = new Nieruchomosc(nazwa, wklad, wklad, roi);
		nieruchomosci->dodaj(nieruchomosc);
		break; }
	case 5: {	cout << "Podaj nazwe, wklad poczatkowy, zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) i dlugosc trwania (np. pol roku to 0.5) swojego kontraktu terminowego\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		double okres;
		cout << "Czas trwania kontraktu: ";
		okres = podajWartosc();
		Kontrakt *kontrakt = new Kontrakt(nazwa, wklad, wklad, roi, okres);
		kontrakty->dodaj(kontrakt);
		break; }
	case 6: {	cout << "Podaj nazwe, wklad poczatkowy i zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) swojego funduszu inwestycyjnego\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		JednostkaFunduszu *fundusz = new JednostkaFunduszu(nazwa, wklad, wklad, roi);
		jednostkiFunduszu->dodaj(fundusz);
		break; }
	default: break;
	}

}

void Majatek::usunAktywa() {

}

void Majatek::edytujAktywa() {

}

void Majatek::wypiszAktywa() {
	cout << "Twoje aktywa to:" << endl;
	for (int i = 0; i < lokaty->getIloscAktywow(); i++) {
		cout << "Lokata " << lokaty->getTab()[i].getNazwa() << " o wartosci " << lokaty->getTab()[i].getWartosc() << " i rocznej stopie zwrotu " << lokaty->getTab()[i].getRoi() << endl;
	}
	for (int i = 0; i < produkty->getIloscAktywow(); i++) {
		cout << "Produkt strukturyzowany " << produkty->getTab()[i].getNazwa() << " o wartosci " << produkty->getTab()[i].getWartosc() << 
			" i rocznej stopie zwrotu " << produkty->getTab()[i].getRoi() << endl;
	}
	for (int i = 0; i < iki->getIloscAktywow(); i++) {
		cout << "Indywidualne konto emerytalne " << iki->getTab()[i].getNazwa() << " o wartosci " << iki->getTab()[i].getWartosc() << " i rocznej stopie zwrotu " <<
			iki->getTab()[i].getRoi() << endl;
	}
	for (int i = 0; i < nieruchomosci->getIloscAktywow(); i++) {
		cout << "Nieruchomosc " << nieruchomosci->getTab()[i].getNazwa() << " o wartosci " << nieruchomosci->getTab()[i].getWartosc() <<
			" generujaca roczny przychod " << nieruchomosci->getTab()[i].getPrzychod(1) << endl;
	}
	for (int i = 0; i < kontrakty->getIloscAktywow(); i++) {
		cout << "Kontrakt " << kontrakty->getTab()[i].getNazwa() << " o wartosci " << kontrakty->getTab()[i].getWartosc() << ", rocznej stopie zwrotu " <<
			kontrakty->getTab()[i].getRoi() << " na okres lat " << kontrakty->getTab()[i].getOkresTrwania() << endl;
	}
	for (int i = 0; i < jednostkiFunduszu->getIloscAktywow(); i++) {
		cout << "Jednostki funduszu inwestycyjneo " << jednostkiFunduszu->getTab()[i].getNazwa() << " o wartosci " << jednostkiFunduszu->getTab()[i].getWartosc() <<
			" i rocznej stopie zwrotu " << jednostkiFunduszu->getTab()[i].getRoi() << endl;
	}
}

void Majatek::przeprowadzSymulacje() {

}
