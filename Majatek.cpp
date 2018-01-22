#include "stdafx.h"
#include "Majatek.h"
#include<fstream>

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

template<class T>
double obliczWartosc(Aktywa<T> *aktywa, int ileLat) {
	double wartosc = 0;
	if (ileLat == 0) {
		for (int i = 0; i < aktywa->getIloscAktywow(); i++) {
			wartosc += aktywa->getTab()[i].getWartosc();
		}
	}
	else {
		for (int i = 0; i < aktywa->getIloscAktywow(); i++) {
			aktywa->getTab()[i].obliczZmianeWartosci(ileLat);
			wartosc += aktywa->getTab()[i].getWartosc();
		}
	}

	return wartosc;
}

double Majatek::obliczWartoscMajatku(int ileLat) {
	double wartosc = 0;
	wartosc += obliczWartosc<Lokata>(lokaty, ileLat);
	wartosc += obliczWartosc<ProduktStrukturyzowany>(produkty, ileLat);
	wartosc += obliczWartosc<IKE>(iki, ileLat);
	wartosc += obliczWartosc<Nieruchomosc>(nieruchomosci, ileLat);
	wartosc += obliczWartosc<Kontrakt>(kontrakty, ileLat);
	wartosc += obliczWartosc<JednostkaFunduszu>(jednostkiFunduszu, ileLat);

	return wartosc;
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
		*lokaty+=lokata;
		break; }
	case 2: {	cout << "Podaj nazwe, wklad poczatkowy i zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) swojego pakiety instrumentow\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		ProduktStrukturyzowany *produkt = new ProduktStrukturyzowany(nazwa, wklad, wklad, roi);
		*produkty+=produkt;
		break; }
	case 3: {	cout << "Podaj nazwe, wklad poczatkowy i zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) swojego indywidualnego konta emerytalnego\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		IKE *ike = new IKE(nazwa, wklad, wklad, roi);
		*iki+=ike;
		break; }
	case 4: {	cout << "Podaj nazwe, wklad poczatkowy i zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) swojej nieruchomosci\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		Nieruchomosc *nieruchomosc = new Nieruchomosc(nazwa, wklad, wklad, roi);
		*nieruchomosci+=nieruchomosc;
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
		*kontrakty+=kontrakt;
		break; }
	case 6: {	cout << "Podaj nazwe, wklad poczatkowy i zwrot z inwestycji (jako liczbe, np. 4% zwrotu to 0.04) swojego funduszu inwestycyjnego\nNazwa: ";
		nazwa = podajNazwe();
		cout << "Wklad poczatkowy: ";
		wklad = podajWartosc();
		cout << "Szacowany roczny zwrot z inwestycji: ";
		roi = podajWartosc();
		JednostkaFunduszu *fundusz = new JednostkaFunduszu(nazwa, wklad, wklad, roi);
		*jednostkiFunduszu+=fundusz;
		break; }
	default: break;
	}

}

template<class T>
void usun(Aktywa<T> *aktywa) {
	int element;
	cout << "Obiekty, ktore mozesz usunac:" << endl;
	for (int i = 0; i < aktywa->getIloscAktywow(); i++) {
		cout << i << ". nazwa: " << aktywa->getTab()[i].getNazwa() << ", wartosc: " << aktywa->getTab()[i].getWartosc() << endl;
	}
	cout << "Wpisz numer elementu, ktory ma zostac usuniety: ";
	cin >> element;
	*aktywa -= element;
	cout << "Element zostal usuniety";
}

void Majatek::usunAktywa() {
	cout << "Wybierz rodzaj aktywow\n---------Aktywa---------\n1. Lokata\n2. Produkt strukturyzowany\n3. IKE\n4. Nieruchomosc\n5. Kontrakt terminowy\n6. Jednostka funduszu inwestycyjnego\n";
	int wybor;
	cin >> wybor;
	switch (wybor) {
	case 1: {
		usun<Lokata>(lokaty);
		break;
	}
	case 2: {
		usun<ProduktStrukturyzowany>(produkty);
		break;
	}
	case 3: {
		usun<IKE>(iki);
		break;
	}
	case 4: {
		usun<Nieruchomosc>(nieruchomosci);
		break;
	}
	case 5: {
		usun<Kontrakt>(kontrakty);
		break;
	}
	case 6: {
		usun<JednostkaFunduszu>(jednostkiFunduszu);
		break;
	}
	default: break;
	}
}

template<class T>
void edytuj(Aktywa<T> *aktywa) {
	int element, pole;
	cout << "Obiekty, ktore mozesz edytowac:" << endl;
	for (int i = 0; i < aktywa->getIloscAktywow(); i++) {
		cout << i << ". nazwa: " << aktywa->getTab()[i].getNazwa() << ", wartosc: " << aktywa->getTab()[i].getWartosc() << endl;
	}
	cout << "Wpisz numer elementu, ktory chcesz edytowac: ";
	cin >> element;
	cout << "Co chcesz edytowac?\n1. Nazwe\n2. Wartosc\n3. Roczna stope zwrotu" << endl;
	cin >> pole;
	switch (pole)
	{
	case 1: cout << "Nazwa: ";	aktywa->getTab()[element].setNazwa(Majatek::podajNazwe()); break;
	case 2: cout << "Wartosc: "; aktywa->getTab()[element].setWartosc(Majatek::podajWartosc()); break;
	case 3: cout << "Stopa zwrotu: "; aktywa->getTab()[element].setRoi(Majatek::podajWartosc()); break;
	default: cout << "Nie ma takiej opcji"; break;
	}
}

void Majatek::edytujAktywa() {
	cout << "Wybierz rodzaj aktywow\n---------Aktywa---------\n1. Lokata\n2. Produkt strukturyzowany\n3. IKE\n4. Nieruchomosc\n5. Kontrakt terminowy\n6. Jednostka funduszu inwestycyjnego\n";
	int wybor;
	cin >> wybor;
	switch (wybor) {
	case 1: {
		edytuj<Lokata>(lokaty);
		break;
	}
	case 2: {
		edytuj<ProduktStrukturyzowany>(produkty);
		break;
	}
	case 3: {
		edytuj<IKE>(iki);
		break;
	}
	case 4: {
		edytuj<Nieruchomosc>(nieruchomosci);
		break;
	}
	case 5: {
		edytuj<Kontrakt>(kontrakty);
		break;
	}
	case 6: {
		edytuj<JednostkaFunduszu>(jednostkiFunduszu);
		break;
	}
	default: break;
	}
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
	int ileLat;
	cout << "Podaj w przedziale ilu lat od teraz chcialbys przeprowadzic symulacje: ";
	ileLat = (int)podajWartosc();
	cout << "Obecna wartosc aktywow to " << obliczWartoscMajatku(0) << endl;
	cout << "Za " << ileLat << " lat wartosc twoich aktywow bedzie wynosic "<<obliczWartoscMajatku(ileLat);
}

template <class T>
void zapiszAktywa(Aktywa<T> *aktywa, ofstream &out) {
	out << aktywa->getIloscAktywow() << endl;
	for (int i = 0; i < aktywa->getIloscAktywow(); i++) {
		out << aktywa->getTab()[i].getNazwa() << " " << aktywa->getTab()[i].getWartosc() << " " << aktywa->getTab()[i].getWklad() << " " << aktywa->getTab()[i].getRoi() << endl;
	}
}

void Majatek::zapis(ofstream &out) {
	out << kontrakty->getIloscAktywow() << endl;
	for (int i = 0; i < kontrakty->getIloscAktywow(); i++) {
		out << kontrakty->getTab()[i].getNazwa() << " " << kontrakty->getTab()[i].getWartosc() << " " << kontrakty->getTab()[i].getWklad() << " " <<
			kontrakty->getTab()[i].getRoi() << " " << kontrakty->getTab()[i].getOkresTrwania() << endl;
	}
	zapiszAktywa<Lokata>(lokaty, out);
	zapiszAktywa<ProduktStrukturyzowany>(produkty, out);
	zapiszAktywa<IKE>(iki, out);
	zapiszAktywa<Nieruchomosc>(nieruchomosci, out);
	zapiszAktywa<JednostkaFunduszu>(jednostkiFunduszu, out);

}

template<class T>
void odczytajAktywa(Aktywa<T> *aktywa, ifstream &in) {
	int ile;
	string nazwa;
	double wartosc, wklad, roi;
	in >> ile;
	for (int i = 0; i < ile; i++) {
		in >> nazwa >> wartosc >> wklad >> roi;
		T *t = new T(nazwa, wartosc, wklad, roi);
		aktywa->dodaj(t);
	}
}

void Majatek::odczyt(ifstream &in){
	int ile;
	string nazwa;
	double wartosc, wklad, roi, okres;
	in >> ile;
	for (int i = 0; i < ile; i++) {
		in >> nazwa >> wartosc >> wklad >> roi >> okres;
		Kontrakt *kontrakt = new Kontrakt(nazwa, wartosc, wklad, roi, okres);
		kontrakty->dodaj(kontrakt);
	}
	odczytajAktywa<Lokata>(lokaty, in);
	odczytajAktywa<ProduktStrukturyzowany>(produkty, in);
	odczytajAktywa<IKE>(iki, in);
	odczytajAktywa<Nieruchomosc>(nieruchomosci, in);
	odczytajAktywa<JednostkaFunduszu>(jednostkiFunduszu, in);
}