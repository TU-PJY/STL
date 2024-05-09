//-----------------------
//��78
// 5.6 ȭ
// 
// Iterator - Iterators are a generalization of pointers.
//			- �����͸� �Ϲ�ȭ �� ���� �ݺ��ڴ�.
// 
// 
// 6�� 6�� ����� ���� ����
//----------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "save.h"
#include "String.h" 
using namespace std;
extern bool ����;
//
//template <class �ݺ���>
//void f(�ݺ��� iter) {
//	// ��� �ݺ����� ������ �Ǻ��ϴ� ǥ�� ����
//	cout << typeid(iterator_traits<�ݺ���>::iterator_category).name() << endl;
//
//}

template <class �ݺ���>
void f(�ݺ��� iter) {
	cout << typeid(iterator_traits<�ݺ���>::iterator_category).name() << endl;

	// c++20
	cout << typeid(�ݺ���::iterator_concept).name() << endl;
}

int main() {
	save("FileName.cpp");

	String s{ "1357924680" };

	for (auto i = s.rbegin(); i != s.rend(); ++i) {
		cout << *i << ' ';
	}
 }
