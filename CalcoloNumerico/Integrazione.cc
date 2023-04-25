#ifndef __Integral_h__
#define __Integral_h__

#include <cmath>
#include <iomanip>

#include "iostream"
#include "Integral.h"
#include "Funzioni.h"

using namespace std;

/*====================================================================
implementazione metodo MIDPOINT con N FISSATO
====================================================================*/
double Midpoint::IntegraNstep(unsigned nstep) {

	if(m_a == m_b) return 0;
	m_h = (m_b - m_a)/double(nstep);
  m_sum = 0.;

  for (unsigned int i=1; i<nstep; i++){
    m_sum += m_f->Eval( m_a + (i+0.5)*m_h );
  }	

  m_integral = m_sign*m_sum*m_h;
  return m_integral;
};


/*===================================================================
implementazione metodo SIMPSON con N FISSATO
====================================================================*/
double Simpson::IntegraNstep(unsigned nstep) {

	if (m_a == m_b) return 0;
	m_h = (m_b - m_a)/double(nstep); //definisco il passo in funzione del numero di passi inserito
  m_sum = 0.; //inzializzo la somma

	//separo il caso indice pari - indice dispari
	for (unsigned int i=1; i<nstep; i++) {
		if(i%2 == 0) {
			//se l'indice è pari considero per la somma 4 volte il valore della funzione nel punto a+ i*h;
			m_sum = m_sum + (2*m_f->Eval(m_a + i*m_h));
		} else { 
			//se l'indice è dispari considero per la somma 2 volte il valore della funzione nel punto a+ i*h;
			m_sum = m_sum + (4*m_f->Eval(m_a + i*m_h));
		}
	}

	double f0 = m_f->Eval(m_a); //valuto f nel primo estremo di integrazione
	double fn = m_f->Eval(m_b); //valuto f nel secondo estremo di integrazione
	m_integral = m_sign*(m_h/3)*(f0 + m_sum + fn);
	
};



/*====================================================================
METODO di SIMPSON a PRECISIONE FISSATA
=====================================================================*/

double Simpson::IntegraPrec(double prec) {

	if(m_a == m_b) return 0;
	//controllo la precisione inserita
	double limit = 1E-8;
	if (prec < limit) {
		cout << "precision limit: " << limit << endl;
		exit(-3);
	}

	double In = 0;
	double I2n = 0;
	double err = 999;

	if(m_a == m_b) return 0;
	m_sum = 0;
	m_h = m_b - m_a;

	for(int n=2; err > prec; n=n*2) {
		In = m_h*(0.5*m_f->Eval(m_a) + 0.5*m_f->Eval(m_b) + m_sum);
		m_h = (m_b - m_a)/n;

		for(int k = 1; k<n; k= k+2) {
			m_sum = m_f ->Eval(k*(m_b + m_a)/n);
		}

		I2n = m_h*(0.5*m_f->Eval(m_a) + 0.5*m_f->Eval(m_b) + m_sum);

		m_err = 4*fabs(In - I2n);
	}

	m_h = sqrt((prec*15*m_h*m_h)/(16*fabs(In-I2n)));
	m_sum = 0;
	unsigned int nstep = static_cast<int>((m_b-m_a)/m_h);
	m_h = (m_b - m_a)/nstep;

	return IntegraNstep(nstep);
};



/*====================================================================
METODO dei TRAPEZI con N FISSATO
====================================================================*/

double Trapezi::IntegraNstep(unsigned nstep) {

	if (m_a == m_b) return 0;
	m_h = (m_b - m_a)/double(nstep); //definisco il passo a partire dal numero di passi fissato
  m_sum = 0.;

	//valuto la funzione dopo ogni passo
	for (unsigned int i=1; i<nstep; i++){
    m_sum += m_f->Eval(m_a + i*m_h);
  }	

	//valuto la funzione agli estremi di integrazione
	double fa = m_f->Eval(m_a); 
	double fb = m_f->Eval(m_b);

	m_integral = m_sign*(0.5*fa + m_sum + 0.5*fb)*m_h;
  return m_integral;

};


/*====================================================================
METODO dei TRAPEZI a PRECISIONE FISSATA
====================================================================*/

double Trapezi::IntegraPrec(double prec) {

	if(m_a == m_b) return 0;
	//controllo la precisione inserita
	double limit = 1E-8;
	if (prec < limit) {
		cout << "precision limit: " << limit << endl;
		exit(-3);
	}

	double In = 0;
	double I2n = 0;
	double err = 999;

	if(m_a == m_b) return 0;
	m_sum = 0;
	m_h = m_b - m_a;

	for(int n=2; err > prec; n=n*2) {
		In = m_h*(0.5*m_f->Eval(m_a) + 0.5*m_f->Eval(m_b) + m_sum);
		m_h = (m_b - m_a)/n;

		for(int k = 1; k<n; k= k+2) {
			m_sum = m_f ->Eval(k*(m_b + m_a)/n);
		}

		I2n = m_h*(0.5*m_f->Eval(m_a) + 0.5*m_f->Eval(m_b) + m_sum);

		m_err = 4*fabs(In - I2n);
	}

	m_h = sqrt((prec*3*m_h*m_h)/(4*fabs(In-I2n)));
	m_sum = 0;
	unsigned int nstep = static_cast<int>((m_b-m_a)/m_h);
	m_h = (m_b - m_a)/nstep;

	return IntegraNstep(nstep);

};

#endif



