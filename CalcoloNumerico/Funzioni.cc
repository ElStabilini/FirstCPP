#include "Funzioni.h"
#include <iostream>
#include <cmath>

/*
	IMPLEMENTAZIONE METODI PARABOLA 
*/

Parabola::Parabola()  {
	cout << "calling default constructor" << endl;
	m_a = 0; m_b = 0;	m_c = 0;
	};

Parabola::Parabola(double a, double b, double c) {
		cout << "calling construcr with arguments" << endl;
		m_a = a;
		m_b = b;
		m_c = c;
};

Parabola::Parabola(const Parabola& p)  {
	cout << "calling copy constructor" << endl;
	m_a = p.GetA();
	m_b = p.GetB();
	m_c = p.GetC();
};


void Parabola::Print () const {
	cout << "f(x) = " << GetA() << "x^2 + " << GetB() << "x + " << GetC() << endl;
};

void Coseno::Print() const {
	cout << "f(x) = " << GetA() << "cos(" << GetB() << "x + " << GetC() << ") + " << GetD() << endl;
};

void Retta::Print() const {
	cout << "f(x) = " << GetA() << "x + " << GetB() << endl;
};


double FunzioneModulo::Eval(double x) const {
	if(m_f->Eval(x) >= 0)
		return m_f->Eval(x);
	else
		return (-1)*m_f->Eval(x);
};




/*=============================================================
IMPLEMENTAZIONE METODI FUNZIONE INTEGRAlE
=============================================================*/
FunzioneIntegrale::FunzioneIntegrale(double d, double lambda, double L, double prec) {
	m_lambda = lambda;
	m_d = d;
	m_L = L;
	m_prec = prec;
}

double FunzioneIntegrale::Eval(double x) const {
	FunzioneBase * Integranda = new FunzioneF(m_d, m_lambda, x, m_L);
	Integratore * myTrapezi = new Trapezi(-m_d/2, m_d/2, Integranda);
	return myTrapezi->IntegraPrec(m_prec);

	delete[] Integranda;
	delete[] myTrapezi;
}

/*=============================================================
IMPLEMENTAZIONE METODI FUNZIONE F (può essere sostituita con una generica funzione)
=============================================================*/

//Per questa funzione x è un parametro
FunzioneF::FunzioneF(double d, double lambda, double x, double L) {
	m_lambda = lambda;
	m_d = d;
	m_L = L;
	m_x = x;
};

double FunzioneF::Eval(double t) const {
	return cos(m_L/m_lambda * (sqrt(1+pow( ((m_x - t)/m_L), 2 )) - sqrt(1+  m_x*m_x/m_L*m_L )))/m_d;
};


/*=============================================================
IMPLEMENTAZIONE METODI FUNZIONE INTEGRAlE con ESTREMI DIVERSI
=============================================================*/
FunzioneIntegraleEstremi::FunzioneIntegraleEstremi(double ext1, double ext2, double d, double lambda, double L, double prec) {
	m_lambda = lambda;
	m_ext1 = ext1;
	m_ext2 = ext2;
	m_d = d;
	m_L = L;
	m_prec = prec;
}

double FunzioneIntegraleEstremi::Eval(double x) const {
	FunzioneBase * Integranda = new FunzioneF(m_d, m_lambda, x, m_L);
	Integratore * myTrapezi = new Trapezi(m_ext1, m_ext2, Integranda);
	return myTrapezi->IntegraPrec(m_prec);

	delete[] Integranda;
	delete[] myTrapezi;
}
