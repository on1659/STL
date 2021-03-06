#include "stdafx.h"

//#define Pair_정렬
//#define Pair_정렬_ver2
#define STL을_느낄수있는

#ifdef Pair_정렬
void AddAge(pair<string, int> &other)
{
	other.second += 10;
}
/*
  pair : 서로 다른 두 개의 자료형을 하나의 자료형으로 묶는다.
  2차원 좌표를 pair로 관리해보자!
*/

//typedef 는 권장사항이 아님. using 이 권장사항임
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

	//2자췅 좌표 100개를 만들어 봅시당!
	D3DXVECTOR2 v2[100];
	for (auto &p : v2) //반드시 래퍼런스
	{
		p.first = RandomRange(-100, 100);
		p.second = RandomRange(-100, 100);
	}

	//for (auto &p : v2) //반드시 래퍼런스
	//	f2(p);

	sort(begin(v2), end(v2), [](const D3DXVECTOR2& a,const D3DXVECTOR2& b) { return a.second < b.second; });

	for (auto &p : v2) //반드시 래퍼런스
	{
		cout << "(" << p.first << "," << p.second << ")" << endl;
	}

	//이름 & 나이
	//pair<string, int> p;
	//
	//p.first = "가을";
	//p.second = 24;
	//
	//AddAge(p);
	//
	//cout << p.first << "," << p.second << endl;


}
#endif

#ifdef Pair_정렬_ver2

int main()
{
	pair<string, int> OnePiece[]
	{
		{ "루피", 400000000 },
		{ "조로", 200000000 },
		{ "나미", 30000000},
		{ "쵸파", 50 },
		{ "로빈", 15000000},
		{ "상디", 15000000}
	};

	sort(begin(OnePiece), end(OnePiece), [](pair<string, int> a, pair<string, int> b) {return a.second > b.second;});

	for (auto &character : OnePiece)
	{
		cout << "이름 : " << character.first << " / 현상금 : " << character.second << " 베리" << endl;
	}

}

#endif

#ifdef STL을_느낄수있는

int main()
{
	/*
	 키보드에서 사용자가 그만 둘 때 까지 
	 입력한 모든 단어를 저장하고,
	 오름차순으로 정리하여 출력하라
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