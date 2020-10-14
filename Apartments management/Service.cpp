#include "Service.h"
#include <algorithm>

Service::Service()
{
}

//Descr: creeaza un obiect de tip Service
//In: r: repositoryul de cheltuieli de manevrat
//Out: o instanta de tip Service
Service::Service(const Repository& r)
{
	repo = r;
}

//Descr: initializeaza un repository
//In: r: repository de initializat
//Out: -
void Service::setRepo(const Repository& r)
{
	repo = r;
}

//Descr: adauga o cheltuiala
//In: c: cheltuiala de adaugat
//Out: -
void Service::addCheltuiala(Cheltuiala& c)
{
	repo.addElem(c);
}

//Descr: Sterge o cheltuiala
//In: id: id-ul cheltuielii de sters
//Out: -
void Service::delCheltuiala(int id)
{
	repo.delElem(id);
}

//Descr: modifica o cheltuiala
//In: id: id-ul cheltuielii de modificat;  new_zi: noua zi;  new_suma: noua suma;    new_tip: noul tip
//Out: -
void Service::update(int id, int zi, int suma, char* tip)
{
	repo.updateElem(id, zi, suma, tip);
}

//Descr: Sterge cheltuielile din ziua 15
//In: -
//Out: -
void Service::sterge_zi_15()
{
	for (Cheltuiala c : getAll()) {
		if (c.getZi() == 15)
			delCheltuiala(c.getId());
	}
}

//Descr: Sterge cheltuielile cu ziua in intervalul [2,9]
//In: -
//Out: -
void Service::sterge_zi_2_9()
{
	for (Cheltuiala c : getAll()) {
		if (c.getZi() >= 2 && c.getZi() <= 9)
			delCheltuiala(c.getId());
	}
}

//Descr: Calculeaza suma tuturor cheltuielilor pe mancare
//In: -
//Out: suma tuturor cheltuielilor pe mancare
int Service::suma_mancare() {
	int Suma = 0;
	for (Cheltuiala c : getAll()) {
		if (strcmp(c.getTip(), "mancare") == 0)
			Suma += c.getSuma();
	}
	return Suma;
}

//Descr: Calculeaza ziua cu cea mai mare suma a cheltuielilor
//In: -
//Out: ziua cu cea mai mare suma a cheltuielilor
int Service::max_zi() {
	int v[31], i, Max = 0, poz = 0;
	for (i = 1;i <= 30;i++)
		v[i] = 0;
	for (Cheltuiala c : getAll())
		v[c.getZi()] += c.getSuma();
	for (i = 1;i <= 30;i++)
		if (v[i] > Max)
		{
			Max = v[i];
			poz = i;
		}
	return poz;
}

bool cmp(int a, int b) {
	return a > b;
}

//Descr: Sorteaza descrescator sumele cheltuielilor zilnice
//In: -
//Out: vectorul de sume sortat descrescator
int* Service::sortare_descr_sume_zilnice() {
	int v[31], i;
	for (i = 1;i <= 30;i++)
		v[i] = 0;
	for (Cheltuiala c : getAll())
		v[c.getZi()] += c.getSuma();
	sort(v + 1, v + 31, cmp);
	return v;
}

//Descr: returneaza lista tuturor cheltuielilor
vector<Cheltuiala> Service::getAll()
{
	return repo.getAll();
}

//Descr: filtreaza cheltuielile dupa tipul 'mancare'
void Service::filter_by_mancare()
{
	for (Cheltuiala c : getAll()) {
		if (strcmp(c.getTip(), "mancare"))
			delCheltuiala(c.getId());
	}
}

//Descr: filtreaza cheltuielile dupa 'menaj' pentru suma < 100
void Service::filter_by_menaj_suma()
{
	for (Cheltuiala c : getAll()) {
		if (strcmp(c.getTip(), "menaj") != 0 || c.getSuma() >= 100)
			delCheltuiala(c.getId());
	}
}

//Descr: returneaza un vector de cheltuieli de tipul mancare cu suma mai mare decat 5
//Out: vectorul de cheltuieli de tip mancare si suma>5
vector<Cheltuiala> Service::afisare_mancare_mai_mare_5()
{
	vector<Cheltuiala> rez;
	for (Cheltuiala c : getAll())
	{
		if (strstr(c.getTip(), "mancare") && c.getSuma() > 5)
			rez.push_back(c);
	}
	return rez;
}

//Destructor
//Distruge un obiect de tip Service
Service::~Service()
{
}
