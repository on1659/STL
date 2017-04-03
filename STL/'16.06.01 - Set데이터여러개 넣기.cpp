��
#include "stdafx.h"
#include <numeric>
#include "GameObject.h"

/*
	 Set���� �Լ� ��ü�ε� ������ �� �� �ִ�.
	 
	 439page !
	  7.10 STL �� �� STL Container !

	����� ���� �ڷᱸ���� STL Container�μ� �����ϱ� ���� ����� !?
	1. STL �����̳��� �䱸�Ǵ� �������̽��� �����Ѵ�.
	2. �����̳ʿ� �˰����� ��������Ʋ�� ����ϴ� ��ü�� �����Ѵ�.
	ex) int a[];

	3. wrapper Ŭ������ �����.

	7���� �������� ~_~ 

	7.12�� ���� @@	
	 - ���� ���� �����̳ʸ� ��߰ڴ�!!!
	 -  ���� 1!! �� �а� ���� 2�� ����
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


	//���ĵ� �������� ���ؼ��� ����Ž���� �մϴ�.
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


	//���� �Ǿ� �ִٴ� ���� ���� ����!
	//���ĵǾ� �����Ƿ� ����Ž���Ѵ�.
	ChornoTime();
	pair<vector<int>::iterator, vector<int>::iterator> range =  std::equal_range(v.begin(), v.end(), 32);
	cout << "32�� ������ : " << distance(range.first, range.second) << endl;
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

		// ���� ����Ѵ�.
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
