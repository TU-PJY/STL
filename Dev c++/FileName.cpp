//-----------------------
//��78
// callable type -> STL std::sort
// sort �Լ��� ���� ����� ��� �˷��־���?  
// 1. �Լ� ������ ����
// 2. ����(lamda) -> ��ü��? 
// 3. �Լ� ��ü 
// �⸻���� 8�� 2�� -> 4�� 25�� 
//----------------------
#include <iostream>			
#include "save.h"

using namespace std;

// ����
// int 100���� ������ ������ Ȯ���϶�
// int 100���� ���� [1, 99999] ������ ���������� �����϶�
// sort�� ����Ͽ� ������������ ���� 
// ���ĵ� int���� �� �ٿ� 10���� ����϶� 

  auto lambda1 = []() {cout << "���� ����" << endl;};


auto lambda2 = []() {cout << "���� ����" << endl;};

int main() {
	save("FileName.cpp");


    cout << typeid(lambda1).name() << endl;
    cout << typeid(lambda2).name() << endl;
}







