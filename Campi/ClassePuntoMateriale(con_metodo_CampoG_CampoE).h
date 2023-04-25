#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__

#define _USE_MATH_DEFINES
#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"
#include <cmath>
#include <iostream>

double const eps0 = 8.85418781762E-12;
double const G = 6.674E-11;

using namespace std;

class PuntoMateriale: public Particella, public Posizione {

public:

	//costruttori
	PuntoMateriale(double massa, double carica, const Posizione& p) : Particella(massa,carica), Posizione(p) {
		cout << "calling constructor PM" << endl;
	}

	PuntoMateriale(double massa, double carica, double x, double y, double z) : Particella(massa, carica), Posizione(x,y,z) {
		cout << "calling constructor PM"<< endl;
	}

	PuntoMateriale(Particella p, Posizione& r) : Particella(p), Posizione(r) {;};

	PuntoMateriale(Particella p, double x, double y, double z) : Particella(p), Posizione(x,y,z) {;};

	~PuntoMateriale() {;};

	//creo un metodo tc fornita una posizione mi restituisca il campo elettrico in quel punto assumendo che questo sia generato dal punto materiale che sta invocando il metodo
	CampoVettoriale CampoElettrico(const Posizione& p) const {
		double r = Distanza(p); //calcolo la distanza da dove sono io *coordinate del punto materiale* dal punto p che gli ho passato come argomento
		double k = m_carica/(4*M_PI*eps0*pow(r,3)); //creo una costante che include tutto tranne il campo
		//definisco i valori del campo
		double Ex = k*(p.getX()-getX());
		double Ey = k*(p.getY()-getY());
		double Ez = k*(p.getZ()-getZ());
		return CampoVettoriale(p.getX(), p.getY(), p.getZ(), Ex, Ey, Ez);
	}; //campo eletterico è un metodo di punto materiale (quindi ha accesso diretto a tutti i datamembri di PuntoMateriale), prende come argomento una posizione e mi restituisce un campo vettoriale

	CampoVettoriale CampoGravitazionale(const Posizione& p) const {
		double r = Distanza(p);
		double k = m_massa*G/(pow(r,3));
		double Gx = k*(p.getX()-getX());
		double Gy = k*(p.getY()-getY());
		double Gz = k*(p.getZ()-getZ());
		return CampoVettoriale(p.getX(), p.getY(), p.getZ(), Gx, Gy, Gz);
	};

	//non ci sono datamembri privati perchè tutte le caratteristiche fondamentali della classe PuntoMateriale sono erditate da Posizione e da Particella

};

#endif // __PuntoMateriale_h__

