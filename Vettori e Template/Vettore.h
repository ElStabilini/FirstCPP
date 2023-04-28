#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>

using namespace std;

template <typename T> class Vettore {
                          
 public:
  
	Vettore() {
		cout << "Calling default constructor" << endl;
  	m_N = 0;
  	m_v = NULL;
	};
	
	Vettore(unsigned int N) {
  	cout << "Calling constructor with arguments" << endl;
 	 	m_N = N;
  	m_v = new T[N];
  	for ( int k = 0 ; k < N ; k++ ) 
			m_v[k] = 0;
  }; //costruttore con dimensione del Vettore

	//definisco il distruttore
	~Vettore() {
		cout << "Calling destructor" << endl;
		delete [] m_v;
	};
	
	//definisco i metodi
	unsigned int GetN() const {return m_N;}  //accede e mi restituisce la dimensione del Vettore

	T GetComponent(unsigned int i) const {
		//assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
		if (i < m_N) {
			return m_v[i];
		} else { 
			cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
    	exit (-1);
		};
	}
	
	void SetComponent(unsigned int i, T a) {
		//assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
		if (i < m_N) {
			m_v[i] = a;
		} else {
			cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
    	exit (-1);
		};
	}
	//accede a una cella del vettore e ne modifica il valore come mi serve

	void Scambia(unsigned int i, unsigned int j) {
	//assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
	//assert( ( m_N > j ) && "Errore : l'indice e' troppo grande");
	T temp = GetComponent(i);
	SetComponent(i, GetComponent(j));
	SetComponent(j, temp);
	};

	//operatore reference - overloading di operatore d'accesso a una variabile -
	T& operator[](unsigned int i) {
		//assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
		if (i < m_N) {
			return m_v[i];
		} else { 
			cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
    	exit (-1);
		}
	};

	//definisco il copy contructor
	Vettore(const Vettore& V) {
		m_N = V.GetN();
		m_v = new T[m_N];
		for (int i=0; i<m_N; i++) 
			m_v[i]=V.GetComponent(i);
	}

	//definisco un operatore di assegnazione della classe vettore
	Vettore& operator=(const Vettore& V) {
		m_N = V.GetN();
		if (m_v) //se esiste questo
			delete[] m_v; //lo dealloco
		m_v = new T[m_N]; 
		for (int i=0; i < m_N; i++)
			m_v[i] = V.GetComponent(i);
		return *this;
	}	

 private:
  
   unsigned int m_N;                        
   T* m_v;     
  
};

#endif // __Vettore_h__


