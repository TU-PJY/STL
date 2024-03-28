//-----------------------
//목78
// callable type -> 정렬 예제에서 시작(qsort -> sort) 
//----------------------
#include <iostream>
#include <random>
#include <array>
#include <cstdlib>
#include "save.h"

using namespace std;

// 문제
// int 100개를 저장할 공간을 확보하라
// int 100개의 값을 [1, 99999] 사이의 랜덤값으로 설정하라
// qsort를 사용하여 오름차순으로 정렬 
// 정렬된 int값을 한 줄에 10개씩 출력하라 

int qs(const void* a, const void* b); 

default_random_engine dre;
uniform_int_distribution uid {1, 99999};

array<int, 100> a;


int main() {
	(*save)("FileName.cpp");
	
	for(int &num: a)
		num = uid(dre);
		
	// qsort() -> c함수이지만 generic 함수 
	// qsort(시작 번지, 개수, 한 개의 크기, 정렬 방법)
	
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
