#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

class Dog {
	string name;
	int x, y;
	int speed;
public:
	explicit Dog(string name, int x, int y, int speed) :
		name(name), x(x), y(y), speed(speed) {}
	string getName() const { return name; }
	int getX() const { return x; }
	int getY() const { return y; }
	int getSpeed() const { return speed; }
	void setX(int n) { x = n; }
	void setY(int n) { x = n; }
};
/////6�� ��////////////////////////////////////////////
ostream& operator << (ostream& os, const vector<Dog>& v)
{
	os << "2015.4.23 �߰�����" << endl;
	for (auto data : v)
		os << data.getName() << "\t"
		<< data.getX() << "\t"
		<< data.getY() << "\t"
		<< data.getSpeed() << endl;
	return os;
}
/////////////////////////////////////////////////////////
//////2���� print�Լ��� ����ÿ�////////////////////////
void print(vector<Dog> v, int index, int cnt)
{
	cout << "���� �� : " << v.size() << endl;
	for (int i = index; i < index + cnt; ++i)
	{
		cout << v[i].getName() << "(" << v[i].getX() << ", " << v[i].getY() << " ) ���ǵ� : " << v[i].getSpeed() << endl;
	}
}
///////////////////////////////////////////////////////////
double calcDistance(const Dog&a, const Dog& b)
{
	double distA = sqrt((a.getX() - 100)*(a.getX() - 100) + (a.getY() - 100)*(a.getY() - 100));
	double distB = sqrt((b.getX() - 100)*(b.getX() - 100) + (b.getY() - 100)*(b.getY() - 100));
	return distA < distB;
}

/////////7�� ��////////////////////////////////////////////
template <class T>
void printGeneric(T b, T e)
{
	for (; b != e; ++b)
		cout << "���׸� �Լ�" << endl;
};
///////////////////////////////////////////////////////////

int main()
{
	vector<Dog> dogs;
	default_random_engine dre;
	string name;
	char buf[10];

	//////1���� ������������ ����///////////////////////////////////
	dogs.reserve(100);
	uniform_int_distribution<int> dxy(-500, 500);
	uniform_int_distribution<int> dspeed(10, 20);
	for (int i = 0; i < 100; i++) {
		_itoa_s(i, buf, 10);
		name = string("�ٶ���") + string(buf);
		dogs.push_back(Dog(name, dxy(dre), dxy(dre), dspeed(dre)));
	}
	/////////////////////////////////////////////////////////////////
	int bx = 100;
	int by = 100;
	int distX;
	int distY;
	vector<Dog> ::iterator p;
	//��
	//(150, 90)
	//�̸� distX = -50
	//�̸� distY = 10;
	// �׷��� �� ���� (135, 105)
	//////3����/////////////////////////////////////
	for (p = dogs.begin(); p < dogs.end(); ++p) {
		distX = bx - p->getX();
		distY = by - p->getY();
		if (distX < 0)
			p->setX(p->getX() - p->getSpeed());
		else if (distX > 0)
			p->setX(p->getX() + p->getSpeed());
		if (distY < 0)
			p->setY(p->getY() - p->getSpeed());
		else if (distY > 0)
			p->setY(p->getY() + p->getSpeed());
	}
	/////////////////////////////////////////////////
	//////4����//////////////////////////////////////
	sort(dogs.begin(), dogs.end(), calcDistance);
	//////5����/////////////////////////////////////
	auto f = find_if(dogs.begin(), dogs.end(), [](const Dog&a) {
		return a.getName() == "�ٶ���71"; });
	print(dogs, (f - dogs.begin()) - 5, 11);
	/////////////////////////////////////////////////


}