//-------------------------------------------
// String.cpp  STL�� ������ �����ϱ� ����
// 
// 2024.04.04 ����
// 2024/04.04 ���� ����ġ �߰�
//-------------------------------------------
#include "String.h"

bool ����{false};

size_t String::uid{};

// �� Ŭ������ String()�� ~String()�� �ڵ��� ������ ������, ������ ���� �ڵ�
String::String() : id{++uid}
{
	if(����)
		std::cout << "[" << id << "] ����Ʈ ����, ����: " << len << ", �ּ�: " << static_cast<void*>(p.get()) << std::endl;
}

String::~String() {
	if(����)
		std::cout << "[" << id << "] �Ҹ�, ����: " << len << ", �ּ�: " << static_cast<void*>(p.get()) << std::endl;
}

String::String(const char* s)
	: len{ strlen(s) }, id{++uid}
{
	p.reset(new char[len]);
	memcpy(p.get(), s, len);

	if (����)
		std::cout << "[" << id << "] ����(char*), ����: " << len << ", �ּ�: " << static_cast<void*>(p.get()) << std::endl;
}


// ���� ������ / ���� �Ҵ� ������ - 2024.04.04
String::String(const String& other)
	: len{ other.len }, id{++uid}
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (����)
		std::cout << "[" << id << "] ���� ����, ����: " << len << ", �ּ�: " << static_cast<void*>(p.get()) << std::endl;
}


String& String::operator=(const String& rhs) {
	if (this == &rhs)  // �ڱ� �ڽ� �Ҵ� ����
		return *this;

	len = rhs.len;
	p.release();
	p = std::make_unique<char[]>(len);

	memcpy(p.get(), rhs.p.get(), len);

	if (����)
		std::cout << "[" << id << "] ���� �Ҵ� ������, ����: " << len << ", �ּ�: " << static_cast<void*>(p.get()) << std::endl;

	return *this;
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