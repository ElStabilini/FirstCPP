#ifndef _AttritoViscoso_h_
#define _AttritoViscoso_h

#include <cmath>
#include "RandomGen.h"

class AttritoViscoso {

public :
	AttritoViscoso(); //costruttore implementato nel .cxx
	~AttritoViscoso() {;};

	void Esegui();
	void Analizza();
	
	double GetxAinput() {return m_xA_input;};
	double GetxAmisurato() {return m_xA_misurato;};
	double GetxBinput() {return m_xB_input;};
	double GetxBmisurato() {return m_xB_misurato;};
	double GetR1input() {return m_R1_input;};
	double GetR1misurato() {return m_R1_misurato;};
	double GetR2input() {return m_R2_input;};
	double GetR2misurato() {return m_R2_misurato;};
	double GetT1input() {return m_t1_input;};
	double GetT1misurato() {return m_t1_misurato;};
	double GetT2input() {return m_t2_input;};
	double GetT2misurato() {return m_t2_misurato;};
	double GetVlimite1input() {return m_vlimite1_input;};
	double GetVlimite1misurato() {return m_vlimite1_misurato;}
	double GetVlimite2input() {return m_vlimite2_input;};
	double GetVlimite2misurato() {return m_vlimite2_misurato;}
	double GetDxinput() {return m_dx_input;};
	double GetDxmisurato() {return m_dx_misurato;};
	double GetEtainput() {return m_eta_input;};
	double GetEta1misurato() {return m_eta1_misurato;};
	double GetEta2misurato() {return m_eta2_misurato;};


private:

	RandomGen m_gen; //generatore di numeri casuali che viene dichiarato come datamembro privato perchè non deve cambiare fino alla fine "dell'esperimento" (il generatore deve aggiornare il seed di volta in volta in modo da restituire risultati diversi e non sempre lo stesso)
	double m_rho, m_rho0, m_g, m_sigma_t, m_sigma_x, m_sigma_R; //parametri sperimentali

	//valori delle osservabili (suddivisi tra quelli input - risultati attesi che inserisco come punto di partenza - misurati: valori che ottengo dopo aver eseguito la simulazione)

	double m_xA_input, m_xA_misurato;
	double m_xB_input, m_xB_misurato;
	double m_R1_input, m_R1_misurato;
	double m_R2_input, m_R2_misurato;
	double m_t1_input, m_t1_misurato;
	double m_t2_input, m_t2_misurato;
	double m_vlimite1_input, m_vlimite1_misurato;
	double m_vlimite2_input, m_vlimite2_misurato;
	double m_dx_input, m_dx_misurato;
	double m_eta_input, m_eta1_misurato, m_eta2_misurato;
};

#endif
