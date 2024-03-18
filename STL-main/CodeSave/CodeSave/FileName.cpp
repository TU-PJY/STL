//-----------------------
// 2024.3.7 목78
//
//c++ 복습
// 실행 파일의 메모리 영역 - STACK, DATA, CODE, free store(heap)
//----------------------
#include <iostream>
#include <array>
#include <string>
#include "save.h"

using namespace std;

char gc;  // DATA
int gnum;

int main() {
	save("FileName.cpp");

	array<int, 10> a;  // int 10개릐 주소 출력
	string s{"안녕하세요"};
	double* p = new double[10];
}