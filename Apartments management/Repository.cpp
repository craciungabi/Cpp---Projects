#include "Repository.h"
#include <fstream>
#include <string>
using namespace std;

Repository::Repository() {

}

//Descr: creeaza un obiect de tip repository de cheltuieli
//In: filename, const char: numele fisierului din care sunt luate cheltuielile
//Out: o instanta de tip repository
Repository::Repository(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* tip = new char[10];
	int id, zi, suma;
	while (!f.eof()) {
		f >> id >> zi >> suma >> tip;
		if (tip != "") {
			Cheltuiala c(id, zi, suma, tip);
			elem.push_back(c);
		}
	}
	delete[] tip;
	f.close();
}

//Descr: incarca date dintr-un fisier
//In: filename: numele fisierului
//Out: -
void Repository::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* tip = new char[10];
	int id, zi, suma;
	while (!f.eof()) {
		f >> id >> zi >> suma >> tip;
		if (strcmp(tip, "") != 0) {
			Cheltuiala c(id, zi, suma, tip);
			elem.push_back(c);
		}
	}
	delete[] tip;
	f.close();
}

/* Descr: Adauga o noua cheltuiala in lista de cheltuieli
   Input: c, Cheltuiala: cheltuiala de adaugat
   Output:-            */
void Repository::addElem(Cheltuiala c) {
	elem.push_back(c);
}

// Descr: Obtine o cheltuiala dupa id
// In: id:id-ul cheltuielii de cautat
// Out: cheltuiala cu id-ul dat
Cheltuiala Repository::getById(int id)
{
	vector<Cheltuiala>::iterator it;
	for (it = elem.begin(); it <= elem.end(); it++) {
		if ((*it).getId() == id)
			return *it;
	}
}

//Descr: Sterge o cheltuiala
//In: id: id-ul cheltuielii de sters
//Out: -
void Repository::delElem(int id)
{
	vector<Cheltuiala>::iterator it;
	Cheltuiala c = getById(id);
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end()) {
		elem.erase(it);
	}
}

//Descr: modifica o cheltuiala
//In: id: id-ul cheltuielii de modificat;  new_zi: noua zi;  new_suma: noua suma;    new_tip: noul tip
//Out: -
void Repository::updateElem(int id, int new_zi, int new_suma, char* new_tip)
{
	vector<Cheltuiala>::iterator it;
	Cheltuiala c = getById(id);
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end()) {
		(*it).setZi(new_zi);
		(*it).setSuma(new_suma);
		(*it).setTip(new_tip);
	}

}

/*descr:  Acceseaza dimensiunea listei de cheltuieli(numarul curent al cheltuielilor)
  Output: numarul de cheltuieli	*/
int Repository::getSize() {
	return elem.size();
}

/*Descr: Acceseaza toate cheltuielile din repository
  Output: lista de cheltuieli   	*/
vector<Cheltuiala> Repository::getAll()
{
	return elem;
}

//Descr: salveaza datele in fisier
void Repository::saveToFile()
{
	ofstream f(fis);
	for (size_t i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}

Repository::~Repository() {
	//destructorul
}
