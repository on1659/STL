#include "stdafx.h"

//#define �ǽ�1 
//#define �ǽ�2
#define �ǽ�3_����

/*
  ��35page �ֽ��?

  ��ǥ���� �� �ʿ��ϴ�? 
     - ���� § �ҽ��� �ڵ尡 ǥ������ § �ڵ��� ������ �����Ϸ�������
	  �����ϰ� ���ư��°� �����Ѵ�.(���)

  ���� å���� ������ �ٷ����
     - I/O Class�� �ſ� ���ϰ� �� �ʿ伺�� ������.. 
	   ���࿡ ���� I/O�� �ڼ��ϰ� �����Ѵ�? �׷� �� å�� ¯!
	 - å ����
     - 812 ~ 980���� I/O�� ���ؼ� ������ �Ѵ�.

  �����ڿ��� Ÿ�԰� ���� ǥ����!!
     - regualr express ���ڿ��� ������ �峭ġ�°��� ���� �ְ��..
	 - 
  �������迭 / �ؽ�/ �ؽ����̺� �� �پ��� sort algorithm,

  ����Ƽ������/ ���ü� ��� ���� Ŭ����
     - ���� / ǻó / ���ؽ� / locking ���

  ������ȭ ������ ���� Ŭ����
     
  ��36page �б����� �˾ƾ� �� ��
     - C++ Component!
	 - class, template, ��� �� �˾ƾ� �Ѵ�.
	 -
  �� ������ 3�����~
    - ������ lamda, namespace, ���

  �� 5���� �߿�
     - share, clock, ť�ä� ���

  �� 6�� STL ����

  �� 7�� 
     - C++03 ~07 ~ 11 ~ 14 ��� �ε�
	 - �� å�� C++ 11��.
  
  �� C++ ǥ���� �� ��� ���������? �̰� �������̴�??

  �� �˰��� ���⵵!
     - ���, ���� nlogn , n^2 ���
	 - for(int x = 0; x < size; ++x)// for(int y = x + 1; y < size; ++y);

  �� ���� ǥ�� ��ȯ�� �Ĥ����� ������ �� �� �յ�.
  �� å�� �� �о��!!!!!!
  �� �÷����� ��ιǷ� �����ص�..����

  �� move, �ø�ƽ, �ƺ���..?


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


/*
  �ǽ� 1
*/
#ifdef �ǽ�1
	int compare(const void* a, const void* b)
	{
	
		string* sA = (string*)a;
		string* sB = (string*)b;
	
		if (a > b)return 1;
		else return -1;
	}
	int main()
	{
		//C++ �ʱ�ȭ
		std::string msg[] = { "������", "3��", "11��", "�ݰ���", "�л����� �ִ�" };
	
		//end�� ������ �迭�� �ƴ϶� �������� �پ��ִ� NULL pointer;
		//������ ����! , ���� �Լ�
		sort(begin(msg), (end(msg)), [](string a, string b) -> float { return a > b;});
	
		for (auto str : msg)
		{
			cout << str << endl;
		}
	
	
		std::string s("The quick  brown fox jumps over the lazy dog");
	
		sort(s.begin(), s.end());
		cout << s << endl;
	
	
		sort(s.begin(), s.end(), [](char a, char b) -> bool {return a < b;});
		cout << s << endl;
	
	}
#endif
	enum class Salut : float
	{
		mr, ms, co, none
	};

int main()
{
	int x = 0;
	int y = 42;
	auto qqq = [x, &y]
	{
		std::cout << "x:" << x << std::endl;
		std::cout << "y:" << y++ << std::endl;
	};

	Salut c = Salut::mr;

	x = y = 77;
	qqq();
	qqq();
	std::cout << "final y:" << y;
}
//
//#elif �ǽ�2
//	/*
//	   �ǽ� 2 
//	*/
//	
//	void function(int, int){ cout << "?" << endl; }
//
//	int main()
//	{
//		//auto�� �ڵ� ������ �� �߷�
//		void(*a)(int, int) = function;
//		auto p = function;
//		p(1, 2);
//		cout << typeid(p).name() << endl;
//
//		vector<string> vString{ "STL","3��","auto","�����߷�","Ÿ���߷�","����" };
//
//		//sort(vString.begin(), vString.end(), [](char* a, char* b) ->bool {return a[0] > b[0];});
//
//
//		//v�� ���� �ִ� ���Ҹ� ó������ ������ ������� ���
//
//		//vector<string>::const_iterator i = vString.begin();
//		//
//		//for (; i < vString.end(); ++i)
//		//	cout << *i << endl;
//
//		for (auto str : vString)
//		{
//
//			cout << str << endl;
//		}
//
//		//���յ� �ʱ�ȭ�ϸ� ����
//		//Test a;
//		//Test b = a; // �������
//		//Test C(10);// ���� 10�������� c�� ����
//		//
//		////�̷��ϱ� 
//		//Test a;
//		//Test b{ 10 }; //�̷��� ��������
//		//int n{ 3.141592 };
//		//cout << n << endl;
//
//		for (auto &str : vString)
//			cout << str << endl;
//
//	}
//
////#elif
////	int main()
////	{
////		//����(lambda:�͸��Լ�) - �� �� �ִ� ���̶�� ������ ����
////		//���ٷ� ����� ������ �����ڵ�
////		[]{cout << "���� ������";  }();
////
////		int val = 100;
////		//[=val](x)
////		[val] //(o)
////		//[&val] //(o)
////		{
////		  cout << "�ȳ�?" << val++ << endl;
////		}();
////
////	}
////
//#endif