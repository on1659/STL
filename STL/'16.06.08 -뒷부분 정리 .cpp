#include "stdafx.h"
#include <iterator>


/*	
	알고리즘 함수 rotate(b, nb, e)는 [b,e)구간의 원소를
	nb가 새로운 begin이 되도록 순환시킨다.
	532page

	내가 만약 나만의 자료구조를 만들었다면!
	그리고 이 자료구조가 STL Algorithm을 활용하도록 하고 싶다면
	  -> 자신의 자료구조를 순회할 수 있는 반복자를 프로그램 해야 한다.

	 531page User Define Iter Make;
	 531p 사용자 정의 반복자 만들기!!


	 ~ 함수객체 : 펑터~
	 : () 연산자를 오버로딩한 클래스!


	//
	542page;
	 
*/

template<class Iter>
void shiftLeft(Iter begin, Iter end)
{
	auto t = *begin;
	auto r = begin;
	++r;
	int size = distance(begin, end) - 1;
	for (int i = 0; i < size; ++i)
		*begin++ = *r++;
	*begin = t;

}

template<class Iter>
void myReverse(Iter begin, Iter end)
{
	for (; begin != end && begin != --end; ++begin)
		std::iter_swap(begin, end);
}

//
//class Monster
//{
//protected:
//	string s;
//
//public:
//	Monster() {};
//	~Monster() {};
//
//	virtual string getString() { return s; }
//
//};
//
//class Lavar
//{
//private:
//	 static string Lavarname;
//
//public:
//
//	Lavar() { 
//		if (Lavarname.size() == 0)
//		{
//			Lavarname = "Lavar";
//			cout << "첫..." << endl;
//		}
//		cout << " 이미있음" << endl;
//	};
//
//	~Lavar() {};
//
//	operator string () const { return Lavarname; }
//
//	string getName() const { return Lavarname; }
//};
//
//class Dragon : public Monster
//{
//private:
//	 string DragonName;
//
//public:
//	Dragon() { if (DragonName.size() == 0)
//		s = "Dragon"; };
//	~Dragon() {};
//
//	operator string () const { return DragonName; }
//	virtual string getString() { return DragonName; }
//};



int main()
{

	CGameObject a{ 1 };
	CGameObject b{ 5 };
	CGameObject c;

	c = a + b;

	cout << c << endl;

	vector<CGameObject> v{ 1,2,3,4,5,6 };
	vector<CGameObject> v2{ 4,5,6};

	CGameObject f;
	CGameObject fun = for_each(v.begin(), v.end(), f);
	
	cout << "Avr : " << fun.ave() << endl;

 cout << 
	none_of(v.begin(), v.end(), 
	[](int n)
	{
		return n & 1;
	}
	)
	 << endl;
 

	cout << "---------------------------" << endl;
	auto f2 = std::search(v.begin(), v.end(), v2.begin(), v2.end());

	if (f2 != v.end())
	cout << *f2 << endl;

	cout << "---------------------------" << endl;
	random_shuffle(v.begin(), v.end());
	for (auto &d : v)
		cout << d << endl;


	vector<CGameObject> vG{ 1,2,3,4,5,6,7,8,9 };


	//stable_partition;
	auto p = partition
	(
		vG.begin(), vG.end(),
		[](int n)
	{
		return n & 1;
	}
	);

	cout << "홀수 - ";

	for (auto &d : vG)
	{
		if (d == *p)break;
		cout << d << " ";
	}

	cout << endl;
	cout << "짝수 - ";
	for (; p != vG.end(); p++)
		cout << *p << " ";

	cout << endl;


	/*
	Sort;
	*/
	//vector<int> k2;
	//std::set_union(v.begin(), v.end(), v2.begin(), v2.end(), &k2);
	//
	//for (auto k : k2)
	//	cout << k << " ";


	make_heap(vG.begin(), vG.end());
	random_shuffle(vG.begin(), vG.end());
	sort_heap(vG.begin(), vG.end());
	for (auto k : vG)
		cout << k << " ";
}