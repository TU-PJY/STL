//-------------------------------------------
// String.cpp  STL의 동작을 관찰하기 위함
// 
// 2024.04.04 시작
// 2024/04.04 관찰 스위치 추가
// 2024.05.02 operator < (operator less) (list::merge)
//-------------------------------------------
#include "String.h"

bool 관찰{false};

size_t String::uid{};

// 이 클래스는 String()과 ~String()을 코딩할 이유가 없지만, 관찰을 위해 코딩
String::String() : id{++uid}
{
	if(관찰)
		std::cout << "[" << id << "] 디폴트 생성, 개수: " << len << ", 주소: " << static_cast<void*>(p.get()) << std::endl;
}

String::~String() {
	if(관찰)
		std::cout << "[" << id << "] 소멸, 개수: " << len << ", 주소: " << static_cast<void*>(p.get()) << std::endl;
}

String::String(const char* s)
	: len{ strlen(s) }, id{++uid}
{
	p.reset(new char[len]);
	memcpy(p.get(), s, len);

	if (관찰)
		std::cout << "[" << id << "] 생성(char*), 개수: " << len << ", 주소: " << static_cast<void*>(p.get()) << std::endl;
}


// 복사 생성자 / 복사 할당 연산자 - 2024.04.04
String::String(const String& other)
	: len{ other.len }, id{++uid}
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰)
		std::cout << "[" << id << "] 복사 생성, 개수: " << len << ", 주소: " << static_cast<void*>(p.get()) << std::endl;
}


String& String::operator=(const String& rhs) {
	if (this == &rhs)  // 자기 자신 할당 방지
		return *this;

	len = rhs.len;
	p.release();
	p = std::make_unique<char[]>(len);

	memcpy(p.get(), rhs.p.get(), len);

	if (관찰)
		std::cout << "[" << id << "] 복사 할당 연산자, 개수: " << len << ", 주소: " << static_cast<void*>(p.get()) << std::endl;

	return *this;
}



//이동 생성자/이동 할당 연산자 -2024.4.11
String::String(String&& other) : len{ other.len }, id{++uid} {
	p = std::move(other.p);
	other.len = 0;
	other.p.reset();

	if (관찰)
		std::cout << "[" << id << "] 이동 생성, 개수: " << len << ", 주소: " << static_cast<void*>(p.get()) << std::endl;
}


String& String::operator = (String&& rhs) {
	if(this != &rhs)
		return *this;

	len = rhs.len;
	p = std::move(rhs.p);

	rhs.len = 0;
	rhs.p.reset();

	if (관찰)
		std::cout << "[" << id << "] 이동 복사 할당 연산자, 개수: " << len << ", 주소: " << static_cast<void*>(p.get()) << std::endl;

	return *this;
}


//2024.05.02 operator <
bool String::operator < (const String& rhs) const {
	// 내 String과 rhs의 String을 사전식으로 비교해야 한다
	return std::lexicographical_compare(p.get(), p.get() + len, rhs.p.get(), rhs.p.get() + rhs.len);
}


size_t String::get_len() const {
	return len;
}

std::istream& operator >> (std::istream& is, String& s) {
	std::string ts;
	is >> ts;
	s.len = ts.size();

	s.p = std::make_unique<char[]>(s.len);

	memcpy(s.p.get(), ts.data(), s.len);

	return is;
}