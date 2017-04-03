#include "stdafx.h"

#include <set>

class Animal
{
protected:
	int age;
public:
	Animal(int n) : age(n) { };
	Animal(Animal& other)
	{
		cout << " &" << endl;
		age = other.age;
	};
	Animal(Animal&& other)
	{
		cout << " &&" << endl;
		age = other.age;
		other.age = 0;
	};
	Animal() {};
	
	virtual ~Animal() 
	{
		age = 0;
	};

	virtual void move() {}
	int getAage() const { return age; }


	bool operator<=(const Animal* other) const
	{
		return (age < other->age);
	}


	bool operator=(const Animal* other) const
	{
		return (age < other->age);
	}

	bool operator>=(const Animal* other) const
	{
		return (age < other->age);
	}
	operator int() const { return age; }
};

class Dog : public Animal
{
public :
	Dog(int n) : Animal(n) 
	{  
	}

	Dog(Dog& other) 
	{
	}
	Dog(Dog&& other) 
	{  
	}
	~Dog() {};
	virtual void move() { cout << "개가 뛴다 - " << age << endl; }
};

class Bird : public Animal 
{
public:
	Bird(int n) :Animal(n) {  }
	~Bird() {};
	virtual void move() { cout << "새가 난다 - " << age << endl; }
};




int main()
{

	Dog* d1 = new Dog(1);
	Dog* d2 = new Dog(2);
	Bird* b1 = new Bird(3);
	Bird* b2 = new Bird(4);


	Animal* anmals[4];

	anmals[0] = d1;
	anmals[1] = d2;
	anmals[2] = b1;
	anmals[3] = b2;

	cout << "-------------------" << endl;
	cout << "다형성 구현 확인 출력" << endl;
	cout << "-------------------" << endl;

	for (auto p : anmals)
		p->move();

	vector<Animal*> v;
	for (auto i = 0; i < 100; ++i)
	{
		auto k = (rand() % 30 + 1);
		if (k & 1 == 1)							//홀수
			v.emplace_back(move(new Dog(k)));
		else                                //짝수
			v.emplace_back(move(new Bird(k)));

	}


	cout << "-------------------" << endl;
	cout << "문제 4 결과 출력" << endl;
	cout << "-------------------" << endl;
	for (auto p : v)
	{
		p->move();
	}


	cout << "-------------------" << endl;
	cout << "문제 8 결과 출력" << endl;
	cout << "-------------------" << endl;

	typedef pair<int, Animal*> dic;
	multiset<Animal*, less<Animal>> s;
	for (Animal* p : v)
	{
		s.insert(p);
	}
	
	for (auto p : s)
	{
	}


	cout << "삭제후 동물 수 : " << s.size() << endl;





	if(d1)delete d1; d1 = nullptr;
	if(d2)delete d2; d2 = nullptr;
	if(b1)delete b1; b1 = nullptr;
	if(b2)delete b2; b2 = nullptr;
	
}