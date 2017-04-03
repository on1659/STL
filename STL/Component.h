#pragma once

class Component

{
protected:
	int x, y;
public:
	std::string str;
public:
	Component();
	virtual ~Component();
	virtual void Start();
	virtual void Animation(float fTime);
	virtual void Animation(CGameObject* object, float fTime);
	virtual void Render();

};

class Rotation : public Component
{
private:
	int mx, my;

public:
	Rotation();
	virtual ~Rotation();
	virtual void Start();
	virtual void Animation(CGameObject* object, float fTime);
	virtual void Animation(float fTime);
	virtual void Render();
	void Set(int x, int y){ mx = x; my = y; }
};



