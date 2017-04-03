#include "stdafx.h"

//#define 실습1 
//#define 실습2
#define 실습3_람다

/*
  ㆍ35page 왜썼니?

  ㆍ표준은 왜 필요하니? 
     - 내가 짠 소스가 코드가 표준으로 짠 코드라면 동일한 컴파일러에서도
	  동일하게 돌아가는걸 보장한다.(비슷)

  ㆍ이 책에서 무엇을 다루는지
     - I/O Class을 매우 상세하게 할 필요성은 없지만.. 
	   만약에 내가 I/O를 자세하게 봐야한다? 그럼 이 책이 짱!
	 - 책 극찬
     - 812 ~ 980까지 I/O에 대해서 설명을 한다.

  ㆍ문자열의 타입과 정규 표현식!!
     - regualr express 문자열을 가지고 장난치는거의 대한 최고봉..
	 - 
  ㆍ동적배열 / 해시/ 해시테이블 등 다양한 sort algorithm,

  ㆍ멀티스레드/ 동시성 제어를 위한 클래스
     - 아톰 / 퓨처 / 뮤텍스 / locking 등등

  ㆍ국제화 지원을 위한 클래스
     
  ㆍ36page 읽기전에 알아야 할 점
     - C++ Component!
	 - class, template, 상속 등 알아야 한다.
	 -
  ㆍ 오늘은 3장까지~
    - 오늘은 lamda, namespace, 등등

  ㆍ 5장이 중요
     - share, clock, 큐플ㄷ 등등

  ㆍ 6장 STL 시작

  ㆍ 7장 
     - C++03 ~07 ~ 11 ~ 14 등등 인데
	 - 이 책은 C++ 11임.
  
  ㆍ C++ 표준은 왜 계속 만들어지니? 이게 마지막이니??

  ㆍ 알고리즘 복잡도!
     - 상수, 선형 nlogn , n^2 등등
	 - for(int x = 0; x < size; ++x)// for(int y = x + 1; y < size; ++y);

  ㆍ 하향 표준 변환시 컴ㅍ파일 오류가 날 수 잇따.
  ㆍ 책을 꼭 읽어봐!!!!!!
  ㆍ 컬렉션을 모두므로 번역해둠..ㅁㅊ

  ㆍ move, 시멘틱, 아벨류..?


*/

class Dog
{
private:
	std::string m_name;
	int m_age;

public:
	Dog(std::string name, int age) { m_name = name; m_age = age; }

	int getAge() { return m_age; }
	std::string getName() { return m_name; }

	int SortAge(int age)
	{
		if (age > m_age)
			return -1;
		else if (age == m_age)
			return 0;
		else
			return 1;
	}
};


/*
  실습 1
*/
#ifdef 실습1
	int compare(const void* a, const void* b)
	{
	
		string* sA = (string*)a;
		string* sB = (string*)b;
	
		if (a > b)return 1;
		else return -1;
	}
	int main()
	{
		//C++ 초기화
		std::string msg[] = { "오늘은", "3월", "11일", "반가운", "학생들이 있다" };
	
		//end는 마지막 배열이 아니라 마지막에 붙어있는 NULL pointer;
		//사전식 정렬! , 람다 함수
		sort(begin(msg), (end(msg)), [](string a, string b) -> float { return a > b;});
	
		for (auto str : msg)
		{
			cout << str << endl;
		}
	
	
		std::string s("The quick  brown fox jumps over the lazy dog");
	
		sort(s.begin(), s.end());
		cout << s << endl;
	
	
		sort(s.begin(), s.end(), [](char a, char b) -> bool {return a < b;});
		cout << s << endl;
	
	}
#endif
	enum class Salut : float
	{
		mr, ms, co, none
	};

int main()
{
	int x = 0;
	int y = 42;
	auto qqq = [x, &y]
	{
		std::cout << "x:" << x << std::endl;
		std::cout << "y:" << y++ << std::endl;
	};

	Salut c = Salut::mr;

	x = y = 77;
	qqq();
	qqq();
	std::cout << "final y:" << y;
}
//
//#elif 실습2
//	/*
//	   실습 2 
//	*/
//	
//	void function(int, int){ cout << "?" << endl; }
//
//	int main()
//	{
//		//auto로 자동 데이터 형 추론
//		void(*a)(int, int) = function;
//		auto p = function;
//		p(1, 2);
//		cout << typeid(p).name() << endl;
//
//		vector<string> vString{ "STL","3장","auto","형식추론","타입추론","벡터" };
//
//		//sort(vString.begin(), vString.end(), [](char* a, char* b) ->bool {return a[0] > b[0];});
//
//
//		//v가 갖고 있는 원소를 처음부터 끝까지 순서대로 출력
//
//		//vector<string>::const_iterator i = vString.begin();
//		//
//		//for (; i < vString.end(); ++i)
//		//	cout << *i << endl;
//
//		for (auto str : vString)
//		{
//
//			cout << str << endl;
//		}
//
//		//통합된 초기화하를 쓰자
//		//Test a;
//		//Test b = a; // 복사생성
//		//Test C(10);// 인자 10을가지고 c를 생성
//		//
//		////이러니깐 
//		//Test a;
//		//Test b{ 10 }; //이렇게 통합하자
//		//int n{ 3.141592 };
//		//cout << n << endl;
//
//		for (auto &str : vString)
//			cout << str << endl;
//
//	}
//
////#elif
////	int main()
////	{
////		//람다(lambda:익명함수) - 쓸 수 있는 곳이라면 무조건 쓰자
////		//람다로 만드느 ㄴ가장 작은코드
////		[]{cout << "ㅎㅇ 난람다";  }();
////
////		int val = 100;
////		//[=val](x)
////		[val] //(o)
////		//[&val] //(o)
////		{
////		  cout << "안녕?" << val++ << endl;
////		}();
////
////	}
////
//#endif