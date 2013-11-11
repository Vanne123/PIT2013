//Erstellt von Alex am 08.11.13

#ifndef Menue_H
#define Menue_H

#include <iostream>
using namespace std;

#include "Faktoren.h"


class Menue{	

private:
	Faktoren meineFaktoren;
	//Bibliothek meineBibliothek;
	//SignalListeErzeuger meinSignalListeErzeuger;
	//GraphErzeuger meinGraphErzeuger;
	//LaufzeitAnalysator meinLaufzeitAnalysator;
	//Signal* signale; // Im Klassendiagramm ist kein Hinweis drauf, aber ist das nicht ein Array?

	void faktorenMenue();
	void bibliothekMenue();
	void schaltwerkMenue();
	void analyse();
	void menueKopf();

public:
	Menue();
	~Menue();

	void start();




};



#endif