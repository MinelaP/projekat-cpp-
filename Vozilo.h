
#ifndef AUTO_VOZILO_H
#define AUTO_VOZILO_H
#include <iostream>
#include <string>
struct Vozilo {
    std::string tipMarka;
    float cijena;

    // Konstruktor koji inicijalizuje tipMarka i cijena
    Vozilo(std::string tipMarka="",float cijena=0);
    // Funkcija koja ispisuje informacije o vozilu
    void ispisInformacija() const;
};

#endif //AUTO_VOZILO_H
