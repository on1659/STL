#include "stdafx.h"

/*
  1. 알고리즘 조작 (269);
  2. 알고리즘과 멤버변수274);
  3. 알고리즘 인자로서의 함수
  4. bind();
   

  들어보자!
  list는 ::remove_if를 써서 프로그래밍하는게 나쁠 수 있음.
  그러니 list는 클래스 함수 remove_if를 쓰는게 나음



*/

int main()
{

	std::vector<int> v{ 1,2,3,4,5,6 };
	std::list<int> l{ 1, 2, 3, 4, 5, 6 };
	//v에서 짝수를 찾아 지워주세요.
	// ->짝수라는 조건에 맞는 원소를 지우는 것이므로 remove_if()를 사용

	auto p =remove_if(v.begin(), v.end(),[](const int& a) 
		{
			if(a % 2 == 0)
				return true; 
			else 
				return false;
		});

	l.remove_if([](const int& a){return !( a & 1);});
	v.erase(p, v.end());

	for (auto p : l)
	{
		cout << p << ",";
	}


}