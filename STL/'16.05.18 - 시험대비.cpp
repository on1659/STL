#include "stdafx.h"
#include <unordered_map>

class Cookie
{
private:
	int id;
public:
	Cookie(int n) :id(n) {}
	operator int() const 
	{
		return id;
	}
};



int main()
{
	vector<Cookie> v;
	v.reserve(10000);

	default_random_engine dre;
	uniform_int_distribution<int> ui(1, 10);

	
	/*

	  [���� 1] ���� �ٸ�, ������ id�� ���� ��Ű 10000���� vector�� �־��
	  //id�� 1~ 10000������ �����̴�.
	  //class Cookie�� ������ �� ����.
	  //�ڵ鸣 �ϼ����� ���� ��� �ڽ��� �ذ�å�� ���� ����..

	  ��ġ�� id�� �ϳ��� �������� ������ ���� Ȯ���� �� �ִ�.
	  1. v�� �����Ѵ�
	  2. �˰��� unique()�� ����Ͽ� ��ġ�� ���Ҹ� �����.
	  3. v�� 10000�ΰ� Ȯ���϶�
	  [���� 2]  ���� ������� �ڵ��϶�

	  [���� 3] [���� 2]�� set�� ����Ͽ� �ذ��϶�

	*/

	//------------------------------������� �⺻�ڵ� ------------------------------��

	//set<int, int> map;
	//while(map.size() < 10000)
	//	map.insert(pair<int, int>(ui(dre), 75));
	//for(auto m : map) v.push_back(m.first);

	for(int i =0; i < 100; ++i)
	v.push_back(ui(dre));

	printf("\n--------------Sort Insert-------------------\n");
	for (auto d : v) printf("%d\t",d);

	printf("\n--------------Sort After-------------------\n");
	sort(v.begin(), v.end());
	for (auto d : v) printf("%d\t", d);

	printf("\n--------------Sort Unique------------------\n");
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto d : v) printf("%d\t", d);

	printf("\n--------------Sort Size------------------\n");
	printf("Size : %d\n",v.size());

	printf("\n--------------set------------------\n");
	set <Cookie> s;// = { v.begin(), v.end() };
	for (auto &d : v) s.insert(d);
	for (auto &d : s) printf("%d\t", d);


}

