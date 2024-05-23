//-----------------------
//목78
// 5.6 화
// 
// 6월 6일 목요일 강의 예정
// 
// STL Unordered Associative container - unordered_set / unordered_map
// 
// 순서가 없다?
// 메모리 구조를 화면에 출력
// String을 unordered 컨테이너에 저장
//----------------------
#include <iostream>
#include <unordered_set>
#include <print>
#include "save.h"
#include "String.h" 
using namespace std;
extern bool 관찰;

template<class 언오더드셋>

void print_us(언오더드셋 us) {
	// unordered_set의 메모리를 화면에 출력한다
	for (int i = 0; i < us.bucket_count(); ++i) {
		print("[{:3}] ", i);

		for (auto p = us.begin(i); p != us.end(i); ++p)
			cout << " - " << *p;

		cout << endl;
	}
	cout << endl;
}

struct Hasher {
	int operator()(const String& s) const {
		return 3;
	}
};

int main() {
	save("FileName.cpp");

	unordered_multiset<String, Hasher> us{"1", "2", "4", "3"};

	관찰 = true;
	
	while (true) {
		print_us(us);

		cout << "추가 할 데이터 >> ";
		String s;
		cin >> s;
		cout << endl;

		us.insert(s);
	}
 }
