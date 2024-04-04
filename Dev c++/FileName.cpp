//-----------------------
//목78
// callable type -> STL std::sort
// sort 함수에 정렬 방법을 어떻게 알려주었나?  
// 1. 함수 포인터 전달
// 2. 람다(lamda) -> 정체는? 
// 3. 함수 객체 
// 기말시험 8주 2일 -> 4월 25일 
//----------------------
#include <iostream>			
#include "save.h"

using namespace std;

// 문제
// int 100개를 저장할 공간을 확보하라
// int 100개의 값을 [1, 99999] 사이의 랜덤값으로 설정하라
// sort를 사용하여 오름차순으로 정렬 
// 정렬된 int값을 한 줄에 10개씩 출력하라 

  auto lambda1 = []() {cout << "나는 람다" << endl;};


auto lambda2 = []() {cout << "나는 람다" << endl;};

int main() {
	save("FileName.cpp");


    cout << typeid(lambda1).name() << endl;
    cout << typeid(lambda2).name() << endl;
}







