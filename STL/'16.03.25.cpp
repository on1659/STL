#include "stdafx.h"

//#define Pair_Á¤·Ä
//#define Pair_Á¤·Ä_ver2
#define STLÀ»_´À³¥¼öÀÖ´Â

#ifdef Pair_Á¤·Ä
void AddAge(pair<string, int> &other)
{
	other.second += 10;
}
/*
  pair : ¼­·Î ´Ù¸¥ µÎ °³ÀÇ ÀÚ·áÇüÀ» ÇÏ³ªÀÇ ÀÚ·áÇüÀ¸·Î ¹­´Â´Ù.
  2Â÷¿ø ÁÂÇ¥¸¦ pair·Î °ü¸®ÇØº¸ÀÚ!
*/

//typedef ´Â ±ÇÀå»çÇ×ÀÌ ¾Æ´Ô. using ÀÌ ±ÇÀå»çÇ×ÀÓ
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

	//2ÀÚ­  ÁÂÇ¥ 100°³¸¦ ¸¸µé¾î º¾½Ã´ç!
	D3DXVECTOR2 v2[100];
	for (auto &p : v2) //¹İµå½Ã ·¡ÆÛ·±½º
	{
		p.first = RandomRange(-100, 100);
		p.second = RandomRange(-100, 100);
	}

	//for (auto &p : v2) //¹İµå½Ã ·¡ÆÛ·±½º
	//	f2(p);

	sort(begin(v2), end(v2), [](const D3DXVECTOR2& a,const D3DXVECTOR2& b) { return a.second < b.second; });

	for (auto &p : v2) //¹İµå½Ã ·¡ÆÛ·±½º
	{
		cout << "(" << p.first << "," << p.second << ")" << endl;
	}

	//ÀÌ¸§ & ³ªÀÌ
	//pair<string, int> p;
	//
	//p.first = "°¡À»";
	//p.second = 24;
	//
	//AddAge(p);
	//
	//cout << p.first << "," << p.second << endl;


}
#endif

#ifdef Pair_Á¤·Ä_ver2

int main()
{
	pair<string, int> OnePiece[]
	{
		{ "·çÇÇ", 400000000 },
		{ "Á¶·Î", 200000000 },
		{ "³ª¹Ì", 30000000},
		{ "ÃİÆÄ", 50 },
		{ "·Îºó", 15000000},
		{ "»óµğ", 15000000}
	};

	sort(begin(OnePiece), end(OnePiece), [](pair<string, int> a, pair<string, int> b) {return a.second > b.second;});

	for (auto &character : OnePiece)
	{
		cout << "ÀÌ¸§ : " << character.first << " / Çö»ó±İ : " << character.second << " º£¸®" << endl;
	}

}

#endif

#ifdef STLÀ»_´À³¥¼öÀÖ´Â

int main()
{
	/*
	 Å°º¸µå¿¡¼­ »ç¿ëÀÚ°¡ ±×¸¸ µÑ ¶§ ±îÁö 
	 ÀÔ·ÂÇÑ ¸ğµç ´Ü¾î¸¦ ÀúÀåÇÏ°í,
	 ¿À¸§Â÷¼øÀ¸·Î Á¤¸®ÇÏ¿© Ãâ·ÂÇÏ¶ó
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