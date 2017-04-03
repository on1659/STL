#include "stdafx.h"

int main()
{
	ifstream fin("정규분포.txt");
	map<int, int> m;
	int n;
	while (fin >> n)
		m[n]++;

	for (auto d : m)
		cout << d.first << " --- " << d.second << endl;

	cout << endl;

	multimap<int, int, greater<int>> m2;
	for (auto d : m)
		m2.insert(make_pair(d.second, d.first));

	for (auto d : m)
		cout << d.first << " --- " << d.second << endl;


	}