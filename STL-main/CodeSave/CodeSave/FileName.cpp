//-----------------------
//��78
// 5.6 ȭ
// 
// 6�� 6�� ����� ���� ����
// 
// STL Unordered Associative container - unordered_set / unordered_map
// 
// ������ ����?
// �޸� ������ ȭ�鿡 ���
// String�� unordered �����̳ʿ� ����
//----------------------
#include <iostream>
#include <unordered_set>
#include <print>
#include "save.h"
#include "String.h" 
using namespace std;
extern bool ����;

template<class ��������>

void print_us(�������� us) {
	// unordered_set�� �޸𸮸� ȭ�鿡 ����Ѵ�
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

	���� = true;
	
	while (true) {
		print_us(us);

		cout << "�߰� �� ������ >> ";
		String s;
		cin >> s;
		cout << endl;

		us.insert(s);
	}
 }
