#include "stdafx.h"

/*
	Container는 다양하게 생성할 수 있다.
	반복자 구간으로도 생성할 수 있다.

	반복자 4가지.
	  1. 삽입반복자.
	  2. 이동반복자.			move
	  3. 스트림반복자.	
	  4. 역참조반복자		

	 Set 은 Const라서 옮기는거 자체가 안되야 한다.

*/
#include <iterator>


class Game
{
private:
	char* buf;
	int i = 0;
public:
	Game(int size)
	{
		buf = new char[size];
	};
	~Game()
	{
		cout << i++ << endl;
		buf = nullptr;
	}
};
class Test
{
private:
std::shared_ptr<char> buf;

public:
	Test(int size)
	{
		buf = make_shared<char>(size);
	};
	~Test()
	{
		cout << sizeof(buf) << endl;;
		if(buf)buf.reset();
	}
};
class GameObject
{
private:
	int id;

public:
	GameObject() { id = rand()%10; }

	GameObject(GameObject&& gameobject)
	{
		cout << "&&" << endl;
		id = gameobject.GetId();
	}

	GameObject(GameObject& gameobject)
	{
		cout << "&" << endl;
		id = gameobject.GetId();
	}

	int GetId() const { return id; }

	GameObject& operator=(const GameObject& other)
	{
		cout << "&";
		return (*this);
	}
};

int main()
{
	{
		vector<Game> k{ 1,10,100,100,10000 };
		return 0;
	}

	//string
	{		

		set<string> v{ "123","456", "789" };
		vector<string> r(make_move_iterator(v.begin()), make_move_iterator(v.end()));
		//vector<string> r(move(v.begin()), move(v.end()));

		cout << "--------------String-----------------\n v : ";
		for (auto d : v)
			cout << d << " ";
		cout << endl;

		cout << "-------------------------------------\n r : ";

		for (auto d : r)
			cout << d << " ";
		cout << "\n-------------String-----------------\n\n";
	}

	//GameObject*
	{
		vector<GameObject*> v;
		for (int i = 0; i < 5; ++i) v.push_back(new GameObject());
		vector<GameObject*> r(make_move_iterator(v.begin()), make_move_iterator(v.end()));


		cout << "--------------GameObject*------------\n v : ";
		for (auto d : v)
			cout << d->GetId() << " ";
		cout << endl;

		cout << "-------------------------------------\n r : ";

		for (auto d : r)
			cout << d->GetId() << " ";
		cout << "\n-------------------------------------\n\n";
	}


	//std::shared_ptr<GameObject> 아직 안된당
	{
		vector<std::shared_ptr<GameObject>> v;
		for (int i = 0; i < 5; ++i) v.push_back(std::make_shared<GameObject>());
		vector<std::shared_ptr<GameObject>> r(make_move_iterator(v.begin()), make_move_iterator(v.end()));


		cout << "-----std::shared_ptr<GameObject>------\n v : ";
		for (auto d : v)
		{
			if (d == nullptr)continue;
			cout << "[" << d->GetId() << " " << "Count : " << d.use_count() << "]";
		}
		cout << endl;

		cout << "-------------------------------------\n r : ";

		for (auto &d : r)
			cout << "[" << d->GetId() << " " << "Count : " << d.use_count() << "]";

		cout << "\n-----std::shared_ptr<GameObject>------\n\n";
	}

	//std::unique_ptr<GameObject> 아직 안된당
	{
		vector<std::unique_ptr<GameObject>> v;
		for (int i = 0; i < 5; ++i) v.push_back(std::make_unique<GameObject>());
		vector<std::unique_ptr<GameObject>> r(make_move_iterator(v.begin()), make_move_iterator(v.end()));


		cout << "-----std::unique_ptr<GameObject>------\n v : ";
		for (auto &d : v)
		{
			if (d == nullptr)continue;
			cout << d->GetId() << " ";
		}
		cout << endl;

		cout << "-------------------------------------\n r : ";

		for (auto &d : r)
			cout << d->GetId() << " ";
		cout << "\n-----std::unique_ptr<GameObject>------\n\n";
	}




}