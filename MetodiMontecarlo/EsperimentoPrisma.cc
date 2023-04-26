#include <cmath>
#include "EsperimentoPrisma.h"
#include "RandomGen.h"

#define _USE_MATH_DEFINES

//implemento il costruttore della classe EsperimentoPrisma utilizznado una lista di inizializzazione
//utilizzo la lista perchè in questo modo utilizzo il costruttore corretto per m_gen; altrimenti verrebbe invocato il costruttore senza argomenti che epr la mia classe non esiste
EsperimentoPrisma::EsperimentoPrisma():
	m_gen(1),
	m_lambda1(579.1E-9),
	m_lambda2(404.7E-9),
	m_alpha(60.*M_PI/180.),
	m_sigmath(0.3E-3),
	m_A_input(2.7),
	m_B_input(60000E-18)
{
	//per prima cosa calcolo gli indici di rifrazione attesi (indici "teorici" che ottengo dai parametri iniziali che ho inserito)
	m_n1_input = sqrt(m_A_input + m_B_input / pow(m_lambda1, 2)) ;
	m_n2_input = sqrt(m_A_input + m_B_input / pow(m_lambda2, 2)) ;

	//assegno un valore arbitrario a theta0
	m_th0_input = M_PI/2;

	//dai parametri ricavo delta1m e delta2m
	m_dm1_input = 2*asin(m_n1_input * sin(0.5 * m_alpha)) - m_alpha;
	m_th1_input = m_th0_input + m_dm1_input;

	m_dm2_input = 2*asin(m_n2_input * sin(0.5 * m_alpha)) - m_alpha;
	m_th2_input = m_th0_input + m_dm2_input;

};

//implemento il metodo esegui (metodo che mi restituisce le misure simulate)
void EsperimentoPrisma::Esegui() {
	m_th0_misurato = m_gen.Gauss(m_th0_input, m_sigmath);
	m_th1_misurato = m_gen.Gauss(m_th1_input, m_sigmath);
	m_th2_misurato = m_gen.Gauss(m_th2_input, m_sigmath);
};


//il metodo analizza, dai tre angoli che sono stati misurati con il metodo esegui ricavo gli angoli di deviazione e i valori di A e B che otterrei con queste misure
void EsperimentoPrisma::Analizza() {
	m_dm1_misurato = m_th1_misurato - m_th0_misurato;
	m_dm2_misurato = m_th2_misurato -m_th0_misurato;
	m_n1_misurato = sin((m_dm1_misurato + m_alpha)/2)/sin(m_alpha/2);
	m_n2_misurato = sin((m_dm2_misurato + m_alpha)/2)/sin(m_alpha/2);


	//inverto la relazione di Cauchy e ricavo i coefficienti A e B
	m_A_misurato = (pow(m_lambda2, 2)*pow(m_n2_misurato, 2) - pow(m_lambda1,2)*pow(m_n1_misurato,2))/(pow(m_lambda2,2) - pow(m_lambda1, 2));

	m_B_misurato = (pow(m_n2_misurato, 2) - pow(m_n1_misurato, 2))/((1/pow(m_lambda2,2)) - (1/pow(m_lambda1, 2))); 
}
