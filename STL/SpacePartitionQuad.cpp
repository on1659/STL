#include "stdafx.h"
#include "SpacePartitionQuad.h"

CSpacePartitionQuad::CSpacePartitionQuad(XMFLOAT3 xmWorldSize, int nMaxDepth)
{
	m_xmWorldSize = xmWorldSize;

	//내부적으론 한개 있는게 1레벨, 네개 있는게 2레벨임
	m_nMaxDepth = (nMaxDepth-1); 

	m_nDepth = pow(2, m_nMaxDepth);

	m_xmSpaceSize.x = m_xmWorldSize.x / m_nDepth;
	m_xmSpaceSize.y = 0.0f;
	m_xmSpaceSize.z = m_xmWorldSize.z / m_nDepth;

}
CSpacePartitionQuad::CSpacePartitionQuad(float width, float look, int nMaxDepth)
{
	m_xmWorldSize.x = width;
	m_xmWorldSize.y = 0.0f;
	m_xmWorldSize.z = look;


	//내부적으론 한개 있는게 1레벨, 네개 있는게 2레벨임
	m_nMaxDepth = (nMaxDepth - 1);

	m_nDepth = pow(2, m_nMaxDepth);

	m_xmSpaceSize.x = m_xmWorldSize.x / m_nDepth;
	m_xmSpaceSize.y = 0.0f;
	m_xmSpaceSize.z = m_xmWorldSize.z / m_nDepth;
}

CSpacePartitionQuad::~CSpacePartitionQuad()
{
	m_vRoom.clear();
}

void CSpacePartitionQuad::Load()
{
	float xStart = m_xmSpaceSize.x * 0.5f;
	float zStart = m_xmSpaceSize.z * 0.5f;
	int count = 0;
	for (int z = 0; z < m_nDepth; ++z)
	{
		for (int x = 0; x < m_nDepth; ++x)
		{
			std::shared_ptr<CSpaceNodeQuad> room =
				std::make_shared<CSpaceNodeQuad>
				(
				XMFLOAT3((x * m_xmSpaceSize.x) + xStart, 0.0f, (z * m_xmSpaceSize.z) + zStart), 
				m_xmSpaceSize
				);
			//room->name = intToString(count++);
			m_vRoom.push_back(room);
			count++;
		}
	}
}
std::shared_ptr<CSpaceNodeQuad> CSpacePartitionQuad::FindSpaceNode(XMFLOAT3 position)
{
	int xNum = (int)(position.x / m_xmSpaceSize.x);
	int zNum = (int)(position.z / m_xmSpaceSize.z);

	return m_vRoom[xNum + (zNum * m_nDepth)];
}

bool CSpacePartitionQuad::IsSameNode(std::shared_ptr<CGameObject> object)
{
	if (object->GetSpaceNode() == FindSpaceNode(object->GetPositionXMFLOAT3()).get() )
	{
		return true;
	}
	return false;
}

void CSpacePartitionQuad::Update(std::shared_ptr<CGameObject> object)
{
	auto inRoom = FindSpaceNode(object->GetPositionXMFLOAT3()).get();
	auto nowRoom = object->GetSpaceNode();
	if (inRoom == nowRoom)
		return;
	else
	{
		nowRoom->DeleteObject(object);
		
		inRoom->AddObject(object);

		object->SetSpaceNode(inRoom);
	}
}

void CSpacePartitionQuad::AddObject(std::shared_ptr<CGameObject> object)
{
	XMFLOAT3 position = object->GetPositionXMFLOAT3();
	FindSpaceNode(position)->AddObject(object);
	
}
void CSpacePartitionQuad::DeleteObject(std::shared_ptr<CGameObject> object)
{
	object->GetSpaceNode()->DeleteObject(object);
	object->SetSpaceNode(NULL);
}

