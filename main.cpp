#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
//#include "JednostkaAktywow.h"
//#include "Lokata.h"
//#include "ProduktStrukturyzowany.h"
//#include "IKE.h"
//#include "Nieruchomosc.h"
//#include "Kontrakt.h"
//#include "JednostkaFunduszu.h"
//#include "Aktywa.h"
#include "Majatek.h"

using namespace std;

void pokazMenu() {
	cout << "\nWybierz jedna z opcji" << endl;
	cout << "---------Menu---------\n1. Dodaj skladnik aktywow\n2. Usun skladnik aktywow\n3. Edytuj skladnik aktywow\n4. Dodaj gotowke\n5. Odejmij gotowke" << endl;
	cout << "6. Wyswietl szczegoly wartosci majatku\n7. Przeprowadz symulacje zmiany wartosci majatku\n8. Zapisz manualnie\n9. Zamknij program" << endl;
}

void dodajGotowke(double &gotowka) {
	double ile;
	cout << "Podaj ilosc: ";
	cin >> ile;
	gotowka += ile;
	cout << "Dodano " << ile << " gotowki, aktualny stan konta to " << gotowka << endl;
}

void odejmijGotowke(double &gotowka) {
	double ile;
	cout << "Podaj ilosc: ";
	cin >> ile;
	gotowka -= ile;
	cout << "Odebrano " << ile << " gotowki, aktualny stan konta to " << gotowka << endl;
}

void wypiszGotowke(double &gotowka) {
	cout << "Twoja gotowka to: " << gotowka << endl;
}

void zapiszDoPliku(Majatek *majatek, double &gotowka) {
	ofstream out("zapis.txt");
	out << gotowka << endl;
	majatek->zapis(out);
	out.close();
}

void odczytajZPliku(Majatek *majatek, double &gotowka) {
	ifstream in("zapis.txt");
	in >> gotowka;
	majatek->odczyt(in);
	in.close();
}

int main() {
    /*Aktywa<IKE> *ike = new Aktywa<IKE>(10);
    IKE *a = new IKE("some ike", 100, 110, 0.01);
    IKE *b = new IKE("some other ike", 300, 210, 0.04);

    cout<<ike->getIloscAktywow()<<endl;

	*ike += a;
	*ike += b;
	*ike -= 1;

    for (int i = 0; i < ike->getIloscAktywow(); i++) {
        ike->setWartoscAktywow(ike->getWartoscAktywow() + ike->getTab()[i].getWartosc());
    }

    cout << ike->getWartoscAktywow() << endl;
    cout << ike->getIloscAktywow() << endl;*/
	double gotowka = 0;
	int opcja;
	bool dzialanie = true;
	
	Majatek *majatek = new Majatek();

	odczytajZPliku(majatek, gotowka);
	cout << "Witaj w kalkulatorze oszczednosci \"Oszczedzanie jak marzenie\" - twoja satysfakcja naszym priorytetem" << endl;
	while (1) {
		pokazMenu();
		cin >> opcja;
		switch (opcja)
		{
		case 1: majatek->dodajAktywa(); zapiszDoPliku(majatek, gotowka); break;
		case 2: majatek->usunAktywa(); zapiszDoPliku(majatek, gotowka); break;
		case 3: majatek->edytujAktywa(); zapiszDoPliku(majatek, gotowka); break;
		case 4: dodajGotowke(gotowka); zapiszDoPliku(majatek, gotowka); break;
		case 5: odejmijGotowke(gotowka); zapiszDoPliku(majatek, gotowka); break;
		case 6: wypiszGotowke(gotowka); majatek->wypiszAktywa(); break;
		case 7: majatek->przeprowadzSymulacje(); break;
		case 8: zapiszDoPliku(majatek, gotowka); break;
		case 9: dzialanie = false; break;
		default: break;
		}

		if (!dzialanie)
			break;
	}

    cout << "\nProgram zakonczyl dzialanie" << endl;
    return 0;
}