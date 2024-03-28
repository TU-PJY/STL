//-----------------------
//��78
// callable type -> ���� �������� ����(qsort -> sort) 
//----------------------
#include <iostream>
#include <random>
#include <array>
#include <cstdlib>
#include "save.h"

using namespace std;

// ����
// int 100���� ������ ������ Ȯ���϶�
// int 100���� ���� [1, 99999] ������ ���������� �����϶�
// qsort�� ����Ͽ� ������������ ���� 
// ���ĵ� int���� �� �ٿ� 10���� ����϶� 

int qs(const void* a, const void* b); 

default_random_engine dre;
uniform_int_distribution uid {1, 99999};

array<int, 100> a;


int main() {
	(*save)("FileName.cpp");
	
	for(int &num: a)
		num = uid(dre);
		
	// qsort() -> c�Լ������� generic �Լ� 
	// qsort(���� ����, ����, �� ���� ũ��, ���� ���)
	
	int (*qs2)(const void* , const void* ) = qs;
	
	qsort(a.data(), a.size(), sizeof(int), qs2);
	
	for(int num : a)
		cout << num << endl;
}

int qs(const void* a, const void* b) {
	int x = *(int*) a;
	int y = *(int*) b;
	
	if(x < y)
		return -1;
		
	else if(x > y)
		return 1;
		
	return 0;
}
