#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <deque>
#include <unordered_map>

using namespace std;

class Chreey
{
private:
	int x{ 0 }, y{ 768 };
	int speed{ 0 };
	bool alive{ true };

public:
	Chreey(int x, int y, int speed) : x(x), y(768), speed(speed) {}

	//getter
	pair<int, int> getXY()const { return make_pair(x,y); }
	int getSpeed() const { return speed; }
	bool isAlive() const { return alive; }
	void render() { cout << "²ÉÀÙ" << "(" << x << "," << y << ")"<<endl;}
	void update()
	{
		if (alive)y -= speed;
		if (y < 0)
			alive = false;
	}
};


void print(list<Chreey>& l, int s, int e)
{
	auto iter = l.begin();
	if (s != 0) 
	{

	for (int i = 0; i < s+1; ++i)
		iter++;
	}
	for(int i = 0; i < e; ++i)
	{	
		cout << "(" << iter->getXY().first << "," << iter->getXY().second << ") ¼Óµµ : " << iter->getSpeed()<< endl;
		iter++;
	}
}

/////6¹ø ´ä////////////////////////////////////////////
ostream& operator << (ostream& os, const list<Chreey>& v)
{
	os << "2016.4.22 Áß°£½ÃÇè" << endl;
	for (auto iter : v)
	{
		os << "(" << iter.getXY().first << "," << iter.getXY().second << ") ¼Óµµ : " << iter.getSpeed() << endl;
	}
	return os;
}
bool Calc(const Chreey& a, const  Chreey& b)
{
	return a.getXY().second < b.getXY().second;
}

int main()
{

	list<Chreey> data;

	default_random_engine dre;
	uniform_int_distribution<int> dx(0, 1023);
	uniform_int_distribution<int> dspeed(1, 10);

	for (int i = 0; i < 100; ++i)
	{
		data.push_back(move(Chreey(dx(dre), 0, dspeed(dre))));
	}
	
	cout << "------------------------------" << endl;
	cout << "------------------------------" << endl;

	cout << "²ÉÀÙ ¼ö " << data.size() << endl;
	print(data, 5, 10);




	cout << "------------------------------" << endl;
	cout << "------------------------------" << endl;

	int n = 10;
	while (0 < n)
	{
		list<Chreey>::iterator p = data.begin();
		for (;p != data.end(); ++p)
		{
			p->update();
			//p->render();
		}
		n--;
	}

	n = 70;
	while (0 < n)
	{
		for (auto &p : data)
		{
			p.update();
			//p.render();
		}
		n--;
	}
	
	cout << "------------------------------" << endl;
	cout << "------------------------------" << endl;
	cout << "[¹®5]²ÉÀÙ ¼ö " << data.size() << endl;

	data.sort(Calc);
	print(data, 0, 10);

	cout << "------------------------------" << endl;
	cout << "------------------------------" << endl;
	
	auto iter =find_if(data.begin(), data.end(),
		[](const Chreey& a)
		{
			return (a.getSpeed() == 9);
		}
	);

	auto prev = iter;
	auto next = iter;
	deque<list<Chreey>::iterator> deque;
	for (int i = 0; i < 5; ++i)
		deque.push_front(--prev);
	deque.push_back(iter);
	for (int i = 0; i < 5; ++i)
		deque.push_back(++next);
	cout << "--------------------------------------------------------\n";
	for (auto &que : deque)
	{
		if (que == iter)
			cout << "******* ";
		cout << "(" << que->getXY().first << "," << que->getXY().second << ") ¼Óµµ : " << que->getSpeed() << endl;
	}
	cout << "--------------------------------------------------------\n";


	cout << "--------------------------------------------------------\n";
	cout << "--------------------------------------------------------\n";
	data.remove_if(
		[](auto& a)
		{
			return (false ==a.isAlive());
		}
	);


	cout << "²ÉÀÙ ¼ö " << data.size() << endl;
	print(data, 0, 7);

	ofstream out("Áß°£°á°ú.txt");
	out << data;

}