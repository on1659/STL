#include "stdafx.h"

#define MAX 100000

int nA[MAX] = { 0 };
bool bA[MAX] = { 0 };

int main()
{
	::ChornoTime();
	cout << "reinterpret_cast : ";
	for (int j = 0; j < MAX; ++j)
		for (int i = 0; i < MAX; ++i)
		{
			bA[i] = reinterpret_cast<bool*>(nA[i]);
		}
	::ChornoTime(false);

	
	::ChornoTime();
	cout << endl << "\static_cast : ";
	for (int j = 0; j < MAX; ++j)
		for (int i = 0; i < MAX; ++i)
		{
			//bA[i] = reinterpret_cast<bool*>(nA[i]);
			bA[i] = static_cast<bool>(nA[i]);

		}
	::ChornoTime(false);
	bool k = bA[0];
}