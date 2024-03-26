//-----------------------
// 2024.3.21 목78
//
//c++ 복습
// 실행 파일의 메모리 영역 - STACK, DATA, CODE, free store(heap)
//----------------------
#include <iostream>
#include <numeric>
#include <algorithm>
#include "save.h"

using namespace std;

// 문제
// 사용자가 입력한 int num값을 받아 free store int[num]메모리를 확보하라.
// 확보 메모리의 내용을 1부터 시작하여 1씩 증가하는 int 값으로 채워라.
// 메모리의 값을 합산한 값을 출력하라



int main() {
	save("FileName.cpp");
	
	while (true) {
		int num;

		cout << ">> ";
		cin >> num;

		int* p = new int[num];

		iota(p, p + num, 1);

		long long sum = accumulate(p, p + num, 0);

		wcout << L"1부터 num까지의 합계: " << sum << endl;
	}
}