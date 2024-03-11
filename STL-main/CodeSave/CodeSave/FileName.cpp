//-----------------------
// 2024.3.7 목78
//
//c++ 복습
//-----------------------
#include <iostream>
#include <fstream>
#include <print>
#include <algorithm>
#include <random>
#include <array>
#include "save.h"
#define code 1

//[문제] 파일 "int천개.txt"에 int값 1000개의 숫자값이 그대로 기록되어있다.
// // 값과 값은 공백으로 떨어져 있다.
// // 가장 큰 값을 찾아 화면에 출력하라.

std::default_random_engine dre;
std::uniform_int_distribution uid {0, 99999};

int main() {
	if (code == 0) {
		std::ifstream in{ "int천개.txt" };
		if (!in)
			exit(0);

		std::cout << *std::max_element(std::istream_iterator<int>{in}, {}) << std::endl;
	}

	else if (code == 1) {
		std::array<int, 1000> a;  // 정수 배열 선언

		for (int& i : a)  // 배열에 랜덤 숫자들을 저장한다.
			i = uid(dre);

		for (int i : a)  // 배열에 저장된 랜덤 숫자들을 출력한다.
			std::print("{:8d}", i);

		std::cout << std::endl;
		std::cout << "max:" << *std::max_element(std::begin(a), std::end(a)) << std::endl;  // 최대 값을 찾는다

		std::ofstream out{ "int천개.txt" };  // 파일에 덮어쓰기 한다.
		for (int i : a)
			std::print(out, "{:8d} ", i);

		std::print(out, "\n{:8} ", *std::max_element(std::begin(a), std::end(a)));
	}

	save("FileName.cpp");
}
