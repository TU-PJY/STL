//-----------------------
//목78
// 5.6 화
// 
// Iterator - Iterators are a generalization of pointers.
//			- 포인터를 일반화 한 것이 반복자다.
// 
// 
// 6월 6일 목요일 강의 예정
//----------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "save.h"
#include "String.h" 
using namespace std;
extern bool 관찰;
//
//template <class 반복자>
//void f(반복자 iter) {
//	// 모든 반복자의 종류를 판별하는 표준 문장
//	cout << typeid(iterator_traits<반복자>::iterator_category).name() << endl;
//
//}

template <class 반복자>
void f(반복자 iter) {
	cout << typeid(iterator_traits<반복자>::iterator_category).name() << endl;

	// c++20
	cout << typeid(반복자::iterator_concept).name() << endl;
}

int main() {
	save("FileName.cpp");

	String s{ "1357924680" };

	for (auto i = s.rbegin(); i != s.rend(); ++i) {
		cout << *i << ' ';
	}
 }
