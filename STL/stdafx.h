// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <random>
#include <math.h>
#include <string>
#include <memory>
#include <chrono>
#include <fstream>
#include <random>
#include <math.h>
#include <functional>
#include <iterator>
#include <set> //Set

// C�� ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <sstream>

#include <d3d11.h>
#include <d3dx11.h>
#include <D3DX10Math.h>
#include <d3dcompiler.h>

//#include <xnamath.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
#include <DirectXPackedVector.h>
#include <DirectXCollision.h>

using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace std;

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

#include "GameObject.h"
#include "Component.h"
#include "ComponentManager.h"

#include "Utill.h"


static std::chrono::high_resolution_clock::time_point cStart;
extern void ChornoTime(bool start = true);
extern void gotoxy(int x, int y);