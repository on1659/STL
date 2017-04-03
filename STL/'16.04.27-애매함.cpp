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
	//ㆍcpy()의 세 번째 인자로 전달된 것은 반복자 어댑터의 하나인 삽입반복자이다.
	//ㆍ반복자 어댑터는 클래스로 반복자에 필요한 연산자를 오버로딩하고 있다.
	//ㆍ삽입반복자의 실제 타입은 아래와 같으며 그 동작을 단계별로 살표보자.
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
	//::Save("'16.04.27-애매함.cpp");

}