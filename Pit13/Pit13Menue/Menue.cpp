// Erstellt von A. Nitsch am 08.11.13

#include "Menue.h";
#include <string>
#include <iostream>

Menue::Menue(){

	//Faktoren* meineFaktoren2 = new Faktoren() ;
	//erstellung von MeineFaktoren, meineBibliothek usw...

}


void Menue::start(){

	bool stop = false;
	int auswahl;

	double spannung = 0; 
	double temperatur = 0;
	double prozess = 0;
	string bibPfad = "-";
	string schaltwPfad = "-";


	while( !stop ){

		// hier muss Spannung und Co durch die entsprechenden Ausgabemethoden gesetzt werden
		// Bsp: bibPfad = meineBibliothek.getPfad();
		spannung = meineFaktoren.getSpannung();
		temperatur = meineFaktoren.getTemperatur();
		prozess = meineFaktoren.getProzess();

		system( "cls" );
		menueKopf();

		cout << "(1) aeussere Faktoren" << endl;
		cout << "Spannung [Volt] : " << spannung << endl;
		cout << "Temperatur [Grad Celsius]: " << temperatur << endl;
		cout << "Prozess (1=slow, 2=typical, 3=fast): " << prozess << endl << endl;

		cout << "(2) Bibliothek" << endl;
		cout << "Pfad zur Bibliotheksdatei: " << bibPfad << endl << endl;

		cout << "(3) Schaltwerk" << endl;
		cout << "Pfad zur Schaltwerksdatei: " << schaltwPfad << endl << endl;

		cout << "(4) Analyse starten" << endl << endl;

		cout << "(5) Programm beenden" << endl << endl;

		cout << "Waehle einen Menuepunkt und bestaetige mit Enter: " << endl;
		cin >> auswahl ;

		system( "cls" );
		menueKopf();

		switch (auswahl){

		case 1:
			faktorenMenue();
			break;

		case 2:
			bibliothekMenue();
			break;

		case 3:
			schaltwerkMenue();
			break;

		case 4:
			analyse();
			break;

		case 5:
			stop = true;
			break;

		default:
			cout << "keine gueltige Eingabe! Waehle 1 , 2 , 3 , 4 oder 5" << endl;
			break;

			auswahl = 0;
		}
	}
	system( "cls" );
	cout << endl << "Tschuess! :) " << endl << endl;
	system( "pause" );
}

void Menue::faktorenMenue(){

	double spannung = meineFaktoren.getSpannung(); //werte werden gesetzt
	double temperatur = meineFaktoren.getTemperatur();
	double prozess = meineFaktoren.getProzess();
	int auswahl;

	cout << "(1) Spannung [Volt] : " << spannung << endl;
	cout << "(2) Temperatur [Grad Celsius]: " << temperatur << endl;
	cout << "(3) Prozess (1=slow, 2=typical, 3=fast): " << prozess << endl;
	cout << "(4) Ausgabe errechneter Faktoren" << endl;
	cout << "(5) Hauptmenue" << endl << endl;

	cout << "Waehle einen Menuepunkt und bestaetige mit Enter: " ;
	cin >> auswahl;

	switch (auswahl){ // bin mir nicht sicher obs so gedacht ist, zum testen ists aber praktisch

		case 1:
			cout << endl << "Neue Spannung: ";
			cin >> spannung;
			meineFaktoren.setSpannung( spannung );
			break;

		case 2:
			cout << endl << "Neue Temperatur: ";
			cin >> temperatur;
			meineFaktoren.setTemperatur( temperatur );
			break;

		case 3:
			cout << endl << "Neuer Prozessspeed( (1)slow , (2)typical , (3)fast ): ";
			cin >> prozess;
			meineFaktoren.setProzess( prozess );
			break;

		case 4:
			//vorsicht, evtl sind sie noch nicht berechnet
			meineFaktoren.ausgabeFaktoren();
			break;

		case 5: // hier muss nichts gemacht werden
			break;

		default:
			cout << "keine gueltige Eingabe! Waehle 1 , 2 , 3 , 4 oder 5" << endl;
			break;

		}



		

}

void Menue::bibliothekMenue(){

	string bibPfad = "-"; // hier dann gleich zuweisung des richtigen Werts
	int auswahl;

	cout << "Untermenue Bibliothek" << endl;
	cout << "(1) Pfad zur Bibliotheksdatei: " << bibPfad << endl;
	cout << "(2) Ausgabe der Bibliotheksdatei" << endl;
	cout << "(3) Hauptmenue" << endl << endl;

	cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";
	cin >> auswahl;

	cout << endl << "----------------------------------------------------" << endl << endl;

	switch (auswahl){

		case 1:
			//setPfad von meineBib
			break;

		case 2:
			//aufruf der Funktion von meineBib, sonst nichts
			break;

		case 3: // nix
			break;

		default:
			cout << "keine gueltige Eingabe! Waehle 1 , 2 oder 3. Rueckkehr zum Hauptmenue..." << endl;
			system("pause");
			break;

		}



}

void Menue::schaltwerkMenue(){
	
	string schaltwPfad = "-"; // hier gleich die zuweisung des werts
	int auswahl;
	
	cout << "Untermenue Schaltwerk" << endl;
	cout << "(1) Pfad zur Schaltnetzdatei: " << schaltwPfad << endl;
	cout << "(3) Ausgabe der Signale" << endl;
	cout << "(4) Ausgabe der Graphstruktur" << endl;
	cout << "(5) Hauptmenue" << endl << endl;

	cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";
	cin >> auswahl;

	switch (auswahl){

		case 1:
			cout << "Aenderung des Schaltnetzpfades zu : ";
			cin >> schaltwPfad;
			//ueberpruefung und dann reinschreiben ins Schaltwerk Objekt
			break;

		case 2:
			
			break;

		case 3:
			
			break;

		case 4:
			
			break;

		case 5: // hier muss nix hin
			break;

		default:
			cout << "keine gueltige Eingabe! Waehle 1 , 2 , 3 , 4 oder 5. Zurueck zum Hauptmenue..." << endl;
			system( "pause" );
			break;

		}



	
	
}

void Menue::analyse(){

}

void Menue::menueKopf(){

	cout << "******************************************" << endl;
	cout << "*     IT-Projektpraktikum WS2013/2014    *" << endl; 
	cout << "* Laufzeitanalyse synchroner Schaltwerke *" << endl;
	cout << "******************************************" << endl << endl;

}







