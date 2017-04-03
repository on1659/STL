#include "stdafx.h"

/*	
	deque()는 메모리가 연속되어 있지 않다.
	하지만 임의접근은 가능하다. ~338page

	1. Insert & Remove element is very Fast;
	1.요소의 삽입과 제거는 시작과 끝 부분에서 모두 빠르다.
	  - 이 연산들은 모두 분할 상환 된 (= amortized	)


	439page, 437page가 중요하다.


	set은 원소의 순서를 <연산사 하나로 판단한다. - strctly weak ordering
	이것은 판단의 기준에 하나의 연산자만 사용할 수 있다는 점이 장점이다.
	즉! 같은 가의 판단을 ==에 의존하지 않고 a<b, b<a가 모두 거짓인 경우 같다고 판단하는 것이다.
	(Game < Game를 operator해줘야 한다)
	이 것을 동등성(equivalence)라 한다.
	한편 find()에서는 같은 원소를 찾는데 == 연산자를 이용한다.
	이것은 상등성(equality)라 한다. 
	 - 358page임


*/


//#define _스트링하나하나_찾아가기
//#define _Deque()
//#define _ContainerList()
#define _ContainerSet()

#ifdef _스트링하나하나_찾아가기

int main()
{

	vector<string> v{ "123","abcdefghijklmn", "456" };

	string* str = ((v.data()));
	for (auto d : v)
	{
		char* c = (char*)(str->data());
		char d = *c;
		for(int i = 0; i < strlen(c); ++i)
		{
			cout << d++ << "_";
		}

		cout << endl;
		cout << *(str++) << endl;
	}

}

#endif

#ifdef _Deque()

int main()
{

	deque<string> que{ "123","abcdefghijklmn", "456" };

	for(int i =0; i < que.size(); ++i)
		cout << que[i] << endl;

}

#endif

#ifdef _ContainerList()

int deleteCount = 0;
class Game
{
private:
	char* buf;
	int n;
public:
	Game(int size) : n(size)
	{
		buf = new char[size];
	};

	Game(const Game& other)
	{
		buf = other.buf;
		n = other.n;

		cout << "----복사생성시 삭제----" << endl;
		other.~Game();
		cout << "------------------------" << endl;
		//buf = other.buf;
	};

	Game(const Game&& other)
	{
		buf = other.buf;
		n = other.n;

		cout << "----Move 삭제----" << endl;
		other.~Game();
		cout << "------------------------" << endl;
		//buf = other.buf;
	};

	~Game()
	{
		cout << ++deleteCount << endl;
		buf = nullptr;
	}

	int getNumber() const { return n; }

	operator const int() { return n; }

	bool operator=(const Game& other) const
	{
		return (n == other.n);
	}

};
int main()
{
	vector<Game> l1{ move(Game(1)),move(Game(2)),move(Game(3)),move(Game(4)),move(Game(8)) };
	vector<Game> l2{ move(Game(3)),move(Game(5)),move(Game(7)) };

	//auto p = lower_bound(l1.begin(), l1.end(), 3);
	//auto p2 = l1.begin();
	//++p2;
	//++p2;
	//l1.splice(p2, l2);

	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	for (const Game& d : l1)
		cout << "┃\t\t\t" << d.getNumber() << "　      \t\t┃"<<endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;



	

	//cout << "Delete L1" << endl;
	//l1.~list();
	//cout << "Delete L1" << endl;
	//
	//cout << "Delete L2" << endl;
	//l2.~list();
	//cout << "Delete L2" << endl;

}
#endif


#ifdef _ContainerSet()

int deleteCount = 0;
class Game
{
private:
	char* buf;
	int n;
public:
	Game(int size) : n(size)
	{
		buf = new char[size];
	};

	Game(const Game& other)
	{
		buf = other.buf;
		n = other.n;

		cout << "----복사생성시 삭제----" << endl;
		other.~Game();
		cout << "------------------------" << endl;

		//buf = other.buf;
	};

	~Game()
	{
		cout << ++deleteCount << endl;
		buf = nullptr;
	}

	int getNumber() const { return n; }

	operator const int() { return n; }

	bool operator=(const Game& other) const
	{
		return (n == other.n);
	}

	bool operator<(const Game& other) const
	{
		return (n < other.n);
	}
	


};
int main()
{
	multiset<Game> s{ 1,2,4,3,1 };
}
#endif
