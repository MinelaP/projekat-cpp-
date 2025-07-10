#include "PorodicnoAuto.h"

PorodicnoAuto::PorodicnoAuto(Vozilo vozilo, std::string registracija, Vrsta vrsta, bool rezervisano)
        : Auto(vozilo, registracija), vrsta(std::make_shared<Vrsta>(vrsta)), rezervisano(rezervisano) {}

bool PorodicnoAuto::isRezervisano() const {
    return rezervisano;
}

void PorodicnoAuto::setRezervisano(bool rezervisano) {
    this->rezervisano = rezervisano;
}

Vrsta PorodicnoAuto::getvrsta() const {
    return *vrsta;
}

std::ostream& operator<<(std::ostream& out, const PorodicnoAuto& pa) {
    out << pa.vozilo.tipMarka << " (" << pa.vozilo.cijena << ") - registracija: " << pa.registracija
        << " - Vrsta: ";

    if (*pa.vrsta == Vrsta::karavan) {
        out << "karavan";
    } else if (*pa.vrsta == Vrsta::limuzina) {
        out << "limuzina";
    } else if (*pa.vrsta == Vrsta::vagon) {
        out << "vagon";
    }

    out << " - Rezervisano: " << (pa.rezervisano ? "da" : "ne");
    return out;
}
std::istream& operator>>(std::istream& in,PorodicnoAuto& pa){
    std::string tipMarka;
    float cijena;
    std::string registracija;
    bool rezervisano;
    int vrsta;

    std::cout<<"unesite tip auta";
    in>>tipMarka;
    std::cout<<"unesite cijenu";
    in>>cijena;
    std::cout<<"unesite datum registracje";
    in>>registracija;
    std::cout<<"da li je rezervisano(1 da 0 ne)";
    in>>rezervisano;
    std::cout<<"Unesite vrstu auta(0-limuzna,1-karavan,2-vagon)";
    in>>vrsta;
    pa = PorodicnoAuto(Vozilo(tipMarka, cijena), registracija, static_cast<Vrsta>(vrsta), rezervisano);
    return in;
}
// Preopterećeni postfiksni operator ++ za promjenu statusa rezervacije
PorodicnoAuto& PorodicnoAuto::operator++(int) {
    rezervisano = !rezervisano;
    return *this;}