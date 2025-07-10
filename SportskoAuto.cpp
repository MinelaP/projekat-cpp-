#include "SportskoAuto.h"
SportskoAuto::SportskoAuto(Vozilo vozilo, std::string registracija, int brojBrzina, int brKW)
        : Auto(vozilo,registracija),brojBrzina(brojBrzina),brKW(brKW){}

std::ostream& operator<<(std::ostream& out, const SportskoAuto& sa) {
    out << sa.vozilo.tipMarka << "(" << sa.vozilo.cijena << ") - registracija: "
        << sa.registracija << " - broj brzina: " << sa.brojBrzina
        << " - kW: " << sa.brKW;
    return out;
}
std::istream& operator>>(std::istream& in, SportskoAuto& sa) {
    std::string tipMarka;
    float cijena;
    std::string registracija;
    int brojBrzina;
    int brKW;

    std::cout << "Unesite tip auta: ";
    in >> tipMarka;
    std::cout << "Unesite cijenu: ";
    in >> cijena;
    std::cout << "Unesite datum registracije: ";
    in >> registracija;
    std::cout << "Unesite broj brzina: ";
    in >> brojBrzina;
    std::cout << "Unesite broj kW: ";
    in >> brKW;

    sa = SportskoAuto(Vozilo(tipMarka, cijena), registracija, brojBrzina, brKW);
    return in;
}

float SportskoAuto::operator!() const {
    return brojBrzina==6? brKW * 1.341f : brKW * 1.287f;
}