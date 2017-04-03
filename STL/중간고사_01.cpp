#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>

#include <unordered_map>

using namespace std;
/*
	 mult map�� ����Ͽ� �ߺ� �� �����켭 �����ϱ�
*/
class Dog
{
	string name;
	int x, y;
	int speed;

	int distance;

public:
	//what is explict?
	explicit Dog(string name, int x, int y, int speed) :name(name), x(x), y(y),speed(speed)
	{
		distance = 0;
		//Dog::name = name;
		//
		//default_random_engine dre;
		//uniform_int_distribution<int> d1(-500, 500);
		//uniform_int_distribution<int> d2(10, 20);
		//x = d1(dre);
		//y = d1(dre);
		//speed = d2(dre);
	}

	std::string getName() const { return name; }
	int getX() const { return x; }
	int getY() const { return y; }
	int getSpeed() const { return speed; }
	void setX(int n) { x = n; }
	void setY(int n) { y = n; }


	void Move(int dx, int dy)
	{
		if (dx > 0) dx = 1;
		if (dx < 0) dx = -1;

		if (dy > 0) dy = 1;
		if (dy < 0) dy = -1;
		
		x += dx * speed;
		y += dy * speed;
	}
	void Show()
	{
		cout << name << ", (" << x << "," << y << ") ���ǵ� : " << speed << endl;
		//printf("Name : %s, pos(%d, %d), speed : %d\n", name, x, y, speed);// << endl;
	}
	void Show(ostream& os)
	{
		os << name << ", (" << x << "," << y << ") ���ǵ� : " << speed << endl;
		//printf("Name : %s, pos(%d, %d), speed : %d\n", name, x, y, speed);// << endl;
	}

	void setDistance(int n) { distance = n; }
	int getDistance() const { return distance; }
};

double calcDistance(const Dog& a, const Dog& b)
{
	double distA = sqrt((a.getX() - 100) * (a.getX() - 100) + (a.getY() - 100) * (a.getY() - 100));
	double distB = sqrt((b.getX() - 100) * (b.getX() - 100) + (b.getY() - 100) * (b.getY() - 100));
	return distA < distB;
}

int calcDistance(const Dog& a)
{
	return sqrt((a.getX() - 100) * (a.getX() - 100) + (a.getY() - 100) * (a.getY() - 100));
}

void print(vector<Dog> v, int s, int e)
{
	for (int i = s; i < s+5; ++i)
	{
		v[i].Show();
	}
}

void TestSave(std::string str = "�߰����_01.cpp", bool isCreate = true)
{
	// ���� �ð� ���
	// ���� �ð������� ����Ѵ�.
	auto tp = chrono::system_clock::now();
	// �ð������� time_t �������� �ٲ۴�.
	auto t = chrono::system_clock::to_time_t(tp);
	// ��¥�� ��ȯ�Ѵ�.
	string date(ctime(&t));
	//������ Null Size ����
	date.resize(date.length() - 1);

	//�� ������Ʈ�� �ҽ������� �ϵ忡 ����
	//�տ� ������ ���俨 ���ٿ� ��� �����Ѵ�.

	//���� ������ ����.
	string readStr = str;
	readStr.append(".cpp");
	ifstream in(readStr);

	//�� ������ ����. app = apeend mode
	string outName = "../../SaveFile/";
	outName.append(str);
	outName.append(".txt");

	if (isCreate)
	{
		ofstream out(outName, ios::out);
		out << endl << endl << endl;
		out << "//========================" << endl;		    //����� ����Ѵ�.
		out << "//      " << date << endl;				    //��¥�� ����Ѵ�.
		out << "//========================" << endl << endl; //����� ����Ѵ�.

															 //���� ������ ��� ������ �о� �� ���Ͽ� ����Ѵ�.
		char c;
		while (in.get(c))
		{
			out.put(c);
		}
	}

	else
	{
		ofstream out(outName, ios::app);

		//���� ������ ��� ������ �о� �� ���Ͽ� ����Ѵ�.
		out << endl;
		out << "//========================" << endl;		    //����� ����Ѵ�.
		out << "//      " << date << endl;				    //��¥�� ����Ѵ�.
		out << "//========================" << endl << endl; //����� ����Ѵ�.

															 //���� ������ ��� ������ �о� �� ���Ͽ� ����Ѵ�.
		char c;
		while (in.get(c))
		{
			out.put(c);
		}

	}
	cout << "//========================" << endl;
	cout << "//======Save Success========" << endl;
	cout << "//========================" << endl;

}

template<class Iter>
void printGeneric(Iter begin, Iter end)
{
	while(begin != end)
	{
		begin++;
		cout << "���׸��Լ� ���\n";
	}
}


ostream& operator<<(ostream& os, vector<Dog>& v)
{
	os << "�߰���� ����" << endl;

	for (auto d : v)
		d.Show(os);
	return os;
}


/////6�� ��////////////////////////////////////////////
//ostream& operator << (ostream& os, const vector<Dog>& v)
//{
//	os << "2015.4.23 �߰�����" << endl;
//	for (auto data : v)
//		os << data.getName() << "\t"
//		<< data.getX() << "\t"
//		<< data.getY() << "\t"
//		<< data.getSpeed() << endl;
//	return os;
//}
int main()
{
	vector<Dog> dogs;
	std::string name;
	char buf[10];
	default_random_engine dre;
	uniform_int_distribution<int> random_pos(-500, 500);
	uniform_int_distribution<int> random_speed(10, 20);

	//int n = 100;
	for(int i = 0; i < 100; ++ i)
	{
		_itoa_s(i, buf, 10);
		name = string("�ٶ���") + string(buf);
		dogs.push_back(Dog(name, random_pos(dre), random_pos(dre), random_speed(dre)));
	}

	cout << "--------------------------------------------------------\n";
	print(dogs, 30, 5);
	cout << "--------------------------------------------------------\n";


	int bx = 100;
	int by = 100;
	int disX;
	int disY;


	for (auto &dog : dogs)
	{
		// ����ġ  - ����ġ; 
		// ���⺤�͸� ����;
		// ���⺤�� * speed;
		int dx, dy;
		dx = bx - dog.getX();
		dy = by - dog.getY();
		dog.Move(dx, dy);
	}


	for (auto &dog : dogs)
	{
		dog.setDistance(calcDistance(dog));
	}


	sort(dogs.begin(), dogs.end(),
		[](Dog& a, Dog& b)
	{ return a.getDistance() < b.getDistance();}
	);

	cout << "--------------------------------------------------------\n";
	print(dogs, 0, 10);
	cout << "--------------------------------------------------------\n";


	auto iter = find_if
	(
		dogs.begin()
		, dogs.end()
		, [](Dog& dog)
		  {
		    if (dog.getName() == "�ٶ���71") return true;
		    else return false;
		  }
	);

	auto prev = iter;
	auto next = iter;
	deque<vector<Dog>::iterator> deque;
	for(int i =0; i < 5; ++i)
		deque.push_front(--prev);
	deque.push_back(iter);
	for (int i = 0; i < 5; ++i)
		deque.push_back(++next);
	cout << "---------------------------------------------------------\n";
	iter->Show();
	cout << "--------------------------------------------------------\n";
	for (auto &que : deque)
		que->Show();
	cout << "--------------------------------------------------------\n";



	ofstream out("����.txt");
	out << dogs;

	printGeneric(dogs.begin(), dogs.begin() + 5);





}
