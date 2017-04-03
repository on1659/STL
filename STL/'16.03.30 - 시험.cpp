
#include "stdafx.h"

#ifdef _Pair_vector
	int main()
	{
		/*
		 �̸��� ������ pair�� ��������
		 pair<string, int> : ���� �ٸ� �ڷ����� string�� int�� ��ġ �ϳ��� 
							 �ڷ��� ó�� ��� �� �� �ֵ��� ���ش�.
		*/

	  //std::vector<int> v; // ���� �̷�����(int)�� �����͸� ��������.
							// ���� �迭��(contigous) ���ʹ� ������ (homogeneous)
							// �ڷ����� ������ ���� �� �� �ִ�. 
		//���ʹ� ���� ���� ������ push_back()��!!
		//�߰��� �����ϴ°Ŵ� ������

		std::vector<pair<string, int>> v;
		v.push_back(pair<string, int>("����", 100));					//�����ǰ� push�� ��
		v.push_back(std::make_pair("���", 80));						//���� ���
		v.push_back(std::make_pair<std::string, int>("����", 40));	//�̰� �躸�� ���� ���
		v.push_back(std::make_pair(std::string("����"), 90)); 		//
		v.push_back(std::make_pair(std::string("����"), 20)); 		//
		v.push_back(std::make_pair(std::string("����Ű"), 30)); 		//


		// �̸� ������������ ��������
		// pair ������ ��ü�� 4����Ʈ���� ũ�� ������ only Read �� �ϴ� const class& �� �ٿ��ش�.
		using Score = pair<string, int>;
		static int count = 0;
		sort(v.begin(), v.end(),[](const Score& a,const Score& b) 
		{ 
			cout << "Count:" << count++ <<"  ["<<a.first << "<->" << b.first << "]"<<endl;
			return a.second < b.second;
		}
		);

		cout << "-End-" << endl;
		for (auto &p : v)
		{
			cout << "Name : " << p.first << " | " << "Score : " << p.second << endl;
		}
	}
#endif

#ifdef _SmartPointer_����
/*
  ����Ʈ ������!
   ������ - �ּҴ� �����ϱ�? �����Ϳ� ����Ǵ� �ּҶ� �����ϱ�??
           �����ʹ� ������ �ִ� �ּҸ� ��°� �ƴϾ�!

		  ȹ���� �ڿ��� ����Ű�� �뵵.
	use.
	1. �ڿ��� ȹ���Ѵ�. (heap �� �Ҵ��� �޸𸮸� ����Ų��.)
	2. �ڿ��� Ȱ���Ѵ�.
	3. �ڿ��� ��ȯ�Ѵ�. �ڡ�

	�߿��� �ڿ��� �����Ͷ�� �θ���.
	ex) ��Ʈ��ũ������? = ����
	    �ڵ� ~ ���� ���

	

*/
int main()
{
	int *p;					//��� {}������ �ݵ�� �������. pod Type
	p = new int[1000000];	//new int�� ��������� �������� �ʴ� �̻� �����Ѵ�.

	Save("'16.03.30 - ����");

}
#endif

/*
 �̵��Ҵ翬����
 �Ҵ翬����
*/