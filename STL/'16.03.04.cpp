#include "stdafx.h"

template<typename T>
void change(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

class Wizard
{
private:
	std::string m_name;
	int m_age;

public:
	Wizard(string name, int age) { m_name = name, m_age = age; }
	~Wizard() {};

	std::string getName() const { return m_name; }
	int getAge() const { return m_age; }
};

ostream& operator<< (ostream& os, const Wizard& w)
{
	os << w.getName() << "-" << w.getAge();
	return os;
}

/*
  첫 시간
*/
//int main()
//{
//	Wizard x{ "A", 100 }, y{ "B", 20 };
//
//	change(x, y);
//
//	cout << x << "," << y << endl;
//
//}

/*
  둘째 시간
*/
template<typename T>
int compare(const void * a, const void * b)
{
	return (*(T*)a - *(T*)b);
}

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}


int main()
{
	//다음 자료를 오름차순으로 정렬해ㅜㅈ세ㅛㅇ.
	// Qsort()를 사용합니다.
	int a[1000];
	for(auto& n : a) n = rand() % 100000000000000000;

	//임의의 값을 채워라
	//C++11 랜덤엔진을 이용한 랜덤넘버 생성, #incldue<random>
	
	//1. 엔진을 선택한다.
	default_random_engine dre;

	//2. 분포를 선택한다.
	uniform_int_distribution<int> ui(0, 6);

	for (auto& n : a)
		n = ui(dre);


	//qsort()를 이용한 정렬코드
	//qsort(무엇을?, 몇개인데?, 하나크기는? 어떻게 정렬할까??)
	qsort(a, sizeof(a) / 4, sizeof(int), compare);

	for (auto& d : a)
	{
		cout << d << " ";
	}
	cout << endl;

	::Save("'16.03.04",true);
}