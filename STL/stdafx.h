// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

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

// C의 런타임 헤더 파일입니다.
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

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

#include "GameObject.h"
#include "Component.h"
#include "ComponentManager.h"

#include "Utill.h"


static std::chrono::high_resolution_clock::time_point cStart;
extern void ChornoTime(bool start = true);
extern void gotoxy(int x, int y);