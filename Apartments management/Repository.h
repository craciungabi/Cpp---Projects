#pragma once
#include "Cheltuiala.h"
#include <vector>

class Repository {
private:
	vector<Cheltuiala> elem;
	const char* fis;
public:
	Repository();
	Repository(const char* filename);
	void loadFromFile(const char* fileName);
	void addElem(Cheltuiala);
	Cheltuiala getById(int);
	void delElem(int);
	void updateElem(int, int, int, char*);
	vector<Cheltuiala> getAll();
	int getSize();
	~Repository();
	void saveToFile();
};
