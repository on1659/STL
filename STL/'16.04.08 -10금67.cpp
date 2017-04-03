
// 16.04.08 ��

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "save.h"
using namespace std;

// [id,  ����]�� ���Ϳ� �־��

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "�̸�";

	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	for (auto i = v.begin(); i < v.end(); ++i) {
		cout << i->first << " --> " << i->second << endl;
	}

	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  ����]�� ���Ϳ� �־��

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "�̸�";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	sort(begin(v), end(v), [](const Score& a, const Score& b) {
		return a.first > b.first;
	});
	cout << ">> �̸� �������� ����" << endl;

	for (auto i = v.begin(); i < v.end(); ++i) {
		cout << i->first << " --> " << i->second << endl;
	}


	sort(begin(v), end(v), [](const Score& a, const Score& b) {
		return a.second < b.second;
	});
	cout << ">> ���� �������� ����" << endl;

	for (auto i = v.begin(); i < v.end(); ++i) {
		cout << i->first << " --> " << i->second << endl;
	}

	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  ����]�� ���Ϳ� �־��

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "�̸�";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.first > b.first;
	//});
	//cout << ">> �̸� �������� ����" << endl;

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}


	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.second < b.second;
	//});
	//cout << ">> ���� �������� ����" << endl;

	// ���ϴ� ������ �ִ��� ã�ƺ���
	auto p = find_if(v.begin(), v.end(), [](const Score& a) {
		if (a.second == 11234)
			return true;
		else
			return false;
	});
	cout << p->first << " --- " << p->second << endl;

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}

	save();
}


// 16.04.08 ��

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  ����]�� ���Ϳ� �־��

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "�̸�";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.first > b.first;
	//});
	//cout << ">> �̸� �������� ����" << endl;

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}


	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.second < b.second;
	//});
	//cout << ">> ���� �������� ����" << endl;

	// ���ϴ� ������ �ִ��� ã�ƺ���
	auto p = find_if(v.begin(), v.end(), [](const Score& a) {
		if (a.second == 11234)
			return true;
		else
			return false;
	});

	if(p!=v.end())
		cout << p->first << " --- " << p->second << endl;
	else {
		cout << "���ϴ� ���� ã�� ����" << endl;
	}

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}

	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  ����]�� ���Ϳ� �־��

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "�̸�";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.first > b.first;
	//});
	//cout << ">> �̸� �������� ����" << endl;

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}


	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.second < b.second;
	//});
	//cout << ">> ���� �������� ����" << endl;

	// ���ϴ� ������ �ִ��� ã�ƺ���
	auto p = find_if(v.begin(), v.end(), [](const Score& a) {
		if (a.second == 1123244)
			return true;
		else
			return false;
	});

	if(p!=v.end())
		cout << p->first << " --- " << p->second << endl;
	else {
		cout << "���ϴ� ���� ã�� ����" << endl;
	}

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}

	save();
}


// 16.04.08 ��

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  ����]�� ���Ϳ� �־��

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "�̸�";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.first > b.first;
	//});
	//cout << ">> �̸� �������� ����" << endl;

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}


	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.second < b.second;
	//});	
	//cout << ">> ���� �������� ����" << endl;

	// ���ϴ� ������ �ִ��� ã�ƺ���
	auto p = find_if(v.begin(), v.end(), [](const Score& a) {
		if (a.second == 11234)
			return true;
		else
			return false;
	});

	for (auto b = p - 10; b < p + 10; ++b) {
		if (b == p) {
			cout << "*********";
		}
		cout << b->first << " --> " << b->second << endl;
	}

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}

	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;

	v.push_back(Mini());

	cout << "--���� ������ ��--" << endl;
	save();
}


// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;

	Mini a;
	v.push_back(a);

	cout << "--���� ������ ��--" << endl;
	save();
}


// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;

	v.push_back(Mini());
	v.push_back(Mini());

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}


// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;

	Mini a;
	v.push_back(a);
	v.push_back(a);

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}


// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;

	Mini a;
	v.push_back(Mini());
	v.push_back(Mini());
	v.push_back(Mini());

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}


// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;

	v.push_back(Mini());
	v.push_back(Mini());
	v.push_back(Mini());

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;

	v.push_back(Mini());
	//v.push_back(Mini());
	//v.push_back(Mini());

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;
	v.reserve(3);

	v.push_back(Mini());
	v.push_back(Mini());
	v.push_back(Mini());

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int) { cout << "int ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;
	v.reserve(3);			// ������ �̸� �Ҵ������ν� �ణ�� ���� ���� ����

	v.push_back(Mini(1));	
	v.push_back(Mini(2));
	v.push_back(Mini(3));

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int) { cout << "int ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;
	v.reserve(3);			// ������ �̸� �Ҵ������ν� �ణ�� ���� ���� ����

	v.push_back(Mini(1));	// int�����ڸ� ����� ����
	v.push_back(Mini(2));
	v.push_back(Mini(3));

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int) { cout << "int ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;
	v.reserve(3);			// ������ �̸� �Ҵ������ν� �ణ�� ���� ���� ����

	v.emplace_back(1);		// �����ڿ� ���ڸ� �Ѱ� ���Ͱ� �����ϵ��� ��
	v.emplace_back(2);
	v.emplace_back(3);


	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int) { cout << "int ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;
	//v.reserve(3);			// ������ �̸� �Ҵ������ν� �ణ�� ���� ���� ����

	v.emplace_back(1);		// �����ڿ� ���ڸ� �Ѱ� ���Ͱ� �����ϵ��� ��
	v.emplace_back(2);
	v.emplace_back(3);


	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}


// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int) { cout << "int ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	Mini(Mini&&) { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;
	//v.reserve(3);			// ������ �̸� �Ҵ������ν� �ణ�� ���� ���� ����

	v.emplace_back(1);		// 1�� �̿�, int������
	v.emplace_back(2);
	v.emplace_back(3);

	// 

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}



// 16.04.08 ��

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// ������ ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

class Mini {
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int) { cout << "int ������" << endl; }
	Mini(const Mini&) { cout << "���������" << endl; }
	Mini(Mini&&) { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
};

int main() {
	vector<Mini> v;
	//v.reserve(3);			// ������ �̸� �Ҵ������ν� �ణ�� ���� ���� ����

	v.emplace_back();		// 1�� �̿�, int������
	v.emplace_back();
	v.emplace_back();

	// 

	cout << endl << "--���� ������ ��--" << endl << endl;
	save();
}


// 16.04.08 ��

#include <iostream>
#include <deque>
#include "save.h"
using namespace std;

class Mini {
	int n{ 0 };		// ����Ʈ�� 0
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int n) : n{ n } { cout << "int ������" << endl; }		// int n�� �Ѿ������ n���� n����
	Mini(const Mini&) { cout << "���������" << endl; }
	Mini(Mini&&) { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
	operator int() { return n; }
};

// ���� ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

int main() {
	deque<Mini> d;

	// ���� �޸� ������ ���� .push_back�� �Բ� .push_front ����Լ��� �ִ�.
	d.push_back(Mini(1));
	d.push_back(Mini(2));
	d.push_front(Mini(3));
	d.push_front(Mini(4));

	for (auto i = d.begin(); i < d.end(); ++i)		// �޸𸮰� �پ��־ ����
		cout << *i << endl;				// d[i]�� �� �ȵ�¡...

	save();
}


// 16.04.08 ��

#include <iostream>
#include <deque>
#include "save.h"
using namespace std;

class Mini {
	int n{};		// ����Ʈ�� 0
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int n) : n{ n } { cout << "int ������" << endl; }		// int n�� �Ѿ������ n���� n����
	Mini(const Mini& other) : n{ other.n } { cout << "���������" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
	operator int() { return n; }
};

// ���� ������ �����غ��� - class�� �޼����� �Ἥ �����ϴ� �������

int main() {
	deque<Mini> d;

	// ���� �޸� ������ ���� .push_back�� �Բ� .push_front ����Լ��� �ִ�.
	d.push_back(Mini(1));
	d.push_back(Mini(2));
	d.push_front(Mini(3));
	d.push_front(Mini(4));
	// ���������, �̵������� �� ¥�� 0 0 0 0 ���� ��µ� 

	for (auto i = d.begin(); i < d.end(); ++i)		// �޸𸮰� �پ��־ ����
		cout << *i << endl;				// d[i]�� �� �ȵ�¡...

	save();
}


// 16.04.08 ��

#include <iostream>
#include <deque>
#include <list>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// ����Ʈ�� 0
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int n) : n{ n } { cout << "int ������" << endl; }		// int n�� �Ѿ������ n���� n����
	Mini(const Mini& other) : n{ other.n } { cout << "���������" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
	operator int() { return n; }
};

// ����Ʈ�� ������ �����غ��� - å �������

int main() {
	list<char> l;
	
	// ����Ʈ��  a���� z���� ���ڸ� push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// �޸𸮰� ��� ����̹Ƿ� i != l.end();
		cout << *i << " ";
	}
	cout << endl;

	save();
}


// 16.04.08 ��

#include <iostream>
#include <deque>
#include <list>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// ����Ʈ�� 0
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int n) : n{ n } { cout << "int ������" << endl; }		// int n�� �Ѿ������ n���� n����
	Mini(const Mini& other) : n{ other.n } { cout << "���������" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
	operator int() { return n; }
};

// ����Ʈ�� ������ �����غ��� - å �������

int main() {
	list<char> l;
	
	// ����Ʈ��  a���� z���� ���ڸ� push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// �޸𸮰� ��� ����̹Ƿ� i != l.end();
		cout << *i << " ";
	}
	cout << endl;

	// ���� ���
	// ���� ���� ����(l.end() - 1)�� ��������.
	auto end = l.end();	// ������ ��ü�� -������Ѵ�. l.end()-1�� �� ��!
	end--;

	cout << *end << endl;
	save();
	// ����Ʈ�� �߰��� �����͸� �����ֱ� ����.
}


// 16.04.08 ��

#include <iostream>
#include <deque>
#include <list>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// ����Ʈ�� 0
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int n) : n{ n } { cout << "int ������" << endl; }		// int n�� �Ѿ������ n���� n����
	Mini(const Mini& other) : n{ other.n } { cout << "���������" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
	operator int() { return n; }
};

// ����Ʈ�� ������ �����غ��� - å �������

int main() {
	list<char> l;
	
	// ����Ʈ��  a���� z���� ���ڸ� push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// �޸𸮰� ��� ����̹Ƿ� i != l.end();
		cout << *i << " ";
	}
	cout << endl;

	// ���� ���
	// ���� ���� ����(l.end() - 1)�� ��������.
	auto end = l.end();	// ������ ��ü�� -������Ѵ�. l.end()-1�� �� ��!
	end--;

	for (; end != l.begin(); --end)
		cout << *end << endl;

	save();
	// ����Ʈ�� �߰��� �����͸� �����ֱ� ����.
}



// 16.04.08 ��

#include <iostream>
#include <deque>
#include <list>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// ����Ʈ�� 0
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int n) : n{ n } { cout << "int ������" << endl; }		// int n�� �Ѿ������ n���� n����
	Mini(const Mini& other) : n{ other.n } { cout << "���������" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
	operator int() { return n; }
};

// ����Ʈ�� ������ �����غ��� - å �������

int main() {
	list<char> l;
	
	// ����Ʈ��  a���� z���� ���ڸ� push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// �޸𸮰� ��� ����̹Ƿ� i != l.end();
		cout << *i << " ";
	}
	cout << endl;

	// ���� ���
	// ���� ���� ����(l.end() - 1)�� ��������.
	auto end = l.end();	// ������ ��ü�� -������Ѵ�. l.end()-1�� �� ��!
	end--;

	for (; end != l.begin(); --end)
		cout << *end << " ";
	cout << *end << endl;		// �̷��� ���� a���� ����

	save();
	// ����Ʈ�� �߰��� �����͸� �����ֱ� ����.
}


// 16.04.08 ��

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// ����Ʈ�� 0
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int n) : n{ n } { cout << "int ������" << endl; }		// int n�� �Ѿ������ n���� n����
	Mini(const Mini& other) : n{ other.n } { cout << "���������" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
	operator int() { return n; }
};

// ����Ʈ�� ������ �����غ��� - å �������

int main() {
	list<char> l;
	
	// ����Ʈ��  a���� z���� ���ڸ� push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	// o�� p���̿� A,B,C�� �����غ���.
	auto p = find(l.begin(), l.end(), 'p');	// begin���� end���� ���� p�� ã�´�.
	l.insert(p, 'A');		// l.insert(���(p��ġ��), ������('A'��));
	
	// ���
	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// �޸𸮰� ��� ����̹Ƿ� i != l.end();
		cout << *i << " ";
	}
	cout << endl;
	
	save();
}


// 16.04.08 ��

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// ����Ʈ�� 0
public:
	Mini() { cout << "����Ʈ ������" << endl; }
	Mini(int n) : n{ n } { cout << "int ������" << endl; }		// int n�� �Ѿ������ n���� n����
	Mini(const Mini& other) : n{ other.n } { cout << "���������" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "�̵�������" << endl; }
	~Mini() { cout << "�Ҹ���" << endl; }
	operator int() { return n; }
};

// ����Ʈ�� ������ �����غ��� - å �������

int main() {
	list<char> l;
	
	// ����Ʈ��  a���� z���� ���ڸ� push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	// o�� p���̿� A,B,C�� �����غ���.
	auto p = find(l.begin(), l.end(), 'p');	// begin���� end���� ���� p�� ã�´�.
	l.insert((l.insert(p, 'B')), 'A');		// l.insert(���(p��ġ��), ������('A'��));
	
	// ���
	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// �޸𸮰� ��� ����̹Ƿ� i != l.end();
		cout << *i << " ";
	}
	cout << endl;
	
	save();
}