#include "stdafx.h"


using namespace std::placeholders;

/*

 ȣ�� ���� ��ü - () �� �� �ִ� ��� ��

*/

//#define TryCatch_Bad_Error
//#define ClassReview
//#define EnumClass
//#define ȣ�Ⱑ���Ѱ�ü
#define ���δ�

#ifdef TryCatch_Bad_Error

int main()
{
	int n = 5000;
	while (n--)
	{
		char *p;
		try
		{
			p = new char[10000000];
			cout << n << endl;
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
		}
		delete (p);
	}


}

#endif

#ifdef ClassReview

class Animal
{
protected:
	int type;

public:

	virtual void Move() = 0;
};

class Dog : public Animal
{ 
public:

	void Move() override final
	{
		cout << " Dog is Run" << endl;

	}
};

		//if(dynamic_cast<Dog*>(&animal))
class Bird : public Animal
{
public:
	void Move() override final
	{
		cout << " Bird is Fly" << endl;
	}
};

void IsAnimal(Animal& animal)
{
	
	try
	{
		Dog& dog = dynamic_cast<Dog&>(animal);
		dog.Move();
	}
	catch(exception &e)
	{
		cout << e.what()<< endl;
	}
}





/*
 ���� �Լ��ε� ������ ���ڷ� �ްŵ�?
 �� ������ ����� ���� move()�Լ��� �ҷ��ְڴ�
 if (Animal& a)
 {
	if(a == ���� �����)
	  ���� a�� move�Լ��� �θ���
 }


*/

int main()
{
	Animal* vAnimal[] = { new Dog, new Bird, new Dog };
	
	for (auto &animial : vAnimal)
	{
		IsAnimal(*animial);

		//if(dynamic_cast<Dog*>(animial))
		//	animial->Move();
	}


}
#endif

#ifdef EnumClass

enum Color
{
	Red, Green, Blue
};

enum class ColorW
{
	RedW, GreenW, BlueW
};

int main()
{
	int r = Color::Red;
	ColorW rw = ColorW::RedW;
}

#endif

#ifdef ȣ�Ⱑ���Ѱ�ü

/* 
 ~ �Լ���ü : ����~
           : () �����ڸ� �����ε��� Ŭ����!

  ȣ�� ������ ��ü!  - ��ü���ٰ� �̰� ���� �� ������ ȣ�� ������ ��ü�� ( function call operator() )
  1. �Լ�
  2. �Լ� ������
  3. ��� �Լ�    - ��� ȥ�� ȣ�� �� �� ����! ��ü�� �����ܾ� �ȴ�.
  4. �Լ� ��ü : �Լ� ȣ�� ������( function call operator() )�� �����ε��� Ŭ����
     - Ŭ����!
  5. ����
  6. ���δ��� ���� ��ü - �ɰ��ϰ� ���� ����Ѵ�. 
  7. ?
*/
class Tekken
{
public:
	int operator() ()  // �ͼ��ؾߵȴ� +�� ���۷����ͷ�!!
	{						// �ڡڡڡڡڡڡڡ�
		cout << "I'am Tekken!" << endl;
		return 5432;		// �ڡڡڡڡڡڡڡ�
	};
	int operator() (int a)  // �ͼ��ؾߵȴ� +�� ���۷����ͷ�!!
	{						// �ڡڡڡڡڡڡڡ�
		return a*a;		// �ڡڡڡڡڡڡڡ�
	};

};

template <class Call>
int F(Call call)
{
	return call();
}

template <class Call>
int  F2(Call call)
{
	return call(4);
};


int main()
{
	//------------------------------------------------------------------
	Tekken wulong;
	cout << wulong(642) << endl;			// ���� ����
	cout << wulong.operator()(642) << endl; // ���� ����
	//------------------------------------------------------------------
	cout << F([]() {cout << "���ٶ���"; return 5;});
		//------------------------------------------------------------------
	vector<int> vNumber;
	for (int i = 0; i < 100; ++i)
		vNumber.push_back(rand()%100);

	for (auto &n : vNumber)
	{
		cout << n << endl;
	}
	cout << "--------------------------------------------" << endl;
	sort(vNumber.begin(), vNumber.end(), [](int a, int b) { return a > b;});

	for (auto &n : vNumber)
	{
		cout << n << endl;
	}
	//------------------------------------------------------------------
	// f(bind(sqrt,2);
	//cout << F2(sqrt) << endl;	//����


}
#endif


#ifdef ���δ�
int add(int a, int b) { return a + b; }

void sqrt(int n)
{
	
}

int main()
{
	//cout << add(5, 3);

	auto f = bind(add, 3, _1);
	function<int(int)> f2 = bind(add, 3, _1); //7�� �̾߱�
	cout << f2(111) << endl;
	
	sqrt(5);
	bind(add, 4, 2);
	bind(sqrt, 5);
	bind(sqrt, 2);


	//f(bind(sqrt, 2);
}
#endif