
#include "stdafx.h"

#include "GameObject.h"


class Game
{
private:
	int m_age;
	int m_score;

public:
	Game(int age, int score) : m_age(age), m_score(score){}

	int getAge() const { return m_age; }
	int getSocre() const { return m_score; }

	void Show() 
	{
		cout << "[Age : " << m_age << "][Socre : " << m_score << "]" << endl;
	}

	bool operator<(const Game& other) const
	{
		return m_age > other.getAge();
	}

	bool operator==(const Game& other)const
	{
		return (m_age == other.getAge());
	}
};

int main()
{
	/*
		원소의 순서를 결정하는데 < 연산자 하나만 사용한다.
		두 원소가 같은지 검사하는 <를 두번 사용한다.동등성 검사(equivalence);
		이와 달리 원하는 값을 찾는 find() 에서는 == 연산자
	*/
	set<Game> s{ Game(10,100), Game(13,200), Game(15,330) };

	for (auto &d : s) d.Show();

	auto p = s.find(Game(10, 200));
	if (p != s.end()) cout << "Find" << endl;
	else			  cout << "Nope" << endl;
	
}