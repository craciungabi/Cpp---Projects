#include "TestRepository.h"
#include "Cheltuiala.h"
#include <assert.h>



TestRepository::TestRepository() {
	assert(repo.getSize() == 0);
}

void TestRepository::testLoadFromFile() {
	repo.loadFromFile("Chelt.txt");
	assert(repo.getSize() == 6);
}

void TestRepository::testAddElem() {
	repo.loadFromFile("Chelt.txt");
	Cheltuiala c = repo.getById(1);
	repo.addElem(c);
	assert(repo.getSize() == 7);
}

void TestRepository::testDelElem() {
	repo.loadFromFile("Chelt.txt");
	repo.delElem(4);
	assert(repo.getSize() == 5);
}

void TestRepository::testGetAll() {
	repo.loadFromFile("Chelt.txt");
	vector<Cheltuiala> rez = repo.getAll();
	assert(rez.size() == 6);
}

void TestRepository::testUpdateElem() {
	repo.loadFromFile("Chelt.txt");
	Cheltuiala c = repo.getById(3);
	assert(c.getSuma() == 800);
}

void TestRepository::testSize() {
	repo.loadFromFile("Chelt.txt");
	assert(repo.getSize() == 6);
}

void TestRepository::testGetById() {
	repo.loadFromFile("Chelt.txt");
	Cheltuiala c = repo.getById(1);
	assert(c.getZi() == 23);
}

void TestRepository::runTests() {

	testLoadFromFile();
	testAddElem();
	testDelElem();
	testGetAll();
	testGetById();
	testUpdateElem();
	testSize();
}

TestRepository::~TestRepository()
{
}
