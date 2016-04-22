#include "pacient.h"
#include <string>
#include <iostream>

using namespace std;



Pacient::Pacient()
{
	codi = -1;
	nom = "";
}


void Pacient::setNom(string n)
{
	nom = n;
}

void Pacient::setHoraEntrada(Hora h)
{
	horaEntrada = h;

}

void Pacient::setCodi(int c)
{
	codi = c;
}

std::string Pacient::getNom()
{
	return nom;
}

Hora Pacient::getHoraEntrada()
{
	return horaEntrada;
}

int Pacient::getCodi()
{
	return codi;
}

void Pacient::entrada()
{
	//Pre:--
	//Post:Dona valors des de cin al pacient
	cout << "ENTRA EL PACIENT:" << endl << "CODI:" << endl;
	cin >> codi;
	cout << "NOM:" << endl;
	cin.ignore(1, '/n');
	getline(cin, nom);
	cout << "HORA ENTRADA:" << endl;
	horaEntrada.Llegir();
}

void Pacient::mostrar()
{
	//Pre:--
	//Post:Mostra el pacient per pantalla
	cout << "CODI: " << codi << endl;
	cout << "NOM: " << nom << endl;
	cout << "HORA ENTRADA: ";
	horaEntrada.Mostrar();
	cout << endl;
}

void Pacient::mostrar(Hora sortida)
{
	//Pre:--
	//Post:Mostra el pacient per pantalla, i el seu temps d espera
	cout << "CODI: " << codi << endl;
	cout << "NOM: " << nom << endl;
	cout << "HORA ENTRADA: ";
	horaEntrada.Mostrar();
	cout << endl;
	cout << "TEMPS D'ESPERA: " << horaEntrada.MinutsDiferencia(sortida) << " MINUTS" << endl;
}
