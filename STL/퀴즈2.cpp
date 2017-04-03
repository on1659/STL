	#include "stdafx.h"

	/*
		���� 1 
		txt���Ͽ��� �����͸� �о�;���..
		���� ���Ժ��� txt���Ͽ��� 10~99�����Ǽ��ڰ� �����ϰ� 10000���� ������
		�׷��� �� ������ ���ڵ� �߿��� �� ���ڰ� ��� �ִ��� ������.
		ex) 
			1312 = 14
			1403 = 15
			0945 = 20
			8231 = 60
			������ �̷�������

		���� 2.
		���� 1���� ���� �����͸� �󵵼��� �������� ���������ض�
		 ex) 
			8231 = 60
			1403 = 15
			1313 = 14
			 945 = 20
			 �̷�������
	*/

	int main()
	{
		//char name[100];// = { "�ȳ��ϼ���" };
		//
		//scanf("%s",&name);
		//auto p = _strrev(name);
		//printf("%s",strrev(name));
		//
		//return 0;
		default_random_engine dre;
		normal_distribution<double> nd(5.0, 1.0);

		ofstream out("���Ժ���.txt");

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


		cout << "���� ���� : " << cnt << endl;

		map<int, int> nMap;

		std::ifstream fin;
		fin.open("���Ժ���.txt", std::ios_base::binary);

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