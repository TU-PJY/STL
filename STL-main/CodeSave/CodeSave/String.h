//-------------------------------------------
// String.h  STL�� ������ �����ϱ� ����
// 
// 2024.04.04 ����
// 2024.04.04 Ŭ������ special ���� ����
//-------------------------------------------
#pragma once
#include <iostream>
#include <memory>

class String {

size_t len{};
std::unique_ptr <char[]> p{};
size_t id{};

public:
	// �� Ŭ������ String()�� ~String()�� �ڵ��� ������ ������, ������ ���� �ڵ�
	String();

	~String();

	String(const char* s);

	// ���� ������ / ���� �Ҵ� ������ - 2024.04.04
	String(const String& other);
	String& operator=(const String& rhs);

	//�̵� ������/�̵� �Ҵ� ������ -2024.4.11
	String(String&& other);
	String& operator = (String&& rhs);

	size_t get_len() const;

	friend std::ostream& operator << (std::ostream& os, const String& s) {
		for (size_t i = 0; i < s.len; ++i)
			os << s.p.get()[i];
		return os;
	}

	// 2024.04.08
	friend std::istream& operator >> (std::istream& is, String& s);

private:
	static size_t uid;  // �뵵�� Ȯ������

};