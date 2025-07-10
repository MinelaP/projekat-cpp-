
#ifndef AUTO_AUTO_H
#define AUTO_AUTO_H
#include <iostream>
#include "Vozilo.h"
#include <string>
class Auto{
public:Vozilo vozilo;
    std::string registracija;
//konstruktor
public:   Auto(Vozilo vozilo=Vozilo(),std::string registracija="");
// Virtualni destruktor, omogućava nasleđivanje
public:virtual ~Auto()=default;
};
#endif //AUTO_AUTO_H
