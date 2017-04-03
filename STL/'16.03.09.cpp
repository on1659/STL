#include "stdafx.h"

#define MAX 1000000

/*
  C의 qsort()를 이용하여 정수를 정렬해보자.
  랜덤 엔진을 이용하여 정수 1000개를 생성하라.
  qsort()를 이용해서 오름차순을 정렬하라

  ☆ RandomEngine의 향상된 점 (교재 17장 입니다);
    1. 더욱 더 랜덤성 -> 예측 하기 점점 힘들어짐!
	2. 분포를 내가 설정 할 수 있다.
	
	
	f = compare;
	이렇게 만들었을 때 오류가 나지 않게 해야한다.

	전역변수는  Data지 Heap가 아니다.

	Contigous  - 물리적으로 연결되어있다. (배열같은거) 
	Continuse  - 시간적으로 연결되어있다.

	out.write | ios::binary | ios::text 모드를 찾아 봐야함

	text는 읽어야 하는 프로그램에서 한 바이트씩 읽어서 이걸 아스키로 읽는다.
	사실 데이터는 1010100110인 2진수로 되어있음
	데이터가 변한게 아니라 해석이 변한거임!!!!!


*/
/*
  실습 1
 */
/*
int cmp(const void* p, const void* q)
{
	return (*(int*)p - *(int*)q);
}

int compare(const void* p, const void* q)
{
	return (*((int*)p) - *((int*)q));
}

int main()
{
	//char message[20];
	//
	//cin >> message;
	//
	//cout << strlen(message);
	//
	//message[strlen(message)] = NULL;
	
	std::vector<int> vNumber;
	int *pCount;
	uniform_int_distribution<> distribution(1, MAX); // ★ Probability Distribution.
	default_random_engine randomEngine;		 //    Random Engine.

	for (auto i = 0; i < MAX; ++i)
	{
		vNumber.push_back(distribution(randomEngine));
	}
	
	pCount = new int[vNumber.size()];
	int nCount = 0;
	for (auto n : vNumber)
	{
		pCount[nCount++] = n;
	}

	//int(*f) (const void*, const void*) = cmp;

	qsort(pCount, vNumber.size(), sizeof(int), compare);

	
	
	//파일 저장
	//Default ios::text임 그래서 이거와 ios::binary 차이점을 알아야 한다.
	//ofstream out("100만개 저장.txt", ios::binary); 
	//out.write((char*)pCount, vNumber.size() * sizeof(int));
	//out.close();

	ifstream in("100만개 저장.txt", ios::binary);
	int *nArrary = new int[vNumber.size()];
	in.read((char*)nArrary, sizeof(int) * vNumber.size());
	in.close();

	for (auto i = MAX -100; i < MAX; ++i)
		cout << pCount[i] << endl;
	
}
*/

/*
  실습 2
*/


class Dog
{
private:
	std::string m_name;
	int m_age;

public:
	Dog(std::string name, int age) { m_name = name; m_age = age; }

	int getAge() { return m_age; }
	std::string getName() { return m_name; }

	int SortAge(int age)
	{
		if (age > m_age)
			return -1;
		else if (age == m_age)
			return 0;
		else
			return 1;
	}
};

int compare(const void* a, const void* b)
{
	Dog* x = (Dog*)(a);
	Dog* y = (Dog*)(b);
	return -1;
}

int main()
{
	//int a[100];
	//for (int i = 0; i < 100; ++i)a[i] = rand() % 10000;
	//
	//sort(begin(a), end(a), [](int a, int b) {return a > b;});
	//
	//for (int d : a)
	//	cout << d << "	";
	
	
	//qsort()를 이용하여 다음 class 객체를 정렬해보자.
	Dog a[] = { {"윤정현", 5},{"용빠", 3},{"짱아", 5} };
	qsort(a, 3, sizeof(a), compare);
	
	for (auto p : a)
		cout << p.getName() << endl;

}