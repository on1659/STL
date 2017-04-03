#include "stdafx.h"

#include <algorithm>
#include <iterator>
/*
	

  1. �˰��� ���� (269);
  2. �˰���� �������(274��);
  3. �˰��� ���ڷμ��� �Լ�
  4. bind();

  ����!
  list�� ::remove_if�� �Ἥ ���α׷����ϴ°� ���� �� ����.
  �׷��� list�� Ŭ���� �Լ� remove_if�� ���°� ����

  
	�˰��� �Լ� for_each()
	[beg, end) �������� ������ ���ҵ��� 
	�� ���� �Ѱ��� �������� ����
	3��° callable type�� ���ڷ� ����Ͽ�
	callable type�� ȣ���Ѵ�.


	�˰��� �Լ��� ���ڷμ��� ���޵Ǵ� ȣ�� ����Ÿ��!

	1. �Ϲ��Լ�
	  1�г⶧���� ����� �Լ�
	2. ����.
		[�ڵ��� �������� �ſ� ���Ǵϴ�.]
		�����Ϸ��� ����ȭ�� ���ɼ��� �ſ� ���� callable type;

	3. �Լ���ü
	  2�� ���� ������ �Ϲ� �Լ����� ���� �ӵ��� ���� 
	  callable type ���ٿ� �޸� ���¸� ���� �� �ֵ�.

	���δ�!
	 - ���� �� ���� ����.!!
	 - �̸� ������ ��ü�� �ٸ����� ���ս�Ű�� ����!! Ȥ�� Ư���� ��츦 ���������
	   Ư���� �Լ� ����͸� �� �� �ִ�.(???????? å�� �ִ� ������)

	 - � ȣ�� ��� Ÿ���� ���� ������ �ٲ� ���ο� ȣ�� ���� Ÿ���� �����.
*/


#ifdef for_each
	int main()
	{
		list<int> l;
		for (int i = 0; i < 6; ++i) l.push_back(i);


		//�Ϲ��Լ�
		std::for_each(l.begin(), l.end(), f);

		//����
		std::for_each(l.begin(), l.end(),
			FunctionInstance()
		);

		//�Լ���ü
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

		//�̸� ���ǵǾ��ִ� �Լ� ��ü���� �ִ�.(546page);


		/*	
			m�� ���� 2���� �ʿ��ѵ� transform�� ���ڸ� �Ѱ��� �����Ѵ�.
			���δ��� m�� ���� �Ѱ��� �޴� ȣ�Ⱑ��Ÿ������ �ٲ� �� �ִ�.
			using namspace std::placeholders; �̷��� _1�� ���ǵǾ�����.
			 auto f = bind(m, 10, _1)~~�̷������� 
			 (m�� multiplies<int>�� �Ű����� �ΰ��ʿ���)

		*/

		//vector�� �����߿��� 3���� ū ���Ҹ� ������ּ���!!!
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


