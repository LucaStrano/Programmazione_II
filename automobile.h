#include "veicolo.h"
#include <sstream>


class Auto : public Veicolo {
	
	public:
	
	Auto(int velocitaMassima, double prezzo, std::string marca, std::string motorizzazione) : 
	Veicolo(4, velocitaMassima, prezzo, marca, "benzina", motorizzazione) {}
	
	std::string toString() const {
		std::stringstream stream;
		stream << "Auto " << marca << ", " << motorizzazione << " " << "; velocita' " << velocita << " km/h";
		return stream.str();
	}
};
