
#include "stdafx.h"
#include <unordered_map>

bool F(string str)
{
	int size = str.size();
	return (str.size() == 10);
}

int main()
{
	//vector<int> v4{ 1,1,1,1,1,1,1,1,11,1,2,3,4,5,5,6,7,7,7,7,8,8,8,9,23,3,432,13,1,2,3 };
	//auto f4 = unique(v4.begin(), v4.end());
	//v4.erase(f4, v4.end());
	//for (auto &d : v4)
	//	cout << d << endl;
	//return 0;

	ifstream ifs("�ȷ�Ȩ���Ǹ���.txt");
	vector<string> v({ istream_iterator<string>(ifs), istream_iterator<string>() });
	ifs.close();


	cout << "��� " << v.size() << "���� �ܾ �о����ϴ�." << endl;


	cout << "-------------------����1--------------" << endl;
	multimap<char, int, less<char> > strMap;
	for (auto &str : v)
	{
		for (auto &c : str)
		{
			auto f = strMap.find(c);
			if (strMap.end() == f)
			{
				strMap.insert(make_pair(c, 1));
			}
			else
			{
				f->second++;
			}
		}
	}
	
	//for (auto &s : strMap)
	//	cout << s.first << " --> " << s.second << endl;
	cout << "-------------------����1--------------" << endl;


	cout << "-------------------����2--------------" << endl;
	multimap<int, char, greater<int> > q2Map;
	for (auto &m : strMap)
	{
		q2Map.insert(make_pair(m.second, m.first));
	}
	//for (auto &s : q2Map)
	//	cout << s.first << " --> " << s.second << endl;
	cout << "-------------------����2--------------" << endl;


	cout << "-------------------����3--------------" << endl;
	int numOfThe = 0;
	for (auto &d : v)
	{
		if( d == "the") numOfThe++;
	}
	
	//cout << "�ܾ� the�� " << numOfThe << "�� ���Ǿ����ϴ�." << endl;
	cout << "-------------------����3--------------" << endl;



	cout << "-------------------����4--------------" << endl;
	multimap<string, int> q4Map;
	multimap<int, string, greater<int> > q4Map2;
	for (auto &str : v)
	{
		auto f = q4Map.find(str);
		if (q4Map.end() == f)
		{
			q4Map.insert(make_pair(str, 1));
		}
		else
		{
			f->second++;
		}
	}
	for (auto &str :  q4Map)
		q4Map2.insert(make_pair(str.second, str.first));

	int count = 0;
	for (auto &str : q4Map2)
	{
		//cout << count << ": " << str.first << " --> " << str.second << endl;
		if (++count >= 20) break;
	}
	cout << "-------------------����4--------------" << endl;



	cout << "-------------------����5--------------" << endl;

	typedef pair<string, int> dic;
	vector<dic> v2;
	
	for (auto &map : q4Map2)
		v2.push_back(make_pair(map.second, map.second.size()));	
	
	sort(v2.begin(), v2.end(),
		[](dic a, dic b)
	{
		return a.second > b.second;
	}
	);
	
	cout << "�ߺ� �� �ܾ ���� �� ������ ���� �� : " << v2.size() << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << v2[2000 + i].first << endl;
	}

	

	vector<string> v3;

	for (auto &map : q4Map2)
		v3.push_back(map.second);
	

	sort(v3.begin(), v3.end(),
		[](auto a, auto b)
	{
		return a.size() > b.size();
	}
	);
	cout << "�ߺ� �� �ܾ ���� �� ������ ���� �� : " << v3.size() << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << v3[2000 + i] << endl;
	}
	cout << "-------------------����5--------------" << endl;

	cout << "-------------------����6--------------" << endl;
	vector<dic> v6;
	vector<dic> v7;
	v6.reserve(v.size());
	v7.reserve(v.size());


	cout << "v6 Size : " << v6.size() << "\t v Size : " << v.size() << endl;
	
	auto f = partition_copy
	(
		  v2.begin()
		, v2.end()
		, v6.begin()
		, v7.begin()
		, [](dic str)
	{
		return (10 == str.second);
	}
	);
	
	cout << "v6 Size : " << v6.size() << "\t v7 Size : " << v7.size() << endl;
	cout << "-------------------����6--------------" << endl;





}



