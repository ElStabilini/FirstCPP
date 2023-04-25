#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "Funzioni.h"

//DEFINISCO LA CLASSE MADRE ASTRATTA INTEGRATORE

class Integratore{

public:
  
	virtual double IntegraNstep(unsigned nstep) = 0; 
	virtual double IntegraPrec(double prec) = 0;
	virtual double GetH() = 0;
	virtual double GetA() = 0;
	virtual	double GetB() = 0;
	virtual	double GetSum() = 0;
	virtual void SetA(double ) = 0;
	virtual void SetB(double ) = 0;
	virtual void SetH(double ) = 0;


protected:

  double m_a, m_b;
  double m_sum;
  double m_h;
  int m_sign;
  double m_integral;
  const FunzioneBase* m_f;
  
};


//==========================================================================
//DEFINISCO LA CLASSE FIGLIA MIDPOINT
class Midpoint : public Integratore {

public:
	//costruttore
	Midpoint(double a, double b, const FunzioneBase* f) {
		m_f = f;
  	m_a = min(a,b);
  	m_b = max(a,b);
  	if ( a > b) m_sign = -1;
  	else m_sign = 1;   
	};

	~Midpoint() {;};

	double GetA() {return m_a;};
	double GetB() {return m_b;};
	double GetSum() {return m_sum;};
	double GetH() {return m_h;};
	void SetA(double a) {m_a = a;};
	void SetB(double b) {m_b = b;};
	void SetH(double h) {
		if (h<1E-6) {
			cout << "passo h troppo piccolo" << endl;
			exit(-1);
		} else {
			m_h = h;
		}
	};

	double IntegraNstep(unsigned nstep);
	double IntegraPrec(double prec) {cout << "no" << endl;};

};



//==========================================================================
//DEFINISCO LA CLASSE FIGLIA SIMPSON
class Simpson : public Integratore {
	
public:

	Simpson(double a, double b, const FunzioneBase* f) {
		m_f = f;
  	m_a = min(a,b);
  	m_b = max(a,b);
  	if ( a > b) m_sign = -1;
  	else m_sign = 1;   
	};

	~Simpson() {;};

	double GetA() {return m_a;};
	double GetB() {return m_b;};
	double GetSum() {return m_sum;};
	double GetH() {return m_h;};
	void SetA(double a) {m_a = a;};
	void SetB(double b) {m_b = b;};
	void SetH(double h) {
		if (h<1E-6) {
			cout << "passo h troppo piccolo" << endl;
			exit(-2);
		} else {
			m_h = h;
		}
	};

	double IntegraNstep(unsigned nstep);
	double IntegraPrec(double prec);

};

//==========================================================================
//DEFINISCO LA CLASSE FIGLIA TRAPEZI
class Trapezi : public Integratore {
	
public:

	Trapezi(double a, double b, const FunzioneBase* f) {
		m_f = f;
  	m_a = min(a,b);
  	m_b = max(a,b);
  	if ( a > b) m_sign = -1;
  	else m_sign = 1;   
	};

	~Trapezi() {;};

	double GetA() {return m_a;};
	double GetB() {return m_b;};
	double GetSum() {return m_sum;};
	double GetH() {return m_h;};
	void SetA(double a) {m_a = a;};
	void SetB(double b) {m_b = b;};
	void SetH(double h) {
		if (h<1E-6) {
			cout << "passo h troppo piccolo" << endl;
			exit(-2);
		} else {
			m_h = h;
		}
	};

	double IntegraNstep(unsigned nstep);
	double IntegraPrec(double prec);

};


#endif
