#include <iostream>
#include "Faktoren.h";

Faktoren::Faktoren() {
        double spannung=0;
        double temperatur=0;
        double prozess=0;
        double spannungFaktor=0;
        double temperaturFaktor=0;
        double prozessFaktor=0;
 }


bool Faktoren::berechneSpannungFaktor( double spg ){

	double tabelle[7][2] = {1.08 ,  1.12 ,  1.16 , 1.20 , 1.24 , 1.28 , 1.32 , 1.121557 , 1.075332 , 1.035161 , 1.00000 , 0.968480 , 0.940065 , 0.914482 }; //tabelle[zeilen][spalten]
	
	if( spg >= tabelle[0][0] && spg <= tabelle[6][0] ){ //ueberpruefung ob Eingabe im DefBereich ist
	
		spannungFaktor = berechneFaktor( spg , tabelle, 7 );
		return true;
	}
	else{	

		cout << "ERROR : Spannung nicht im Bereich zwischen " << tabelle[0][0] << " bis " << tabelle[6][0] << " !" << endl << endl;
		return false;
	}

	
}

bool Faktoren::berechneTemperaturFaktor( double temp ){

	double tabelle[15][2] = { -20,-15,0,15,25,35,45,55,65,75,85,95,105,115,125 , 0.897498,0.917532,0.948338,0.979213,1,1.020305,1.040540,1.061831,1.082983,1.103817,1.124124,1.144245,1.164563,1.184370,1.204966 }; //tabelle[zeilen][spalten] // füllt spaltenweise
	
	if( temp >= tabelle[0][0] && temp <= tabelle[14][0] ){ //ueberpruefung ob Eingabe im DefBereich ist
	
		temperaturFaktor = berechneFaktor( temp , tabelle, 15 );
		return true;
	}
	else{	

		cout << "ERROR : Temperatur nicht im Bereich zwischen " << tabelle[0][0] << " bis " << tabelle[14][0] << " !" << endl << endl;
		return false;
	}

}

bool Faktoren::berechneProzessFaktor( short prozess ){

	switch( prozess ){
		case 1:
			prozessFaktor = 1.174235;
			break;
		case 2:
			prozessFaktor = 1.000000;
			break;
		case 3:
			prozessFaktor = 0.876148;
			break;
		default:
			cout << "ERROR : Prozess muss 1 , 2 oder 3 sein ( slow , typical , fast )" << endl << endl;
			return false;
			
	}
	return true;
}



double Faktoren::berechneFaktor( double wert, double arr[][2], int laenge ){

	 double x1 , x2 , y1 , y2;
	 int i = 0;

	 while( arr[i][0] < wert ){
		 i++;
	 }
	 x2 = arr[i][0];
	 
	 if( wert == x2 ){
		 return arr[i][1];
	 }
	 else{
		x1 = arr[i-1][0];
		y1 = arr[i-1][1];
		y2 = arr[i][1];
		
		return interpolation( wert , x1 , x2 , y1 , y2 );
	 } 
}

double Faktoren::interpolation( double wert , double x1 , double x2 , double y1 , double y2 ){

	double m = ( y2 - y1) / ( x2 - x1 );
	double faktor = m * (wert - x1 ) + y1; // nicht getestet, aber muesste gehen
	return faktor;
}

void Faktoren::ausgabeFaktoren(){

	cout << "-------------------------------" << endl;
	cout << "Spannungsfaktor:  " << spannungFaktor << endl;
	cout << "Temperaturfaktor: " << temperaturFaktor << endl;
	cout << "Prozessfaktor:    " << prozessFaktor << endl;
	cout << "-------------------------------" << endl;
}



