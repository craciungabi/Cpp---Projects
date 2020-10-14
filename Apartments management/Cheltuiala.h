#pragma once
#include <iostream>
using namespace std;

class Cheltuiala {
private:
	int id;
	int zi;
	int suma;
	char* tip;
public:
	Cheltuiala();
	Cheltuiala(int, int, int, char*);
	Cheltuiala(const Cheltuiala&);
	Cheltuiala& operator=(const Cheltuiala&);
	int getId();
	int getZi();
	int getSuma();
	char* getTip();
	void setId(int);
	void setZi(int);
	void setSuma(int);
	void setTip(char*);
	bool operator==(const Cheltuiala&);
	~Cheltuiala();
	friend ostream& operator<<(ostream& os, const Cheltuiala& c);
	friend istream& operator>>(istream&, Cheltuiala&);
};
