#include "pacient.h"


class CuaPacients {
	// Descripció: una cua d’strings
public:
	// CONSTRUCTORS I DESTRUCTOR ----------------------------------
	CuaPacients();
	// Pre: --; Post: cua buida
	CuaPacients(const CuaPacients& o); // const. de còpia
								   // Pre: --; Post: aquesta cua és còpia de la Cua o
	~CuaPacients();
	// Pre: --; Post: memòria alliberada
	// CONSULTORS -------------------------------------------------
	bool buida() const;
	// Pre: -- ; Post: retorna cert si la cua és buida; fals en c.c.
	Pacient primer() const;
	// Pre: cua no buida; Post: retorna còpia del primer string de la cua
	// MODIFICADORS -----------------------------------------------
	void encua(Pacient s);
	// Pre: --; Post: ha afegit s al final de la cua
	void desencua(Hora sortida);
	// Pre: cua no buida; Post: ha eliminat el primer element de la cua
	// OPERADORS REDEFINITS --------------------------------------
	CuaPacients& operator=(const CuaPacients& o);
	// Pre: -- ; Post: aquesta cua és còpia de o 
	void mostrarLlista();
	int getEspera();
	int getAtesos();
	double getTempsMig();
private:
	void allibera();
	void copia(const CuaPacients& o);
	struct Node {
		Pacient p;
		Node* seg;
	};
	// ATRIBUTS
	int espera;
	int atesos;
	double tempsMig;
	Node* a_primer; // punter al primer de la cua
	Node* a_darrer; // punter al darrer de la cua
};