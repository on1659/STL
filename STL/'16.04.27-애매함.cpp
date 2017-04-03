#include "stdafx.h"


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<class Iter, class Dest>
void cpy(Iter begin, Iter end, Dest des)
{
	while (begin != end)
	{
		//*des++ = *begin++;
		des.operator*().operator++() = begin.operator*().operator++();
		//des.operator++();
		//begin.operator++();
	}
}


int main()
{
	vector<int> v{ 1,2,3,4,5 };
	vector<int> v2;

	cpy(v.begin(), v.end(), back_inserter(v2));
	//cpy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "\n"));

	//std::back_insert_iterator<vector<int>> p(v2);
	//p = 3333;
	//p = 444;
	//p = 555;
	//p = 666;
	//
	//
	///*
	//��cpy()�� �� ��° ���ڷ� ���޵� ���� �ݺ��� ������� �ϳ��� ���Թݺ����̴�.
	//���ݺ��� ����ʹ� Ŭ������ �ݺ��ڿ� �ʿ��� �����ڸ� �����ε��ϰ� �ִ�.
	//�����Թݺ����� ���� Ÿ���� �Ʒ��� ������ �� ������ �ܰ躰�� ��ǥ����.
	//*/
	//
	//for (int d : v2)
	//	cout << d << endl;
	//
	//
	//int n = 100;
	//ostream_iterator<char> p2(cout);
	//while (n--)
	//	p2 = 007;
	//
	//::Save("'16.04.27-�ָ���.cpp");

}