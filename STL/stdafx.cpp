// stdafx.cpp : ǥ�� ���� ���ϸ� ��� �ִ� �ҽ� �����Դϴ�.
// STL.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj���� �̸� �����ϵ� ���� ������ ���Ե˴ϴ�.

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
