#include "stdafx.h"
#include <iterator>
#include <unordered_map>

class PartitionString
{
};

int main()
{
	ifstream fRead;
	ofstream fWrite;
	string inputName;
	int error_input = 0;

	cout << "----------- Find the Anagram -----------" << endl;
	cout << "���������� �Է��ϼ��� : " ;
	retry:
		//cin >> inputName;
		inputName = "../Data/diction";
		cout << endl;
		fRead.open(inputName);
		if(false == fRead.is_open())
		{
			if (error_input++ < 2)
			{
				cout << "���������� �ٽ� �Է��ϼ��� : ";
				goto retry;
			}

			cout << "�ȴ�" << endl << endl << endl;
			exit(1);
		}

	vector<string> vMsg;
	std::copy(istream_iterator<string>(fRead), 
			  istream_iterator<string>(),
			  back_inserter(vMsg));
	cout << "���� �ܾ�� : " << vMsg.size() << endl;

	cout << "�ƹ�Ű�� ��������.....";
	//for (auto &msg : vMsg)
	//	cout << msg << " ";
	//
	//copy(vMsg.begin(), vMsg.end(),
	//	ostream_iterator<string>(cout , "  "));


	ChornoTime();
	map<string, string> vDic;
	typedef pair<string, string> dic;
	vector<dic> vFind;
	for (auto msg : vMsg)
	{
		string str = msg;
		int size = msg.size();
		sort(&str[0], &str[size - 1]);

		auto p = vDic.find(str);
		if (vDic.end() == p)
		{
			vDic.insert(std::make_pair(str, msg));
		}
		else
		{
			if (p.operator*().second == msg)continue;
			vFind.push_back(make_pair(p.operator*().second, msg));
		}
	}
	ChornoTime(false);


	cout << endl;
	cout << "Anagram Count : " << vMsg.size() - vDic.size() << endl;

	getchar();
	int cnt = 1;
	for (auto &d : vFind)
	{
		cout << cnt++ << " A:" << d.first << "\tB:" << d.second << endl;
	}
	cout << endl;

	/*
	vector<PartitionString>::const_iterator j = v.Msg.begin(),
		end = vMsg.end(), k;


	cout << "�߰��� Anagram ������ �����ϴ�" << endl;
	while (true)
	{

		j = adjacent_find(j, end,
		[](const PartitionString& a, const PartitionString& b)
		{
			if (j == end)
				break;
			k = find_if_not(j + 1, end, [j](const PartitionString& a))
			{
				return a.first == j->frist;
			}
		});

		//j, k �� anagram����;
	*/



}


//TOM MARVOLO RIDDLE �� I AM LORD VOLDEMORT).
