#include "stdafx.h"

#define MAX 1000000

/*
  C�� qsort()�� �̿��Ͽ� ������ �����غ���.
  ���� ������ �̿��Ͽ� ���� 1000���� �����϶�.
  qsort()�� �̿��ؼ� ���������� �����϶�

  �� RandomEngine�� ���� �� (���� 17�� �Դϴ�);
    1. ���� �� ������ -> ���� �ϱ� ���� �������!
	2. ������ ���� ���� �� �� �ִ�.
	
	
	f = compare;
	�̷��� ������� �� ������ ���� �ʰ� �ؾ��Ѵ�.

	����������  Data�� Heap�� �ƴϴ�.

	Contigous  - ���������� ����Ǿ��ִ�. (�迭������) 
	Continuse  - �ð������� ����Ǿ��ִ�.

	out.write | ios::binary | ios::text ��带 ã�� ������

	text�� �о�� �ϴ� ���α׷����� �� ����Ʈ�� �о �̰� �ƽ�Ű�� �д´�.
	��� �����ʹ� 1010100110�� 2������ �Ǿ�����
	�����Ͱ� ���Ѱ� �ƴ϶� �ؼ��� ���Ѱ���!!!!!


*/
/*
  �ǽ� 1
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
	uniform_int_distribution<> distribution(1, MAX); // �� Probability Distribution.
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

	
	
	//���� ����
	//Default ios::text�� �׷��� �̰ſ� ios::binary �������� �˾ƾ� �Ѵ�.
	//ofstream out("100���� ����.txt", ios::binary); 
	//out.write((char*)pCount, vNumber.size() * sizeof(int));
	//out.close();

	ifstream in("100���� ����.txt", ios::binary);
	int *nArrary = new int[vNumber.size()];
	in.read((char*)nArrary, sizeof(int) * vNumber.size());
	in.close();

	for (auto i = MAX -100; i < MAX; ++i)
		cout << pCount[i] << endl;
	
}
*/

/*
  �ǽ� 2
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
	
	
	//qsort()�� �̿��Ͽ� ���� class ��ü�� �����غ���.
	Dog a[] = { {"������", 5},{"���", 3},{"¯��", 5} };
	qsort(a, 3, sizeof(a), compare);
	
	for (auto p : a)
		cout << p.getName() << endl;

}