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

	  [문제 1] 서로 다른, 임의의 id를 갖는 쿠키 10000개를 vector에 넣어라
	  //id는 1~ 10000사이의 정수이다.
	  //class Cookie를 수정할 수 있음.
	  //코들르 완성하지 못한 경우 자신의 해결책을 적어 볼것..

	  겹치는 id가 하나도 없난가는 다음과 같이 확인할 수 있다.
	  1. v를 정렬한다
	  2. 알고리즘 unique()를 사용하여 겹치는 원소를 지운다.
	  3. v가 10000인가 확인하라
	  [문제 2]  위의 순서대로 코딩하라

	  [문제 3] [문제 2]를 set을 사용하여 해결하라

	*/

	//------------------------------여기까지 기본코드 ------------------------------ㅋ

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

