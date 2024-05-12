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

#include <string>
#include "save.h"
#include "String.h" 
using namespace std;
extern bool 관찰;

template <class 반복자, class 호출가능타입>
반복자 f(반복자 begin, 반복자 end, 호출 가능 타입 f) {

}

int main() {
	save("FileName.cpp");

	String s{ "1357924680" };

	//문제
	//다음 코드가 의도대로 실행되도록 함수 f()를 작성하라
	// f는 구간 s.begin(), s.end()에서 조건에 맞는 원소를 찾아 반복자를 리턴한다
	f(s.begin(), s.end(), [](char c) {if (글자 c의 숫자값이 짝수라면 리턴 true  else return false;)});

	cout << "처음 찾은 짝수의 위치 - " << ? << endl;
	cout << "처음 찾은 짝수의 값 - " << *p << endl;
 }
