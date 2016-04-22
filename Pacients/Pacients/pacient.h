#pragma once
#include <iostream>
#include <string>
#include "hora.h"
using namespace std;
class Pacient
{
public:
	Pacient();
	//setters
	void setNom(string n);
	void setHoraEntrada(Hora h);
	void setCodi(int c);
	//getters
	string getNom();
	Hora getHoraEntrada();
	int getCodi();
	//Entraders
	void entrada();
	//Sortiders
	void mostrar();
	void mostrar(Hora sortida);


private:
	string nom;
	Hora horaEntrada;
	int codi;
};

