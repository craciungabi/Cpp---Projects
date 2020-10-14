#include "TestService.h"
#include <assert.h>

void TestService::test_sortare_descr_sume_zilnice() {
	Repository repo;
	repo.loadFromFile("Chelt.txt");
	Service serv;
	serv.setRepo(repo);
	int v[31];
	for (int i = 1; i <= 30;i++)
		v[i] = serv.sortare_descr_sume_zilnice()[i];
	assert(v[1] == 805);
}

void TestService::test_filter_by_mancare() {
	Repository repo;
	repo.loadFromFile("Chelt.txt");
	Service serv;
	serv.setRepo(repo);
	serv.filter_by_mancare();
	vector<Cheltuiala> rez = serv.getAll();
	assert(rez.size() == 2);
}

void TestService::test_max_zi() {
	Repository repo;
	repo.loadFromFile("Chelt.txt");
	Service serv;
	serv.setRepo(repo);
	assert(serv.max_zi() == 8);
}

void TestService::test_suma_mancare() {
	Repository repo;
	repo.loadFromFile("Chelt.txt");
	Service serv;
	serv.setRepo(repo);
	assert(serv.suma_mancare() == 27);
}

void TestService::test_sterge_zi_2_9() {
	Repository repo;
	repo.loadFromFile("Chelt.txt");
	Service serv;
	serv.setRepo(repo);
	serv.sterge_zi_2_9();
	vector<Cheltuiala> rez = serv.getAll();
	assert(rez.size() == 3);
}

TestService::TestService()
{
}

void TestService::runTests()
{
	test_sortare_descr_sume_zilnice();
	test_filter_by_mancare();
	test_max_zi();
	test_suma_mancare();
	test_sterge_zi_2_9();
}

TestService::~TestService()
{
}
