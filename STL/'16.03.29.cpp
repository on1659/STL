#include "stdafx.h"
#include <iterator>

class Test
{
private:
	char* data;
	int size;
public:
	Test(char* str) 
	{
		int n = strlen(str) + 1;
		size = n; 
		data = new char[n]; 
		strcpy_s(data, size, str);
		cout << "기본생성 Data : " << data << endl;
	}
	
	~Test() 
	{
		if (data != nullptr)
		{
			delete data;
		}
	}

	Test(Test& other)
	{
		size = other.size;
		data = new char[size];
		strcpy_s(data, size, other.data);
		cout << "복사생성 Data : " << data << endl;
	}

	Test(Test&& other)
	{
		size = other.size;
		data = other.data;
		other.data = nullptr;
		other.size = 0;
		cout << "이동생성 Data : " << data << endl;
	}

	void Show()
	{
		cout << data << endl;
	}

	char* getData()
	{
		return data;
	}
};

int main()
{
	

	return 0;
	Test a("2015년 3월 30일");
	Test b = (a);
	Test c = static_cast<Test&&>(a);

	Test *ment[3] { new Test("2016년"), new Test("3월"), new Test("30일") };
	cout << " sort 이전" << endl;
	for (auto &p : ment) p->Show();

	sort(begin(ment), end(ment), [](Test *a, Test *b) {return (a->getData() < b->getData());});

	cout << " sort 이후" << endl;
	for (auto &p : ment) p->Show();

	for (Test *t : ment)
	{
		delete(t);
	}
}