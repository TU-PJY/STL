//-----------------------
// 2024.3.7 ��78
//
//c++ ����
//-----------------------
#include <iostream>
#include <random>
#include <array>
#include <fstream>
#include "save.h"

std::default_random_engine dre;
std::uniform_int_distribution uidC{ 'a', 'z' };
std::uniform_int_distribution uidNum{ -9999, 9999 };


//[����] ���� "intõ��"���� int�� 1000���� ��ϵǾ��ִ�.
// ������ ���̳ʸ� ���� ��������,  ����� �� write�Լ��� 4000����Ʈ�z ����Ͽ���.
// ������ �о� ���� ū ���� ����϶�

class Dog {
	char c{ static_cast<char> (uidC(dre)) };
	int num{ uidNum(dre) };

public:
	friend std::ostream& operator << ( std::ostream & os, const Dog & dog) {
		return os << "����: " << dog.c << " ����: " << dog.num << std::endl;
	}
};

// [����] "����"���� 100��ü�� ��ϵǾ���. 
// ���̳ʸ� ����̸�, sizeof(Dog) * 100����Ʈ�� ����Ͽ���.
// Dog�� ����� �Ʒ��� ����.
// num���� ���� ū Dog�� ã�� ȭ�鿡 ����϶�.
class Dog {
	char c;
	int num;
};

int main() {

	std::array<Dog, 100> dogs;

	std::ofstream out{ "����" , std::ios::binary };

	out.write((char*)dogs.data(), dogs.size() * sizeof(Dog));

	for (const Dog& dog : dogs)
		std::cout << dog << std::endl;

	save("FileName.cpp");
}
