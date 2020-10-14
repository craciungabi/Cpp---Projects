#include "Cheltuiala.h"
#include <string.h>
#include <sstream>
using namespace std;

//Descr: creeaza o cheltuiala
//In: -
//Out: o instanta de tip Cheltuiala
Cheltuiala::Cheltuiala() {
	id = 0;
	zi = 0;
	suma = 0;
	tip = NULL;
}

//Descr: creeaza un obiect de tip cheltuiala
//In: id, int: id-ul cheltuielii;    zi, int: ziua cheltuiala;    suma, int: suma cheltuielii;    tip, char*: tipul cheltuielii
//Out: o instanta de tip cheltuiala
Cheltuiala::Cheltuiala(int id, int zi, int suma, char* tip) {
	this->id = id;
	this->zi = zi;
	this->suma = suma;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

//Descr: creeaza o cheltuiala folosind informatii din alta cheltuiala
//In: o cheltuiala c
//Out: o instanta de tip Cheltuiala cu informatii din c
Cheltuiala::Cheltuiala(const Cheltuiala& c) {
	this->id = c.id;
	this->zi = c.zi;
	this->suma = c.suma;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
}

//Descr: acceseaza id-ul unei cheltuieli
//In: o cheltuiala
//Out: id-ul ei
int Cheltuiala::getId() {
	return id;
}

//Descr: acceseaza ziua unei cheltuieli
//In: o cheltuiala
//Out: ziua ei
int Cheltuiala::getZi() {
	return zi;
}

//Descr: acceseaza suma unei cheltuieli
//In: o cheltuiala
//Out: suma ei
int Cheltuiala::getSuma() {
	return suma;
}

//Descr: acceseaza tipul unei cheltuieli
//In: o cheltuiala
//Out: tipul ei
char* Cheltuiala::getTip() {
	return tip;
}

//Descr: modifica id-ul unei cheltuieli
//In: o cheltuiala si un id
//Out: cheltuiala cu id modificat
void Cheltuiala::setId(int i) {
	id = i;
}

//Descr: modifica ziua unei cheltuieli
//In: o cheltuiala si o zi
//Out: cheltuiala cu ziua modificata
void Cheltuiala::setZi(int z) {
	zi = z;
}

//Descr: modifica suma unei cheltuieli
//In: o cheltuiala si o suma
//Out: cheltuiala cu suma modificata
void Cheltuiala::setSuma(int s) {
	suma = s;
}

//Descr: modifica tipul unei cheltuieli
//In: o cheltuiala si un tip
//Out: cheltuiala cu tip modificat
void Cheltuiala::setTip(char* t) {
	if (tip) delete[]tip;
	tip = new char[strlen(t) + 1];
	strcpy_s(tip, strlen(t) + 1, t);
}

//Descr: distruge o cheltuiala
//In: o cheltuiala
//Out: - (destructor)
Cheltuiala::~Cheltuiala() {
	id = 0;
	zi = 0;
	suma = -1;
	if (tip) delete[]tip;
	tip = NULL;
}

Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c) {
	if (this == &c) return *this;
	if (tip) delete[] tip;
	tip = new char[strlen(c.tip) + 1];
	strcpy_s(tip, strlen(c.tip) + 1, c.tip);
	id = c.id;
	zi = c.zi;
	suma = c.suma;
	return *this;
}

//Descr: compara 2 cheltuieli
//In: 2 cheltuieli
//Out: true/false
bool Cheltuiala::operator==(const Cheltuiala& c) {
	return id == c.id;
}

//Descr: afiseaza o cheltuiala sub forma de string
ostream& operator<<(ostream& os, const Cheltuiala& c) {
	os << c.id << ". ziua: " << c.zi << ", " << c.suma << " lei " << c.tip << endl;
	return os;
}

//Descr: citeste o cheltuiala
//Out: o noua cheltuiala
istream& operator>>(istream& is, Cheltuiala& c)
{
	cout << "Dati id-ul: ";
	int id;
	cin >> id;
	cout << "Dati ziua: ";
	int zi;
	cin >> zi;
	cout << "Dati suma: ";
	int suma;
	cin >> suma;
	cout << "Dati tipul: ";
	char* tip = new char[10];
	is >> tip;
	c.setId(id);
	c.setZi(zi);
	c.setSuma(suma);
	c.setTip(tip);
	delete[] tip;
	return is;
}
