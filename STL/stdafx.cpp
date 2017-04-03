// stdafx.cpp : 표준 포함 파일만 들어 있는 소스 파일입니다.
// STL.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj에는 미리 컴파일된 형식 정보가 포함됩니다.

#include "stdafx.h"
#include <Windows.h>

void ChornoTime(bool start)
{
	if (start) 
		cStart = std::chrono::high_resolution_clock::now();

	else
	{
		auto d = std::chrono::high_resolution_clock::now() - cStart;
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(d).count() << "msec" << endl;
	}

}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	//ConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
