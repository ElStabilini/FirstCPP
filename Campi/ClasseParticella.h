#ifndef __Particella_h__
#define __Particella_h__

#include <string>
#include <iostream>

//#include "Posizione.h"

using namespace std;

/***********************************************************
 * Classe astratta per una generica particella
 * definisce i metodi che ogni particella 
 * deve implementare e delle funzioni di utilizzo generale.
 ***********************************************************/

class Particella {

public:

  // costruttori
  Particella() {
		cout <<"calling default costructor" << endl;
		m_massa = 0;
		m_carica = 0;
	};

  Particella(double massa, double carica) {
		cout <<"calling costructor with arguments" << endl;
		m_massa = massa;
		m_carica = carica;
	}

  // distruttore
  ~Particella() {;};

  // metodi
  double GetMassa() const  {return m_massa;};
  double GetCarica() const {return m_carica;};
  void Print() const {
		cout << "stampa particella" << endl;
		cout << "massa: " << m_massa << endl;
		cout << "carica: " << m_carica << endl;
	};

 protected:

  double m_massa;
  double m_carica;

};

/*********************************************************
 * Implementazione concreta di una particella elementare
 * in questo caso tutte le proprietà della particella 
 * sono costanti, definite nel costruttore di default.
 ***********************************************************/

class Elettrone : public Particella {
public:
  // costruttore
  Elettrone() {
		m_massa = 9.109E-31;
		m_carica = 1.602E-19;
	} ;

  // distruttore
  //~Elettrone();
  
	//pseudo cpoy constructor
	Elettrone (Particella) {
		cout << "calling p-copy constructor" << endl;
		m_massa = 9.109E-31;
		m_carica = -1.602E-19;
	}

  void Print() const {
		cout << "stampa elettrone" << endl;
		cout << "massa: " << m_massa << endl;
		cout << "carica: " << m_carica << endl;
	};

};

#endif // __Particella_h__

