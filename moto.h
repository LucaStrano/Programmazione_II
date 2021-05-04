#include <iostream>
#include <sstream>
#include "veicolo.h"

class Moto : public Veicolo {
	public:
		
		Moto(int velocitaMassima, double prezzo, std::string marca, std::string motorizzazione) : 
		Veicolo(2, velocitaMassima, prezzo, marca, "benzina", motorizzazione) 
		{}
		
		std::string toString() const {
			std::stringstream stream;
			stream << "Moto " << marca << ", " << motorizzazione << "; velocita' " << velocita << " km/h";
			return stream.str();
		}
	
};
