#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>

class Test
{
	int n;

public:
	Test() : n{} {}
	Test(const int& n): n(n) {}
	void set(const int& val) { n = val; }
	int get() const { return n; }
};

#include <vector>

std::ofstream& operator<<(std::ofstream& os,std::vector<Test> vTest)
{
	for (const auto& d : vTest)
	{
		os << d.get() << std::endl;
	}
	return os;
}

int main()
{
	std::default_random_engine dre;
	std::uniform_int_distribution<> ui;
	dre.seed(20131822777);


	std::vector<Test> vTest;
	vTest.reserve(1000);
	for (int i = 0; i < 1000; ++i) vTest.push_back(Test(ui(dre)));


	sort
	(
		  vTest.begin()
		, vTest.end()
		, [](Test a, Test b)
			{
				return a.get() > b.get();
			}
	);

	std::cout << vTest.begin()->get() << std::endl;
	std::cout << (--vTest.end())->get() << std::endl;

	
	std::ofstream ofs("학번.txt");
	ofs << vTest;
	ofs.close();

	std::ifstream ifs("학번.txt");

	if (ifs.fail())
	{
		std::cout << "read fail" << std::endl;
		return 0;
	}

	char nRead[100];
	vTest.clear();
	vTest.reserve(100);
	int count = 0;
	while (ifs.getline(nRead, 100))
	{
		int input = atoi(nRead);
		vTest.push_back(Test(input));
		if (count++ == 100)break;
	}

	for (auto& d : vTest)
	{
		std::cout << d.get() << std::endl;
	}


}