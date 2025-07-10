
#include "Autokuca.h"
void Autokuca::ucitajAuta() {
    // Otvaranje fajla za porodična auta
    std::ifstream porodicniFile("porodicnaAuta.csv");
    if (porodicniFile.is_open()){
        PorodicnoAuto pa;
        while (porodicniFile>>pa){
            porodicnaAuta.push_back(pa);// Dodavanje porodičnog auta u vektor
        }
        porodicniFile.close();// Zatvaranje fajla
    } // Otvaranje fajla za sportska auta
    std::ifstream sportskiFile("sportskaAuta.csv");
    if (sportskiFile.is_open()){
        SportskoAuto sa;
        while (sportskiFile>>sa){
            sportskaAuta.push_back(sa);// Dodavanje sportskog auta u vektor
        }
        sportskiFile.close(); // Zatvaranje fajla
    }
}//file
void Autokuca::unosPorodicnogAuta(const PorodicnoAuto &pa)  {
   // PorodicnoAuto pa;
    //std::cin>>pa; // Unos podataka o novom porodičnom autu
    porodicnaAuta.push_back(pa);// Dodavanje u vektor
    // Otvaranje fajla u režimu dopisivanja (append mode)
    std::ofstream  porodicniFile("porodicnaAuta.csv", std::ios::app);
    if ( porodicniFile.is_open()) {
        porodicniFile << pa << std::endl;// Snimanje podataka u fajl
        porodicniFile.close();// Zatvaranje fajla
    }
}
void Autokuca::unosSportskogAuta(const SportskoAuto &sa) {
   sportskaAuta.push_back(sa);// Dodavanje u vektor
    std::ofstream sportskiFile("sportskaAuta.csv", std::ios::app);
    if (sportskiFile.is_open()) {
        sportskiFile << sa << std::endl;// Snimanje podataka u fajl
        sportskiFile.close(); // Zatvaranje fajla
    }
}
std::ostream& operator<<(std::ostream& out, const Autokuca& a) {
    out << "Porodicna auta:" << std::endl;
    for (const auto& pa : a.porodicnaAuta) {
        out << pa << std::endl;// Ispis svih porodičnih auta
    }

    out << "Sportska auta:" << std::endl;
    for (const auto& sa : a.sportskaAuta) {
        out << sa << std::endl;// Ispis svih sportskih auta
    }

    return out;
}
/*
ucitajAuta() učitava vozila iz fajlova porodicnaAuta.csv i sportskaAuta.csv i smješta ih u odgovarajuće vektore.
unosPorodicnogAuta() unosi porodično vozilo putem konzole, dodaje ga u vektor porodicnaAuta i snima u fajl porodicnaAuta.csv.
unosSportskogAuta() unosi sportsko vozilo putem funkcije, dodaje ga u vektor sportskaAuta i snima u fajl sportskaAuta.csv.
Operator << ispisuje sve porodične i sportske automobile iz vektora porodicnaAuta i sportskaAuta.*/