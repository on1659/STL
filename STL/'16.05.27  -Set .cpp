
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
		������ ������ �����ϴµ� < ������ �ϳ��� ����Ѵ�.
		�� ���Ұ� ������ �˻��ϴ� <�� �ι� ����Ѵ�.��� �˻�(equivalence);
		�̿� �޸� ���ϴ� ���� ã�� find() ������ == ������
	*/
	set<Game> s{ Game(10,100), Game(13,200), Game(15,330) };

	for (auto &d : s) d.Show();

	auto p = s.find(Game(10, 200));
	if (p != s.end()) cout << "Find" << endl;
	else			  cout << "Nope" << endl;
	
}