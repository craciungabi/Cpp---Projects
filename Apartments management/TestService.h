#pragma once
#include "Service.h"

class TestService {
private:
	Service s;
	void test_sortare_descr_sume_zilnice();
	void test_filter_by_mancare();
	void test_max_zi();
	void test_suma_mancare();
	void test_sterge_zi_2_9();
public:
	TestService();
	void runTests();
	~TestService();
};
