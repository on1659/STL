
#include "stdafx.h"

#define 실습_1
#define 실습_2
//#define 새로운_이야기
/*
~ 익스플리싯

  이동생성자 : 한 객체가 동적으로 생

  ★ 정리
   Model Class
  {
    만일 위와같이 *를 멤버로 만들기로 했다면
	생성자에서 new로 자원을 확득하겠다는 뜻이겠죠?

	그렇다면 당신은 소멸자에서 delete를 잊지 마세요.? 넹?

	복사생성자를 만들어 깊은 복사가 되도록 해야 합니다.
	또 대엽연산자도 깊은 복사가 되도록 프로그램해야 합니다.

	C++11 부터 지원되는 이동의미론도 구현하려면 이동생성자를 프로그램하세요.
	
	이와같은 이유로 이동대입연산자도 프로그램해야함을 잊지 마세요 ㅜ

	//final; // 더 이상 상속되지 않게 하려고!

	4장 일반개념.
	 - namespace std; header 형식, error & try catch, 호출가능한 객체,

	 - 동시성과 멀티스레드는 읽어보시고, 할당자와 메모리는 안읽어도 되요!

	ㆍ예외
	  - STL은 예외따위는 신경도 쓰지 않는다.
	  - STL의 모든 코드는 속도에 최적화 되어있다.
	  - 만일 진짜로 예외에 안정적인 프로그램을 원한다면 
	    그에 맞는 함수나 또는 외부 Lib를 사용해야 할 것이다.
	  

  }

*/


//이동생성자!

#ifdef 실습_1
	#ifdef 실습_2
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
			//기존의 메모리가 있다면 반드시 해제한다.
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

		//아벨류
		Model& operator= (Model&& other)
		{
			m_size = other.m_size;
			m_data = other.m_data;
			other.m_data = nullptr; // 여기가 중요하다★
			other.m_size = 0;
			m_id = gId++;
			cout << "[ ID : " << m_id << " ] 이동할당 - Operator() operator=" << endl;
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
			// *this = other; //가능하긴함!!
			m_size = other.m_size;
			m_data = new char[m_size];
			m_id = gId++;
			memcpy(m_data, other.m_data, sizeof(other.m_data));
			cout << "[ ID : " << m_id << " ] 복사생성자 - Model(const Model& other)" << endl;
		}

		//아벨류 생성자/ 
		Model(Model&& other)
		{
			// *this = other; //가능하긴함!!
			m_size = other.m_size;
			m_data = other.m_data;
			other.m_data = nullptr; // 여기가 중요하다★
			other.m_size = 0;
			m_id = gId++;
			cout << "[ ID : " << m_id <<" ] 이동생성자 - Model(Model&& other)"<< endl;
		}

		Model(size_t n)
		{
			m_id = gId++;
			m_size = n;
			m_data = new char[m_size];
			gotoxy(0, m_id);
			cout << "[ ID : " << m_id << " ] 생성자 - Model()" << endl;

		}

		~Model()
		{
			if (m_data != nullptr)
			{
				delete m_data;
				cout << "[ ID : " << m_id << " ] 소멸자 - ~Model()" << endl;
			}
		}
	};
	#endif
#endif

#ifdef 실습_1

int main()
{
	//------------------------------이동생성--------------------
	Model a{ 1000 };
	//Model b = move(a); //이동이 가능하려면 개발자가 이동생성자를 코딩해야 한다.
	Model b = static_cast<Model&&>(a); //이동이 가능하려면 개발자가 이동생성자를 코딩해야 한다.
	//------------------------------이동생성--------------------

	//------------------------------이동--------------------
	b = move(a);
	a = move(b);
	//------------------------------이동--------------------
}

#endif

#ifdef 실습_2

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


#ifdef 새로운_이야기

class Model 
{
public:
	Model() = default;
	Model(int) {}
	Model(const Model&) = delete;

private:

};

//pod 데이터?
int main()
{
	vector<int> a = { 0,1,2 };

	bool isPlaying = true;
	while (isPlaying)
	{
		cout << "원하는 번호를 입력해 주세요 ";
		int num;
		cin >> num;
		try
		{
			cout << a.at(num) << endl;
		}
		catch (exception)
		{
			cout << "잘못입력함" << endl;
		}
	}

	//try
	//{
	//	cout << a.at(-1) << endl;
	//}
	//catch (...)
	//{
	//	cout << "예외";
	//}
	
}

#endif