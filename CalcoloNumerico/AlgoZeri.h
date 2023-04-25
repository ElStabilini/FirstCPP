/*
The algorithms to find zeros of a function are coded here. The base class
Solutore represents a generic algorithm. Concrete algorithms ( Bisezione,
Secanti and Newton ) derive from the baseclass
*/

#ifndef __AlgoZeri_h__
#define __Algozeri_h__

#include "Funzioni.h"
#include <cmath>
#include "iostream"

using namespace std;

//creo una classe solutore che ha come datamembri privati m_prec che definisce la precisione con cui voglio conoscere lo zero della mia funzione,  m_a che definisce il primo estremo dell'intervallo e m_b che definisce invece l'insieme sinistro dell'intervallo 

class Solutore{

public:

	virtual double CercaZeri(double xmin, double xmax, const FunzioneBase* f) = 0;

  virtual void SetPrecision(double epsilon) {
		if (epsilon < 10E-7) {
			cout << "valore di precisione troppo piccolo" << endl;
			exit(2);
		} else {
			m_prec = epsilon;
			};
	};

	virtual	void SetNmax(long double nmax) {
		if (nmax > 100) {
			cout << "numero massimo di iterazioni troppo grande" << endl;
			exit(3);
		} else {
			m_nmax = nmax;
		};
	};

	virtual void SetA(double a) {m_a = a;};
	virtual void SetB(double b) {m_b = b;};
	virtual double GetA() const {return m_a;};
	virtual double GetB() const {return m_b;};
  virtual double GetPrecision() const {return m_prec;};
	virtual double GetNmax() const {return m_nmax;};

protected:

  double m_a, m_b;
  double m_prec;
	long double m_nmax;

};

double sign(double);

class Bisezione: public Solutore 	{

	public:

  	Bisezione(double xmin, double xmax, double prec) {
			m_a = xmin; m_b = xmax; m_prec = prec;
			m_nmax = 100;
		};

		Bisezione() {
			m_a = 0; m_b = 0; m_prec = 0,001; 
			m_nmax = 100;
		}

 	virtual ~Bisezione() {;};

  virtual double CercaZeri(double xmin, double xmax, const FunzioneBase* f);

};

#endif

//immagina di definire l'n max come datamembro
