#ifndef GARA_H
#define GARA_H
#include "veicolo.h"

#include <iostream>
#include <cstdlib>
#include<ctime>

class Gara {
	int durata;
	int maxPartecipanti;
	int numeroIscritti;
	void controlla(int t);
	Veicolo ** veicoli;
	
	public:
	
	Gara(int durata, int _maxPartecipanti) : durata(durata), maxPartecipanti(_maxPartecipanti) {
		veicoli = new Veicolo*[_maxPartecipanti];
		numeroIscritti = 0;
	}
	
	~Gara() {
		delete [] veicoli;
	}
	
	void partenza();
	void stampaClassifica();
	void aggiungiPartecipante(Veicolo& v);
};

#endif

//AGGIUNGI PARTECIPANTI SOLO SE NUM ISCRITTI <= MAXPARTECIPANTI
void Gara::aggiungiPartecipante(Veicolo& v) {
	if(numeroIscritti<maxPartecipanti){
		veicoli[numeroIscritti++] = &v;
		std::cout<<"aggiunta "<<veicoli[numeroIscritti-1]->toString()<<std::endl;
	}
	else 
		std::cout<<"impossibile aggiungere altri partecipanti - num max raggiunto.\n";
		
}


void Gara::controlla(int t) {
	
	int massimo_temporaneo = veicoli[0]->getVelocita(); //veicoli[0].getVelocita()
	int indice_massimo = 0;

	for(int i=1; i < numeroIscritti; i++) {
		if(veicoli[i]->getVelocita() > massimo_temporaneo) {
			massimo_temporaneo = veicoli[i]->getVelocita();
			indice_massimo = i;
		}
	}
	
	std::cout << "Il veicolo piu veloce e' " << veicoli[indice_massimo]->getMarca() << 
				" e ha velocita'  " << massimo_temporaneo << "km/h" << std::endl;
		
}

void Gara::partenza() {
	srand(time(0));
	std::cout<<"----------------------INIZIO GARA----------------------"<<std::endl;
	for(int i=0; i < durata; i++) {
		for(int j=0; j < numeroIscritti; j++) {

			if( rand() % 2 == 1 )
				veicoli[j]->accelera();
			else
				veicoli[j]->decelera();	
		}
		this->controlla(i); //per controllare il veicolo più veloce
	}
	std::cout<<"----------------------FINE GARA----------------------"<<std::endl;	
	this->stampaClassifica();
}

//
void Gara::stampaClassifica() {
	
	//INSERTION SORT
	/*int velocita_curr,j;
	Veicolo *temp;
	for(int i=1;i<numeroIscritti;i++) { 
		velocita_curr=veicoli[i]->getVelocita(); 
		temp = veicoli[i];
        j=i-1; 
		while( (veicoli[j]->getVelocita() < velocita_curr) && j>=0 ) { 
			veicoli[j+1]=veicoli[j]; 
            j--;
        } 
		veicoli[j+1]=temp; 
	} */
	
	//BUBBLESORT BLEAH
	for(int i=0; i<numeroIscritti-1; i++){
		for(int j=0; j<numeroIscritti-1-i; j++){
			if(veicoli[j]->getVelocita() < veicoli[j+1]->getVelocita()){
				Veicolo *temp = veicoli[j];
				veicoli[j] = veicoli[j+1];
				veicoli[j+1] = temp;
			}
		}
	}
	std::cout << "CLASSIFICA: " << std::endl;
	for(int i=0; i<numeroIscritti; i++){
		std::cout<<i+1<<". ";
		std::cout<<veicoli[i]->toString()<<std::endl;
	}
}
