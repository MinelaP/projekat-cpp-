

#ifndef AUTO_SPORTSKOAUTO_H
#define AUTO_SPORTSKOAUTO_H

#include <iostream>
#include "Auto.h"
class SportskoAuto:public Auto{
public: int brojBrzina;
    int brKW;
    SportskoAuto(Vozilo vozilo=Vozilo(),std::string registracija = "",int brojBrzina=0, int brKW=0);
    // Preopterećenje operatora za unos i ispis
    friend std::ostream& operator<<(std::ostream& out, const SportskoAuto& pa);
    friend std::istream& operator>>(std::istream& in, SportskoAuto& sa);
  float operator!() const;
};
#endif //AUTO_SPORTSKOAUTO_H
