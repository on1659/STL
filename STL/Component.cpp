#include "stdafx.h"
#include "Component.h"


Component::Component()
{
	str.clear();
}

Component::~Component()
{
}

void Component::Start()
{
	x = 0;	y = 0;
}

void Component::Animation(float fTime)
{

}

void Component::Render()
{

}

void Component::Animation(CGameObject* object, float fTime)
{
}

//----------------------------------------------------------

Rotation::Rotation()
{
}

Rotation::~Rotation()
{
}

void Rotation::Start()
{
	x = 10; y = 10;
}

void Rotation::Animation(float fTime)
{
	mx++;
}

void Rotation::Animation(CGameObject *object, float fTime)
{
	mx++;
	if (mx > 100)
	{
		mx = 0;
	}
	object->SetPosition(mx, 0);
}

void Rotation::Render()
{
	system("cls");
	cout << str;
	cout << "pos(" << mx << "," << my << ")" << endl;
	gotoxy(mx, my);
	cout << " бр";
	//cout << " бр_Rotation" << "pos : " << mx << "," << my;
}