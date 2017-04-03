
#include "stdafx.h"

/*
   ����������
   ��Data ��
   ��	  ��   
   ��Stack��
   ��     ��
   ��Code ��
   ����������
   Model a;
   Model b;
   Model c(b);
   ->
     a = nullptr;
	 b = 1000;
	 c = 1000;  - b�� ���� ���� �ƿ� �����Ŷ�� �����ϸ� ��
   
  (���� �� �� ����!) �������� �� ���ư�.
    
	� ���������� �ִٸ� ���������� ���� �������� ����ְ�,
	���������� ������ �״´�.

	dangling point �� �ȴ�.

 ���ذ��
   - ���� ���縦 �ؼ� ���� ���������� ��ġ�� �ٸ��� ���ش�.

 �������ؾ��� ��
   - �������縦 ����� �Ҹ��ڸ� �����!!!
   - �̵������ڱ��� ��������!!
*/


//#define ���°�
//#define ��������_ù��°

//���� �����ڿ� ���ؼ� ���� �� �ɵ��ְ� ����
#define ��������_�ι�°

#ifdef ���°�
	static int id = 0;

	class Model
	{
	private:
		int m_id;
		char* data;
		size_t size;
	public:

		Model() 
		{ 
			m_id = id++;
			data = nullptr;
			cout << "id : " << m_id << endl;
		}

		Model(size_t&& s)
		{
			size = s;
			m_id = id++;
			data = nullptr;
			cout << "Create id : " << m_id << endl;
		}

		~Model()
		{
			cout << "Release id : " << m_id << endl;
			if(data) delete data;
		}
	
	};

	int main()
	{	
		//Model a;
		//Model b(1000);
		//Model c = b;
		//
		//cout << "����";

		Model a(1000);
		Model b = move(a);
	


		auto un_a = std::make_unique<Model>(9955);
		std::unique_ptr<Model> un_b = std::make_unique<Model>();

		un_b = move(un_a);

	}
#endif

#ifdef ��������_ù��°
	static int id;
class Model
{
	private:
		char*  m_data = { nullptr };
		size_t m_size = { 0 };
		int m_id;

	public:
		Model(size_t n = 0 ) 
		{
			m_id = id++;
			m_size = n;
			m_data = new char[1000];
			gotoxy(0, m_id);
			cout << "������ - Model() / ID : " << m_id << endl; 
		}

		~Model()
		{
			if (m_data)
			{
				delete[] m_data;
				cout << "�Ҹ��� - Model() / ID : " << m_id << endl;
			}
		}
};

int main()
{
	Model a;

}
#endif

#ifdef ��������_�ι�°

static int gId;

class Model
{
private:
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
		cout << "Operator - Model() / ID : " << m_id << endl;
		return *this;
	}


	Model()
	{ 
		m_data = nullptr;
		m_size = 0;
		m_id = gId++;
		cout << "Default - Model() / ID : " << m_id << endl;
	};

	Model(const Model& other)
	{
		// *this = other; //�����ϱ���!!
		m_size = other.m_size;
		m_data = new char[m_size];
		m_id = gId++;
		memcpy(m_data, other.m_data, sizeof(other.m_data));
		cout << "��������� - Model() / ID : " << m_id << endl;
	}

	Model(size_t n)
	{
		m_id = gId++;
		m_size = n;
		m_data = new char[m_size];
		gotoxy(0, m_id);
		cout << "������ - Model() / ID : " << m_id << endl;
	}

	~Model()
	{
		if (m_data != nullptr)
		{
			delete m_data;
			cout << "�Ҹ��� - Model() / ID : " << m_id << endl;
		}
	}
};

int main()
{
	Model a;
	Model b(1000);
	Model c = b;  // == Move c(b); // Model (const Model&) �б⸸ �Ҳ���
				  //���� ����!
	
	a = c;		 // assignment; 
	
	// a.operator=(c); ���⿡���� return �� �ʿ��ѵ� ������
	// a = b = c;     <- ��ó�� �� �� �ֱ� �����̴�.

	vector<Model> queue;

	while (0)
	{
		if (rand() % 2)
		{
			Model model(5);
			queue.push_back(model);
		}
		else
		{
			if (queue.size() > 0)
			{
				auto model = queue.back();
				queue.pop_back();
				model.~Model();
			}
		}
	}
}
#endif
