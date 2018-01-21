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

int main() {
	cout << "VS" << endl;
    Aktywa<IKE> *ike = new Aktywa<IKE>(10);
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
	cout << ike->getIloscAktywow() << endl;

    cout << "Program zakonczyl dzialanie" << endl;
    return 0;
}