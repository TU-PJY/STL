//-------------------------------------------
// String.h  STL�� ������ �����ϱ� ����
// 
// 2024.04.04 ����
// 2024.04.04 Ŭ������ special ���� ����
// 2024.05.02 operator < (operator less) (list::merge)
// 2024.05.06 begin, end
// 2024.05.09 rbegin, rend�� ���� Ÿ���� Ŭ������ �ڵ��ؾ� �Ѵ�
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

	// �ݺ����� �⺻ �������̽�
	String_iterator& operator++() {
		++p;
		return *this;
	}

	char& operator*() const {  // sort ������ const ���
		return *(p);
	}

	bool operator==(const String_iterator& rhs) const {
		return p == rhs.p;
	}

	// std::sort�� �䱸�ϴ� �����ڸ� �ڵ��Ѵ�
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



// ������ �ݺ��ڸ� �ڵ��� ������ ����. reverse_iterator�� ����ϸ� �ȴ�. 
// �׷�����, �����̳��� �ݺ��ڴ� �ݵ�� Ŭ������ �ڵ��ؾ� �Ѵ�.
// 2024.05.09 ������ �ݺ��� ���� �ڵ� - �ݺ��� ������� ����
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

	// �ݺ����� �⺻ �������̽�
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
	static size_t uid;  // �뵵�� Ȯ������

};