#ifndef __funzioni_h__
#define __funzioni_h__

#include <iostream>
#include <cmath>
#include <vector>

//SE da problemi in fase di copmilazione commenta le funzioni print

/*
	DICHIARAZIONE FUNZIONE BASE - FUNZIONE MADRE ASTRATTA
*/

using namespace std;

class FunzioneBase{

public:

  	virtual double Eval(double x) const = 0;
	virtual void Print() const = 0;
	//virtual double operator () (double x) const = 0;
};



/* =========================================================================
	DICHIARAZIONE FUNZIONE PARABOLA
==========================================================================*/
class Parabola: public FunzioneBase{

public:
	
	//costruttori
  Parabola();
  Parabola(double a, double b, double c);

	//costruttore di copia
	Parabola(const Parabola& p);

	//distruttore
  ~Parabola() {;};

  virtual double Eval(double x) const {return m_a*x*x + m_b*x + m_c;};
  void SetA(double a) {m_a = a;};
  void SetB(double b) {m_b = b;};
  void SetC(double c) {m_c = c;};
  double GetA() const {return m_a;};
  double GetB() const {return m_b;};
  double GetC() const {return m_c;};

	double GetVertice() const {return -GetB()/(2*GetA());};
	virtual void Print () const;

	virtual double operator() (double x) const {return m_a*x*x + m_b*x + m_c;};

private:

  double m_a, m_b, m_c;

};


/* =========================================================================
	DICHIARAZIONE FUNZIONE COSENO
==========================================================================*/

class Coseno : public FunzioneBase {

public:
	Coseno() {m_a = 0; m_b = 1; m_c = 0; m_d = 0;};
	Coseno(double a, double b, double c, double d) { m_a = a;	m_b = b; m_c = c; m_d = d;};

  ~Coseno() {;};

	void SetA(double a) {m_a = a;};
  	void SetB(double b) {m_b = b;};
  	void SetC(double c) {m_c = c;};
	void SetD(double d) {m_d = d;};
  	double GetA() const {return m_a;};
  	double GetB() const {return m_b;};
 	double GetC() const {return m_c;};
	double GetD() const {return m_d;};

	virtual double Eval(double x) const {return m_a*cos(m_b*x + m_c) + m_d;};

	virtual void Print() const;

private:
	double m_a, m_b, m_c, m_d;

};

/* =========================================================================
	DICHIARAZIONE FUNZIONE RETTA
==========================================================================*/

class Retta : public FunzioneBase {

public:

	Retta() {m_a = 0; m_b = 0;};
	Retta(double a, double b) {m_a = a; m_b = b;};

	~Retta() {;};

  	double GetA() const {return m_a;};
  	double GetB() const {return m_b;};
	void SetA(double a) {m_a = a;};
  	void SetB(double b) {m_b = b;};

	virtual double Eval(double x) const {return m_a*x + m_b;};

	virtual void Print() const;
	
private:
	double m_a, m_b;

};


/* =========================================================================
	DICHIARAZIONE FUNZIONE SOMMA
==========================================================================*/
class FunzioneSomma : public FunzioneBase {

public:
	//costruttore
	FunzioneSomma(FunzioneBase * f1, FunzioneBase * f2) {m_f1 = f1; m_f2 = f2;};
	virtual double Eval(double x) const {return m_f1->Eval(x) + m_f2->Eval(x);};

private:
	FunzioneBase * m_f1;
	FunzioneBase * m_f2;

};

/* =========================================================================
	DICHIARAZIONE FUNZIONE PRODOTO
==========================================================================*/

class FunzioneProdotto : public FunzioneBase {

public:
	//costruttore
	FunzioneProdotto(FunzioneBase * f1, FunzioneBase * f2) {m_f1 = f1; m_f2 = f2;};
	virtual	double Eval(double x) const {return m_f1->Eval(x)*m_f2->Eval(x);};

private:
	FunzioneBase * m_f1;
	FunzioneBase * m_f2;
};

/* =========================================================================
	DICHIARAZIONE FUNZIONE DIFFERENZA
==========================================================================*/

class FunzioneDifferenza : public FunzioneBase {

public:
	//costruttore
	FunzioneDifferenza(FunzioneBase * f1, FunzioneBase * f2) {m_f1 = f1; m_f2 = f2;};
	virtual	double Eval(double x) const {return m_f1->Eval(x)-m_f2->Eval(x);};

private:
	FunzioneBase * m_f1;
	FunzioneBase * m_f2;
};

//=========================================================================
/*
	DICHIARAZIONE GAUSSIANA - è una classe a parte, non è figlia di nessuna classe

*/
class Gaussiana {

public :

	//costruttore
	Gaussiana(double mean, double sigma) {
		m_mean = mean; 
		m_sigma = sigma;
	};

		double Eval(double x) const { 
		double c= 1/(m_sigma*sqrt(2*M_PI));
		double e = exp(-pow((x-m_mean), 2)/( 2*pow(m_sigma, 2) ));
		return e*c;
		}

private :
	double m_mean;
	double m_sigma;
};


//========================================================================
/*
	DICHIRAZIONE FUNZIONE GRADINO
*/

class FunzioneGradino : public FunzioneBase {

public:

	FunzioneGradino() {m_a = 1; m_b = 0;};
	FunzioneGradino(double a, double b) {m_a = a; m_b = b;};
	~FunzioneGradino() {;};

	void SetA(double a) {m_a = a;};
	void SetB(double b) {m_b = b;};
	double GetA() const {return m_a;};
  double GetB() const {return m_b;};

	virtual double Eval(double x) const {
		double n;
		if (-1 <= x || x <= 1)
			n=1;
		if (x < -1 || x > 1)
			n=0;
		return n;
	};

//=========================================================================

/*
	DICHIARAZIONE FUNZIONE APPROSSIMATA
*/

class FunzioneApprossimata : public FunzioneBase {

public:
	//costruttore
	FunzioneApprossimata(FunzioneBase* polinomio[], int n, double v[], double parametro) {
		//passagli il vettore della dimnesione che ti serve altrimenti dovreti templetizzare la funzione per usare un vector o gestire array dinamici
		
		for (int i=0; i<n; i++) {
			m_v[i] = v[i];
			m_pol[i] = polinomio[i]; //in alternativa puoi definire l'operatore = per gli array
		}
		m_para = parametro;
	};

	virtual double Eval(double x) const {
	
		double sum = 0;
		for (int i=0; i<m_n; i++) {
			sum = sum + m_v[i]*m_pol[i]->Eval(x);
		}

		return sum + m_para;
	};


private:
	FunzioneBase* m_pol[10];
	double m_v[10]; //scegli la dimensione a seconda di quello di cui hai bisogno, se usi un array statico (meglio perchè non devi templatizzare FunzionBase e non devi gestire la memoria con i vettori dinamici) hai bisogno di sapre a priori quanta memoria devi allocare
	double m_para; //eventuale parametro da aggiungere esterno alla sommatoria
	int m_n; //numero effettivo di elementi nel vettore

};

/*
======================================================================
	DICHIARAZIONE FUNZIONE MODULO
======================================================================
*/

	class FunzioneModulo : public FunzioneBase {

public:
	//costruttore
	FunzioneModulo(FunzioneBase * f) {m_f = f;};
	virtual double Eval(double x) const;

private:
	FunzioneBase * m_f;

};

/* ======================================================================
	DICHIARAZIONE FUNZIONE INTEGRALE
======================================================================*/

class FunzioneIntegrale : public FunzioneBase {

public:
	//costruttore
	FunzioneIntegrale(double d, double lambda, double L, double prec);
	virtual double Eval(double x) const;

private:
	double m_d, m_L, m_lambda, m_prec;

};

/*====================================================================
DICHIARAZIONE FUNZIONE GENERICA
==================================================================*/

//Per questa funzione x è un parametro
class FunzioneF : public FunzioneBase {

public:
	FunzioneF(double d, double lambda, double x, double L);
	~FunzioneF() {;};

	virtual double Eval(double t) const;

private:
	double m_lambda, m_d, m_L, m_x;
};


//la funzione GENERICA è da usare insieme alla funzione integrale:
//la funzione integrale è una funzione A(x) = integrale (d/dt) ovvero per conoscere il valore di A nel punto x devo integrare l'integranda in dt
//quello che faccio è fare variare x su un intervallo (intervallo su cui voglio plottare) e PER OGNI VALORE DI X - che quindi viene vista dall'integranda come un parametro - DEVO CALCOLARE L'INTEGRALE IN dt SU UN ALTRO INTERVALLO


/* ======================================================================
	DICHIARAZIONE FUNZIONE INTEGRALE con ESTREMI DIVERSI
======================================================================*/

class FunzioneIntegraleEstremi : public FunzioneBase {

public:
	//costruttore
	FunzioneIntegraleEstremi(double ext1, double ext2, double d, double lambda, double L, double prec);
	virtual double Eval(double x) const;

private:
	double m_ext1, m_ext2, m_d, m_L, m_lambda, m_prec;

};



#endif
