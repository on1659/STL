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
  ù �ð�
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
  ��° �ð�
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
	//���� �ڷḦ ������������ �����ؤ̤����ˤ�.
	// Qsort()�� ����մϴ�.
	int a[1000];
	for(auto& n : a) n = rand() % 100000000000000000;

	//������ ���� ä����
	//C++11 ���������� �̿��� �����ѹ� ����, #incldue<random>
	
	//1. ������ �����Ѵ�.
	default_random_engine dre;

	//2. ������ �����Ѵ�.
	uniform_int_distribution<int> ui(0, 6);

	for (auto& n : a)
		n = ui(dre);


	//qsort()�� �̿��� �����ڵ�
	//qsort(������?, ��ε�?, �ϳ�ũ���? ��� �����ұ�??)
	qsort(a, sizeof(a) / 4, sizeof(int), compare);

	for (auto& d : a)
	{
		cout << d << " ";
	}
	cout << endl;

	::Save("'16.03.04",true);
}