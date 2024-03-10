//-----------------------
// 2024.3.7 목78
//
//c++ 복습
//-----------------------
#include <iostream>
#include "save.h"

class Dog;  // forward declaration(전방선언)

template <class T>
void change(T&, T&);

class Dog {
public:
	Dog(int num) : num{ num } {};
	//Dog(const Dog& other) -> special 함수, 컴파일러가 자동 생성

	operator int() {
		return num;
	}

private:
	int num;
};


// [문제] main()을 변경하면 안된다. 함수 chage()를 선언하고 정의
int main() {
	save("FileName.cpp");

	Dog a{ 1 }, b{ 2 };
	change(a, b);
	std::cout << a << ", " << b << std::endl;  // 2, 1로 출력
}

template <class T>

void change(T& a, T& b) {
	T temp{ a };
	a = b;
	b = temp;
}

