#pragma once
#include "Repository.h"
#include "Cheltuiala.h"
#include <vector>
using namespace std;

class Service
{
private:
	Repository repo;
public:
	Service();
	Service(const Repository&);
	void setRepo(const Repository&);
	void addCheltuiala(Cheltuiala&);
	void delCheltuiala(int);
	void update(int, int, int, char*);
	void sterge_zi_15();
	void sterge_zi_2_9();
	vector<Cheltuiala> getAll();
	void filter_by_mancare();
	void filter_by_menaj_suma();
	int suma_mancare();
	int max_zi();
	int* sortare_descr_sume_zilnice();
	vector<Cheltuiala> afisare_mancare_mai_mare_5();
	~Service();
};
