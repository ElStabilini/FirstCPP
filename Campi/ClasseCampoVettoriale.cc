#include "Posizione.h"
#include "CampoVettoriale.h"

//dopo : gli sto dicendo come riempire i datamembri protetti della classe madre (prima dell'informazione su come riempire i suoi specifici)
CampoVettoriale::CampoVettoriale(const Posizione& r) : Posizione(r.getX(), r.getY(), r.getZ()) {
		//cout << "calling default constructor cv" << endl;
		m_Fx = 0; 
		m_Fy = 0;
		m_Fz = 0;
};

//con questo costruttore sto passando anche le informazioni sulla forza, gli passo una posizione e lui sa come spacchettarla e dividere le informazioni
CampoVettoriale::CampoVettoriale(const Posizione& r, double Fx, double Fy, double Fz) : Posizione(r) {
	//con Posizione(r) uso il costruttore di copia di default per riempire la sezione posizione dell'oggetto CampoVettoriale facendogli copiare i datamembri da quelli di r
	//cout << "calling fo constructor with arguments cv" << endl;
	m_Fx = Fx;
	m_Fy = Fy;
	m_Fz = Fz;

};

//passo tutte le informazioni singolarmente
CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz) : Posizione(x, y, z) {
	m_Fx = Fx;
	m_Fy = Fy;
	m_Fz = Fz;
};

//creo un campo con definita solo la posizione (so che c'è un cmapo ma non so ancora quanto vale)
CampoVettoriale::CampoVettoriale(double x, double y, double z) : Posizione(x, y, z) {
	m_Fx = 0;
	m_Fy = 0;
	m_Fz = 0;
};

//modifico il valore del campo in un punto
double CampoVettoriale::setCampo(double Fx, double Fy, double Fz) {
	m_Fx = Fx;
	m_Fy = Fy;
	m_Fz = Fz;
};

CampoVettoriale& CampoVettoriale::operator+=(const CampoVettoriale& v) {
	return (*this) = (*this) + v;
}
//anche questo metodo ha un ritorno per poter fare operazioni matematiche concatenate

CampoVettoriale CampoVettoriale::operator+(const CampoVettoriale& v ) const {
	CampoVettoriale sum(v); //creo una copia di v a cui poi sommo le mie componenti
	sum.setFx( sum.getFx() + getFx() );
	sum.setFy( sum.getFy() + getFy() );
	sum.setFz( sum.getFz() + getFz() );

	return sum;
};
//ha un ritorno perchè in questo modo posso fare operazioni matematiche concatenate

