#include "stdafx.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>	
#include <random>
#include <fstream>

using namespace std;

typedef pair<string, int > Score;



int main()
{
	// 10000명의 데이터를 생성
	array < string, 20 > a = { "김", "이", "박", "정", "임", "오", "임", "최", "조", "백",
		"홍", "황", "한", "안", "강", "유", "천", "노", "양", "남" };
	array < string, 50 > b = { "태", "준", "유", "훈", "종", "화", "지", "수", "병", "호",
		"우", "규", "형", "석", "미", "영", "화", "선", "현", "은",
		"민", "빈", "성", "경", "자", "원", "정", "진", "리", "용",
		"시", "동", "명", "인", "대", "한", "혁", "건", "윤", "희",
		"혜", "효", "예", "채", "종", "환", "연", "솔", "연", "아" };
	array < string, 50 > c = { "태", "준", "유", "훈", "종", "화", "지", "수", "병", "호",
		"우", "규", "형", "석", "미", "영", "화", "선", "현", "은",
		"민", "빈", "성", "경", "자", "원", "정", "진", "리", "용",
		"시", "동", "명", "인", "대", "한", "혁", "건", "윤", "희",
		"효", "혜", "예", "채", "종", "환", "연", "솔", "연", "아" };

	default_random_engine dre;
	uniform_int_distribution<int> di(0, 10000);
	uniform_int_distribution<int> di2(0, 19);
	uniform_int_distribution<int> di3(0, 49);

	vector<Score> v;
	v.reserve(10100);


	int num; //실행 입력
	string name; //사용자 이름
	int nowScore; //입력한 점수
	bool run = true;
	while (run == true) {
		cout << "-----------------------------------------------" << endl;
		cout << " 1. 10000개의 데이터 생성" << endl;
		cout << " 2. 사용자 정보 입력" << endl;
		cout << " 3. 사용자 순위" << endl;
		cout << " 4. 사용자 점수 상위 퍼센트" << endl;
		cout << " 5. ID를 기준으로 오름차순으로 정렬" << endl;
		cout << " 6. 점수를 기준으로 내림차순으로 정렬" << endl;
		cout << " 7. 사용자 점수를 기준으로 위아래로 10명의 순위" << endl;
		cout << " 8. 파일 저장" << endl;
		cout << " 9. 파일 불러오기" << endl;
		cout << " 10. 프로그램 종료" << endl;
		cout << "-----------------------------------------------" << endl;

		cout << "실행할 입력번호 : ";
		cin >> num;
		cout << "-----------------------------------------------" << endl;
		if (num < 1 || num >10) {
			cout << "입력범위가 잘못 되었습니다." << endl;
		}
		else if (num == 1) {
			for (int i = 0; i < 10000; ++i)
				v.push_back(make_pair(a[di2(dre)] + b[di3(dre)] + c[di3(dre)], di(dre)));
			cout << "10000개의 ID와 점수를 생성했습니다. " << endl;
		}
		else if (num == 3 || num == 4 || num == 7 || num == 8) {
			cout << "사용자 정보를 먼저 입력해 주세요!" << endl;
		}
		else if (num == 9) {
			ifstream load;
			load.open("Data.txt");

			string ID;
			int score;
			load.seekg(0, ios_base::end);               // 파일의끝으로이동
			streamoff fileSize = load.tellg();    // 파일크기를얻음

			if (fileSize == 0)
			{
				cout << "저장된 데이터가 없습니다. " << endl;
				// 에러처리
			}
			else {
				load.seekg(0, 0);
				while (!load.eof())
				{
					ID = "";
					score = 0;
					;					load >> ID >> score;
					if (ID.size() > 0)
						v.push_back(make_pair(ID, score));
				}
				cout << v.size() << "개의 데이터를 불러왔습니다." << endl;
			}
			load.close();
		}
		else if (num == 10) {
			run = false;
		}
		else if (num == 5) {
			sort(v.begin(), v.end(), [](const Score& a, const Score& b) {
				return a.first < b.first; });
			for (Score data : v)
				cout << data.first << "---" << data.second << endl;
		}
		else if (num == 6) {
			sort(v.begin(), v.end(), [](const Score& a, const Score& b) {
				return a.second > b.second; });
			for (Score data : v)
				cout << data.first << "---" << data.second << endl;
		}
		else if (num == 2) {
			cout << "이름을 입력하세요(KOREA) : ";
			cin >> name;
			cout << "점수를 입력하세요(0~10000) : ";
			cin >> nowScore;
			v.push_back(make_pair(name, nowScore));
			while (run == true) {
				cout << "-----------------------------------------------" << endl;
				cout << " 1. 10000개의 데이터 생성" << endl;
				cout << " 2. 사용자 정보 입력" << endl;
				cout << " 3. 사용자 순위" << endl;
				cout << " 4. 사용자 점수 상위 퍼센트" << endl;
				cout << " 5. ID를 기준으로 오름차순으로 정렬" << endl;
				cout << " 6. 점수를 기준으로 내림차순으로 정렬" << endl;
				cout << " 7. 사용자 점수를 기준으로 위아래로 10명의 순위" << endl;
				cout << " 8. 파일 저장" << endl;
				cout << " 9. 파일 불러오기" << endl;
				cout << " 10. 프로그램 종료" << endl;
				cout << "-----------------------------------------------" << endl;

				cout << "실행할 입력번호 : ";
				cin >> num;
				cout << "-----------------------------------------------" << endl;
				if (num == 1) {
					for (int i = 0; i < 10000; ++i)
						v.push_back(make_pair(a[di2(dre)] + b[di3(dre)] + c[di3(dre)], di(dre)));
					cout << "10000개의 ID와 점수를 생성했습니다. " << endl;
				}
				else if (num == 2) {
					cout << "이름을 입력하세요(KOREA) : ";
					cin >> name;
					cout << "점수를 입력하세요(0~10000) : ";
					cin >> nowScore;
					v.push_back(make_pair(name, nowScore));
				}
				else if (num == 3) {
					sort(v.begin(), v.end(), [](const Score& a, const Score& b) {
						return a.second > b.second; });
					vector<Score> ::iterator f = find(v.begin(), v.end(), pair<string, int>(name, nowScore));
					if (f != v.end()) {
						cout << "당신의 순위는 : " << f - v.begin() << "입니다." << endl;
					}
				}
				else if (num == 4) {
					sort(v.begin(), v.end(), [](const Score& a, const Score& b) {
						return a.second > b.second; });
					vector<Score> ::iterator f = find(v.begin(), v.end(), pair<string, int>(name, nowScore));
					if (f != v.end()) {
						int abcdef = (f - v.begin());
						cout << "당신의 점수는 : 상위" << abcdef / 100 << "%입니다. " << endl;
					}
				}
				else if (num == 5) {
					sort(v.begin(), v.end(), [](const Score& a, const Score& b) {
						return a.first < b.first; });
					for (Score data : v)
						cout << data.first << "---" << data.second << endl;
				}
				else if (num == 6) {
					sort(v.begin(), v.end(), [](const Score& a, const Score& b) {
						return a.second > b.second; });
					for (Score data : v)
						cout << data.first << "---" << data.second << endl;
				}
				else if (num == 7) {
					sort(v.begin(), v.end(), 
						[](const Score& a, const Score& b) { return a.second > b.second; });
					vector<Score> ::iterator f = find(v.begin(), v.end(), pair<string, int>(name, nowScore));
					if (f != v.end()) {
						int ranking = f - v.begin();
						int a = ranking - 10;
						int b = ranking + 11;
						if (ranking - 10 < 0)
							a = 0;
						if (ranking + 11 > v.size())
							b = v.size();
						for (auto i = a; i != b; ++i)
							cout << v[i].first << "---" << v[i].second << endl;
					}
				}
				else if (num == 8) {
					ofstream save;
					save.open("Data.txt", ios::app);

					for (int i = 0; i < v.size(); ++i)
						save << v[i].first << "\t" << v[i].second << endl;
					cout << "저장하였습니다. " << endl;
					save.close();

				}
				else if (num == 9) {
					ifstream load;
					load.open("Data.txt");

					string ID;
					int score;
					load.seekg(0, ios_base::end);               // 파일의끝으로이동
					streamoff fileSize = load.tellg();    // 파일크기를얻음

					if (fileSize == 0)
					{
						cout << "저장된 데이터가 없습니다. " << endl;
						// 에러처리
					}
					else {
						while (!load.eof())
						{
							load >> ID >> score;
							v.push_back(make_pair(ID, score));
						}
						cout << v.size() << "개의 데이터를 불러왔습니다." << endl;
					}
					load.close();
				}
				else if (num == 10) {
					run = false;
				}
			}
		}
	}
}

