#ifndef __CampoVettoriale_h__
#define __CampoVettoriale_h__

#include "Posizione.h"
#include <iostream>
#include <cmath>

class CampoVettoriale: public Posizione {

public:

	//costruttori
  CampoVettoriale(const Posizione&);	
	CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz);
	CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);
	CampoVettoriale(double x, double y, double z);

	//distruttore
	~CampoVettoriale() {;};

	//restituire le informazioni su CampoVettoriale
	double getFx() const {return m_Fx;}
	double getFy() const {return m_Fy;}
	double getFz() const {return m_Fz;}

	//modificare il campo vettoriale in un pounto
	double setFx(double Fx) {m_Fx = Fx;}
	double setFy(double Fy) {m_Fy = Fy;}
	double setFz(double Fz) {m_Fz = Fz;}

	double setCampo(double Fx, double Fy, double Fz);
	
	//metodo che mi restituisce la lunghezza del vettore del campo
	double Modulo() {
		return sqrt(pow(m_Fx, 2) + pow(m_Fy, 2) + pow(m_Fz, 2));
	}

	//overloading degli operatori + e +=
	CampoVettoriale operator+ (const CampoVettoriale &) const;
	CampoVettoriale& operator+= (const CampoVettoriale &); //in questo caso non è un const perchè non sto creando un nuovo vettore somma ma sto sommando ame stesso (CampoVettoriale che ha chiamato questo metodo) il campo che viene preso come argomento del metodo

private:

	double m_Fx, m_Fy, m_Fz;

};

#endif // __CampoVettoriale_h__
