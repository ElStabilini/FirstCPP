#include <iostream>
#include <fstream> 

#include <vector>

using namespace std;

// =====================================================================

//FUNZIONI STAMPA VETTORI

//stampa su schermo
template <typename T> void Print( const vector<T> & v ) {
  for (unsigned int i=0; i<v.size(); i++) cout << v[i] << endl;
};


//stampa su file
template <typename T> void Print( const vector<T> & v  , char* filename ) {
	ofstream outfile(filename);
	if(!outfile) {
    cerr << "errore apertura file risultati.dat" << endl;
    exit(0);
  }
 
	for (int i=0; i<v.size(); i++)
		outfile << v[i] << endl;

	outfile.close();
	return;

};

// =====================================================================

//FUNZIONI LETTURA VETTORI
template <typename T> vector<T> Read( unsigned int N, char* filename ) {
vector <T> V;
	cout <<"inizio apertura file"<< endl;
  ifstream infile(filename);

  if (!infile) {
		cerr << "errore apertura file" << endl;
    exit(1);
	}

	for (unsigned int i = 0; i < N; i++) {
		double x = 0;
		infile >> x;
    if (infile.eof()) {
      cout << "fine dati da leggere" << endl;
       break;
    } else {
			V.push_back(x);
		}
	}

  return V;

};

template <typename T> vector<T> ReadAll( const char* filename ) {
	vector <T> v;
	cout << "inizio apertura file" << endl;
	ifstream infile(filename);

	if(!infile) {
		cerr << "errore apertura file" << endl;
		exit(2);
	}

	T x;
	while(!infile.eof()) {
		infile >> x;
		cout << x << endl;
		v.push_back(x);
	}

	return v;
};

// =========================================================================
//FUNZIONI STATISTICHE
//==========================================================================

//Calcola MEDIA
template <typename T> double CalcolaMedia( const vector<T> & v) {
double sum = 0;
	for (int i=0; i<v.size(); i++)
		sum = sum + v[i];
	return sum/v.size();
};


//Calcola MEDIANA
template <typename T> double CalcolaMediana( vector<T> v ) {
	
	sort( v.begin(), v.end() ) ;  
  double mediana = 0;
	double x = v.size()/2;
	if (v.size()%2 == 0) {
		mediana = (v[v.size()/2]+v[v.size()/2 -1])/2;
	} else {
		int n = (int)x;
		mediana = v[x];
	}
  return mediana;
	
};


//Calcola VARIANZA
template <typename T> double CalcolaVarianza( const vector<T> & v) {
	double scarto = 0;
	double media = CalcolaMedia(v);
	for (int i=0; i<v.size(); i++)
  	scarto = scarto + pow(v[i] - media, 2);
	return scarto/v.size();
};


//Calcola SIGMA
template <typename T> double CalcolaSigma( const vector<T> & v) {
	double mediaq = pow(CalcolaMedia(v), 2);
	vector<T> quadrato;
	for (int i=0; i<v.size(); i++)
		quadrato.push_back(pow(v[i], 2));
	double qmedia = CalcolaMedia(quadrato);
	return sqrt(qmedia - mediaq);
};


//Calcola CORRELAZIONE
template <typename T> double CalcolaCorrelazione (const vector<T> & x, const vector<T> & y) {
	vector<T> xy;
	for (int i=0; i<10000; i++)
		xy.push_back(x[i]*y[i]);
	double xmedia = CalcolaMedia(x);
	double ymedia = CalcolaMedia(y);
	double xymedia = CalcolaMedia(xy);
	double sx = CalcolaSigma(x);
	double sy = CalcolaSigma(y);
	return (xymedia - xmedia*ymedia)/(sx*sy);
}


//calcola la DEVIAZIONE STANDARD
template <typename T> double CalcolaDev( const vector<T> & v) {
	return sqrt(CalcolaVarianza(v));
};


//Calcola la deviazione standard del campione
template <typename T> double CalcolaDevCampione( const vector<T> & v) {
	double scarto = 0;
	double media = CalcolaMedia(v);
	for (int i=0; i<v.size(); i++)
  	scarto = scarto + pow(v[i] - media, 2);
	return sqrt(scarto/(v.size()-1));
};

// =====================================================================
// in caso si puo' usare anche questa nel main

template <typename T> TH1F FillHisto( const vector<T> & v){
 
  TH1F h ("histo","histo", 100, -10, 100) ;
  h.StatOverflows( kTRUE );
  for ( int k = 0 ; k < v.size() ; k++ ) h.Fill( v[k] );
  return h;

}


