
#include "stdafx.h"

template<typename T>
void change(T &x, T &y)
{
	T t = x;
	x = y;
	y = t; 
}

void changeT(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}


template<typename T>
T atofT(std::string str)
{
	T data;
	auto n = atof(str.c_str());
	data = (T)n;
	return data;
}

int main()
{

	int a, b;
	a = 5; b = 10;
	change<int>(a, b);
	cout << a << ends << b << endl;
	cout << "------------------" << endl;

	int f = atof("3.14");
	cout << ++(++f) << endl;

	int fTest = atofT<int>("10.5f");
	cout << fTest << endl;
	cout << "------------------" << endl;

	unique_ptr<int> n = make_unique<int>(100);
	cout << *n << endl;
	cout << "------------------" << endl;

}


/*
 함수는 메모리 크기에 들어가지 않음

  Default Access 지정자의 차이

  int *n = new int(100); //이게 초기값임
  *n = 100;은 초기값이 아님!

  래퍼런스와 포인터의 차이점!?
   - int n[4]
  
 int *p = &n; //p는 n의 주소를 포인팅해
   *p = 2000;

   포인터는 메모리를 왔다갔다 하려고 만든거!!

   래퍼런스는 얘와 다른녀석이야!
   
   int &r = n;
   r얘는 ailes(별명); 
   얘는 한 번 가리킨걸 다시 바꿀 수 없음!!!!!!
  
 */

