#include <iostream>
#include"cuaPacients.h"
#include"pacient.h"
#include "hora.h"

using namespace std;

void mostrarOpcions() {
	//Pre:--
	//Post: mostra les opcions
	cout << "OPCIONS:" << endl <<
		"1: ENTRAR UN PACIENT" << endl <<
		"2: SORTIR UN PACIENT " << endl <<
		"3: MOSTRAR LLISTA D'ESPERA	 " << endl <<
		"4: MOSTRAR NOMBRE DE PACIENTS EN ESPERA  " << endl <<
		"5: MOSTRAR RESUM DELS PACIENTS ATESOS	 " << endl <<
		"9: MOSTRAR EL MENU D'OPCIONS		  " << endl <<
		"0: SORTIR DEL PROGRAMA" << endl;
}
void desinscriure(CuaPacients &cua) {
	//Pre:--
	//Post:Cua amb el pacient desinscrit
	if (cua.getEspera() != 0) {
		Pacient temp = cua.primer();
		Hora temps;
		cout << "HORA ACTUAL:" << endl;
		temps.Llegir();
		cout << "SURT PACIENT:" << endl;
		cua.desencua(temps);
		temp.mostrar(temps);
	}
	else cout << "NO HI HA PACIENTS ESPERANT" << endl;
}
void mainLoop(CuaPacients &cua, int &opcio) {
	//Pre:--
	//Post: Bucle principal
	switch (opcio) {
	case 0:
		break;
	case 1: {
		Pacient temp;
		temp.entrada();
		cua.encua(temp);
		break;
	}
	case 2: {
		desinscriure(cua);
		break; }
	case 3:
		cua.mostrarLlista();
		break;
	case 4:
		cout << "NOMBRE DE PACIENTS EN ESPERA:" << endl << cua.getEspera() << endl;
		break;
	case 5:
		cout << "NOMBRE DE PACIENTS ATESOS:" << endl << cua.getAtesos() << endl;
		cout.precision(1);
		if (cua.getAtesos() != 0) {
			cout << "TEMPS MIG D'ESPERA:" << endl << fixed << cua.getTempsMig() << endl;
		}
		break;
	case 9:
		mostrarOpcions();
		break;
	}
	if (opcio != 0) {
		cout << "OPCIO:" << endl;
		cin >> opcio;
	}
}

int main() {
	int opcio = 9;
	CuaPacients cua;
	while (opcio != 0) {
		mainLoop(cua, opcio);
	}
	cout << "FINAL DEL PROGRAMA" << endl;
}