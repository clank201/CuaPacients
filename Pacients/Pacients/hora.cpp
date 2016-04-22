#include <iostream>
#include <math.h>
#include "Hora.h"
using namespace std;
Hora::Hora()
{
	hores = 61;
	minuts = 61;
	//ctor
}

bool Hora::Esvalida() {
	//Pre:--
	//Post:Retorna si l'hora actual és valida
	bool valida = true;
	if (hores > 23|| hores < 0 || minuts>59 || minuts < 0)
		valida = false;
	return valida;
}

void Hora::Llegir() {
	//Pre:--
	//Post:Dona valors a l'hora des de cin
	hores = 70;
	int temps;
	cin >> temps;
	hores = floor(temps / 100);
	minuts = temps -( hores * 100);
}

void Hora::Reiniciar_hora() {
	//pre:--
	//Post:Reinicia l'hora a les 00:00
	hores = 0;
	minuts = 0;
}

bool Hora::Esmesantiga(Hora q) {
	//Pre:--
	//Post: Retorna si una hora és mes antiga que una altre
	bool older = false;
	if (hores < q.hores)
		older = true;
	else if (hores == q.hores) {
		if (minuts < q.minuts)
			older = true;
	}
	return older;
}

void Hora::Mostrar() const {
	//Pre:--
	//Post:Mostra l'hora per pantalla
	if (hores < 10)cout<<"0"<<hores<<":";
	else cout<<hores<<":";
	if (minuts < 10)cout<<"0"<<minuts;
	else cout<<minuts;
}

int Hora::MinutsDiferencia(Hora temp) {
	//Pre:--
	//Post:Retorna els minuts de diferencia entre l'hora que introduim i la actual
	int total1 = 0, totalTemp = 0, dif;
	total1 = hores * 60 + minuts;
	totalTemp = temp.hores * 60 + temp.minuts;
	if (totalTemp < total1) {
		totalTemp += 24 * 60;
	}
	dif = total1 - totalTemp;
	return abs(dif);
}