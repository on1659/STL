#pragma once

#include "SpacePartitionQuad.h"

class Component;

class CGameObject
{

public:
	std::string name;
	int			id;

private:
	vector<shared_ptr<Component>> componetPoint;
	int ox;
	int oy;

	int sum;
	int count;
public:
	CGameObject();

	CGameObject(int n);

	virtual ~CGameObject();

	void Move(int x, int y);

	void SetPosition(int x, int y);

	void SetComponent(unique_ptr<Component> _componet);

	void Animation(float fTime);

	void Render();

	operator int() const { return id; }

private:
	CSpaceNodeQuad*									m_SpaceNode;

public:
	
	void SetSpaceNode(CSpaceNodeQuad* space)
	{
		m_SpaceNode = space;
	}

	CSpaceNodeQuad* GetSpaceNode(){ return m_SpaceNode; }


	XMFLOAT3 GetPositionXMFLOAT3()
	{
		return XMFLOAT3( ox, 0.0f, oy);
	}


	//�Լ���ü
	void operator()(int n)
	{
		sum += n;
		count++;
		cout << "�Լ� ȣ�� : " << sum << endl;
	}

	double ave()
	{
		cout << "sum / count : " << sum <<"/" << count << endl;
		return (double)(sum / count);
	}
};


