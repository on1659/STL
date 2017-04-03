ㅣ
#include "stdafx.h"
#include <numeric>
#include "GameObject.h"

/*
	 Set에는 함수 객체로도 정렬을 할 수 있다.
	 
	 439page !
	  7.10 STL 그 외 STL Container !

	당신이 만든 자료구조가 STL Container로서 동작하기 위한 방법은 !?
	1. STL 컨테이너의 요구되는 인터페이스를 제공한다.
	2. 컨테이너와 알고리즘간의 인터페이틀르 담당하는 객체를 제공한다.
	ex) int a[];

	3. wrapper 클래스를 만든다.

	7장을 정리하자 ~_~ 

	7.12를 보자 @@	
	 - 언제 무슨 컨테이너를 써야겠니!!!
	 -  과제 1!! 꼭 읽고 과제 2를 하자
	  449page ~_~


*/

//#define Binary_Serch
#define Make_Container

#ifdef Binary_Serch
int main()
{
	// n = [-100, 100];
	vector<int> v;

	for (int i = 0; i < 20000000; ++i)
		v.push_back(rand()%201 - 100);

	int f = 32;


	ChornoTime();
	sort(v.begin(), v.end());
	cout << " Sort : ";
	ChornoTime(false);
	cout << "-----------------------------" << endl;


	//정렬된 시퀀스에 대해서는 이진탐색을 합니다.
	ChornoTime();
	bool b = binary_search(v.begin(), v.end(), f);
	cout << boolalpha << b << endl;
	cout << " binary_search : ";
	ChornoTime(false);
	cout << "-----------------------------" << endl;

	ChornoTime();
	cout << " count : ";
	cout << count(v.begin(), v.end(), f) << endl;
	ChornoTime(false);
	cout << "-----------------------------" << endl;


	ChornoTime();
	if (v.end() != find(v.begin(), v.end(), f))
		cout << "Find : " << f << endl;
	
	else
		cout << "Not Find : " << f << endl;
	cout << " Find : ";
	ChornoTime(false);
	cout << "-----------------------------" << endl;


	//정렬 되어 있다는 것을 잊지 말자!
	//정렬되어 있으므로 이진탐색한다.
	ChornoTime();
	pair<vector<int>::iterator, vector<int>::iterator> range =  std::equal_range(v.begin(), v.end(), 32);
	cout << "32의 개수는 : " << distance(range.first, range.second) << endl;
	cout << "equal_range : ";
	ChornoTime(false);
	cout << "-----------------------------" << endl;


	string str;
	str.begin(); str.end();

}
#endif

#ifdef Make_Container


template<class Type, int size>
class MyCount
{
private:
	//Type data[size];
	Type data[size];

public:
	MyCount()
	{
		for (int i = 0; i < size; ++i)
			data[i] = i;

		// 많이 사용한다.
		iota(data, data, size); 
	}
	Type* begin()
	{
		return data;
	}
	Type* end()
	{
		return data+size;
	}


	//typedef value_type;
	//typedef pointer;
};

#include <array>
int main()
{


	//vector<int> v;
	//char str[] = "Hellow World!";
	//sort(str, str + 14);
	//
	//for(auto s : str)
	//cout << s << "";

	srand(unsigned int(time(NULL)));

	MyCount<int, 10> a;

	sort(a.begin(), a.end(), 
		[](int a, int b)
	{ve
		return rand()%2;
	}
	);
	
	for (auto p : a)
		cout << p << endl;

	

}


#endif
