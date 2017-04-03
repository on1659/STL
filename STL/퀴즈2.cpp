	#include "stdafx.h"

	/*
		문제 1 
		txt파일에서 데이터를 읽어와야함..
		현재 정규분포 txt파일에는 10~99까지의숫자가 랜덤하게 10000개가 들어가있음
		그래서 이 만개의 숫자들 중에서 각 숫자가 몇개가 있는지 세야함.
		ex) 
			1312 = 14
			1403 = 15
			0945 = 20
			8231 = 60
			떙때땡 이런식으로

		문제 2.
		문제 1에서 나온 데이터를 빈도수를 기준으로 내림차순해라
		 ex) 
			8231 = 60
			1403 = 15
			1313 = 14
			 945 = 20
			 이런식으로
	*/

	int main()
	{
		//char name[100];// = { "안녕하세요" };
		//
		//scanf("%s",&name);
		//auto p = _strrev(name);
		//printf("%s",strrev(name));
		//
		//return 0;
		default_random_engine dre;
		normal_distribution<double> nd(5.0, 1.0);

		ofstream out("정규분포.txt");

		int cnt{ 0 };


		for (int i = 0; i < 1000000; ++i)
		{
			double d = nd(dre);
			int n = d;
			if (0 < n && n < 101)
			{
				out << n << " ";
				cnt++;
			}

		
		}
		out.close();


		cout << "생성 개수 : " << cnt << endl;

		map<int, int> nMap;

		std::ifstream fin;
		fin.open("정규분포.txt", std::ios_base::binary);

		char msg[4];
		while (fin.get(msg,4))
		{
			//cout << msg << endl;

			auto p = nMap.find(atof(msg));
			if ( p == nMap.end())
			{
				nMap.insert(make_pair(atof(msg), 1));
			}
			else
			{
				p->second++;
			}
		}
		fin.close();
		cout << endl;
		struct vPair 
		{
			int fir;
			int se;
			vPair(int a, int b)
			{
				fir = a;
				se = b;
			}
		};

		vector<vPair> v;
		for (auto m : nMap)
		{
			cout <<m.second << " --- " << m.first << endl;
			v.push_back(vPair(m.first, m.second));
		}
		sort(
			v.begin()
			, v.end()
			, [](const vPair& a, const vPair& b) { return (a.se > b.se); }
		);
		cout << "-------------------------------------" << endl;
		for (auto vv : v)
		{
			cout << "" << vv.se << " --- " << vv.fir << endl;
		}
	
		v.clear();
		nMap.clear();
	}