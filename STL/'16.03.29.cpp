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
		cout << "�⺻���� Data : " << data << endl;
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
		cout << "������� Data : " << data << endl;
	}

	Test(Test&& other)
	{
		size = other.size;
		data = other.data;
		other.data = nullptr;
		other.size = 0;
		cout << "�̵����� Data : " << data << endl;
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
	Test a("2015�� 3�� 30��");
	Test b = (a);
	Test c = static_cast<Test&&>(a);

	Test *ment[3] { new Test("2016��"), new Test("3��"), new Test("30��") };
	cout << " sort ����" << endl;
	for (auto &p : ment) p->Show();

	sort(begin(ment), end(ment), [](Test *a, Test *b) {return (a->getData() < b->getData());});

	cout << " sort ����" << endl;
	for (auto &p : ment) p->Show();

	for (Test *t : ment)
	{
		delete(t);
	}
}