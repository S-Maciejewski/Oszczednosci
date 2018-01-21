#include "stdafx.h"
#include <vector>

using namespace std;

template<class T>
class Aktywa {
private:
    T *tab;
    double wartoscAktywow;
    int iloscAktywow;

public:
    Aktywa(int rozmiar) {
        wartoscAktywow = 0;
        iloscAktywow = 0;
        tab = new T[rozmiar];
    };

	Aktywa& operator+=(T *jednostkaAktywow) {
		tab[getIloscAktywow()] = *jednostkaAktywow;
		setIloscAktywow(getIloscAktywow() + 1);
		return *this;
	}

	Aktywa& operator-=(int numer) {
		if (numer >= getIloscAktywow())
			cout << "Nie znaleziono pozycji do usuniecia";
		else if (getIloscAktywow()==1) {
			setIloscAktywow(0);
		} else {
			tab[numer] = tab[getIloscAktywow() - 1];
			setIloscAktywow(getIloscAktywow() - 1);
		}

		return *this;
	}

    ~Aktywa() {
        delete &tab;
        delete &wartoscAktywow;
    };

    T *getTab() const {
        return tab;
    }

    int getIloscAktywow() const {
        return iloscAktywow;
    }

    void setIloscAktywow(int iloscAktywow) {
        Aktywa::iloscAktywow = iloscAktywow;
    }

    void setWartoscAktywow(double wartoscAktywow) {
        Aktywa::wartoscAktywow = wartoscAktywow;
    }

    double getWartoscAktywow() const {
        return wartoscAktywow;
    }

    void dodaj(T *jednostkaAktywow) {
        tab[getIloscAktywow()] = *jednostkaAktywow;
        setIloscAktywow(getIloscAktywow() + 1);
    }

};