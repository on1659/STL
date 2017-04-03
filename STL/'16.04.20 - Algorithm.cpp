#include "stdafx.h"

#include <iterator>


/*
  �� STL ���� �߿��� �� ���� ���
    iterator, Container, Algorithm
	
	���⼭ �˰����� ���캸��.

	�� 250 page

	���˰����� [�����Լ�] �̴�.  ��� (��) ����Լ�
	  - �����Լ� : Generic Fucntion. � Ÿ���̵��� ���� ���� �� ���� ����.
	  - ����Լ� : ����Լ��� Ư���� Ŭ������ ������ ���, �ٸ� Ŭ���� X.
	  - �Լ��� ���� ������ �ڵ带 ��Ȱ���ϱ� ���ؼ� �����

	���˰����� ���ڴ� 
	����[begin, end]�̴�.
	���˰����� �׻� ȿ������ ���� ����.

	�� Copy
	 vector<int> srcV{ 1,3,5,7,9 };
	 vector<int> desV;

	coy(��𿡼�, ������, ����);

*/
#define MAX 1000

template<class Src, class Des>
inline void myCopy(Src begin, Src end, Des des)
{
	while (begin != end)
	{
		*des++ = *begin++;

		//�̷� ���� ���ִ°���
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
	  //	//���� ���� ���� ã�� min_element
	  //	ChornoTime();
	  //	cout << *my_min_element(v.begin(), v.end()) << endl;
	  //	cout << "template : ";ChornoTime(false);
	  //
	  //	//���� ���� ���� ã�� min_element
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