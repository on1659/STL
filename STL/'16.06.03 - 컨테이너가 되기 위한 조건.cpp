#include "stdafx.h"
#include <iterator>
/*
 Iterators are a generalization of pointers
  tha allow a c++program(Alogorithm, User Fuction) to work with
  differend data structures(containers) in a uniform manner;

  �ݺ��ڴ� �����̳ʰ� �����̵� ������� �ϰ��� �������
  c++ ���α׷��� �����̳��� ���ҿ� ������ �� �ֵ��� �ϴ�
  �����Ϳ� ������ �� �����δ�.


  * �ݺ��� ��� ����
     range				- [begin, end)
     rechable			- [begin, end) ����, b���� ++���� ������ end�� ���� ����
     valid range	    - rechable range�̴�.
     dereferenceable	- ���� �ݺ����� ���� read access �� �� ����
     mutable iterator	- ���� �ݺ����� ���� write access �� �� ����

*/

#define Container list

template<class Iter>
int dist(Iter begin, Iter end, random_access_iterator_tag)
{
	cout << " ���� ������" << endl;
	return end - begin;
}

template<class Iter>
int dist(Iter begin, Iter end, forward_iterator_tag)
{
	cout << " ������ ������" << endl;
	int i = 0;
	for (; begin != end; ++i, begin++);
	return i;

	//�񷣴�
	int cnt = 0;
	while (begin != end)
	{
		begin++;
		cnt++;
	}
	return cnt;
}

template<class Iter>
int dist(Iter begin, Iter end, bool)
{
	//�񷣴�
	int cnt = 0;
	while (begin != end)
	{
		begin++;
		cnt++;
	}
	return cnt;
}


template<class Iter>
int ytDist(Iter begin, Iter end)
{
	//���� ���ڷ� ���� ���� � �ݺ������� �˾Ƴ��� ����� �ִٸ�
	// �� �Լ��� ������ ���� �ݺ��ڷ� �������� ������?
	
	auto beg = begin;


	bool isRandom = true;
	int n = 5;
	while(n--)
	{
		auto refe = &beg; beg++;
		auto refe2 = &beg;

		if ((refe2 - refe) != 4)
		{
			isRandom = false;
			break;
		}
	}
	

	if (isRandom)
	{
		cout << "����������" << endl;
		return dist(begin, end, bool());
	}
	else
	{
		cout << "������ ������" << endl;
	 int count = 0;
		while (begin != end)
		{
			begin++;
			count++;
		}
		return count;
	}
}

template<class Iter>
int dist(Iter begin, Iter end)
{
	return dist(begin, end, 
		iterator_traits<Iter>::iterator_category());

}


int main()
{
	int input = 0;
	Container<int>	 container{ input++, input++,input++, input++, input++ };

	//int nC = 100000;
	//while (nC--)container.push_back(rand() % input++);

	//iterator_traits<vector<int>::iterator>::iterator_category ve;
	//iterator_traits<list<int>::iterator>::iterator_category li;
	//iterator_traits<map<int, int>::iterator>::iterator_category ma;
	//
	//int n2 = 5;
	//while (n2--)
	//{
	//
	//	cout << typeid(ve).hash_code() << endl;
	//	cout << typeid(li).hash_code() << endl;
	//	cout << typeid(ma).hash_code() << endl;
	//
	//	cout << endl;
	//
	//}

	int a[] = { 1,2,4,5,42343,52 };
	int n = dist(a, a+3);			//528page �ϴܺ�

	cout << n << endl;


	for (auto &p : container)
	{
	//	printf("[�ּ� : %x ][�� : %d]\n", &p, p);
	}


	iterator_traits<int*>::value_type nTest = 10;
	iterator_traits<int*>::iterator_category pT;

	cout << "������ (528page)" << typeid(pT).name() << endl;


}