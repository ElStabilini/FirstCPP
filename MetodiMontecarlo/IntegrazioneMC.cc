#include "IntegrazioneMC.h"
#include "Funzioni.h"
#include "RandomGen.h"
#include "statistica.h"
#include <cmath>
#include <vector>

using namespace std;

IntegraleMC::IntegraleMC(unsigned int seed) : 
	m_gen(seed),
	m_errore(0.)
{};

IntegraleMC::~IntegraleMC() {};

/*=============================================================================*/

//Metodi MEDIA
double IntegraleMC::Media(const FunzioneBase* f, double xmin, double xmax, unsigned int punti) {

	double sum = 0;
	double x = 0;
	
	for (int i=0; i<punti; i++) {
		x = m_gen.Unif(xmin, xmax);
		double fi = f->Eval(x);
		sum = sum + fi;
	}

	m_gen.SetSeed(m_gen.GetSeed()+1);

	return (sum/punti)*(xmax-xmin);
};

//metodo di integrazione (montecarlo) della media a precisione fissata
double IntegraleMC::MediaFixedPrec(const FunzioneBase* f, double xmin, double xmax, double prec) {
	unsigned int M = 100; //numero di volte per cui calcolo l'integrale per poi stimare la deviazione standard
	vector<double> v;
	IntegraleMC myintegral(1);

	for (int i=0; i<M; i++){
		v.push_back(myintegral.Media(f, xmin, xmax, 100));
	}

	double dev = CalcolaDev(v);
	double k = dev*sqrt(100);
	double N = k*k/(prec*prec);

	double I = myintegral.Media(f, xmin, xmax, N);
	return I;
};


//metodo di integrazione (montecarlo) della media a precisione fissata in cui ho già calcolato M volte l'integrale e passo gli M valori in un vettore
template <typename T> double IntegraleMC::MediaFixedPrec(const FunzioneBase* f, double xmin, double xmax, double prec, const vector<T> v) {
	IntegraleMC myintegral(1);

	double dev = CalcolaDev(v);
	double k = dev*sqrt(100);
	double N = k*k/(prec*prec);

	double I = myintegral.Media(f, xmin, xmax, N);
	return I;
};


/*=============================================================================*/


//metodi HitMiss
double IntegraleMC::HitMiss(const FunzioneBase *f, double xmin, double xmax, unsigned int punti) {

	double hit = 0;
	double M = 1;

	for (int i=0; i<punti; i++) {
		double x = 0;
		double y = 0;
		x = m_gen.Unif(xmin, xmax);
		double fi = f->Eval(x);
		y = m_gen.Unif(0, M);
		if (y < fi)
			hit++;
	}

	m_gen.SetSeed(m_gen.GetSeed()+1);

	return (xmax-xmin)*M*(hit/punti);
}


double IntegraleMC::HitMiss(const FunzioneBase *f, double xmin, double xmax, unsigned int punti, double M) {

	double hit = 0;
	double max = M;

	//inserire un controllo sul numero dei punti?

	for (int i=0; i<punti; i++) {
		double x = 0;
		double y = 0;
		x = m_gen.Unif(xmin, xmax);
		double fi = f->Eval(x);
		y = m_gen.Unif(0, M);
		if (y < fi)
			hit++;
	}

	m_gen.SetSeed(m_gen.GetSeed()+1);

	return (xmax-xmin)*max*(hit/punti);
};

double IntegraleMC::HitMissFixedPrec(const FunzioneBase *f, double xmin, double xmax, double prec, double M) {
	unsigned int G = 100; //numero di volte per cui calcolo l'integrale per poi stimare la deviazione standard
	vector<double> v;
	IntegraleMC myintegral(1);

	for (int i=0; i<G; i++){
		v.push_back(myintegral.HitMiss(f, xmin, xmax, 100, M));
	}

	double dev = CalcolaDev(v);
	double k = dev*sqrt(100);
	double N = k*k/(prec*prec);

	double I = myintegral.HitMiss(f, xmin, xmax, N, M);
	return I;
};


template <typename T> double IntegraleMC::HitMissFixedPrec(const FunzioneBase* f, double xmin, double xmax, double prec, double M, const vector<T> v) {
	IntegraleMC myintegral(1);

	double dev = CalcolaDev(v);
	double k = dev*sqrt(100);
	double N = k*k/(prec*prec);

	double I = myintegral.HitMiss(f, xmin, xmax, N, M);
	return I;
};

