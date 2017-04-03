#include "stdafx.h"

#include <map>

//#define _ù�ð�_Set_Map
#define _��°�ð�


//KYT '16.04.15

/*

   ~ Set�� �������
  
   ~ Map�� �������!
     �� map(�޸𸮰� �پ����� ������) Ư���� [ ] �����ڸ� �����ε� �ϰ� �ִ�.
     �� �迭�� ÷�ڿ� ���ڸ� ���� �ʴ� �迭�� �����迭�̶�� �Ѵ�.

   ~ �ݺ��ڶ� �����ΰ�?
	 �� �ڱⰡ �����ϴ� ��� ���Ҹ� �ϳ��� ���߸��� �ʰ� ��ȸ �� �� �ֵ���
	    �����̳ʰ� �����ϴ� �����Ϳ� ������ ��ü�̴�.
	
	 �ݺ��ڷ� �� �� �ִ� ����
	   1.  * ������   - ����Ű�� ������ ���� ��´�.
	   2. ++   ����   - ���� ���ҷ� �̵��Ѵ�.
	   3. ==   ��   - �� �ݺ��ڰ� ���� ���Ҹ� ����Ű������ ���Ѵ�.
0
	�����̳ʴ� ��� �ݺ��ڸ� �����ϴ°�
	  1.  begin()	- ù ���Ҹ� ����Ų��.
	  2.    end()   - ������ ���ҿ��� �ϳ� ������ ��ġ�� ����Ų��.
	    �������
		��        ��	
	  begin()	  end()
	  rend()	  rbegin()
	  �ݰ������!! [ ) : ������ �����ְ�, ������ ��������.

	 �ݺ��ڴ� �� ������ ī�װ��� ����!
	   1. �����		  �ܹ������θ� ���� ī�װ�. foward Container. ��������Ʈ
	   2. �����		  ����� �ݺ���
	   3. ��    ��  ���  ������ȸ �ݺ���.

	 �ݺ��� ī�װ�
	  STL �����̳��� �ݺ��ڴ� ���� category �� �ϳ��� ���Ѵ�.
	   1. ������ �ݺ���     (forward iterator)
	   2. ����� �ݺ���     (bidirectional) 
	   3. �����］�� �ݺ��� (random access)
	   4.  ~
	   5.  ~



*/

#ifdef _ù�ð�_Set_Map
	int main()
	{
	
		srand(int(time(NULL)));
	
		std::set<int> sContainer;	//< - less
		int n = 100;
		while(--n) sContainer.insert(RandomRange(0, 100000));
		//for (auto &s : sContainer) cout << ++n << ":" << s << endl;

		auto p = sContainer.begin();
		// *p = 41; //�̰� key ���̱� ������ �ȵȴ�
		cout << (*p) << endl;

		std::set<int, greater<int>> sContainerGareater;	
		std::set<int, less<int>>	sContainerLess;


		//----------------------------------------Map------------------------------------
	

		//�ʿ� �����͸� �ִ� ����� ���� �پ��ϴ�
		std::map<std::string, int> mRanking{ make_pair("����",384) };
		std::multimap<std::string, int> mtRanking{ make_pair("����",100) };	//���� Ű���� ���

		mRanking.insert(pair < std::string, int> ("����", 75));
		mRanking.insert(std::make_pair("����", 50));

		auto p2 = mRanking.begin();
		p2++;
		p2++;
		p2->second = 10123;
		cout << p2->second << endl;

		mRanking["����"] = 123123;			//�̷��͵� �ǳ�..
		mRanking.operator[]("����") = 321123123;			//�̷��͵� �ǳ�..
	

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

#ifdef _��°�ð�

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
