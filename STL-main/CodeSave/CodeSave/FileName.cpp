//-----------------------
// 2024.3.7 ��78
//
//c++ ����
// ���� ������ �޸� ���� - STACK, DATA, CODE, free store(heap)
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

	array<int, 10> a;  // int 10���l �ּ� ���
	string s{"�ȳ��ϼ���"};
	double* p = new double[10];
}