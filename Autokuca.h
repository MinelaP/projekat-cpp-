
#ifndef AUTO_AUTOKUCA_H
#define AUTO_AUTOKUCA_H
#include "SportskoAuto.h"
#include "PorodicnoAuto.h"
#include <iostream>
#include <vector>
#include <fstream>
class Autokuca{
public:
    std::vector<PorodicnoAuto> porodicnaAuta;// Vektor koji čuva listu svih porodičnih auta u autokući
    std::vector<SportskoAuto> sportskaAuta;// Vektor koji čuva listu svih sportskih auta u autokući
    void ucitajAuta();// Funkcija koja učitava auta iz fajlova i dodaje ih u odgovarajuće vektore
    void unosPorodicnogAuta(const PorodicnoAuto& pa);// Funkcija koja omogućava unos porodičnog auta u vektor i fajl
    void unosSportskogAuta(const SportskoAuto& sa);// Funkcija koja omogućava unos sportskog auta u vektor i fajl
    // Preopterećen operator << za ispis svih auta u autokući
    friend std::ostream& operator<<(std::ostream& out, const Autokuca& a);


};
#endif //AUTO_AUTOKUCA_H
//Vektori porodicnaAuta i sportskaAuta su liste koje čuvaju sve porodične i sportske aute u autokući.
//Funkcija ucitajAuta() čita podatke o vozilima iz fajlova (porodicnaAuta.csv i sportskaAuta.csv) i smješta ih u odgovarajuće vektore.
//Funkcija unosPorodicnogAuta() omogućava unos novog porodičnog auta, dodavanje tog auta u vektor porodicnaAuta i snimanje u fajl porodicnaAuta.csv.
//Funkcija unosSportskogAuta() omogućava unos novog sportskog auta, dodavanje tog auta u vektor sportskaAuta i snimanje u fajl sportskaAuta.csv.
//Operator << je preopterećen za ispisivanje svih auta u autokući, prvo se ispisuju porodična, a zatim sportska auta.