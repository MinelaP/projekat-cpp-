#ifndef AUTO_PORODICNOAUTO_H
#define AUTO_PORODICNOAUTO_H

#include "Auto.h"
#include <iostream>
#include <memory>

enum class Vrsta { limuzina, karavan, vagon };

class PorodicnoAuto : public Auto {
public:
    std::shared_ptr<Vrsta> vrsta;// Pametni pokazivač na vrstu vozila
    bool rezervisano;

public:
    PorodicnoAuto(Vozilo vozilo = Vozilo(), std::string registracija = "", Vrsta vrsta = Vrsta::karavan, bool rezervisano = false);
    bool isRezervisano() const;// Vraća status rezervacije
    void setRezervisano(bool rezervisano);// Postavlja status rezervacije
    Vrsta getvrsta() const;//Vraća vrstu vozila
    // Preopterećenje operatora za unos i ispis
    friend std::ostream& operator<<(std::ostream& out, const PorodicnoAuto& pa);
    friend std::istream& operator>>(std::istream& in, PorodicnoAuto& pa);
    // Postfiksni operator za promenu statusa rezervacije
    PorodicnoAuto& operator++(int);
};

#endif //AUTO_PORODICNOAUTO_H
