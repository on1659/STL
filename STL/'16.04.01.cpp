#include "stdafx.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <Windows.h>


//#define SmartPointer
#define Next

#ifdef SmartPointer
/*
  ����Ʈ ������!
   ������ - �ּҴ� �����ϱ�? �����Ϳ� ����Ǵ� �ּҶ� �����ϱ�??
           �����ʹ� ������ �ִ� �ּҸ� ��°� �ƴϾ�!

		  ȹ���� �ڿ��� ����Ű�� �뵵.
	use.
	1. �ڿ��� ȹ���Ѵ�. (heap �� �Ҵ��� �޸𸮸� ����Ų��.)
	2. �ڿ��� Ȱ���Ѵ�.
	3. �ڿ��� ��ȯ�Ѵ�. �ڡ�

	�߿��� �ڿ��� �����Ͷ�� �θ���.
	ex) ��Ʈ��ũ������? = ����
	    �ڵ� ~ ���� ���

	������Ʈ ������ -class�� ���� ������!
	��C++11�� ����Ʈ ������!
	  1. unique_ptr - �ڿ��� �����ϴ� ������
	  2. shared_ptr - �ڿ��� �����ϴ� ������! - delete�� �Ű澲�� �ʰ� ���α׷����� �ϰ� ������.

*/
static int gNumber = 0;
class Mini
{
public:
	Mini() { cout << "n : " << gNumber << "������" << endl; }
	~Mini() { cout << "n : " << gNumber << "�Ҹ���" << endl; }

private:



};

int main()
{
	//int* p;					//��� {}������ �ݵ�� �������. pod Type
	//p = new int[1000000];	//new int�� ��������� �������� �ʴ� �̻� �����Ѵ�.

	// �� ������ �ذ��غ���
	//std::unique_ptr<int> a(new Mini[10000]);

	

	std::shared_ptr<Mini> p = std::make_shared<Mini>();

	//p.reset();
	cout << p.use_count() << endl;

	vector<shared_ptr<Mini>> vp;
	for (int i = 0; i < 1000; ++i)
	{
		vp.push_back(p);
	}
	
	int a, b;
	a = 5;
	b = 10;
	swap(a, b);

	cout <<"vpSize : " << vp.size() << endl;
	cout << "pUseCount : " << p.use_count() << endl;

	//{unique_ptr<Mini> p(new Mini);}

	cout << "SV" << endl;


}
#endif

#ifdef Next

	/*
	  ��Ÿ ���~
	  //cout << (int)numeric_limits<int>::max << endl;
		
      5.4 ������ ���� Ư��(data text traits) * [Ư�� : Ư���� �����̳� ����]
	    1. template function���� �Ķ����� type�� ���� �ٸ� ������ �ϰ� �ʹٸ�?  
		data Ʈ����? �˻��� �� �ִ� Ư��
		������ Ÿ�� Ʈ����!!!
		�ľ�� ��������

		

		167page�� �����ִ�.
	*/

template <class T>
void Function(T t)
{
	//if ( T == *)
	if (is_pointer<T>())
	{
		cout << "Pointer" << endl;
		cout << (int*)&t << endl;
	}
	if (is_lvalue_reference<T>())
	{
		cout << "Const" << endl;
		cout << (T*)&t << endl;
	}
	//else
	//	cout << "Value" << endl;
	//if (is_pointer<T>() valuse == false)

}

template<class Iter>
void sort(Iter beg, Iter end)
{

}


int main()
{
	int n{ 100 };
	int *p{ &n };


	cout << "value!" << endl;
	Function(n);

	cout << "+-------------------------------------+" << endl;

	cout << "Point!" << endl;
	Function(p);


	///
	//int n;
	//F(cref(n)); �����Ϥ���
}
#endif