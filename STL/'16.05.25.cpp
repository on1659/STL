#include "stdafx.h"

/*	
	deque()�� �޸𸮰� ���ӵǾ� ���� �ʴ�.
	������ ���������� �����ϴ�. ~338page

	1. Insert & Remove element is very Fast;
	1.����� ���԰� ���Ŵ� ���۰� �� �κп��� ��� ������.
	  - �� ������� ��� ���� ��ȯ �� (= amortized	)


	439page, 437page�� �߿��ϴ�.


	set�� ������ ������ <����� �ϳ��� �Ǵ��Ѵ�. - strctly weak ordering
	�̰��� �Ǵ��� ���ؿ� �ϳ��� �����ڸ� ����� �� �ִٴ� ���� �����̴�.
	��! ���� ���� �Ǵ��� ==�� �������� �ʰ� a<b, b<a�� ��� ������ ��� ���ٰ� �Ǵ��ϴ� ���̴�.
	(Game < Game�� operator����� �Ѵ�)
	�� ���� ���(equivalence)�� �Ѵ�.
	���� find()������ ���� ���Ҹ� ã�µ� == �����ڸ� �̿��Ѵ�.
	�̰��� ��(equality)�� �Ѵ�. 
	 - 358page��


*/


//#define _��Ʈ���ϳ��ϳ�_ã�ư���
//#define _Deque()
//#define _ContainerList()
#define _ContainerSet()

#ifdef _��Ʈ���ϳ��ϳ�_ã�ư���

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

		cout << "----��������� ����----" << endl;
		other.~Game();
		cout << "------------------------" << endl;
		//buf = other.buf;
	};

	Game(const Game&& other)
	{
		buf = other.buf;
		n = other.n;

		cout << "----Move ����----" << endl;
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

	cout << "��������������������������������������������������" << endl;
	for (const Game& d : l1)
		cout << "��\t\t\t" << d.getNumber() << "��      \t\t��"<<endl;
	cout << "��������������������������������������������������" << endl;



	

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

		cout << "----��������� ����----" << endl;
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
