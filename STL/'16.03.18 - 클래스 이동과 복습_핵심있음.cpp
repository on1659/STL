
#include "stdafx.h"

#define �ǽ�_1
#define �ǽ�_2
//#define ���ο�_�̾߱�
/*
~ �ͽ��ø���

  �̵������� : �� ��ü�� �������� ��

  �� ����
   Model Class
  {
    ���� ���Ͱ��� *�� ����� ������ �ߴٸ�
	�����ڿ��� new�� �ڿ��� Ȯ���ϰڴٴ� ���̰���?

	�׷��ٸ� ����� �Ҹ��ڿ��� delete�� ���� ������.? ��?

	��������ڸ� ����� ���� ���簡 �ǵ��� �ؾ� �մϴ�.
	�� �뿱�����ڵ� ���� ���簡 �ǵ��� ���α׷��ؾ� �մϴ�.

	C++11 ���� �����Ǵ� �̵��ǹ̷е� �����Ϸ��� �̵������ڸ� ���α׷��ϼ���.
	
	�̿Ͱ��� ������ �̵����Կ����ڵ� ���α׷��ؾ����� ���� ������ ��

	//final; // �� �̻� ��ӵ��� �ʰ� �Ϸ���!

	4�� �Ϲݰ���.
	 - namespace std; header ����, error & try catch, ȣ�Ⱑ���� ��ü,

	 - ���ü��� ��Ƽ������� �о�ð�, �Ҵ��ڿ� �޸𸮴� ���о �ǿ�!

	������
	  - STL�� ���ܵ����� �Ű浵 ���� �ʴ´�.
	  - STL�� ��� �ڵ�� �ӵ��� ����ȭ �Ǿ��ִ�.
	  - ���� ��¥�� ���ܿ� �������� ���α׷��� ���Ѵٸ� 
	    �׿� �´� �Լ��� �Ǵ� �ܺ� Lib�� ����ؾ� �� ���̴�.
	  

  }

*/


//�̵�������!

#ifdef �ǽ�_1
	#ifdef �ǽ�_2
		static int gId = 0;
		class Model
	{
	public:
		char*  m_data = { nullptr };
		size_t m_size = { 0 };
		int	   m_id;

	public:
		Model& operator= (const Model& other)
		{
			//������ �޸𸮰� �ִٸ� �ݵ�� �����Ѵ�.
			if (m_data)delete[] m_data;
			m_data = nullptr;
			///
			m_size = other.m_size;
			m_data = new char[m_size];
			m_id = gId++;
			memcpy(m_data, other.m_data, sizeof(other.m_data));
			cout << "[ ID : " << m_id << " ] Operator - Model() operator=" << endl;
			return *this;
		}

		//�ƺ���
		Model& operator= (Model&& other)
		{
			m_size = other.m_size;
			m_data = other.m_data;
			other.m_data = nullptr; // ���Ⱑ �߿��ϴ١�
			other.m_size = 0;
			m_id = gId++;
			cout << "[ ID : " << m_id << " ] �̵��Ҵ� - Operator() operator=" << endl;
			return *this;
		}

		Model()
		{
			m_data = nullptr;
			m_size = 0;
			m_id = gId++;
			cout << "[ ID : " << m_id << " ] Default - Model()" << endl;
		};

		Model(const Model& other)
		{
			// *this = other; //�����ϱ���!!
			m_size = other.m_size;
			m_data = new char[m_size];
			m_id = gId++;
			memcpy(m_data, other.m_data, sizeof(other.m_data));
			cout << "[ ID : " << m_id << " ] ��������� - Model(const Model& other)" << endl;
		}

		//�ƺ��� ������/ 
		Model(Model&& other)
		{
			// *this = other; //�����ϱ���!!
			m_size = other.m_size;
			m_data = other.m_data;
			other.m_data = nullptr; // ���Ⱑ �߿��ϴ١�
			other.m_size = 0;
			m_id = gId++;
			cout << "[ ID : " << m_id <<" ] �̵������� - Model(Model&& other)"<< endl;
		}

		Model(size_t n)
		{
			m_id = gId++;
			m_size = n;
			m_data = new char[m_size];
			gotoxy(0, m_id);
			cout << "[ ID : " << m_id << " ] ������ - Model()" << endl;

		}

		~Model()
		{
			if (m_data != nullptr)
			{
				delete m_data;
				cout << "[ ID : " << m_id << " ] �Ҹ��� - ~Model()" << endl;
			}
		}
	};
	#endif
#endif

#ifdef �ǽ�_1

int main()
{
	//------------------------------�̵�����--------------------
	Model a{ 1000 };
	//Model b = move(a); //�̵��� �����Ϸ��� �����ڰ� �̵������ڸ� �ڵ��ؾ� �Ѵ�.
	Model b = static_cast<Model&&>(a); //�̵��� �����Ϸ��� �����ڰ� �̵������ڸ� �ڵ��ؾ� �Ѵ�.
	//------------------------------�̵�����--------------------

	//------------------------------�̵�--------------------
	b = move(a);
	a = move(b);
	//------------------------------�̵�--------------------
}

#endif

#ifdef �ǽ�_2

int main()
{
	vector<Model> vModel;
	vModel.resize(3);
	vector<Model> v2Model;
	int n1, n;
	n1 = n = 3;
	
	while(n--)
	vModel.push_back(Model(1235));
	
	//gId = 0;
	//vModel.clear();
	
	cout << "-------------------" << endl;
	cout << "-------------------" << endl;
	cout << "-------------------" << endl;
	cout << "-------------------" << endl;

	while (n1--)
	{
		//Model m(1000);
		//v2Model.push_back(move(m));
	}
}

#endif


#ifdef ���ο�_�̾߱�

class Model 
{
public:
	Model() = default;
	Model(int) {}
	Model(const Model&) = delete;

private:

};

//pod ������?
int main()
{
	vector<int> a = { 0,1,2 };

	bool isPlaying = true;
	while (isPlaying)
	{
		cout << "���ϴ� ��ȣ�� �Է��� �ּ��� ";
		int num;
		cin >> num;
		try
		{
			cout << a.at(num) << endl;
		}
		catch (exception)
		{
			cout << "�߸��Է���" << endl;
		}
	}

	//try
	//{
	//	cout << a.at(-1) << endl;
	//}
	//catch (...)
	//{
	//	cout << "����";
	//}
	
}

#endif