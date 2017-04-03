#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;



#pragma region test : Launching �Լ��� ���� �Լ������Ϳ� ���ڸ� �Ű��� �޴� �Լ� ����

template<class Fn, class ...Args>
inline auto Launching(Fn&& fn, Args&&... ax)
{
	return forward<Fn>(fn)(forward<Args>(ax)...);
}

int func(int lval, int rval)
{
	cout << lval << "is " << rval << endl;
	return (lval < rval ? rval : lval);
}

#pragma endregion


#pragma region test : print �Լ��� ���� �������� ��� ����

void print()
{
	cout << endl;
}

template <typename T>
void print(const T& t)
{
	cout << t << endl;
}
template<typename Ty, typename... Args>
void print(const Ty& ty, const Args&... ax)
{
	cout << ty << endl;
	print(ax...);
}

#pragma endregion

class CTestBase {

public:

	typedef struct {
		int x, y;
		string str;

	} TestStruct;

public:
	typedef struct {
		int Num; // �������� 
		int Hp; // �޼�����
		int mob_num;//������ ���� ��
		int local_score; // ���� �ִ� ����
		string tag;
	}Scene_MainGame;

protected:

	template<typename Ty>
	void BuildObjects(const Ty& ty)
	{
		BuildObject(ty);
	}

	void BuildObject() const { }

	void BuildObject(int i)
	{
		m_int = i;
	}

	void BuildObject(string str)
	{
		m_str = str;
	}

	void BuildObject(TestStruct str)
	{
		m_s = str;
	}

	void BuildObject(Scene_MainGame Obj)
	{
	}


public:

	int m_int = 0;
	string m_str;
	TestStruct m_s;

	template<typename Ty, typename... Args>
	void BuildObjects(const Ty& ty, const Args&... ax)
	{
		BuildObject(ty);
		BuildObjects(ax...);
	}

};

class CTestSub : public CTestBase {

protected:

	void BuildObject(bool b)
	{
		m_bool = b;
	}
public:

	bool m_bool;

};

int main()
{


	CTestSub t;

	string str = "abc";
	int i = 1;
	bool b = false;
	CTestSub::TestStruct s{ 1,2 };

	CTestSub::Scene_MainGame sm{ 1,2,3,4,"pppa" };

	t.BuildObjects(str, sm, i, s, b);

	cout << t.m_s.x << endl;
	cout << t.m_s.y << endl;

	cout << endl;

	cout << t.m_str << endl;
	cout << t.m_int << endl;
	cout << t.m_bool << endl;

	//   print(str, b, i);

}