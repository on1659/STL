//♥----------------------------------------------------------
// STL 수9,10 금 6,7
// '16.03.04 Fir
// 
// 강의내용을 필요시 마다 저장할 수 있도록 Save() 함수를 만들자 
// 관련내용 - chrono, time, file I/O, 소스 파일 분리
//----------------------------------------------------------
#include "stdafx.h"
#include "Utill.h"

#include <iostream>
#include <chrono>
#include <fstream>
#include <ctime>
using namespace std;
/*
  저장하는 시간과 날짜를 기록한다.
  이 프로젝트의 소스 파일을 하드디스크에 저장한다.
  앞에 저장한 내요엥 덧붙여 계속 저장한다.
*/
void Save(std::string str, bool isCreate)
{
	// 현재 시간 기록
	// 현재 시간지점을 기록한다.
	auto tp = chrono::system_clock::now();
	// 시간지점을 time_t 형식으로 바꾼다.
	auto t = chrono::system_clock::to_time_t(tp);
	// 날짜로 변환한다.
	string date(ctime(&t)); 
	//마지막 Null Size 제거
	date.resize(date.length() -  1); 

	//이 프로젝트의 소스파일을 하드에 저장
	//앞에 저장한 내요엥 덧붙여 계속 저장한다.

	//읽을 파일을 연다.
	string readStr = str;
	readStr.append(".cpp");
	ifstream in(readStr);
	
	//쓸 파일을 연다. app = apeend mode
	string outName = "../../SaveFile/";
	outName.append(str);
	outName.append(".txt");

	if (isCreate)
	{
		ofstream out(outName, ios::out);
		out << endl << endl << endl;
		out << "//========================" << endl;		    //장식을 기록한다.
		out << "//      " << date << endl;				    //날짜를 기록한다.
		out << "//========================" << endl << endl; //장식을 기록한다.

		//읽을 파일의 모든 내용을 읽어 쓸 파일에 기록한다.
		char c;
		while (in.get(c))
		{
			out.put(c);
		}
	}
	
	else
	{
		ofstream out(outName, ios::app);

		//읽을 파일의 모든 내용을 읽어 쓸 파일에 기록한다.
		out << endl;
		out << "//========================"<<endl;		    //장식을 기록한다.
		out << "//      " <<date << endl;				    //날짜를 기록한다.
		out << "//========================" <<endl << endl; //장식을 기록한다.

		//읽을 파일의 모든 내용을 읽어 쓸 파일에 기록한다.
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
	std::uniform_int_distribution<int> distribution(start, end); // ★ Probability Distribution.
	return (distribution(dre));
}

