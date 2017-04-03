//��----------------------------------------------------------
// STL ��9,10 �� 6,7
// '16.03.04 Fir
// 
// ���ǳ����� �ʿ�� ���� ������ �� �ֵ��� Save() �Լ��� ������ 
// ���ó��� - chrono, time, file I/O, �ҽ� ���� �и�
//----------------------------------------------------------
#include "stdafx.h"
#include "Utill.h"

#include <iostream>
#include <chrono>
#include <fstream>
#include <ctime>
using namespace std;
/*
  �����ϴ� �ð��� ��¥�� ����Ѵ�.
  �� ������Ʈ�� �ҽ� ������ �ϵ��ũ�� �����Ѵ�.
  �տ� ������ ���俨 ���ٿ� ��� �����Ѵ�.
*/
void Save(std::string str, bool isCreate)
{
	// ���� �ð� ���
	// ���� �ð������� ����Ѵ�.
	auto tp = chrono::system_clock::now();
	// �ð������� time_t �������� �ٲ۴�.
	auto t = chrono::system_clock::to_time_t(tp);
	// ��¥�� ��ȯ�Ѵ�.
	string date(ctime(&t)); 
	//������ Null Size ����
	date.resize(date.length() -  1); 

	//�� ������Ʈ�� �ҽ������� �ϵ忡 ����
	//�տ� ������ ���俨 ���ٿ� ��� �����Ѵ�.

	//���� ������ ����.
	string readStr = str;
	readStr.append(".cpp");
	ifstream in(readStr);
	
	//�� ������ ����. app = apeend mode
	string outName = "../../SaveFile/";
	outName.append(str);
	outName.append(".txt");

	if (isCreate)
	{
		ofstream out(outName, ios::out);
		out << endl << endl << endl;
		out << "//========================" << endl;		    //����� ����Ѵ�.
		out << "//      " << date << endl;				    //��¥�� ����Ѵ�.
		out << "//========================" << endl << endl; //����� ����Ѵ�.

		//���� ������ ��� ������ �о� �� ���Ͽ� ����Ѵ�.
		char c;
		while (in.get(c))
		{
			out.put(c);
		}
	}
	
	else
	{
		ofstream out(outName, ios::app);

		//���� ������ ��� ������ �о� �� ���Ͽ� ����Ѵ�.
		out << endl;
		out << "//========================"<<endl;		    //����� ����Ѵ�.
		out << "//      " <<date << endl;				    //��¥�� ����Ѵ�.
		out << "//========================" <<endl << endl; //����� ����Ѵ�.

		//���� ������ ��� ������ �о� �� ���Ͽ� ����Ѵ�.
		char c;
		while (in.get(c))
		{
			out.put(c);
		}

	}
	cout << "//========================" << endl;		   
	cout << "//======Save Success========" << endl;		   
	cout << "//========================" << endl;		   

}

int RandomRange(int start, int end)
{
	std::default_random_engine dre;
	dre.seed(rand());
	std::uniform_int_distribution<int> distribution(start, end); // �� Probability Distribution.
	return (distribution(dre));
}

