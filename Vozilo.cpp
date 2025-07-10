#include "Vozilo.h"
Vozilo::Vozilo(std::string tipMarka, float cijena)
:tipMarka(tipMarka),cijena(cijena){}
// Definiše ispis informacija o vozilu u obliku "tipMarka (cijena)"
void Vozilo::ispisInformacija() const {
    std::cout << tipMarka << " (" << cijena << ")" << std::endl; // Method definition
}