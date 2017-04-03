#include "stdafx.h"


using namespace std::placeholders;

/*

 호출 가능 객체 - () 할 수 있는 모든 것

*/

//#define TryCatch_Bad_Error
//#define ClassReview
//#define EnumClass
//#define 호출가능한객체
#define 바인더

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
 나는 함수인데 동물을 인자로 받거든?
 이 동물이 개라면 나는 move()함수를 불러주겠다
 if (Animal& a)
 {
	if(a == 원래 개라면)
	  나는 a의 move함수를 부를래
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

#ifdef 호출가능한객체

/* 
 ~ 함수객체 : 펑터~
           : () 연산자를 오버로딩한 클래스!

  호출 가능한 객체!  - 객체에다가 이걸 붙일 수 있으면 호출 가능한 객체임 ( function call operator() )
  1. 함수
  2. 함수 포인터
  3. 멤버 함수    - 얘는 혼자 호출 할 수 없음! 객체가 따라댕겨야 된다.
  4. 함수 객체 : 함수 호출 연산자( function call operator() )를 오버로딩한 클래스
     - 클래스!
  5. 람다
  6. 바인더로 만든 객체 - 심각하게 많이 사용한다. 
  7. ?
*/
class Tekken
{
public:
	int operator() ()  // 익숙해야된당 +를 오퍼레이터로!!
	{						// ★★★★★★★★
		cout << "I'am Tekken!" << endl;
		return 5432;		// ★★★★★★★★
	};
	int operator() (int a)  // 익숙해야된당 +를 오퍼레이터로!!
	{						// ★★★★★★★★
		return a*a;		// ★★★★★★★★
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
	cout << wulong(642) << endl;			// 같은 문장
	cout << wulong.operator()(642) << endl; // 같은 문장
	//------------------------------------------------------------------
	cout << F([]() {cout << "람다람다"; return 5;});
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
	//cout << F2(sqrt) << endl;	//오류


}
#endif


#ifdef 바인더
int add(int a, int b) { return a + b; }

void sqrt(int n)
{
	
}

int main()
{
	//cout << add(5, 3);

	auto f = bind(add, 3, _1);
	function<int(int)> f2 = bind(add, 3, _1); //7번 이야기
	cout << f2(111) << endl;
	
	sqrt(5);
	bind(add, 4, 2);
	bind(sqrt, 5);
	bind(sqrt, 2);


	//f(bind(sqrt, 2);
}
#endif