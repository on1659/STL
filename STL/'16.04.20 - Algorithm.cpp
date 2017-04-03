#include "stdafx.h"

#include <iterator>


/*
  ※ STL 에서 중요한 세 가지 요소
    iterator, Container, Algorithm
	
	여기서 알고리즘을 살펴보자.

	ㆍ 250 page

	ㆍ알고리즘은 [전역함수] 이다.  ←→ (반) 멤버함수
	  - 전역함수 : Generic Fucntion. 어떤 타입이든지 관계 없이 할 일을 수행.
	  - 멤버함수 : 멤버함수는 특정한 클래스의 동작을 기술, 다른 클래스 X.
	  - 함수의 존재 유무는 코드를 재활용하기 위해서 사용함

	ㆍ알고리즘의 인자는 
	구간[begin, end]이다.
	ㆍ알고리즘이 항상 효율적일 수는 없다.

	※ Copy
	 vector<int> srcV{ 1,3,5,7,9 };
	 vector<int> desV;

	coy(어디에서, 어디까지, 어디로);

*/
#define MAX 1000

template<class Src, class Des>
inline void myCopy(Src begin, Src end, Des des)
{
	while (begin != end)
	{
		*des++ = *begin++;

		//이런 값이 들어가있는거임
		(des.operator*()).operator++(321321) =
			(beg.operator*()).opeator++(3243232);
	}
}



template<class Iter, class val> 
  inline Iter myfind(Iter begin, Iter end, const val& _Val)
{	
	while (begin != end)
	{
		if (*begin == _Val)
			return begin;
		++begin;
	}
	return begin;
}


  inline std::vector<int>::iterator myVectro_min_element(std::vector<int>::iterator begin, std::vector<int>::iterator end)
  {
	  std::vector<int>::iterator p = begin;
	  begin++;
	  while (begin != end)
	  {
		  if (*p > *begin)
			  p = begin;
		  ++begin;
	  }
	  return p;
  }

  template<class Iter>
  inline Iter my_min_element(Iter begin, Iter end)
  {
	  Iter p = begin;
	  begin++;
	  while (begin != end)
	  {
		  if (*p > *begin)
			  p = begin;
		  ++begin;
	  }
	  return p;
  }


  inline std::string myfindChange(std::string::iterator begin, std::string::iterator end, const char& _Val)
  {
	  std::string str;

	  while (begin != end)
	  {

		  if (*begin == _Val)
		  {
			  str.push_back('s');
		  }
		  else
			str.push_back(*begin);
		  ++begin;
	  }
	  return str;
  }

  int main()
  {
	  std::list<int> v;
	  //v.reserve(MAX);
	  for (int i = 0;i < MAX; ++i)v.push_back(i);
	  for (auto n : v)std::cout << n << "\t";


	  auto f = myfind(v.begin(), v.end(), 10);
	  cout << *f << endl;
	  
	  //-------------------------------------------
	  std::string str("Show Me the Money");
	  auto p = find(str.begin(), str.end(), 'S');
	  *p = 'x';
	  cout << str << endl;


	  //-------------------------------------------
	  //vector<int> vE{ 95,3,5,7,9 };

	  //{
	  //	std::cout << "-------------------------------------" << std::endl;
	  //	//가장 작은 값을 찾는 min_element
	  //	ChornoTime();
	  //	cout << *my_min_element(v.begin(), v.end()) << endl;
	  //	cout << "template : ";ChornoTime(false);
	  //
	  //	//가장 작은 값을 찾는 min_element
	  //	ChornoTime();
	  //	cout << *myVectro_min_element(v.begin(), v.end()) << endl;
	  //	cout << "Different : ";ChornoTime(false);
	  //	std::cout << "\n-------------------------------------" << std::endl;
	  //}

	  list<int> srcV{ 1,3,5,7,9 };
	  list<int> desV;

	//myCopy(srcV.begin() + 1, desV.end() - 1, desV.begin()+1);
	// myCopy(srcV.begin(), desV.end(), std::back_inserter(desV));

	for (auto d : desV)
		cout << d << endl;

}