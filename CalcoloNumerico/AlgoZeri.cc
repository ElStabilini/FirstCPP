
#include <cmath>
#include "iostream"
#include "AlgoZeri.h"
#include <iomanip>

using namespace std;

double sign(double x) {
	if (x > 0) {
		return 1;
		}	else { 
			return -1;
		}
};

double Bisezione::CercaZeri(double xmin, double xmax, const FunzioneBase* f) {

	int cifre_significative = -log10(GetPrecision());
	//cout << "cifre significative = " << cifre_significative << endl;

	if (xmin < xmax) {
		//fisso il valore m_a dell'intervallo a xmin e m_b a xmax 
		SetA(xmin);
		SetB(xmax); 
	} else {
		SetA(xmax);
		SetB(xmin);
	}
		
	double a = GetA();
	double b = GetB();
	double fa = f->Eval(a);
	double fb = f->Eval(b);
		
	if (sign(fa)*sign(fb) > 0) {
		cout << "la funzione non ha zeri nell'intervallo" << endl;
		exit(1);
	} else {
		unsigned int niterations = 0;
		//unsigned int nmax = 100; //CAMBIA E METTILO COME DATAMEMBRO
		while (fabs(b-a) > GetPrecision()) {
			/*cout << "a = " << a << endl;
			cout << "b = " << b << endl;
			cout << "fa = " << fa << endl;
			cout << "fb = " << fb <<endl;*/
			
			double c = (b+a)/2;
			double fc = f->Eval(c);

			/*cout << "c = " << c << endl;
			cout << "fc = " << fc << endl;
			cout << endl;*/

			if (niterations > GetNmax()) break;
			niterations ++;

			if (sign(fa)*sign(fc)<0) {
			//se la funzione cambia segno nell'intervallo ac allora l'estremo sinistro rimane a e l'estremo destro diventa c
				b = c;
				fb = fc; 
			} else if (sign(fb)*sign(fc)<0) {
				a = c;
				fa = fc;
			} //return 0. ;
		}
	}
	
	cout << "finished" << endl;
	cout << "x_zero = ";
	cout <<fixed;
	cout << setprecision(cifre_significative) << (b+a)/2 <<endl;
	return (b+a)/2;
		
};

