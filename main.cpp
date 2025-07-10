#include <iostream>
#include "Autokuca.h"
int main() {
    Autokuca autokuca;
    autokuca.ucitajAuta();// Učitavanje vozila iz fajlova
    int  izbor;
    do {
        std::cout<<"1. Unos porodicnog auta"<<std::endl;
        std::cout<<"2.Unos sportsko auta"<<std::endl;
        std::cout<<"3.Ispis svih auta"<<std::endl;
        std::cout<<"4:Ispis snage jednog sportskog vozila"<<std::endl;
        std::cout<<"5.Izvrsit promjenu statusa rezervacije jednog porodicnog auta"<<std::endl;
        std::cout<<"6. Ispis najskupljeg vozila u autokuci"<<std::endl;
        std::cout << "0. Izlaz" << std::endl;
        std::cout << "Izbor: ";
        std::cin >> izbor;
        switch (izbor) {
            case 1:{
               PorodicnoAuto pa;
                std::cin>>pa;
                autokuca.unosPorodicnogAuta(pa);
                break;}
            case 2:{
                SportskoAuto sa;
                std::cin>>sa;
                autokuca.unosSportskogAuta(sa);
                break;
            }
            case 3:{
                std::cout<<autokuca;
                break;

            }
            case 4: {
                std::string registracija;
                std::cout << "Unesite registraciju sportskog vozila: ";
                std::cin >> registracija;

                bool found = false;
                for (const auto& sa : autokuca.sportskaAuta) {
                    if (sa.registracija == registracija) {
                        std::cout << "Snaga sportskog vozila sa registracijom " << registracija << " je " << !sa << " kW" << std::endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    std::cout << "Sportsko vozilo sa registracijom " << registracija << " nije pronađeno!" << std::endl;
                }

                break;
            }
            case 5: {
                std::string registracija;
                std::cout << "Unesite registraciju porodičnog vozila: ";
                std::cin >> registracija;

                bool found = false;
                for (auto& pa : autokuca.porodicnaAuta) {
                    if (pa.registracija == registracija) {
                        pa++;
                        std::cout << "Status rezervacije za porodično vozilo sa registracijom " << registracija << " je promenjen na." <<(pa.rezervisano?"da":"ne")<< std::endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    std::cout << "Porodično vozilo sa registracijom " << registracija << " nije pronađeno!" << std::endl;
                }

                break;
            }
            case 6: {
                if (autokuca.porodicnaAuta.empty() && autokuca.sportskaAuta.empty()) {
                    std::cout << "Nema vozila u autokući." << std::endl;
                    break;
                }

                const PorodicnoAuto* najskupljePorodicno = nullptr;
                const SportskoAuto* najskupljeSportsko = nullptr;

                // Pronađi najskuplje porodično auto
                for (const auto& pa : autokuca.porodicnaAuta) {
                    if (najskupljePorodicno == nullptr || pa.vozilo.cijena > najskupljePorodicno->vozilo.cijena) {
                        najskupljePorodicno = &pa;
                    }
                }

                // Pronađi najskuplje sportsko auto
                for (const auto& sa : autokuca.sportskaAuta) {
                    if (najskupljeSportsko == nullptr || sa.vozilo.cijena > najskupljeSportsko->vozilo.cijena) {
                        najskupljeSportsko = &sa;
                    }
                }

                // Odredi najskuplje vozilo
                if (najskupljePorodicno && najskupljeSportsko) {
                    if (najskupljePorodicno->vozilo.cijena > najskupljeSportsko->vozilo.cijena) {
                        std::cout << "Najskuplje vozilo je porodično vozilo: " << *najskupljePorodicno << std::endl;
                    } else {
                        std::cout << "Najskuplje vozilo je sportsko vozilo: " << *najskupljeSportsko << std::endl;
                    }
                } else if (najskupljePorodicno) {
                    std::cout << "Najskuplje vozilo je porodično vozilo: " << *najskupljePorodicno << std::endl;
                } else if (najskupljeSportsko) {
                    std::cout << "Najskuplje vozilo je sportsko vozilo: " << *najskupljeSportsko << std::endl;
                }

                break;
            }

            case 0: {
                break;
            }
            default:
                std::cout << "Pogresan izbor!" << std::endl;
        }
    
    }while (izbor != 0);
    return 0;
}
