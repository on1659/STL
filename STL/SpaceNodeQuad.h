#pragma once

//KYT '12.02.07
/*Quad Tree를 배열로 만든다.*/

#include <iostream>
#include <list>
#include <vector>

//#define _Bounding


class CGameObject;

class CCamera;
class CShader;

struct AABB
{
	XMFLOAT3 m_d3dxvMinimum;
	XMFLOAT3 m_d3dxvMaximum;
};

//X  = x
//Y  = z
class CSpaceNodeQuad
{
public:
	std::vector<std::shared_ptr<CGameObject>>		m_vObject;
	BoundingBox  boundingbox;
	AABB		 aabb;
	XMFLOAT3	 fCenter;
	XMFLOAT3	 fSize;
	bool	     bCulling;

	std::string name;

public:
	CSpaceNodeQuad();

	CSpaceNodeQuad(XMFLOAT3 center, XMFLOAT3 size);

	~CSpaceNodeQuad();

	void Release()
	{
		m_vObject.clear();
	}

	//Add
	void AddObject(std::shared_ptr<CGameObject> object);
	
	void DeleteObject(std::shared_ptr<CGameObject> object);
	
	bool IsInner(std::shared_ptr<CGameObject> object);

	std::shared_ptr<CSpaceNodeQuad> FindSpaceNode(XMFLOAT3 position);


	//Get & Set
	void SetCenter(XMFLOAT3 center);

	void SetSize(XMFLOAT3 size);
	
	void Set(XMFLOAT3 center, XMFLOAT3 size);

	BoundingBox GetBoundingBox(){ return boundingbox; }
};

