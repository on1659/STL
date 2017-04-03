#include "stdafx.h"

//#define Pair_����
//#define Pair_����_ver2
#define STL��_�������ִ�

#ifdef Pair_����
void AddAge(pair<string, int> &other)
{
	other.second += 10;
}
/*
  pair : ���� �ٸ� �� ���� �ڷ����� �ϳ��� �ڷ������� ���´�.
  2���� ��ǥ�� pair�� �����غ���!
*/

//typedef �� ��������� �ƴ�. using �� ���������
using D3DXVECTOR2 = pair<double, double>; 

void f2(const D3DXVECTOR2 d)
{
	int x = d.first;
	int y = d.second;

	if( x*x + y*y < 400)
		cout << "Find : (" << x << "," << y << ")" << endl;
}

int main()
{
	srand(unsigned int(time(NULL)));

	//2�ڭ� ��ǥ 100���� ����� ���ô�!
	D3DXVECTOR2 v2[100];
	for (auto &p : v2) //�ݵ�� ���۷���
	{
		p.first = RandomRange(-100, 100);
		p.second = RandomRange(-100, 100);
	}

	//for (auto &p : v2) //�ݵ�� ���۷���
	//	f2(p);

	sort(begin(v2), end(v2), [](const D3DXVECTOR2& a,const D3DXVECTOR2& b) { return a.second < b.second; });

	for (auto &p : v2) //�ݵ�� ���۷���
	{
		cout << "(" << p.first << "," << p.second << ")" << endl;
	}

	//�̸� & ����
	//pair<string, int> p;
	//
	//p.first = "����";
	//p.second = 24;
	//
	//AddAge(p);
	//
	//cout << p.first << "," << p.second << endl;


}
#endif

#ifdef Pair_����_ver2

int main()
{
	pair<string, int> OnePiece[]
	{
		{ "����", 400000000 },
		{ "����", 200000000 },
		{ "����", 30000000},
		{ "����", 50 },
		{ "�κ�", 15000000},
		{ "���", 15000000}
	};

	sort(begin(OnePiece), end(OnePiece), [](pair<string, int> a, pair<string, int> b) {return a.second > b.second;});

	for (auto &character : OnePiece)
	{
		cout << "�̸� : " << character.first << " / ����� : " << character.second << " ����" << endl;
	}

}

#endif

#ifdef STL��_�������ִ�

int main()
{
	/*
	 Ű���忡�� ����ڰ� �׸� �� �� ���� 
	 �Է��� ��� �ܾ �����ϰ�,
	 ������������ �����Ͽ� ����϶�
	*/

	vector<string> v;
	copy(istream_iterator<string>(cin), 
		istream_iterator<string>(), back_inserter(v));
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));

	//vector<char> msg;
	//while (1)
	//{
	//	auto ch = getwchar();
	//	if (ch == 10)break;
	//	msg.push_back((char)ch);
	//}
	//sort(msg.begin(), msg.end());
	//for (auto pChar : msg)
	//{
	//	cout << pChar;
	//}

}

#endif