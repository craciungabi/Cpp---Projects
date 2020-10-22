#include <iostream>
#include "Cheltuiala.h"
#include "Repository.h"
#include "TestRepository.h"
#include "TestService.h"
#include "UI.h"
using namespace std;

void initService(Service& s) {
	Repository r;
	r.loadFromFile("Chelt.txt");
	s.setRepo(r);
}

int main() {
	TestRepository tr;
	tr.runTests();
	TestService ts;
	ts.runTests();

	Service serv;
	initService(serv);
	showUI(serv);
	return 0;
}
