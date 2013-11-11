
#ifndef Faktoren_H
#define Faktoren_H

//#include "stdafx.h"; // was ist das?
#include <iostream>
using namespace std;


class Faktoren{	

private:
	double spannung;
	double temperatur;
	double prozess;
	double spannungFaktor;
	double temperaturFaktor;
	double prozessFaktor;

	bool berechneSpannungFaktor( double spg );
	bool berechneTemperaturFaktor( double temp );
	bool berechneProzessFaktor( short prz );
	double berechneFaktor( double value, double arr[][2], int laenge );
	double interpolation( double value, double x1, double x2, double y1, double y2 );

public:
	Faktoren();
	~Faktoren();

	inline double getSpannung() { return spannung; }
	inline double getProzess() { return prozess; }
	inline double getTemperatur() { return temperatur; }

	inline bool setSpannung( double spg ) { spannung = spg; return true; }
	inline bool setTemperatur( double temp ) { temperatur = temp; return true; }
	inline bool setProzess( short proz ) { prozess = proz; return true; }

	void getFaktoren( double& spgFaktor, double& tmpFaktor, double& przFaktor );
	void ausgabeFaktoren();



};

#endif