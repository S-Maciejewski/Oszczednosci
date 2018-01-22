#include "stdafx.h"
#include<string>
#include "JednostkaAktywow.h"

using namespace std;

JednostkaAktywow::JednostkaAktywow() {};

JednostkaAktywow::JednostkaAktywow(string nazwa, double wartosc, double wklad, double roi) {
    this->nazwa = nazwa;
    this->wartosc = wartosc;
    this->wklad = wklad;
    this->roi = roi;
}

JednostkaAktywow::~JednostkaAktywow() {
    delete &nazwa;
    delete &wartosc;
    delete &wklad;
    delete &roi;
}

string JednostkaAktywow::getNazwa() { return nazwa; }

void JednostkaAktywow::setNazwa(string nazwa){
	this->nazwa = nazwa;
}

double JednostkaAktywow::getWartosc(){
    return wartosc;
}

void JednostkaAktywow::setWartosc(double wartosc) {
    this->wartosc = wartosc;
}

double JednostkaAktywow::getWklad() {
    return wklad;
}

double JednostkaAktywow::getRoi() {
    return roi;
}

void JednostkaAktywow::setRoi(double roi){
	this->roi = roi;
}
