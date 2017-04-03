#include "stdafx.h"

#include <Windows.h>
/*
  반복자 어댑터 - 
	  반복자가 하기로 약속한 연산을 오버로딩한 클래스
	 

*/

template <class c, class i>
void push(c& con, i iter)
{
	con.push_back(iter);
}

inline void gotoxy(int x, int y, const char *msg, ...)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	va_list arg;
	va_start(arg, msg);
	vprintf(msg, arg);
	va_end(arg);
	printf("\n");
}

void sgotoxy(int x, int y)
{
	ostream_iterator<char> p(std::cout);
	fflush(stdin);
	for (int i = 0; i < y; ++i)p = '\n';
	for (int i = 0; i < x; ++i)p = ' ';
}



template<class Iter, class Dest>
void cpy(Iter begin, Iter end, Dest des)
{
	while (begin != end)
	{
		*des = *begin; //(d.operator*).operator = (int)
		++des;		   // d.operator()++;
		++begin;
		//*des++ = *begin++;
	}

}

template <class Type>
class My_back
{
protected:
	Type *container;	// pointer to container
	typedef typename Type::value_type _Valty;

public:
	explicit My_back(Type& _Cont) : container(_STD addressof(_Cont))
	{
	}

	My_back& operator=(const _Valty& _Val) 
	{
		container->push_back(_Val);
		return (*this);
	}

	My_back& operator*(){ return (*this); }

	My_back& operator++(){ return (*this); }

	My_back operator++(int){ return (*this); }
};


template <class Type>
class Yoon_Back
{
	Type&	cont;
public:
	Yoon_Back(Type& input) : cont(input) {  };

	Yoon_Back& operator*()    { return *this; }
	void operator++()  { }
	void operator=(int n) { cont.push_back(n); } //여기에는 실제 데이터를 넣는다.

};


/*
  이렇게 하지 않으면 안된당
  연산자 오버로딩
*/
int main()
{
	ostream_iterator<char> p(std::cout);
	p = 'a';
	p = 'b';
	p = 'c\n';

	sgotoxy(3, 3);
	cout << " ㅎㅇ";
	sgotoxy(2, 2);
	cout << "ㅂ2\n";

	std::vector<int> v1{ 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };

	Yoon_Back <std::vector<int>> a(v2);

	printf("[begin  : %#x]\n",   &v1.begin()  );
	printf("[rbegin : %#x]\n",   &v1.rbegin() );
	printf("[end    : %#x]\n",   &v1.end()    );
	printf("[rend   : %#x]\n\n", &v1.rend()   );

	cout << "-----------------------------------\n";
	int n = v1.size();
	for(int i = 0; i < n; ++i )
	{
		printf("[%#x]\n", &v1[i]);
	}
	cout << "-----------------------------------\n";

	cpy(v1.rbegin(), v1.rend(), a);
	for (auto &p : v2) cout << p << " ";
	std::cout << std::endl;


	cout << "\n-------------------------------\n";
	push(v1, 100);
	for (auto &p : v1) cout << p << " ";

}