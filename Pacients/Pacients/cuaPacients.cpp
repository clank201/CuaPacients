#include <stddef.h>
#include "cuaPacients.h"



CuaPacients::CuaPacients() {
	// Pre: --; Post: cua buida
	// COST: O(1)
	espera = 0;
	atesos = 0;
	a_primer = a_darrer = NULL;
}
CuaPacients::CuaPacients(const CuaPacients& o) {
	// Pre: --; Post: aquesta cua és còpia de la cua o
	// COST: O(n)
	a_primer = a_darrer = NULL;
	copia(o); // crida a mètode privat
}
CuaPacients::~CuaPacients() {
	// Pre: --; Post: memòria alliberada
	// COST: O(n)
	allibera(); // crida a mètode privat
}

// CONSULTORS
bool CuaPacients::buida() const {
	// Pre: -- ; Post: retorna cert si la cua és buida; fals en c.c.
	// COST: O(1)
	return a_primer == NULL;
}
Pacient CuaPacients::primer() const {
	// Pre: cua no buida; Post: retorna còpia del primer de la cua
	// COST: O(1)
	return a_primer->p;
}
// MODIFICADORS
void CuaPacients::encua(Pacient s) {
	// Pre: --; Post: ha afegit s al final de la cua
	// COST: O(1)
	Node* nou = new Node;
	nou->p = s; nou->seg = NULL;
	if (buida()) // this->buida()
		a_primer = a_darrer = nou;
	else {
		a_darrer->seg = nou; a_darrer = nou;
	}
	espera++;
}
void CuaPacients::desencua(Hora sortida) {
	// Pre: cua no buida; Post: ha eliminat el primer de la cua
	// COST: O(1)
	Pacient temp = primer();
	tempsMig += ((temp.getHoraEntrada().MinutsDiferencia(sortida)) - tempsMig) / (atesos + 1);
	Node* aux = a_primer;
	if (a_primer == a_darrer) // només hi ha un element
		a_primer = a_darrer = NULL;
	else a_primer = a_primer->seg;
	delete aux;
	espera--;
	atesos++;
}

void CuaPacients::mostrarLlista()
{
	//Pre:--
 //Post:Mostra els pacients de la llista
	cout << "LLISTAT DELS PACIENTS" << endl;
	cout << "-------------------------" << endl;
	if (espera != 0) {
		if (a_primer == a_darrer) {
			a_primer->p.mostrar();
			cout << "-------------------------" << endl;
		}
		else {
			Node* t = NULL;
			for (Node* i = a_primer; i != a_darrer; i = i->seg) {
				i->p.mostrar();
				cout << "-------------------------" << endl;
				t = i;
			}
			t = t->seg;
			t->p.mostrar();
			cout << "-------------------------" << endl;

		}
	}
}

int CuaPacients::getEspera()
{
	//Pre:--
	//Post:Retorna el nombre de pacients en espera
	return espera;
}

int CuaPacients::getAtesos()
{
	//Pre:--
	//Post:Retorna el nombre de pacients atesos
	return atesos;

}

double CuaPacients::getTempsMig()
{
	//Pre:--
	//Post:Retorna el temps d espera mig per pacient
	return tempsMig;
}

// MÈTODES PRIVATS
void CuaPacients::copia(const CuaPacients& o) {
	// Pre: cua buida; Post: aquesta cua és còpia de o
	// COST: O(n)
	Node* i = o.a_primer;
	while (i != NULL) { // recorrem cua o
		encua(i->p); // this->encua(i->p)
		i = i->seg;
	}
}
void CuaPacients::allibera() {
	// Pre: --; Post: cua buida
	// COST: O(n)
	while (a_primer != NULL) { //!buida()
		Node* aux = a_primer;
		a_primer = a_primer->seg;
		delete aux;
		espera--;
		atesos++;
	}
	a_darrer = NULL;
}
// OPERADOR ASSIGNACIÓ
CuaPacients& CuaPacients::operator=(const CuaPacients& o) {
	// Pre: -- ; Post: aquesta cua és còpia de o
	// COST: O(n)
	if (this != &o) {
		allibera();
		copia(o);
	}
	return *this;
}