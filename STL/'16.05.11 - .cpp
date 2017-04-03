#include "stdafx.h"

#include <algorithm>
#include <iterator>
/*
	

  1. 알고리즘 조작 (269);
  2. 알고리즘과 멤버변수(274★);
  3. 알고리즘 인자로서의 함수
  4. bind();

  들어보자!
  list는 ::remove_if를 써서 프로그래밍하는게 나쁠 수 있음.
  그러니 list는 클래스 함수 remove_if를 쓰는게 나음

  
	알고리즘 함수 for_each()
	[beg, end) 구간으로 지정된 원소들을 
	한 번에 한개씩 역참조한 값을
	3번째 callable type의 인자로 사용하여
	callable type을 호출한다.


	알고리즘 함수의 인자로서의 전달되는 호출 가능타입!

	1. 일반함수
	  1학년때부터 사용한 함수
	2. 람다.
		[코드의 가동성이 매우 향상되니다.]
		컴파일러가 최적화할 가능성이 매우 높은 callable type;

	3. 함수객체
	  2와 같은 이유로 일반 함수보다 빠른 속도를 갖는 
	  callable type 람다와 달리 상태를 가질 수 있따.

	바인더!
	 - 이제 쓸 일이 없다.!!
	 - 미리 정의한 객체를 다른값과 결합시키기 위해!! 혹은 특별한 경우를 쓰고싶을때
	   특별한 함수 어댑터를 쓸 수 있다.(???????? 책에 있는 내용임)

	 - 어떤 호출 기능 타입의 인자 갯수를 바꾼 새로운 호출 가능 타입을 만든다.
*/


#ifdef for_each
	int main()
	{
		list<int> l;
		for (int i = 0; i < 6; ++i) l.push_back(i);


		//일반함수
		std::for_each(l.begin(), l.end(), f);

		//람다
		std::for_each(l.begin(), l.end(),
			FunctionInstance()
		);

		//함수객체
		std::for_each(l.begin(), l.end(),
		[]()
		{

		}
		);
	}

template <class T>
void for_each(list<int>::iterator begin, list<int>::iterator end, T function)
{
	while (begin != end)
	{
		function(*begin++);
	}
}

void f(int n)
{
	cout << n << endl;
}


class FunctionInstance
{
public:
	void operator()(int n)
	{
		cout << n << endl;
	}
};


#else


	int main()
	{

	
		vector<int> v{ 1,2,3,4,5 };
		list<int> l;

		//미리 정의되어있는 함수 객체들이 있다.(546page);


		/*	
			m은 인자 2개가 필요한데 transform은 인자를 한개만 전달한다.
			바인더는 m을 인자 한개만 받는 호출가능타입으로 바꿀 수 있다.
			using namspace std::placeholders; 이런데 _1이 정의되어있음.
			 auto f = bind(m, 10, _1)~~이런식으로 
			 (m은 multiplies<int>로 매개변수 두개필요함)

		*/

		//vector의 원소중에서 3보다 큰 원소를 출력해주세요!!!
		std::transform(v.begin(), v.end(), front_inserter(l), 
		[](auto n)
		{
			return n * 10;
		}
		);

		for (auto p : l)
			cout << p << endl;



		return 0;
		int a = 10;
		int *p;

		p = &a;

		for (int i = 0; i < 10; ++i)
		{
			printf("[*p : %d  a : %d]\n",++(*p),a);
		}

		Save("16.05.11 - .cpp");


	}
#endif


