#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

#include "Funzioni.h"

class RandomGen{
  public:

     RandomGen(unsigned int i) {
			 m_a = 1664525;
			 m_c = 1012904223;
			 m_m = pow(2, 31);
			 m_seed = i ;
		 }

		 void SetSeed(unsigned int seed) {m_seed = seed;}
     void SetA(unsigned int a) {m_a = a;}
     void SetC(unsigned int c) {m_c = c;}
     void SetM(unsigned int m) {m_m = m;}
		 //double GetXi() {return m_xi;}
		 double GetMa() {return m_a;}
		 double GetMm() {return m_m;}
		 double GetMc() {return m_c;}
		 unsigned int GetSeed() {return m_seed;}

     double Rand();
     double Unif(double xmin, double xmax);
     double Exp(double mean);
     double Gauss(double mean, double sigma);
     double GaussAR(double mean, double sigma);
		 double AcceptReject(FunzioneBase *f);

  private:
     unsigned int m_a,m_c, m_m;
     unsigned int m_seed;
};
#endif
