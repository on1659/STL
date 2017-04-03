#include "stdafx.h"

/*
  1. �˰��� ���� (269);
  2. �˰���� �������274);
  3. �˰��� ���ڷμ��� �Լ�
  4. bind();
   

  ����!
  list�� ::remove_if�� �Ἥ ���α׷����ϴ°� ���� �� ����.
  �׷��� list�� Ŭ���� �Լ� remove_if�� ���°� ����



*/

int main()
{

	std::vector<int> v{ 1,2,3,4,5,6 };
	std::list<int> l{ 1, 2, 3, 4, 5, 6 };
	//v���� ¦���� ã�� �����ּ���.
	// ->¦����� ���ǿ� �´� ���Ҹ� ����� ���̹Ƿ� remove_if()�� ���

	auto p =remove_if(v.begin(), v.end(),[](const int& a) 
		{
			if(a % 2 == 0)
				return true; 
			else 
				return false;
		});

	l.remove_if([](const int& a){return !( a & 1);});
	v.erase(p, v.end());

	for (auto p : l)
	{
		cout << p << ",";
	}


}