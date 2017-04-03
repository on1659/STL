#include "stdafx.h"

#include <unordered_map>

class Object
{
	int id;

public:
	
	Object(int id) : id(id) {}
	
	~Object() {}

	int GetId() const { return id; }

};

Object operator-(Object a, Object b)
{
	return (a.GetId() - b.GetId());
}

RECT operator-(RECT a, RECT b)
{
	RECT c;
	c.left = a.left - b.left;
	c.right = a.right - b.right;
	c.top = a.top;
	c.bottom = a.bottom;
	return c;
}


RECT operator+=(RECT a, POINT b)
{
	return RECT{ (a.left + b.x),(a.right + b.x),(a.top + b.y),(a.bottom + b.y) };
}

RECT operator+(RECT a, POINT b)
{
	return RECT{ (a.left + b.x),(a.right + b.x),(a.top + b.y),(a.bottom + b.y) };
}

/////6번 답////////////////////////////////////////////
ostream& operator << (ostream& os, const RECT& rect)
{
	{
		os << "[left:" << rect.left << "][right:" << rect.right << "][top:" << rect.top << "][bot:" << rect.bottom << "]" << endl;
	}
	return os;
}


struct UIElement
{
	std::string name;
	std::shared_ptr<CGameObject> object;
	UIElement(const string name, const shared_ptr<CGameObject> obj) : name(name), object(obj) { };
};

string SetString(std::string str)
{
	string s;
	s = "0";
	s.append(str);
	return s;
}

int main()
{
	string s = "안녕하세요";
	string s2 = "0";
	s2.append(s);
	s = s2;
	cout << s << endl;

	return 0;

	std::multimap<std::string, std::shared_ptr<CGameObject>>	m_mGameObject;
	std::vector<UIElement> m_vRenderObject;
	m_vRenderObject.reserve(4);


	//일번
	m_mGameObject.insert(make_pair("1번", make_shared<CGameObject>(0)));
	m_mGameObject.insert(make_pair("1번", make_shared<CGameObject>(1)));
	m_mGameObject.insert(make_pair("1번", make_shared<CGameObject>(2)));
	m_mGameObject.insert(make_pair("1번", make_shared<CGameObject>()));

	//이번
	m_mGameObject.insert(make_pair("2번", make_shared<CGameObject>(0)));
	m_mGameObject.insert(make_pair("2번", make_shared<CGameObject>(1)));

	//삼번
	m_mGameObject.insert(make_pair("3번", make_shared<CGameObject>(0)));
	m_mGameObject.insert(make_pair("3번", make_shared<CGameObject>(1)));

	//사번
	m_mGameObject.insert(make_pair("4번", make_shared<CGameObject>(0)));
	m_mGameObject.insert(make_pair("4번", make_shared<CGameObject>(1)));


	
	for (int i = 0; i < 3; ++i)
	{
		cout << "---------------" << endl;
		auto findObject = m_mGameObject.find("1번");

		if (m_mGameObject.end() == findObject)
			continue;

		m_vRenderObject.push_back(UIElement(findObject->first, findObject->second));
		m_mGameObject.erase(findObject);

		for (auto &obj : m_vRenderObject)
			cout << obj.name << "|" << obj.object->id << endl;
	}


	cout << "-------Map------" << endl;
	auto findObject = m_mGameObject.find("1번");
	 cout <<  findObject->second->id <<endl;


	 while (1)
	 {
		int size = m_vRenderObject.size();
		if (size != 0)
		{
			swap(m_vRenderObject[0], m_vRenderObject[size - 1]);
			auto o = m_vRenderObject.back();
			m_vRenderObject.pop_back();
			m_mGameObject.insert(make_pair(o.name, o.object));
		}
		else
			break;
	 }
	
	cout << "-------Map------" << endl;
	for (auto &obj : m_mGameObject)
	{
		cout << obj.first << "|" << obj.second->id << endl;
	}


}