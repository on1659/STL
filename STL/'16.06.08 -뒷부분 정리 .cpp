#include "stdafx.h"
#include <iterator>


/*	
	�˰��� �Լ� rotate(b, nb, e)�� [b,e)������ ���Ҹ�
	nb�� ���ο� begin�� �ǵ��� ��ȯ��Ų��.
	532page

	���� ���� ������ �ڷᱸ���� ������ٸ�!
	�׸��� �� �ڷᱸ���� STL Algorithm�� Ȱ���ϵ��� �ϰ� �ʹٸ�
	  -> �ڽ��� �ڷᱸ���� ��ȸ�� �� �ִ� �ݺ��ڸ� ���α׷� �ؾ� �Ѵ�.

	 531page User Define Iter Make;
	 531p ����� ���� �ݺ��� �����!!


	 ~ �Լ���ü : ����~
	 : () �����ڸ� �����ε��� Ŭ����!


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
//			cout << "ù..." << endl;
//		}
//		cout << " �̹�����" << endl;
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

	cout << "Ȧ�� - ";

	for (auto &d : vG)
	{
		if (d == *p)break;
		cout << d << " ";
	}

	cout << endl;
	cout << "¦�� - ";
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