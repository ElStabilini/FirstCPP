#ifndef __EQ_DIFF__
#define __EQ_DIFF__

#include "VectorOperations.h"
#include "Funzioni.h"
#include <cmath>

using namespace std;


//==========================================================================
// Classe astratta, restituisce la derivata nel punto x al tempo t
class FunzioneVettorialeBase {

public:
  virtual vector<double> Eval(double t, const vector<double> & x) const = 0;
};


//==========================================================================
//CASO CONCRETO 1: OSCILLATORE ARMONICO
class OscillatoreArmonico : public FunzioneVettorialeBase {

public:

  OscillatoreArmonico(double omega0) { m_omega0 = omega0; };

  vector<double> Eval(double t, const vector<double> &x) const {
		//dato che qualunque vettore che entrà dovra essere pari (n/2 componenti per la posizione e n/2 per la velocità) inserisco un controllo su questo aspetto

		if(x.size()%2 != 0) {
			cout << "invalid position vector" << endl;
			exit(0);
		}
	
		//se entra un vettore con n dimensioni n/2 saranno per la posizione, da n/2 a n saranno velocità -> la derivata per le prime n/2 componenti saranno le seconde n/2; per le seconde n/2  saranno date da -wo^2*(corispondente prima n/2 componente)
		vector<double> derivative(x.size()); //costruisco il vettore derivata che deve essermi restituito
		double size = x.size();
		for (int i=0; i< size/2; i++)
			derivative[i] = x[i+size/2];

		for (int i=size/2; i<size; i++)
			derivative[i] = -	pow(m_omega0, 2)*x[i-size/2];
		
		return derivative;
  }

private:
  double m_omega0;
};


//==========================================================================
//caso concreto2 : PENDOLO
class Pendolo : public FunzioneVettorialeBase {

public :
	
	const double g = 9.80665;
	Pendolo(double l) { m_omega0 = sqrt(g/l); }; 

	vector<double> Eval(double t, const vector<double> &x) const {

		if(x.size()%2 != 0) {
			cout << "invalid position vector" << endl;
			exit(0);
		}

		vector<double> derivative(x.size());
		
		double size = x.size();
		for (int i=0; i< size/2; i++)
			derivative[i] = x[i+size/2];

		for (int i=size/2; i<size; i++)
			derivative[i] = -	pow(m_omega0, 2)*sin(x[i-size/2]);

		return derivative;
  }

private:
  double m_omega0;
}; 


//==========================================================================
// CASO CONCRETO3: OSCILLATORE FORZATO


class OscillatoreForzato : public FunzioneVettorialeBase {

public :

	OscillatoreForzato (double omega0, double alfa, double omega_f) { 
		m_omega0 = omega0;
		m_alfa = alfa; 
		m_omega_f = omega_f;
	};

	void SetOmegaF (double omega) { m_omega_f = omega;};
	void SetAlfa (double alfa) {m_alfa = alfa;};
	void SetOmega0 (double omega0) {m_omega0 = omega0;};

	vector<double> Eval(double t, const vector<double> &x) const {

			if(x.size()%2 != 0) {
			cout << "invalid position vector" << endl;
			exit(0);
		}

		vector<double> derivative(x.size());

		double size = x.size();
		for (int i=0; i< size/2; i++)
			derivative[i] = x[i+size/2];

		for (int i=size/2; i<size; i++)
			derivative[i] = -	pow(m_omega0, 2)*x[i-size/2] - m_alfa*x[i] + sin(m_omega_f*t);
		
		return derivative;
  }


private :

	double m_omega0;
	double m_alfa;
	double m_omega_f;
};

/*==========================================================================
Caso fisico concreto: RAZZO
==========================================================================*/

class Razzo : public FunzioneVettorialeBase {

public:

	Razzo(double M, double S, double theta0) {
		m_M = M;
		m_S = S;
		m_theta0 = theta0;
		g = 9.80665;
	}

	 vector<double> Eval(double t, const vector<double> &x) const {
		
		if(x.size()%2 != 0) {
			cout << "invalid position vector" << endl;
			exit(0);
		}
	
		vector<double> derivative(x.size()); 
		double size = x.size();

		

		for (int i=0; i< size/2; i++)
			derivative[i] = x[i+size/2];

		if(t<=1) {
			derivative[size/2] = m_S*cos(m_theta0)/m_M;
			derivative[size/2+1] = -g + m_S*sin(m_theta0)/m_M;
		} else {
			derivative[size/2] = 0;
			derivative[size/2+1] = -g;
	
		}

		return derivative;
  }

private:
	double m_M, m_S, m_theta0, g;

};




//==========================================================================
// INTEGRATORE DI EQUAZIONI DIFFERNZIALI

// Classe astratta per un integratore di equazioni differenziali

class EquazioneDifferenzialeBase {
public:
  virtual vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase *f) const = 0;
};



//==========================================================================
// Integratore concreto, METODO DI EULERO

class Eulero : public EquazioneDifferenzialeBase {

public:

  vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase *f) const {
		return x + (f->Eval(t, x))*h;
  }

};


//==========================================================================
// METODO 2: RUNGE KUTTA

class RungeKutta : public EquazioneDifferenzialeBase {

public :
	vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase *f) const {
		//calcolo un nuovo passo dimezzando il precedente
		double h2 = h/2;
		vector<double> k1;
		vector<double> k2;
		vector<double> k3;
		vector<double> k4;

		for (int i=0; i<x.size(); i++) {
			k1[i] = f->Eval(t, x)[i];
			k2[i] = f->Eval(t + h2, x + (h2*k1))[i];
			k3[i] = f->Eval(t + h2, x + (k2*h2))[i];
			k4[i] = f->Eval(t + h, x + (k3*h))[i];
		}

		//implemento la formula di integrazione di RungeKutta
		return x + (k1 + 2.*k2 + 2.*k3 + k4)*(h/6);
	}

};


#endif // __EQ_DIFF__

