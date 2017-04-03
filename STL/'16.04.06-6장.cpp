#pragma once

#include "stdafx.h"

#include <array>
#include <vector>
#include <list>
#include <set>
/*
  STL

    DS(generic) + Alogrithm(generic); ->반복자패턴

    - 용어 
    ㆍGeneric, Collection, Componetn, Container, Algorithm
	ㆍIterator, Adaptor, Predicates, Function Object;
			
	ㆍCallable type
   - template이 생기면서 Generic가 가능하게 되었다.

   (호모지니어스, 동일한 타입)
*/



//#define 음
#define 컨테이너처음


#ifdef 음
int add(int a, int b)
{
	cout << "그냥 ㅇ함수" << endl;
	return 333;
}

int main()
{
	//1번방식
	int(*f)(int, int) = add;
	(*f)(3, 3);

	//2번방식
	function<int(int, int)> f2 = add;
	(f2)(3, 3);


	//3번방식
	function<void()> f3 = []() {cout << "람다" << endl;};
	f3();

}

#endif

#define 반복자 abc
#ifdef 컨테이너처음

int main()
{
	//텅빈 array만들기
	array<int, 1000> ay{};
	array<int, 10> b;

	//b = ay;
	
	cout << sizeof(ay) << endl;
	for (auto &a : ay) cout << a << endl;
	cout << endl;

	//
	array<int, 100> cP{1,2,3};
	auto 반복자 = cP.begin();
	*반복자; //역참조 연산자.  dereferencing operator
	cout << *반복자 << endl;
	cout << *반복자+1 << endl;
	cout << *반복자+2 << endl;

	for (auto i = cP.begin(); i != cP.end(); ++i)
		cout << *i << endl;

	Save("'16.04.06-6장.cpp");
}

#endif