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


	char msg[100] = "�ȳ�43234156";
	char numberChar[10];

	for (int i = 0; i < 10; ++i)//���̴� ����������
		numberChar[i] = msg[i + 4]; //+4�� ������ ���� ������ 4���Ͷ�

	int n1 = (int)atof(numberChar);
	printf("%d\n", n1);						//���� �˾ƺ���  ������ +4�� �����̶� �̰� �Ź�Ȯ���ؾ��Ѵ�.

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