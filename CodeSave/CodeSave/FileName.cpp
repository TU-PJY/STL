//-----------------------
// 2024.3.7 ��78
//
//c++ ����
//-----------------------
#include <iostream>
#include "save.h"

class Dog;  // forward declaration(���漱��)

template <class T>
void change(T&, T&);

class Dog {
public:
	Dog(int num) : num{ num } {};
	//Dog(const Dog& other) -> special �Լ�, �����Ϸ��� �ڵ� ����

	operator int() {
		return num;
	}

private:
	int num;
};


// [����] main()�� �����ϸ� �ȵȴ�. �Լ� chage()�� �����ϰ� ����
int main() {
	save("FileName.cpp");

	Dog a{ 1 }, b{ 2 };
	change(a, b);
	std::cout << a << ", " << b << std::endl;  // 2, 1�� ���
}

template <class T>

void change(T& a, T& b) {
	T temp{ a };
	a = b;
	b = temp;
}

