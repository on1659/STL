#pragma once

#include "stdafx.h"

#include <array>
#include <vector>
#include <list>
#include <set>
/*
  STL

    DS(generic) + Alogrithm(generic); ->�ݺ�������

    - ��� 
    ��Generic, Collection, Componetn, Container, Algorithm
	��Iterator, Adaptor, Predicates, Function Object;
			
	��Callable type
   - template�� ����鼭 Generic�� �����ϰ� �Ǿ���.

   (ȣ�����Ͼ, ������ Ÿ��)
*/



//#define ��
#define �����̳�ó��


#ifdef ��
int add(int a, int b)
{
	cout << "�׳� ���Լ�" << endl;
	return 333;
}

int main()
{
	//1�����
	int(*f)(int, int) = add;
	(*f)(3, 3);

	//2�����
	function<int(int, int)> f2 = add;
	(f2)(3, 3);


	//3�����
	function<void()> f3 = []() {cout << "����" << endl;};
	f3();

}

#endif

#define �ݺ��� abc
#ifdef �����̳�ó��

int main()
{
	//�ֺ� array�����
	array<int, 1000> ay{};
	array<int, 10> b;

	//b = ay;
	
	cout << sizeof(ay) << endl;
	for (auto &a : ay) cout << a << endl;
	cout << endl;

	//
	array<int, 100> cP{1,2,3};
	auto �ݺ��� = cP.begin();
	*�ݺ���; //������ ������.  dereferencing operator
	cout << *�ݺ��� << endl;
	cout << *�ݺ���+1 << endl;
	cout << *�ݺ���+2 << endl;

	for (auto i = cP.begin(); i != cP.end(); ++i)
		cout << *i << endl;

	Save("'16.04.06-6��.cpp");
}

#endif