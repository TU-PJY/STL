//-----------------------
// 2024.3.7 목78
//
//c++ 복습
//-----------------------
#include <iostream>
#include <random>
#include <array>
#include <fstream>
#include "save.h"

std::default_random_engine dre;
std::uniform_int_distribution uidC{ 'a', 'z' };
std::uniform_int_distribution uidNum{ -9999, 9999 };


//[문제] 파일 "int천개"에는 int값 1000개가 기록되어있다.
// 파일은 바이너리 모드로 열었으며,  기록할 떄 write함수로 4000바이트틑 기록하였다.
// 파일을 읽어 가장 큰 값을 출력하라

class Dog {
	char c{ static_cast<char> (uidC(dre)) };
	int num{ uidNum(dre) };

public:
	friend std::ostream& operator << ( std::ostream & os, const Dog & dog) {
		return os << "글자: " << dog.c << " 숫자: " << dog.num << std::endl;
	}
};

// [문제] "개들"에는 100객체가 기록되었다. 
// 바이너리 모드이며, sizeof(Dog) * 100바이트를 기록하였다.
// Dog의 멤버는 아래와 같다.
// num값이 가장 큰 Dog를 찾아 화면에 출력하라.
class Dog {
	char c;
	int num;
};

int main() {

	std::array<Dog, 100> dogs;

	std::ofstream out{ "개들" , std::ios::binary };

	out.write((char*)dogs.data(), dogs.size() * sizeof(Dog));

	for (const Dog& dog : dogs)
		std::cout << dog << std::endl;

	save("FileName.cpp");
}
