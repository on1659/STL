
// 16.04.08 금

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "save.h"
using namespace std;

// [id,  점수]를 벡터에 넣어보자

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "이름";

	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	for (auto i = v.begin(); i < v.end(); ++i) {
		cout << i->first << " --> " << i->second << endl;
	}

	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  점수]를 벡터에 넣어보자

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "이름";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	sort(begin(v), end(v), [](const Score& a, const Score& b) {
		return a.first > b.first;
	});
	cout << ">> 이름 내림차순 정렬" << endl;

	for (auto i = v.begin(); i < v.end(); ++i) {
		cout << i->first << " --> " << i->second << endl;
	}


	sort(begin(v), end(v), [](const Score& a, const Score& b) {
		return a.second < b.second;
	});
	cout << ">> 점수 오름차순 정렬" << endl;

	for (auto i = v.begin(); i < v.end(); ++i) {
		cout << i->first << " --> " << i->second << endl;
	}

	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  점수]를 벡터에 넣어보자

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "이름";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.first > b.first;
	//});
	//cout << ">> 이름 내림차순 정렬" << endl;

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}


	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.second < b.second;
	//});
	//cout << ">> 점수 오름차순 정렬" << endl;

	// 원하는 점수가 있는지 찾아보자
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


// 16.04.08 금

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  점수]를 벡터에 넣어보자

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "이름";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.first > b.first;
	//});
	//cout << ">> 이름 내림차순 정렬" << endl;

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}


	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.second < b.second;
	//});
	//cout << ">> 점수 오름차순 정렬" << endl;

	// 원하는 점수가 있는지 찾아보자
	auto p = find_if(v.begin(), v.end(), [](const Score& a) {
		if (a.second == 11234)
			return true;
		else
			return false;
	});

	if(p!=v.end())
		cout << p->first << " --- " << p->second << endl;
	else {
		cout << "원하는 값을 찾지 못함" << endl;
	}

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}

	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  점수]를 벡터에 넣어보자

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "이름";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.first > b.first;
	//});
	//cout << ">> 이름 내림차순 정렬" << endl;

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}


	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.second < b.second;
	//});
	//cout << ">> 점수 오름차순 정렬" << endl;

	// 원하는 점수가 있는지 찾아보자
	auto p = find_if(v.begin(), v.end(), [](const Score& a) {
		if (a.second == 1123244)
			return true;
		else
			return false;
	});

	if(p!=v.end())
		cout << p->first << " --- " << p->second << endl;
	else {
		cout << "원하는 값을 찾지 못함" << endl;
	}

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}

	save();
}


// 16.04.08 금

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [id,  점수]를 벡터에 넣어보자

using Score = pair<string, int>;

int main() {
	vector<Score> v;
	default_random_engine dre;
	uniform_int_distribution<> ui(0, 100000);
	int uid = 1;
	string id = "이름";
	char buf[10];

	for(int i = 0; i < 1000; ++i) {
		v.push_back(make_pair(id+itoa(uid++,buf,10),ui(dre)));
	}

	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.first > b.first;
	//});
	//cout << ">> 이름 내림차순 정렬" << endl;

	//for (auto i = v.begin(); i < v.end(); ++i) {
	//	cout << i->first << " --> " << i->second << endl;
	//}


	//sort(begin(v), end(v), [](const Score& a, const Score& b) {
	//	return a.second < b.second;
	//});	
	//cout << ">> 점수 오름차순 정렬" << endl;

	// 원하는 점수가 있는지 찾아보자
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



// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;

	v.push_back(Mini());

	cout << "--메인 끝나기 전--" << endl;
	save();
}


// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;

	Mini a;
	v.push_back(a);

	cout << "--메인 끝나기 전--" << endl;
	save();
}


// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;

	v.push_back(Mini());
	v.push_back(Mini());

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}


// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;

	Mini a;
	v.push_back(a);
	v.push_back(a);

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}


// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;

	Mini a;
	v.push_back(Mini());
	v.push_back(Mini());
	v.push_back(Mini());

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}


// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;

	v.push_back(Mini());
	v.push_back(Mini());
	v.push_back(Mini());

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;

	v.push_back(Mini());
	//v.push_back(Mini());
	//v.push_back(Mini());

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;
	v.reserve(3);

	v.push_back(Mini());
	v.push_back(Mini());
	v.push_back(Mini());

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int) { cout << "int 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;
	v.reserve(3);			// 공간을 미리 할당함으로써 약간의 성능 개선 가능

	v.push_back(Mini(1));	
	v.push_back(Mini(2));
	v.push_back(Mini(3));

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int) { cout << "int 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;
	v.reserve(3);			// 공간을 미리 할당함으로써 약간의 성능 개선 가능

	v.push_back(Mini(1));	// int생성자를 만들고 복사
	v.push_back(Mini(2));
	v.push_back(Mini(3));

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int) { cout << "int 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;
	v.reserve(3);			// 공간을 미리 할당함으로써 약간의 성능 개선 가능

	v.emplace_back(1);		// 생성자에 인자만 넘겨 벡터가 생성하도록 함
	v.emplace_back(2);
	v.emplace_back(3);


	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int) { cout << "int 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;
	//v.reserve(3);			// 공간을 미리 할당함으로써 약간의 성능 개선 가능

	v.emplace_back(1);		// 생성자에 인자만 넘겨 벡터가 생성하도록 함
	v.emplace_back(2);
	v.emplace_back(3);


	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}


// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int) { cout << "int 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	Mini(Mini&&) { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;
	//v.reserve(3);			// 공간을 미리 할당함으로써 약간의 성능 개선 가능

	v.emplace_back(1);		// 1을 이용, int생성자
	v.emplace_back(2);
	v.emplace_back(3);

	// 

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}



// 16.04.08 금

#include <iostream>
#include <vector>
#include "save.h"
using namespace std;

// 벡터의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

class Mini {
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int) { cout << "int 생성자" << endl; }
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	Mini(Mini&&) { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
};

int main() {
	vector<Mini> v;
	//v.reserve(3);			// 공간을 미리 할당함으로써 약간의 성능 개선 가능

	v.emplace_back();		// 1을 이용, int생성자
	v.emplace_back();
	v.emplace_back();

	// 

	cout << endl << "--메인 끝나기 전--" << endl << endl;
	save();
}


// 16.04.08 금

#include <iostream>
#include <deque>
#include "save.h"
using namespace std;

class Mini {
	int n{ 0 };		// 디폴트는 0
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int n) : n{ n } { cout << "int 생성자" << endl; }		// int n이 넘어왔을때 n값을 n으로
	Mini(const Mini&) { cout << "복사생성자" << endl; }
	Mini(Mini&&) { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
	operator int() { return n; }
};

// 덱의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

int main() {
	deque<Mini> d;

	// 덱의 메모리 구조를 보면 .push_back과 함께 .push_front 멤버함수가 있다.
	d.push_back(Mini(1));
	d.push_back(Mini(2));
	d.push_front(Mini(3));
	d.push_front(Mini(4));

	for (auto i = d.begin(); i < d.end(); ++i)		// 메모리가 붙어있어서 가능
		cout << *i << endl;				// d[i]는 왜 안되징...

	save();
}


// 16.04.08 금

#include <iostream>
#include <deque>
#include "save.h"
using namespace std;

class Mini {
	int n{};		// 디폴트는 0
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int n) : n{ n } { cout << "int 생성자" << endl; }		// int n이 넘어왔을때 n값을 n으로
	Mini(const Mini& other) : n{ other.n } { cout << "복사생성자" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
	operator int() { return n; }
};

// 덱의 동작을 관찰해보자 - class에 메세지를 써서 실행하는 방법으로

int main() {
	deque<Mini> d;

	// 덱의 메모리 구조를 보면 .push_back과 함께 .push_front 멤버함수가 있다.
	d.push_back(Mini(1));
	d.push_back(Mini(2));
	d.push_front(Mini(3));
	d.push_front(Mini(4));
	// 복사생성자, 이동생성자 안 짜면 0 0 0 0 으로 출력됨 

	for (auto i = d.begin(); i < d.end(); ++i)		// 메모리가 붙어있어서 가능
		cout << *i << endl;				// d[i]는 왜 안되징...

	save();
}


// 16.04.08 금

#include <iostream>
#include <deque>
#include <list>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// 디폴트는 0
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int n) : n{ n } { cout << "int 생성자" << endl; }		// int n이 넘어왔을때 n값을 n으로
	Mini(const Mini& other) : n{ other.n } { cout << "복사생성자" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
	operator int() { return n; }
};

// 리스트의 동작을 관찰해보자 - 책 예제대로

int main() {
	list<char> l;
	
	// 리스트에  a부터 z까지 문자를 push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// 메모리가 노드 기반이므로 i != l.end();
		cout << *i << " ";
	}
	cout << endl;

	save();
}


// 16.04.08 금

#include <iostream>
#include <deque>
#include <list>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// 디폴트는 0
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int n) : n{ n } { cout << "int 생성자" << endl; }		// int n이 넘어왔을때 n값을 n으로
	Mini(const Mini& other) : n{ other.n } { cout << "복사생성자" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
	operator int() { return n; }
};

// 리스트의 동작을 관찰해보자 - 책 예제대로

int main() {
	list<char> l;
	
	// 리스트에  a부터 z까지 문자를 push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// 메모리가 노드 기반이므로 i != l.end();
		cout << *i << " ";
	}
	cout << endl;

	// 역순 출력
	// 제일 뒤의 원소(l.end() - 1)를 가져오자.
	auto end = l.end();	// 포인터 자체를 -해줘야한다. l.end()-1은 안 됨!
	end--;

	cout << *end << endl;
	save();
	// 리스트는 중간에 데이터를 끼워넣기 쉽다.
}


// 16.04.08 금

#include <iostream>
#include <deque>
#include <list>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// 디폴트는 0
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int n) : n{ n } { cout << "int 생성자" << endl; }		// int n이 넘어왔을때 n값을 n으로
	Mini(const Mini& other) : n{ other.n } { cout << "복사생성자" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
	operator int() { return n; }
};

// 리스트의 동작을 관찰해보자 - 책 예제대로

int main() {
	list<char> l;
	
	// 리스트에  a부터 z까지 문자를 push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// 메모리가 노드 기반이므로 i != l.end();
		cout << *i << " ";
	}
	cout << endl;

	// 역순 출력
	// 제일 뒤의 원소(l.end() - 1)를 가져오자.
	auto end = l.end();	// 포인터 자체를 -해줘야한다. l.end()-1은 안 됨!
	end--;

	for (; end != l.begin(); --end)
		cout << *end << endl;

	save();
	// 리스트는 중간에 데이터를 끼워넣기 쉽다.
}



// 16.04.08 금

#include <iostream>
#include <deque>
#include <list>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// 디폴트는 0
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int n) : n{ n } { cout << "int 생성자" << endl; }		// int n이 넘어왔을때 n값을 n으로
	Mini(const Mini& other) : n{ other.n } { cout << "복사생성자" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
	operator int() { return n; }
};

// 리스트의 동작을 관찰해보자 - 책 예제대로

int main() {
	list<char> l;
	
	// 리스트에  a부터 z까지 문자를 push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// 메모리가 노드 기반이므로 i != l.end();
		cout << *i << " ";
	}
	cout << endl;

	// 역순 출력
	// 제일 뒤의 원소(l.end() - 1)를 가져오자.
	auto end = l.end();	// 포인터 자체를 -해줘야한다. l.end()-1은 안 됨!
	end--;

	for (; end != l.begin(); --end)
		cout << *end << " ";
	cout << *end << endl;		// 이렇게 쓰면 a까지 찍힘

	save();
	// 리스트는 중간에 데이터를 끼워넣기 쉽다.
}


// 16.04.08 금

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// 디폴트는 0
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int n) : n{ n } { cout << "int 생성자" << endl; }		// int n이 넘어왔을때 n값을 n으로
	Mini(const Mini& other) : n{ other.n } { cout << "복사생성자" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
	operator int() { return n; }
};

// 리스트의 동작을 관찰해보자 - 책 예제대로

int main() {
	list<char> l;
	
	// 리스트에  a부터 z까지 문자를 push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	// o와 p사이에 A,B,C를 삽입해보자.
	auto p = find(l.begin(), l.end(), 'p');	// begin부터 end까지 돌며 p를 찾는다.
	l.insert(p, 'A');		// l.insert(어디에(p위치에), 무엇을('A'를));
	
	// 출력
	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// 메모리가 노드 기반이므로 i != l.end();
		cout << *i << " ";
	}
	cout << endl;
	
	save();
}


// 16.04.08 금

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include "save.h"
using namespace std;

class Mini {
	int n{0};		// 디폴트는 0
public:
	Mini() { cout << "디폴트 생성자" << endl; }
	Mini(int n) : n{ n } { cout << "int 생성자" << endl; }		// int n이 넘어왔을때 n값을 n으로
	Mini(const Mini& other) : n{ other.n } { cout << "복사생성자" << endl; }
	Mini(Mini&& other) : n{ other.n } { cout << "이동생성자" << endl; }
	~Mini() { cout << "소멸자" << endl; }
	operator int() { return n; }
};

// 리스트의 동작을 관찰해보자 - 책 예제대로

int main() {
	list<char> l;
	
	// 리스트에  a부터 z까지 문자를 push_back;
	for (char c = 'a'; c <= 'z'; ++c) {
		l.push_back(c);
	}

	// o와 p사이에 A,B,C를 삽입해보자.
	auto p = find(l.begin(), l.end(), 'p');	// begin부터 end까지 돌며 p를 찾는다.
	l.insert((l.insert(p, 'B')), 'A');		// l.insert(어디에(p위치에), 무엇을('A'를));
	
	// 출력
	for (list<char>::const_iterator i = l.begin(); i != l.end(); ++i) {			// 메모리가 노드 기반이므로 i != l.end();
		cout << *i << " ";
	}
	cout << endl;
	
	save();
}