//-------------------------------------------
// String.h  STL의 동작을 관찰하기 위함
// 
// 2024.04.04 시작
// 2024.04.04 클래스의 special 동작 관찰
// 2024.05.02 operator < (operator less) (list::merge)
// 2024.05.06 begin, end
// 2024.05.09 rbegin, rend의 리턴 타입을 클래스로 코딩해야 한다
//-------------------------------------------
#pragma once
#include <iostream>
#include <memory>


class String_iterator {
public:
	using value_type = char;
	using difference_type = std::ptrdiff_t;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

	//c++20
	using iterator_concept = std::contiguous_iterator_tag;


private:
	char* p;

public:
	String_iterator(char* p) : p{ p } {}

	// 반복자의 기본 인터페이스
	String_iterator& operator++() {
		++p;
		return *this;
	}

	char& operator*() const {  // sort 떄문에 const 사용
		return *(p);
	}

	bool operator==(const String_iterator& rhs) const {
		return p == rhs.p;
	}

	// std::sort가 요구하는 연산자를 코딩한다
	difference_type operator-(const String_iterator& rhs) const {
		return p - rhs.p;
	}

	String_iterator& operator--() {
		--p;
		return *this;
	}

	String_iterator operator+(difference_type diff) const {
		return String_iterator{ p + diff };
	}

	bool operator<(const String_iterator rhs) const {
		return p < rhs.p;
	}

	String_iterator operator-(difference_type diff) const {
		return String_iterator{ p - diff };
	}
};



// 역방향 반복자를 코딩할 이유는 없다. reverse_iterator를 사용하면 된다. 
// 그렇지만, 컨테이너의 반복자는 반드시 클래스로 코딩해야 한다.
// 2024.05.09 역방향 반복자 직접 코딩 - 반복자 어댑터의 일종
class String_reverse_iterator {
public:
	using value_type = char;
	using difference_type = std::ptrdiff_t;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

	//c++20
	using iterator_concept = std::contiguous_iterator_tag;
	

private:
	char* p;

public:
	String_reverse_iterator(char* p) : p{ p } {}

	// 반복자의 기본 인터페이스
	String_reverse_iterator& operator++() {
		--p;
		return *this;
	}

	char& operator*() {
		return *(p - 1);
	}

	bool operator==(const String_reverse_iterator& rhs) const {
		return p == rhs.p;
	}
};



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

	//2024.05.02 operator <
	bool operator < (const String& rhs) const;

	// 2024.4.4 get_set
	size_t get_len() const;


	// 2024.05.06
	String_iterator begin() const {
		return String_iterator(p.get());
	}

	String_iterator end() const {
		return String_iterator(p.get() + len);
	}


	//2024.05.09
	String_reverse_iterator rbegin() const {
		return String_reverse_iterator{ p.get() + len };
	} 

	String_reverse_iterator rend() const {
		return String_reverse_iterator{ p.get() };
	}


	friend std::ostream& operator << (std::ostream& os, const String& s) {
		for (size_t i = 0; i < s.len; ++i)
			os << s.p.get()[i];
		return os;
	}

	bool operator==(String& other) const;

	// 2024.04.08
	friend std::istream& operator >> (std::istream& is, String& s);



private:
	static size_t uid;  // 용도를 확인하자

};