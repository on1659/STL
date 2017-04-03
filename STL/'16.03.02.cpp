
#include "stdafx.h"

template<typename T>
void change(T &x, T &y)
{
	T t = x;
	x = y;
	y = t; 
}

void changeT(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}


template<typename T>
T atofT(std::string str)
{
	T data;
	auto n = atof(str.c_str());
	data = (T)n;
	return data;
}

int main()
{

	int a, b;
	a = 5; b = 10;
	change<int>(a, b);
	cout << a << ends << b << endl;
	cout << "------------------" << endl;

	int f = atof("3.14");
	cout << ++(++f) << endl;

	int fTest = atofT<int>("10.5f");
	cout << fTest << endl;
	cout << "------------------" << endl;

	unique_ptr<int> n = make_unique<int>(100);
	cout << *n << endl;
	cout << "------------------" << endl;

}


/*
 �Լ��� �޸� ũ�⿡ ���� ����

  Default Access �������� ����

  int *n = new int(100); //�̰� �ʱⰪ��
  *n = 100;�� �ʱⰪ�� �ƴ�!

  ���۷����� �������� ������!?
   - int n[4]
  
 int *p = &n; //p�� n�� �ּҸ� ��������
   *p = 2000;

   �����ʹ� �޸𸮸� �Դٰ��� �Ϸ��� �����!!

   ���۷����� ��� �ٸ��༮�̾�!
   
   int &r = n;
   r��� ailes(����); 
   ��� �� �� ����Ų�� �ٽ� �ٲ� �� ����!!!!!!
  
 */

