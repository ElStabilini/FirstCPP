#include <cmath>
#include "AttritoViscoso.h"
#include "RandomGen.h"

#define _USE_MATH_DEFINES

//implemento il costruttore della classe EsperimentoPrisma utilizznado una lista di inizializzazione
//utilizzo la lista perchè in questo modo utilizzo il costruttore corretto per m_gen; altrimenti verrebbe invocato il costruttore senza argomenti che epr la mia classe non esiste
AttritoViscoso::AttritoViscoso():
	m_gen(1),
	m_rho(2700),
	m_rho0(1250),
	m_g(9.81),
	m_eta_input(0.83),
	m_R1_input(0.005),
	m_R2_input(0.01),
	m_sigma_t(0.01),
	m_sigma_x(0.001),
	m_sigma_R(0.0001),
	m_xA_input(0.2),
	m_xB_input(0.8)
{
	//calcolo i risultati attesi
	m_vlimite1_input = (2*m_R1_input*(m_rho - m_rho)*m_g)/(9*m_eta_input);
	m_vlimite2_input = (2*m_R2_input*(m_rho - m_rho)*m_g)/(9*m_eta_input);
	m_dx_input = (m_xB_input - m_xA_input);
	m_t1_input = m_dx_input/m_vlimite1_input;
	m_t2_input = m_dx_input/m_vlimite2_input;
};

void AttritoViscoso::Esegui() {
	//genero una misurta del tempo impiegato a percorrere lo spazio che separa le due posizioni evidenziate secondo una distribuzione gaussiana 
	m_R1_misurato = m_gen.Gauss(m_R1_input, m_sigma_R);
	m_R2_misurato = m_gen.Gauss(m_R2_input, m_sigma_R);
	m_xA_misurato = m_gen.Gauss(m_xA_input, m_sigma_x);
	m_xB_misurato = m_gen.Gauss(m_xB_input, m_sigma_x);
	m_t1_misurato = m_gen.Gauss(m_t1_input, m_sigma_t);
	m_t2_misurato = m_gen.Gauss(m_t2_input, m_sigma_t);
}

void AttritoViscoso::Analizza() {
	m_dx_misurato = m_xB_misurato - m_xA_misurato;
	
	
	//sfera1
	m_vlimite1_misurato = m_dx_misurato/m_t1_misurato;

	m_eta1_misurato = (2*m_R1_misurato*m_R1_misurato*(m_rho - m_rho0)*m_g)/(9*m_eta_input);


	//sfera2
	m_vlimite2_misurato = m_dx_misurato/m_t2_misurato;

	m_eta2_misurato = (2*m_R2_misurato*m_R2_misurato*(m_rho - m_rho0)*m_g)/(9*m_eta_input);
}

