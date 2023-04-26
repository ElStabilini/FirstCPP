#include <cmath>
#include "iostream"
#include "RandomGen.h"
#include "Funzioni.h"
#include <iomanip>

using namespace std;


//===========================================================================
//DISTRIBUZIONE UNIFORME tra  0 e 1
double RandomGen::Rand(){
	m_seed = (m_a*m_seed + m_c)%m_m;
	return m_seed/double(m_m);
}


//===========================================================================
//DISTRIBUZIONE UNIFORME su un INTERVALLO FISSATO
double RandomGen::Unif(double xmin, double xmax) {
	double di = Rand();
	double number = xmin + (xmax - xmin)*di;
	//cout << number << endl;
	return number;
}


//===========================================================================
//DISTRIBUZIONE ESPONENZIALE
double RandomGen::Exp(double mean) {
	double y = Rand();
	double x = -(1/mean)*log(1-y);
	cout << x << endl;
	return x;
}


//===========================================================================
//distribuzione GAUSSIANA
double RandomGen::Gauss(double mean, double sigma) {
	//studiala bene e commentale 
	double s = Rand();
	double t = Rand();
	double x = sqrt(-2*log(s))*cos(2*M_PI*t);
	double gauss = mean + x*sigma;
	cout << gauss << endl;
	return gauss;
}


//===========================================================================
//distribuzione GAUSSIANA ACCEPT-REJECT
double RandomGen::GaussAR(double mean, double sigma) {
	Gaussiana g(mean, sigma);
	double x = 0;
	double y = 0;
	double M = 1000;
	for(;;) {
		x = Unif(mean-M, mean+M);
		y = Unif(0,M/2);
		if(y <g.Eval(x))
			break;
	}
	cout << x << "," << y << endl;
	return x;
}

//===========================================================================
//ACCESPT REJECT per una funzione qualunque
double RandomGen::AcceptReject(FunzioneBase *f) {
	//immagino che la funzione sia stata costruita, e quindi i parametri inizializzati nel main
	double x = 0;
	double y = 0;
	double M = 1000;
	for(;;) {
		x = Unif(-M,M); //NEL CASO POSSONO ESSERE CAMBIATI I PARAMETRI DELL'INTERVALLO
		y = Unif(0,M);
		if(y <f->Eval(x))
			break;
	}
	cout << x << "," << y << endl;
	return x;
}
