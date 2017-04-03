#include "stdafx.h"
#include <iterator>
/*
 Iterators are a generalization of pointers
  tha allow a c++program(Alogorithm, User Fuction) to work with
  differend data structures(containers) in a uniform manner;

  반복자는 컨테이너가 무엇이든 상관없이 일관된 방식으로
  c++ 프로그램이 컨테이너의 원소에 접근할 수 있도록 하는
  포인터와 유사한 그 무엇인다.


  * 반복자 용어 정리
     range				- [begin, end)
     rechable			- [begin, end) 구간, b에서 ++연산 만으로 end에 도달 가능
     valid range	    - rechable range이다.
     dereferenceable	- 현재 반복자의 값을 read access 할 수 있음
     mutable iterator	- 현재 반복자의 값을 write access 할 수 있음

*/

#define Container list

template<class Iter>
int dist(Iter begin, Iter end, random_access_iterator_tag)
{
	cout << " 랜덤 데스네" << endl;
	return end - begin;
}

template<class Iter>
int dist(Iter begin, Iter end, forward_iterator_tag)
{
	cout << " 포워드 데스네" << endl;
	int i = 0;
	for (; begin != end; ++i, begin++);
	return i;

	//비랜덤
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
	//비랜덤
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
	//전달 인자로 부터 현재 어떤 반복자인지 알아내는 방법이 있다면
	// 이 함수는 다음과 같은 반복자로 구현하지 않을까?
	
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
		cout << "랜덤데스네" << endl;
		return dist(begin, end, bool());
	}
	else
	{
		cout << "포워드 데스네" << endl;
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
	int n = dist(a, a+3);			//528page 하단부

	cout << n << endl;


	for (auto &p : container)
	{
	//	printf("[주소 : %x ][값 : %d]\n", &p, p);
	}


	iterator_traits<int*>::value_type nTest = 10;
	iterator_traits<int*>::iterator_category pT;

	cout << "포인터 (528page)" << typeid(pT).name() << endl;


}