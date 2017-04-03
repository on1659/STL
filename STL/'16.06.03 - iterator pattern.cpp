
#include "stdafx.h"

class Element
{
public:
	Element(string str) : data(str) {}

private:
	string data;
};

class Aggregate
{
public:
	Aggregate() : top(-1){}

public:
	friend class Iterator;
	virtual Iterator* createIteator() = 0;
	virtual void push(Element* pElement) = 0;
	virtual Element* pop() = 0;
	virtual Element* GetElement(int index) = 0;
	bool isEmpty() { return top == -1; }
	int GetStackPoint() { return top; }

protected:
	int top;

};