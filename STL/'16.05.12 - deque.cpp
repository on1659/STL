#include "stdafx.h"

#include <deque>
int main()
{
	std::deque<int> que;


	for(int i =0; i < 10; ++i)
		que.push_back(i);

	for (int i = 0; i < 10; ++i)
	{
		cout << que[i] << endl;
	}


	char msg[100] = "안녕43234156";
	char numberChar[10];

	for (int i = 0; i < 10; ++i)//길이는 가변적으로
		numberChar[i] = msg[i + 4]; //+4한 이유는 숫자 시작이 4부터라서

	int n1 = (int)atof(numberChar);
	printf("%d\n", n1);						//단점 알아보기  쉽지만 +4가 고정이라서 이걸 매번확인해야한다.

											//or

	char* startChar = msg;
	for (int i = 0; i < 100; ++i)
	{
		if ('0' <= msg[i] && msg[i] <= '9')
			break;
		startChar++;
	}

	int n2 = (int)atof(startChar);
	printf("%d", n2);
	return 0;

}