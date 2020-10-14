#pragma once
#include "Repository.h"
class TestRepository
{
private:
	Repository repo;
public:
	TestRepository();
	void testLoadFromFile();
	void testAddElem();
	void testDelElem();
	void testGetAll();
	void testGetById();
	void testUpdateElem();
	void testSize();
	void runTests();
	~TestRepository();
};
