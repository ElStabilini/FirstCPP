#ifndef __INTEGRALEMC_H__
#define __INTEGRALEMC_H__

#include "RandomGen.h"
#include "Funzioni.h"
#include <cmath>
#include <vector>

using namespace std;

class IntegraleMC {
	
public :

	IntegraleMC(unsigned int seed);
	~IntegraleMC();

	double Media(const FunzioneBase* f, double xmin, double xmax, unsigned int punti);

	double MediaFixedPrec(const FunzioneBase* f, double xmin, double xmax, double prec);
	
	template <typename T> double MediaFixedPrec(const FunzioneBase* f, double xmin, double xmax, double prec, const vector<T> v);



	double HitMiss(const FunzioneBase *f, double xmin, double xmax, unsigned int punti);

	double HitMiss(const FunzioneBase *f, double xmin, double xmax, unsigned int punti, double M);

	double HitMissFixedPrec(const FunzioneBase *f, double xmin, double xmax, double prec, double M);
	
	template <typename T> double HitMissFixedPrec(const FunzioneBase *f, double xmin, double xmax, double prec, double M, const vector<T> v);
	
	double GetErrore() const {return m_errore;}
	unsigned int GetN() const {return m_punti;}

private :

	RandomGen m_gen;
	double m_errore;
	unsigned int m_punti;
};

#endif //__INTEGRALEMC_H__	
