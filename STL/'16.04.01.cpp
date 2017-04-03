#include "stdafx.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <Windows.h>


//#define SmartPointer
#define Next

#ifdef SmartPointer
/*
  스마트 포인터!
   포인터 - 주소는 무엇일까? 포인터에 저장되는 주소란 무엇일까??
           포인터는 가만히 있는 주소를 담는게 아니야!

		  획득한 자원을 가리키는 용도.
	use.
	1. 자원을 획득한다. (heap 에 할당한 메모리를 가리킨다.)
	2. 자원을 활용한다.
	3. 자원을 반환한다. ★★

	중요한 자원을 포인터라고도 부른다.
	ex) 네트워크포인터? = 소켓
	    핸들 ~ 소켓 등등

	ㆍ스마트 포인터 -class로 만든 포인터!
	ㆍC++11의 스마트 포인터!
	  1. unique_ptr - 자원을 독점하는 포인터
	  2. shared_ptr - 자원을 공유하는 포인터! - delete를 신경쓰지 않고 프로그래밍을 하고 싶을때.

*/
static int gNumber = 0;
class Mini
{
public:
	Mini() { cout << "n : " << gNumber << "생성자" << endl; }
	~Mini() { cout << "n : " << gNumber << "소멸자" << endl; }

private:



};

int main()
{
	//int* p;					//얘는 {}끝나면 반드시 사라진다. pod Type
	//p = new int[1000000];	//new int는 명시적으로 선언하지 않는 이상 삭제한다.

	// 이 문제를 해결해보자
	//std::unique_ptr<int> a(new Mini[10000]);

	

	std::shared_ptr<Mini> p = std::make_shared<Mini>();

	//p.reset();
	cout << p.use_count() << endl;

	vector<shared_ptr<Mini>> vp;
	for (int i = 0; i < 1000; ++i)
	{
		vp.push_back(p);
	}
	
	int a, b;
	a = 5;
	b = 10;
	swap(a, b);

	cout <<"vpSize : " << vp.size() << endl;
	cout << "pUseCount : " << p.use_count() << endl;

	//{unique_ptr<Mini> p(new Mini);}

	cout << "SV" << endl;


}
#endif

#ifdef Next

	/*
	  기타 등등~
	  //cout << (int)numeric_limits<int>::max << endl;
		
      5.4 데이터 형의 특질(data text traits) * [특질 : 특별한 기질이나 성질]
	    1. template function에서 파람터의 type의 따라 다른 동작을 하고 싶다면?  
		data 트레잇? 검사할 수 있는 특성
		데이터 타입 트레잇!!!
		뮬어보면 지나갈래

		

		167page에 답이있다.
	*/

template <class T>
void Function(T t)
{
	//if ( T == *)
	if (is_pointer<T>())
	{
		cout << "Pointer" << endl;
		cout << (int*)&t << endl;
	}
	if (is_lvalue_reference<T>())
	{
		cout << "Const" << endl;
		cout << (T*)&t << endl;
	}
	//else
	//	cout << "Value" << endl;
	//if (is_pointer<T>() valuse == false)

}

template<class Iter>
void sort(Iter beg, Iter end)
{

}


int main()
{
	int n{ 100 };
	int *p{ &n };


	cout << "value!" << endl;
	Function(n);

	cout << "+-------------------------------------+" << endl;

	cout << "Point!" << endl;
	Function(p);


	///
	//int n;
	//F(cref(n)); 가능하ㅏ다
}
#endif