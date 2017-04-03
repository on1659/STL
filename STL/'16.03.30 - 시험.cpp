
#include "stdafx.h"

#ifdef _Pair_vector
	int main()
	{
		/*
		 이름과 점수를 pair로 관리하자
		 pair<string, int> : 서로 다른 자료형인 string과 int를 마치 하나의 
							 자료형 처럼 취급 할 수 있도록 해준다.
		*/

	  //std::vector<int> v; // 나는 이런형식(int)의 데이터를 받을꺼야.
							// 동적 배열인(contigous) 벡터는 동종의 (homogeneous)
							// 자료형을 여러개 저장 할 수 있다. 
		//벡터는 가장 편한 동작이 push_back()임!!
		//중간에 삽입하는거는 불편해

		std::vector<pair<string, int>> v;
		v.push_back(pair<string, int>("루피", 100));					//생성되고 push로 들어감
		v.push_back(std::make_pair("브룩", 80));						//편리한 방법
		v.push_back(std::make_pair<std::string, int>("조로", 40));	//이게 ↑보단 좋은 방식
		v.push_back(std::make_pair(std::string("나미"), 90)); 		//
		v.push_back(std::make_pair(std::string("쵸파"), 20)); 		//
		v.push_back(std::make_pair(std::string("프랑키"), 30)); 		//


		// 이름 오른차순으로 정렬하자
		// pair 데이터 자체가 4바이트보다 크기 때문에 only Read 만 하는 const class& 를 붙여준다.
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

#ifdef _SmartPointer_시작
/*
  스마트 포인터!
   포인터 - 주소는 무엇일까? 포인터에 저장되는 주소란 무엇일까??
           포인터는 가만히 있는 주소를 담는게 아니야!

		  획득한 자원을 가리키는 용도.
	use.
	1. 자원을 획득한다. (heap 에 할당한 메모리를 가리킨다.)
	2. 자원을 활용한다.
	3. 자원을 반환한다. ★★

	중요한 자원을 포인터라고도 부른다.
	ex) 네트워크포인터? = 소켓
	    핸들 ~ 소켓 등등

	

*/
int main()
{
	int *p;					//얘는 {}끝나면 반드시 사라진다. pod Type
	p = new int[1000000];	//new int는 명시적으로 선언하지 않는 이상 삭제한다.

	Save("'16.03.30 - 시험");

}
#endif

/*
 이동할당연산자
 할당연산자
*/