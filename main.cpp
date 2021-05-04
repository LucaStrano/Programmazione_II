#include "moto.h"
#include "automobile.h"
#include "gara.h"

#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
	
	int step=10;
	int max_partecipanti = 5;
	//parametri: STEP - PARTECIPANTI
	Gara gara(step, max_partecipanti);
	
	//AGGIUNTA CASUALE DI AUTO/MOTO
	srand(time(0));
	for(int i=0; i<max_partecipanti; i++){
		Veicolo *v;
		if( rand()%100<50) //se rand è 1
			v = new Moto(120, 5000, "Ducati", "Motorizzazione Delca");
		else
			v = new Auto(180, 10000, "Lamborghini", "Motorizzazione Dellami");
		gara.aggiungiPartecipante(*v);
	}
	
	gara.partenza();
}
