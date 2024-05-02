//-------------------------------------------
// String.h  STL의 동작을 관찰하기 위함
// 
// 2024.04.04 시작
// 2024.04.04 클래스의 special 동작 관찰
//-------------------------------------------
#pragma once
#include <iostream>
#include <memory>

class String {

size_t len{};
std::unique_ptr <char[]> p{};
size_t id{};

public:
	// 이 클래스는 String()과 ~String()을 코딩할 이유가 없지만, 관찰을 위해 코딩
	String();

	~String();

	String(const char* s);

	// 복사 생성자 / 복사 할당 연산자 - 2024.04.04
	String(const String& other);
	String& operator=(const String& rhs);

	//이동 생성자/이동 할당 연산자 -2024.4.11
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
	static size_t uid;  // 용도를 확인하자

};