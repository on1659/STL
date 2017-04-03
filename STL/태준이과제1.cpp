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
	// 10000���� �����͸� ����
	array < string, 20 > a = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
		"ȫ", "Ȳ", "��", "��", "��", "��", "õ", "��", "��", "��" };
	array < string, 50 > b = { "��", "��", "��", "��", "��", "ȭ", "��", "��", "��", "ȣ",
		"��", "��", "��", "��", "��", "��", "ȭ", "��", "��", "��",
		"��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
		"��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
		"��", "ȿ", "��", "ä", "��", "ȯ", "��", "��", "��", "��" };
	array < string, 50 > c = { "��", "��", "��", "��", "��", "ȭ", "��", "��", "��", "ȣ",
		"��", "��", "��", "��", "��", "��", "ȭ", "��", "��", "��",
		"��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
		"��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
		"ȿ", "��", "��", "ä", "��", "ȯ", "��", "��", "��", "��" };

	default_random_engine dre;
	uniform_int_distribution<int> di(0, 10000);
	uniform_int_distribution<int> di2(0, 19);
	uniform_int_distribution<int> di3(0, 49);

	vector<Score> v;
	v.reserve(10100);


	int num; //���� �Է�
	string name; //����� �̸�
	int nowScore; //�Է��� ����
	bool run = true;
	while (run == true) {
		cout << "-----------------------------------------------" << endl;
		cout << " 1. 10000���� ������ ����" << endl;
		cout << " 2. ����� ���� �Է�" << endl;
		cout << " 3. ����� ����" << endl;
		cout << " 4. ����� ���� ���� �ۼ�Ʈ" << endl;
		cout << " 5. ID�� �������� ������������ ����" << endl;
		cout << " 6. ������ �������� ������������ ����" << endl;
		cout << " 7. ����� ������ �������� ���Ʒ��� 10���� ����" << endl;
		cout << " 8. ���� ����" << endl;
		cout << " 9. ���� �ҷ�����" << endl;
		cout << " 10. ���α׷� ����" << endl;
		cout << "-----------------------------------------------" << endl;

		cout << "������ �Է¹�ȣ : ";
		cin >> num;
		cout << "-----------------------------------------------" << endl;
		if (num < 1 || num >10) {
			cout << "�Է¹����� �߸� �Ǿ����ϴ�." << endl;
		}
		else if (num == 1) {
			for (int i = 0; i < 10000; ++i)
				v.push_back(make_pair(a[di2(dre)] + b[di3(dre)] + c[di3(dre)], di(dre)));
			cout << "10000���� ID�� ������ �����߽��ϴ�. " << endl;
		}
		else if (num == 3 || num == 4 || num == 7 || num == 8) {
			cout << "����� ������ ���� �Է��� �ּ���!" << endl;
		}
		else if (num == 9) {
			ifstream load;
			load.open("Data.txt");

			string ID;
			int score;
			load.seekg(0, ios_base::end);               // �����ǳ������̵�
			streamoff fileSize = load.tellg();    // ����ũ�⸦����

			if (fileSize == 0)
			{
				cout << "����� �����Ͱ� �����ϴ�. " << endl;
				// ����ó��
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
				cout << v.size() << "���� �����͸� �ҷ��Խ��ϴ�." << endl;
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
			cout << "�̸��� �Է��ϼ���(KOREA) : ";
			cin >> name;
			cout << "������ �Է��ϼ���(0~10000) : ";
			cin >> nowScore;
			v.push_back(make_pair(name, nowScore));
			while (run == true) {
				cout << "-----------------------------------------------" << endl;
				cout << " 1. 10000���� ������ ����" << endl;
				cout << " 2. ����� ���� �Է�" << endl;
				cout << " 3. ����� ����" << endl;
				cout << " 4. ����� ���� ���� �ۼ�Ʈ" << endl;
				cout << " 5. ID�� �������� ������������ ����" << endl;
				cout << " 6. ������ �������� ������������ ����" << endl;
				cout << " 7. ����� ������ �������� ���Ʒ��� 10���� ����" << endl;
				cout << " 8. ���� ����" << endl;
				cout << " 9. ���� �ҷ�����" << endl;
				cout << " 10. ���α׷� ����" << endl;
				cout << "-----------------------------------------------" << endl;

				cout << "������ �Է¹�ȣ : ";
				cin >> num;
				cout << "-----------------------------------------------" << endl;
				if (num == 1) {
					for (int i = 0; i < 10000; ++i)
						v.push_back(make_pair(a[di2(dre)] + b[di3(dre)] + c[di3(dre)], di(dre)));
					cout << "10000���� ID�� ������ �����߽��ϴ�. " << endl;
				}
				else if (num == 2) {
					cout << "�̸��� �Է��ϼ���(KOREA) : ";
					cin >> name;
					cout << "������ �Է��ϼ���(0~10000) : ";
					cin >> nowScore;
					v.push_back(make_pair(name, nowScore));
				}
				else if (num == 3) {
					sort(v.begin(), v.end(), [](const Score& a, const Score& b) {
						return a.second > b.second; });
					vector<Score> ::iterator f = find(v.begin(), v.end(), pair<string, int>(name, nowScore));
					if (f != v.end()) {
						cout << "����� ������ : " << f - v.begin() << "�Դϴ�." << endl;
					}
				}
				else if (num == 4) {
					sort(v.begin(), v.end(), [](const Score& a, const Score& b) {
						return a.second > b.second; });
					vector<Score> ::iterator f = find(v.begin(), v.end(), pair<string, int>(name, nowScore));
					if (f != v.end()) {
						int abcdef = (f - v.begin());
						cout << "����� ������ : ����" << abcdef / 100 << "%�Դϴ�. " << endl;
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
					cout << "�����Ͽ����ϴ�. " << endl;
					save.close();

				}
				else if (num == 9) {
					ifstream load;
					load.open("Data.txt");

					string ID;
					int score;
					load.seekg(0, ios_base::end);               // �����ǳ������̵�
					streamoff fileSize = load.tellg();    // ����ũ�⸦����

					if (fileSize == 0)
					{
						cout << "����� �����Ͱ� �����ϴ�. " << endl;
						// ����ó��
					}
					else {
						while (!load.eof())
						{
							load >> ID >> score;
							v.push_back(make_pair(ID, score));
						}
						cout << v.size() << "���� �����͸� �ҷ��Խ��ϴ�." << endl;
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

