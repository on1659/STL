#include "stdafx.h"

/*
   STL Container Common Function ( 306 page)
   1. All of (the) Container is Value Context;  
     - Puah back(input) is Call by Value;
	 - Idea! 
	    ~ vector<int*> ...!!!!!
   2. Inner element is away same way Loop possible; =  
   4. Commonly operator is not safty;

   Move iterator;
   STL �����̳��� �������� ���(306page)
   1. ��� �����̳ʴ� �� �����̴�.
   2. 
*/


#include <unordered_set>
#include <iterator>
#include <array>


class Game
{
	int a[2];
};


int main()
{

	//unordered_
	<CGameObject> us;
	//us.insert(CGameObject("����"));
	//us.insert(CGameObject("��ο�"));
	//us.insert(CGameObject("�ȳ�"));
	//us.insert(CGameObject("����"));
	//us.insert(CGameObject("������"));
	//us.insert(CGameObject("�ƴ�"));
	//us.insert(CGameObject("����"));
	//us.insert(CGameObject("�ϴ�"));

	unordered_set<int> u;

	for (int i = 0; i < 100; ++i)
		u.insert(i);
	
	auto f = u.find(10);
	if (f != u.end())
		cout << *f << endl;

	//Please arrange the words received from the keyboard in one sentence in ascending order.

	set<string> sOneSentence
	{
		istream_iterator<string>(cin),
		istream_iterator<string>()
	};
	
	
	//When you create a vector to move the iterator
	set<string> vMoveIterator
	{ 
		std::make_move_iterator(sOneSentence.begin()),
		std::make_move_iterator(sOneSentence.end())
	};
	cout << sOneSentence.size() << endl;
	
	for (auto d : vMoveIterator)
		cout << d << endl;
	
	int asfd = 50;
	
	//string s1;
	//string s2("123123");
	//cout << sizeof(s1) << endl;
	//cout << sizeof(s2) << endl;
	//
	//int alpha[26];

}