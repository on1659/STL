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
	 mult map을 사용하여 중복 값 제거헤서 저장하기
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
		cout << name << ", (" << x << "," << y << ") 스피드 : " << speed << endl;
		//printf("Name : %s, pos(%d, %d), speed : %d\n", name, x, y, speed);// << endl;
	}
	void Show(ostream& os)
	{
		os << name << ", (" << x << "," << y << ") 스피드 : " << speed << endl;
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

void TestSave(std::string str = "중간고사_01.cpp", bool isCreate = true)
{
	// 현재 시간 기록
	// 현재 시간지점을 기록한다.
	auto tp = chrono::system_clock::now();
	// 시간지점을 time_t 형식으로 바꾼다.
	auto t = chrono::system_clock::to_time_t(tp);
	// 날짜로 변환한다.
	string date(ctime(&t));
	//마지막 Null Size 제거
	date.resize(date.length() - 1);

	//이 프로젝트의 소스파일을 하드에 저장
	//앞에 저장한 내요엥 덧붙여 계속 저장한다.

	//읽을 파일을 연다.
	string readStr = str;
	readStr.append(".cpp");
	ifstream in(readStr);

	//쓸 파일을 연다. app = apeend mode
	string outName = "../../SaveFile/";
	outName.append(str);
	outName.append(".txt");

	if (isCreate)
	{
		ofstream out(outName, ios::out);
		out << endl << endl << endl;
		out << "//========================" << endl;		    //장식을 기록한다.
		out << "//      " << date << endl;				    //날짜를 기록한다.
		out << "//========================" << endl << endl; //장식을 기록한다.

															 //읽을 파일의 모든 내용을 읽어 쓸 파일에 기록한다.
		char c;
		while (in.get(c))
		{
			out.put(c);
		}
	}

	else
	{
		ofstream out(outName, ios::app);

		//읽을 파일의 모든 내용을 읽어 쓸 파일에 기록한다.
		out << endl;
		out << "//========================" << endl;		    //장식을 기록한다.
		out << "//      " << date << endl;				    //날짜를 기록한다.
		out << "//========================" << endl << endl; //장식을 기록한다.

															 //읽을 파일의 모든 내용을 읽어 쓸 파일에 기록한다.
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
		cout << "제네릭함수 출력\n";
	}
}


ostream& operator<<(ostream& os, vector<Dog>& v)
{
	os << "중간고사 답지" << endl;

	for (auto d : v)
		d.Show(os);
	return os;
}


/////6번 답////////////////////////////////////////////
//ostream& operator << (ostream& os, const vector<Dog>& v)
//{
//	os << "2015.4.23 중간시험" << endl;
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
		name = string("바람이") + string(buf);
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
		// 공위치  - 개위치; 
		// 방향벡터를 만듬;
		// 방향벡터 * speed;
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
		    if (dog.getName() == "바람이71") return true;
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



	ofstream out("개들.txt");
	out << dogs;

	printGeneric(dogs.begin(), dogs.begin() + 5);





}
