#include "stdafx.h"

#include <map>

//#define _첫시간_Set_Map
#define _둘째시간


//KYT '16.04.15

/*

   ~ Set을 사용하자
  
   ~ Map을 사용하자!
     ㆍ map(메모리가 붙어있지 않지만) 특별히 [ ] 연산자를 오버로딩 하고 있다.
     ㆍ 배열의 첨자에 숫자를 쓰지 않는 배열을 연관배열이라고 한다.

   ~ 반복자란 무엇인가?
	 ㆍ 자기가 관리하는 모든 원소를 하나도 빠뜨리지 않고 순회 할 수 있도록
	    컨테이너가 제공하는 포인터와 유사한 객체이다.
	
	 반복자로 할 수 있는 연산
	   1.  * 역참조   - 가리키는 원소의 값을 얻는다.
	   2. ++   증가   - 다음 원소로 이동한다.
	   3. ==   비교   - 두 반복자가 같은 원소를 가리키는지를 비교한다.
0
	컨테이너는 어떻게 반복자를 제공하는가
	  1.  begin()	- 첫 원소를 가리킨다.
	  2.    end()   - 마지막 원소에서 하나 증가한 위치를 가리킨다.
	    □□□□□▒
		↑        ↑	
	  begin()	  end()
	  rend()	  rbegin()
	  반개방범위!! [ ) : 반쪽은 닫혀있고, 반쪽은 열려있음.

	 반복자는 세 가지의 카테고리가 있음!
	   1. →→→→		  단방향으로만 가는 카테고리. foward Container. 선형리스트
	   2. ↔↔↔↔		  양방향 반복자
	   3. →    →  ←←  랜덤순회 반복자.

	 반복자 카테고리
	  STL 컨테이너의 반복자는 다음 category 중 하나에 속한다.
	   1. 순방향 반복자     (forward iterator)
	   2. 양방향 반복자     (bidirectional) 
	   3. 랜덤억섹스 반복자 (random access)
	   4.  ~
	   5.  ~



*/

#ifdef _첫시간_Set_Map
	int main()
	{
	
		srand(int(time(NULL)));
	
		std::set<int> sContainer;	//< - less
		int n = 100;
		while(--n) sContainer.insert(RandomRange(0, 100000));
		//for (auto &s : sContainer) cout << ++n << ":" << s << endl;

		auto p = sContainer.begin();
		// *p = 41; //이건 key 값이기 때문에 안된당
		cout << (*p) << endl;

		std::set<int, greater<int>> sContainerGareater;	
		std::set<int, less<int>>	sContainerLess;


		//----------------------------------------Map------------------------------------
	

		//맵에 데이터를 넣는 방식은 아주 다양하다
		std::map<std::string, int> mRanking{ make_pair("루피",384) };
		std::multimap<std::string, int> mtRanking{ make_pair("루피",100) };	//동시 키값을 허용

		mRanking.insert(pair < std::string, int> ("쵸파", 75));
		mRanking.insert(std::make_pair("나미", 50));

		auto p2 = mRanking.begin();
		p2++;
		p2++;
		p2->second = 10123;
		cout << p2->second << endl;

		mRanking["가나"] = 123123;			//이런것도 되네..
		mRanking.operator[]("가랏") = 321123123;			//이런것도 되네..
	

		for (auto &rank : mRanking)
			std::cout << rank.first << "," << rank.second << std::endl;

		cout << "-" << endl;
		std::map<int, int> mTest{ make_pair(0,384) };
		mTest[1] = 1032;
		mTest[2] = 1032;
		mTest[123] = 1032;
		mTest[4] = 1032;

		for (auto &test : mTest)
			std::cout << test.first << "," << test.second << std::endl;




	}
#endif

#ifdef _둘째시간

	int main()
	{
		std::ifstream in("Alice.txt");


		std::map<std::string, int> i_want_know_CharCount;
		std::string c;
		while (in >> c)
			i_want_know_CharCount[c]++;

		std::map<int, std::string> m2;

		auto mp = i_want_know_CharCount.begin();
		for (int i = 0; i < i_want_know_CharCount.size(); ++i)
		{
			m2.insert(make_pair(mp->second, mp->first));
			++mp;
		}

		//while (in >> c)
		//{
		//	while ('Z' < c[c.size() - 1] || c[c.size() - 1] < 'A')
		//	{
		//		c.pop_back();
		//	}
		//	while ('Z' < c[c.size() - 1] || c[c.size() - 1] < 'A')
		//	{
		//		c.pop_back();
		//	}
		//
		//	i_want_know_CharCount[c]++;
		//}

		auto adfs = m2.begin();
		//sort(m2.begin(), m2.end(), 
		//	[](std::pair<int, std::string> a, std::pair<int, std::string> b) 
		//{
		//	return (a.first < b.first);
		//}
		//);

		for (auto &m : m2)
		{
			cout << "[ word  : " << m.second << " ] [ Count : " << m.first << " ]" << endl;
		}
		cout << "------" << endl;
		
		
		auto p3 = m2.rbegin();
		for (int i = 0; i < 30; ++i)
		{
			cout << "[Alphabet : " << p3->second << "][Count : " << p3->first << "]" << endl;
			++p3;
		}

		//for (auto &m : i_want_know_CharCount)
		//{
		//	cout << "[Alphabet : " << m.first << "][Count : " << m.second << "]" << endl;
		//}

		in.close();
	
	}
#endif
