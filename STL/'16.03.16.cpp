
#include "stdafx.h"

/*
   ┏━━━┓
   ┃Data ┃
   ┃	  ┃   
   ┃Stack┃
   ┃     ┃
   ┃Code ┃
   ┗━━━┛
   Model a;
   Model b;
   Model c(b);
   ->
     a = nullptr;
	 b = 1000;
	 c = 1000;  - b와 같은 거임 아예 같은거라고 생각하면 됌
   
  (삭제 될 때 까지!) 문제없이 잘 돌아감.
    
	어떤 지역변수가 있다면 지역변수가 끝날 때까지만 살아있고,
	지역변수가 끝나면 죽는당.

	dangling point 가 된다.

 ㆍ해결법
   - 깊은 복사를 해서 같은 데이터지만 위치는 다르게 해준다.

 ㆍ조심해야할 점
   - 깊은복사를 만들고 소멸자를 만들고!!!
   - 이동생성자까지 생각하자!!
*/


//#define 영태가
//#define 교수님이_첫번째

//복사 생성자에 대해서 조금 더 심도있게 연구
#define 교수님이_두번째

#ifdef 영태가
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
		//cout << "하이";

		Model a(1000);
		Model b = move(a);
	


		auto un_a = std::make_unique<Model>(9955);
		std::unique_ptr<Model> un_b = std::make_unique<Model>();

		un_b = move(un_a);

	}
#endif

#ifdef 교수님이_첫번째
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
			cout << "생성자 - Model() / ID : " << m_id << endl; 
		}

		~Model()
		{
			if (m_data)
			{
				delete[] m_data;
				cout << "소멸자 - Model() / ID : " << m_id << endl;
			}
		}
};

int main()
{
	Model a;

}
#endif

#ifdef 교수님이_두번째

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
		//기존의 메모리가 있다면 반드시 해제한다.
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
		// *this = other; //가능하긴함!!
		m_size = other.m_size;
		m_data = new char[m_size];
		m_id = gId++;
		memcpy(m_data, other.m_data, sizeof(other.m_data));
		cout << "복사생성자 - Model() / ID : " << m_id << endl;
	}

	Model(size_t n)
	{
		m_id = gId++;
		m_size = n;
		m_data = new char[m_size];
		gotoxy(0, m_id);
		cout << "생성자 - Model() / ID : " << m_id << endl;
	}

	~Model()
	{
		if (m_data != nullptr)
		{
			delete m_data;
			cout << "소멸자 - Model() / ID : " << m_id << endl;
		}
	}
};

int main()
{
	Model a;
	Model b(1000);
	Model c = b;  // == Move c(b); // Model (const Model&) 읽기만 할꺼야
				  //복사 생성!
	
	a = c;		 // assignment; 
	
	// a.operator=(c); 여기에서는 return 이 필요한데 이유는
	// a = b = c;     <- 이처럼 될 수 있기 떄문이다.

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
