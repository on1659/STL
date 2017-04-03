#include "stdafx.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <Windows.h>

using namespace std;
using namespace chrono;

//#define Test
#define 풀이

#ifdef Test
class Mini
{
private:
	int *p;
public:
	Mini() { p = new int[10000]; }
	Mini(int n) { 
		p = new int[10000]; 
		p[0] = n;
		//cout << "생성 ! " << p[0] << endl;
	}
	~Mini() { delete[] p; }

	Mini(const Mini& other)
	{ 
		p = new int[10000]; 
	}
	Mini(Mini&& other) 
	{
		p = other.p;
		other.p = nullptr;
		//cout << "이동생성 : " << p[0] <<endl;
	}

	Mini & operator = (Mini&& other)
	{
		cout << "이동대입" << endl;
		p = other.p;
		other.p = nullptr;
		return *this;
	}

};
class CQuestInfo
{
public:
	// 기본 생성자
	CQuestInfo()
		: Name(new char[5]), NameLen(5)
	{
		printf("기본 생성자\n");
	}

	// 인수 있는 생성자
	CQuestInfo(const char *strName, int iNameLen)
		: Name(new char[iNameLen]), NameLen(iNameLen)
	{
		printf("인수 있는 생성자\n");
		memcpy(Name, strName, iNameLen);
	}

	// 복사 생성자
	CQuestInfo(const CQuestInfo &quest)
		: Name(new char[quest.NameLen]), NameLen(quest.NameLen)    // 1)
	{
		printf("복사 생성자\n");
		memcpy(Name, quest.Name, quest.NameLen);
	}

	// 대입 연산자
	CQuestInfo & operator = (const CQuestInfo &quest)
	{
		printf("대입 연산자\n");
		if (this != &quest)
		{
			if (NameLen < quest.NameLen)
			{
				delete[]Name;
				Name = new char[quest.NameLen];
			}
			NameLen = quest.NameLen;
			memcpy(Name, quest.Name, NameLen);
		}
		return *this;
	}
	
	// move 생성자
	CQuestInfo(CQuestInfo &&quest)
		: Name(quest.Name), NameLen(quest.NameLen)        // 2)
	{
		printf("move 생성자\n");
		quest.Name = NULL;
		quest.NameLen = 0;
	}

	// move 대입 연산자
	CQuestInfo & operator = (CQuestInfo &&quest)
	{
		printf("move 대입 연산자\n");
		if (this != &quest)
		{
			delete[]Name;
			Name = quest.Name;
			NameLen = quest.NameLen;

			quest.Name = NULL;
			quest.NameLen = 0;
		}
		return *this;
	}

private:
	char *Name;
	int NameLen;
};
int main()
{
	auto start = chrono::system_clock::now();
	auto end = chrono::system_clock::now();
	auto diff = end - start;
	auto msec = chrono::duration_cast<chrono::milliseconds>(diff);
	cout << msec.count() << endl;
	//
	//
	//start = chrono::system_clock::now();
	//for (int i = 0; i < 10000; ++i)
	//	v.push_back(Mini());
	//end = chrono::system_clock::now();
	//diff = end - start;
	//msec = chrono::duration_cast<chrono::milliseconds>(diff);
	//cout << "걸린시간 - " << msec.count() << "밀리초" << endl;
	//
	//v.clear();
	//v.shrink_to_fit();

	vector<Mini> v;
	
	Mini a;
	start = chrono::system_clock::now();
	for (int i = 0; i < 10000; ++i)
	{
		Mini a;
		v.push_back(Mini());
	}
	end = chrono::system_clock::now();
	diff = end - start;
	msec = chrono::duration_cast<chrono::milliseconds>(diff);
	cout << msec.count() << endl;

	//269 - 10000
}
#endif

#ifdef 풀이
class Mini
{
private:
	int *p;
public:
	Mini() { p = new int[10000]; }
	Mini(int n) {
		p = new int[10000];
		p[0] = n;
		//cout << "생성 ! " << p[0] << endl;
	}
	~Mini() { delete[] p; }

	Mini(const Mini& other)
	{
		p = new int[10000];
	}
	Mini(Mini&& other)
	{
		p = other.p;
		other.p = nullptr;
		//cout << "이동생성 : " << p[0] <<endl;
	}

	Mini & operator = (Mini&& other)
	{
		cout << "이동대입" << endl;
		p = other.p;
		other.p = nullptr;
		return *this;
	}

};
int main()
{
	auto start = chrono::system_clock::now();
	Sleep(100);
	auto end = chrono::system_clock::now();
	auto diff = end - start;
	auto msec = chrono::duration_cast<chrono::milliseconds>(diff);
	cout << msec.count() << endl;
	

	vector<Mini> v;

	Mini a;
	start = chrono::system_clock::now();
	v.reserve(10000);
	for (int i = 0; i < 10000; ++i)
		v.push_back(Mini());
	end = chrono::system_clock::now();
	diff = end - start;
	msec = chrono::duration_cast<chrono::milliseconds>(diff);
	cout << "걸린 시간 : " << msec.count() << endl;


	v.clear();
	v.shrink_to_fit();

	/*
	   [문제 1] Class  Mini가 이동 가능하도록 프로그래밍 하라
	   	 ㆁ Mini(Mini&& other)
		   {
		   	 p = other.p;
		   	 other.p = nullptr;
		   }
		[문제 2] 이동가능한 10000개의 프로그램을 v에 추가하는데 걸리는 코드를 걸려줘라.
		 ㆁ 문제와 똑같음 ( 굳이 move 안써도됩니다)

		[문제 3] [문제2]에 측정시간을 적고, 이동지원의 결과와 비교하여 설명하라.
		 ㆁ 40mes / 110 mes ~ 
		    아 시간을 잘못썻네 - 내가 획기적으로 빠르게 썼어야됬는데 그러지 않았음
		   벡터가 동적인 배열인데 push_back도 중에 계속 메모리를 확장합니다. 
		   이때는 복사해야되는데 이동하는거라서 빨라진거다. (벡터와 관련해서 설명해야되나.)


		[문제 4] 개선 할 수 있는 방법은?
			for (int i = 0; i < 10000; ++i)
				v.push_back(Mini());

			1. v.reserve(n)으로 잡아둔다. (답)
			2. release로 바꾼다. ( + 5)

			-이동할당은 사용하지 않으므로 No !

	*/

}
#endif