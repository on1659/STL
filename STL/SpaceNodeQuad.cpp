#include "stdafx.h"
#include "SpaceNodeQuad.h"


CSpaceNodeQuad::CSpaceNodeQuad()
{
	fCenter = { 0.0f, 0.0f, 0.0f };

	fSize = { 0.0f, 0.0f, 0.0f };

	bCulling = true;

	m_vObject.clear();

	boundingbox.Center = { 0.0f, 0.0f, 0.0f };
	boundingbox.Extents = { 0.0f, 0.0f, 0.0f };
}

CSpaceNodeQuad::CSpaceNodeQuad(XMFLOAT3 center, XMFLOAT3 size)
{
	bCulling = true;

	m_vObject.clear();

	CSpaceNodeQuad::Set(center, size);

}

CSpaceNodeQuad::~CSpaceNodeQuad()
{
//	m_vObject.clear();
}

void CSpaceNodeQuad::AddObject(std::shared_ptr<CGameObject> object)
{
	object->SetSpaceNode(this);
	m_vObject.push_back(object);
}

void CSpaceNodeQuad::DeleteObject(std::shared_ptr<CGameObject> object)
{
 	auto findobject = find(m_vObject.begin(), m_vObject.end(), object);
	m_vObject.erase(findobject, m_vObject.end());
}

bool CSpaceNodeQuad::IsInner(std::shared_ptr<CGameObject> object)
{
	if (find(m_vObject.begin(), m_vObject.end(), object) == m_vObject.end())
		return false;
	else
		return true;
}

std::shared_ptr<CSpaceNodeQuad> CSpaceNodeQuad::FindSpaceNode(XMFLOAT3 position)
{
	if (aabb.m_d3dxvMinimum.x < position.x && position.x < aabb.m_d3dxvMaximum.x)
	{
		if (aabb.m_d3dxvMinimum.x < position.x && position.x < aabb.m_d3dxvMaximum.x)
		{
			return (std::shared_ptr<CSpaceNodeQuad>)this;
		}
	}
	return NULL;
}

//Get & Set
void CSpaceNodeQuad::Set(XMFLOAT3 center, XMFLOAT3 size)
{
	CSpaceNodeQuad::SetCenter(center);
	CSpaceNodeQuad::SetSize(size);

	aabb.m_d3dxvMinimum = XMFLOAT3{ fCenter.x - (fSize.x * 0.5f), 0.0f, fCenter.z - (fSize.z * 0.5f) };
	aabb.m_d3dxvMaximum = XMFLOAT3{ fCenter.x + (fSize.x * 0.5f), 0.0f, fCenter.z + (fSize.z * 0.5f) };
}

void CSpaceNodeQuad::SetCenter(XMFLOAT3 center)
{
	fCenter = center;
	boundingbox.Center = fCenter;

	if (fSize.x + fSize.y != 0)
	{
		aabb.m_d3dxvMinimum = XMFLOAT3{ fCenter.x - (fSize.x * 0.5f), 0.0f, fCenter.z - (fSize.z * 0.5f) };
		aabb.m_d3dxvMaximum = XMFLOAT3{ fCenter.x + (fSize.x * 0.5f), 0.0f, fCenter.z + (fSize.z * 0.5f) };
	}
}

void CSpaceNodeQuad::SetSize(XMFLOAT3 size)
{
	fSize = size;
	boundingbox.Extents = fSize;
	
	//Center은 절대 0,0 일 수 없다
	if (fCenter.x + fCenter.y != 0)
	{
		aabb.m_d3dxvMinimum = XMFLOAT3{ fCenter.x - (fSize.x * 0.5f), 0.0f, fCenter.z - (fSize.z * 0.5f) };
		aabb.m_d3dxvMaximum = XMFLOAT3{ fCenter.x + (fSize.x * 0.5f), 0.0f, fCenter.z + (fSize.z * 0.5f) };
	}
}
