#ifndef __VecOp_h__
#define __VecOp_h__

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>  // se se vogliono usare algoritmi STL
#include <numeric>    // std::inner_product

using namespace std;

// somma di due vettori : somma componente per componente
//static_cast  fa il cambio di tipo

template <typename T> vector<T> operator+(const vector<T> &a, const vector<T> &b) {
  
	//se l'affermazione dell'assert non è vera il programma viene bloccato
  assert(a.size() == b.size());  
  vector<T> result(a.size()); //creo un oggetto vector<T> result della stessa dimensione del vector
  
	//inizializzo le componenti del vector con la somma per componenti a +b
  for (int i = 0; i < static_cast<int>(a.size()); i++) 
		result[i] = a[i] + b[i];    
  
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //    std::transform(a.begin(), a.end(), b.begin(), result.begin() , std::plus<T>()); 
  
  return result;
}

// differenza di due vettori componente per componente

//template <typename T> vector<T> -> mi restituisce un vector
template <typename T> vector<T> operator-(const vector<T> &a, const vector<T> &b) {
  
	//se l'affermazione dell'assert non è vera il programma viene bloccato
  assert(a.size() == b.size()); 
  vector<T> result(a.size()); //creo un oggetto vector<T> result della stessa dimensione del vector
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) 
		result[i] = a[i] - b[i];    
  
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //    std::transform(a.begin(), a.end(), b.begin(), result.begin() , std::minus<T>()); 
  
  return result;
}


// prodotto scalare tra due vettori 
//template <typename T> T -> mi restituisce un oggetto di tipo typename
template <typename T> T operator*(const vector<T> &a, const vector<T> &b) {

	assert(a.size() == b.size());  
 	T sum = 0;

	for (int i = 0; i < static_cast<int>(a.size()); i++)
		sum = sum + a[i]*b[i];

	return sum;  
}


// prodotto tra uno scalare e un vettore
template <typename T> vector<T> operator*( T c , const vector<T> &a) {
	
	vector<T> result(a.size());
	for (int i = 0; i < static_cast<int>(a.size()); i++) 
		result[i] = a[i]*c;
	
	return result;  
}


// prodotto tra un vettore e uno scalare 

template <typename T> vector<T> operator*( const vector<T> &a , T c) {

 vector<T> result(a.size());
	for (int i = 0; i < static_cast<int>(a.size()); i++) 
		result[i] = a[i]*c;
	
	return result;   
}


// somma ad a un vettore b e il risultato viene messo in a

template <typename T> vector<T>& operator+=(std::vector<T>& a, const vector<T>& b) {
  
  assert(a.size() == b.size());  
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) 
		a[i] += b[i];    
  
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //    std::transform(a.begin(), a.end(), b.begin(), a.begin() , std::plus<T>()); 
  
  return a;
}


// sottrai ad a un vettore b e il risultato viene messo in a

template <typename T> vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  
  assert(a.size() == b.size());  
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) 
		a[i] -= b[i];    
  
  //    std::transform(a.begin(), a.end(), b.begin(), a.begin() , std::minus<T>()); 
  
  return a;
}


//faccio un'overload dell'operatore << per i vettori
//creo una funzione template che mi restituiscecome output una reference ad un'ostream
template <typename T> ostream& operator <<(ostream& os, const vector<T> &v ) {

	os << "[ ";
  for (unsigned int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	os << "]";
  return os;	
	
};

#endif
