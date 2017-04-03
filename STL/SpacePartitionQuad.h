#pragma once

#include "SpaceNodeQuad.h"

class CSpacePartitionQuad
{
private:
	XMFLOAT3  m_xmWorldSize;

	XMFLOAT3  m_xmSpaceSize;

	int		  m_nMaxDepth;

	int		  m_nDepth;

	std::vector
		<std::shared_ptr
		    <CSpaceNodeQuad>>	m_vRoom;


public:
	CSpacePartitionQuad(XMFLOAT3 worldSize, int nMaxDepth);

	CSpacePartitionQuad(float width, float look, int nMaxDepth);

	~CSpacePartitionQuad();

	void Release()
	{
		for (auto &p : m_vRoom)
			p->Release();
		m_vRoom.clear();
	}

	void Load();

	void AddObject(std::shared_ptr<CGameObject> object);

	void DeleteObject(std::shared_ptr<CGameObject> object);

	bool IsSameNode(std::shared_ptr<CGameObject> object);

	void Update(std::shared_ptr<CGameObject> object);

	std::shared_ptr<CSpaceNodeQuad> FindSpaceNode(XMFLOAT3 position);

	std::shared_ptr<CSpaceNodeQuad> FindSpaceNode(XMVECTOR pos);
};

