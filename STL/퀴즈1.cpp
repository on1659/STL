#include "stdafx.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <Windows.h>

using namespace std;
using namespace chrono;

//#define Test
#define Ǯ��

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
		//cout << "���� ! " << p[0] << endl;
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
		//cout << "�̵����� : " << p[0] <<endl;
	}

	Mini & operator = (Mini&& other)
	{
		cout << "�̵�����" << endl;
		p = other.p;
		other.p = nullptr;
		return *this;
	}

};
class CQuestInfo
{
public:
	// �⺻ ������
	CQuestInfo()
		: Name(new char[5]), NameLen(5)
	{
		printf("�⺻ ������\n");
	}

	// �μ� �ִ� ������
	CQuestInfo(const char *strName, int iNameLen)
		: Name(new char[iNameLen]), NameLen(iNameLen)
	{
		printf("�μ� �ִ� ������\n");
		memcpy(Name, strName, iNameLen);
	}

	// ���� ������
	CQuestInfo(const CQuestInfo &quest)
		: Name(new char[quest.NameLen]), NameLen(quest.NameLen)    // 1)
	{
		printf("���� ������\n");
		memcpy(Name, quest.Name, quest.NameLen);
	}

	// ���� ������
	CQuestInfo & operator = (const CQuestInfo &quest)
	{
		printf("���� ������\n");
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
	
	// move ������
	CQuestInfo(CQuestInfo &&quest)
		: Name(quest.Name), NameLen(quest.NameLen)        // 2)
	{
		printf("move ������\n");
		quest.Name = NULL;
		quest.NameLen = 0;
	}

	// move ���� ������
	CQuestInfo & operator = (CQuestInfo &&quest)
	{
		printf("move ���� ������\n");
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
	//cout << "�ɸ��ð� - " << msec.count() << "�и���" << endl;
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

#ifdef Ǯ��
class Mini
{
private:
	int *p;
public:
	Mini() { p = new int[10000]; }
	Mini(int n) {
		p = new int[10000];
		p[0] = n;
		//cout << "���� ! " << p[0] << endl;
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
		//cout << "�̵����� : " << p[0] <<endl;
	}

	Mini & operator = (Mini&& other)
	{
		cout << "�̵�����" << endl;
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
	cout << "�ɸ� �ð� : " << msec.count() << endl;


	v.clear();
	v.shrink_to_fit();

	/*
	   [���� 1] Class  Mini�� �̵� �����ϵ��� ���α׷��� �϶�
	   	 �� Mini(Mini&& other)
		   {
		   	 p = other.p;
		   	 other.p = nullptr;
		   }
		[���� 2] �̵������� 10000���� ���α׷��� v�� �߰��ϴµ� �ɸ��� �ڵ带 �ɷ����.
		 �� ������ �Ȱ��� ( ���� move �Ƚᵵ�˴ϴ�)

		[���� 3] [����2]�� �����ð��� ����, �̵������� ����� ���Ͽ� �����϶�.
		 �� 40mes / 110 mes ~ 
		    �� �ð��� �߸����� - ���� ȹ�������� ������ ���߉�µ� �׷��� �ʾ���
		   ���Ͱ� ������ �迭�ε� push_back�� �߿� ��� �޸𸮸� Ȯ���մϴ�. 
		   �̶��� �����ؾߵǴµ� �̵��ϴ°Ŷ� �������Ŵ�. (���Ϳ� �����ؼ� �����ؾߵǳ�.)


		[���� 4] ���� �� �� �ִ� �����?
			for (int i = 0; i < 10000; ++i)
				v.push_back(Mini());

			1. v.reserve(n)���� ��Ƶд�. (��)
			2. release�� �ٲ۴�. ( + 5)

			-�̵��Ҵ��� ������� �����Ƿ� No !

	*/

}
#endif