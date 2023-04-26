#ifndef _Esperimento_Prisma_h_
#define _Esperimento_Prisma_h

#include <cmath>
#include "RandomGen.h"

class EsperimentoPrisma {

public :
	EsperimentoPrisma(); //costruttore implementato nel .cxx
	~EsperimentoPrisma() {;};

	void Esegui();
	void Analizza();

	double GetAinput() {return m_A_input;};
	double GetAmisurato() {return m_A_misurato;};
	double GetBinput() {return m_B_input;};
	double GetBmisurato() {return m_B_misurato;};
	double GetN1input() {return m_n1_input;};
	double GetN1misurato() {return m_n1_misurato;};
	double GetN2input() {return m_n2_input;};
	double GetN2misurato() {return m_n2_misurato;};
	double GetTh0input() {return m_th0_input;};
	double GetTh0misurato() {return m_th0_misurato;};
	double GetTh1input() {return m_th1_input;};
	double GetTh1misurato() {return m_th1_misurato;};
	double GetTh2input() {return m_th2_input;};
	double GetTh2misurato() {return m_th2_misurato;};
	double GetDM1input() {return m_dm1_input;};
	double GetDM1misurato() {return m_dm1_misurato;};
	double GetDM2input() {return m_dm2_input;};
	double GetDM2misurato() {return m_dm2_misurato;};

private:

	RandomGen m_gen; //generatore di numeri casuali che viene dichiarato come datamembro privato perchè non deve cambiare fino alla fine "dell'esperimento" (il generatore deve aggiornare il seed di volta in volta in modo da restituire risultati diversi e non sempre lo stesso)
	double m_lambda1, m_lambda2, m_alpha, m_sigmath; //parametri sperimentali

	//valori delle osservabili (suddivisi tra quelli input - risultati attesi che inserisco come punto di partenza - misurati: valori che ottengo dopo aver eseguito la simulazione)

	double m_A_input, m_A_misurato;
	double m_B_input, m_B_misurato;
	double m_n1_input, m_n1_misurato;
	double m_n2_input, m_n2_misurato;
	double m_th0_input, m_th0_misurato;
	double m_th1_input, m_th1_misurato;
	double m_th2_input, m_th2_misurato;
	double m_dm1_input, m_dm1_misurato;
	double m_dm2_input, m_dm2_misurato;
};

#endif
