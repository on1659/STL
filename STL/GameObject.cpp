#include "stdafx.h"
#include "GameObject.h"
#include "Component.h"

CGameObject::CGameObject()
{
	ox = 0; oy = 0;
	componetPoint.clear();
	sum = 0;
	count = 0;
}

CGameObject::CGameObject(int n)
{
	id = n;
	componetPoint.clear();
	sum = 0;
	count = 0;
}
CGameObject::~CGameObject()
{
}

void CGameObject::Move(int x, int y)
{
	ox += x;
	oy += y;
}

void CGameObject::SetPosition(int x, int y)
{
	ox = x;
	oy = y;
}

//void CGameObject::SetComponent(Component _componet)
//{
//	componet.push_back(_componet);
//}

void CGameObject::SetComponent(unique_ptr<Component> _componet)
{
	componetPoint.push_back(move(_componet));
}

void CGameObject::Animation(float fTime)
{
	//for (auto &p : componet)
	//	p.Animation(0.07f);

	for (auto &p : componetPoint)
		p->Animation(this, 0.07f);
}

void CGameObject::Render()
{
	cout << "x,y(" << ox << "," << oy << ")" << endl;
	for (auto &p : componetPoint)
		p->Render();

}