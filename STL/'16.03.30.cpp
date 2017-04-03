
#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <ostream>
#include <chrono>
#include <algorithm>
#include <random>


#define MAX_NUM 100		//<<--------------------천만은 너무 오래걸려서

using namespace std;

int cmp(const void*p, const void* q)
{
	int a = *(int*)p;
	int b = *(int*)q;
	if (a < b)return -1;
	if (a == b)return 0;
}

static int saveNumber[MAX_NUM];

int main()
{
	default_random_engine dre;
	uniform_int_distribution<> ui;
	dre.seed(2011180008);

	//랜덤 정수 한개로 만들 수 있따
	cout << ui(dre) << endl;

	for (int i = 0; i < MAX_NUM; ++i)
	{
		saveNumber[i] = ui(dre);
	}
	
	sort(begin(saveNumber), end(saveNumber), [](int a, int b) {return a < b;});

	cout << "Min : " << saveNumber[0] << endl;
	cout << "Max : " <<saveNumber[MAX_NUM-1] << endl;

	ofstream out("201118008.txt", ios::out);

	for (auto &pInt : saveNumber)
	{
		out << pInt << endl;
	}

	out.close();

	ifstream fin;
	char msg[20];

	fin.open("201118008.txt", ios::in);

	for (int i = 0; i < 100; ++i)
	{
		fin.getline(msg, 20);
		cout << msg << endl;
	}

	fin.close();

}