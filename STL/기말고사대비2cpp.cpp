#include "stdafx.h"

#include <list>


class Player
{
	int hp;
	double x, y;

public:
	Player(double x, double y, int hp = 100) : x(x), y(y)
	{

	}
};

class Monster
{
	int num;
	double x, y;
	int *p;

public:
	Monster(double x, double y, int n) : x(x), y(y), num(n)
	{
		p = new int[num];
		for (int i = 0; i < num; ++i)
			p[i] = rand();
	}
	~Monster()
	{
		if (p)delete p;
		p = nullptr;
	}
	void show()
	{
		cout << "몬스터 " << "{" << x << "," << y << "}" << "[" << dist() <<"] 할당 자원 수 " << num << "\t" << "첫째 값" << p[0] << endl;
		
	}

	double dist() const { return sqrt(x*x + y*y); }

	void Release()
	{
		if (p) delete p;
		p = nullptr;
	}

};


int main()
{
	Player me{ 0.0, 0.0};

	list<Monster*> m;
	for (int i = 0; i < 100; ++i)
		m.push_back((new Monster(rand()%40 - 20, rand()%40 - 20, rand() % 90 + 10)));
	
	for (auto d : m)
		d->show();d
	

	m.remove_if([](auto& d)
	{
		return (10.0 < d->dist());
	}
	);
	
	m.sort([](auto& a, auto& b)
	{
		return a->dist() < b->dist();
	}
	);

	cout << "-----------------------------------" << endl;
	for (auto d : m)		
		d->show();





	for (auto &d : m)d->Release();
	cout << m.size() << endl;
}