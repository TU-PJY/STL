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

#include <string>
#include "save.h"
#include "String.h" 
using namespace std;
extern bool ����;

template <class �ݺ���, class ȣ�Ⱑ��Ÿ��>
�ݺ��� f(�ݺ��� begin, �ݺ��� end, ȣ�� ���� Ÿ�� f) {

}

int main() {
	save("FileName.cpp");

	String s{ "1357924680" };

	//����
	//���� �ڵ尡 �ǵ���� ����ǵ��� �Լ� f()�� �ۼ��϶�
	// f�� ���� s.begin(), s.end()���� ���ǿ� �´� ���Ҹ� ã�� �ݺ��ڸ� �����Ѵ�
	f(s.begin(), s.end(), [](char c) {if (���� c�� ���ڰ��� ¦����� ���� true  else return false;)});

	cout << "ó�� ã�� ¦���� ��ġ - " << ? << endl;
	cout << "ó�� ã�� ¦���� �� - " << *p << endl;
 }
