//-----------------------
// 2024.3.7 ��78
//
//c++ ����
//-----------------------
#include <iostream>
#include <fstream>
#include <print>
#include <algorithm>
#include <random>
#include <array>
#include "save.h"
#define code 1

//[����] ���� "intõ��.txt"�� int�� 1000���� ���ڰ��� �״�� ��ϵǾ��ִ�.
// // ���� ���� �������� ������ �ִ�.
// // ���� ū ���� ã�� ȭ�鿡 ����϶�.

std::default_random_engine dre;
std::uniform_int_distribution uid {0, 99999};

int main() {
	if (code == 0) {
		std::ifstream in{ "intõ��.txt" };
		if (!in)
			exit(0);

		std::cout << *std::max_element(std::istream_iterator<int>{in}, {}) << std::endl;
	}

	else if (code == 1) {
		std::array<int, 1000> a;  // ���� �迭 ����

		for (int& i : a)  // �迭�� ���� ���ڵ��� �����Ѵ�.
			i = uid(dre);

		for (int i : a)  // �迭�� ����� ���� ���ڵ��� ����Ѵ�.
			std::print("{:8d}", i);

		std::cout << std::endl;
		std::cout << "max:" << *std::max_element(std::begin(a), std::end(a)) << std::endl;  // �ִ� ���� ã�´�

		std::ofstream out{ "intõ��.txt" };  // ���Ͽ� ����� �Ѵ�.
		for (int i : a)
			std::print(out, "{:8d} ", i);

		std::print(out, "\n{:8} ", *std::max_element(std::begin(a), std::end(a)));
	}

	save("FileName.cpp");
}
