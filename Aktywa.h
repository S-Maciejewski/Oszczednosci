//#ifndef KALKULATOROSZCZEDNOSCI_AKTYWA_H
//#define KALKULATOROSZCZEDNOSCI_AKTYWA_H
//#endif KALKULATOROSZCZEDNOSCI_AKTYWA_H
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
        cout << "Dodawanie " << endl;
        tab[getIloscAktywow()] = *jednostkaAktywow;
        setIloscAktywow(getIloscAktywow() + 1);
    }

};