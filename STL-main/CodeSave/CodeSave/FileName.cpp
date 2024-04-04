//-----------------------
//목78
// 
//----------------------
#include <iostream>			
#include <memory>
#include "save.h"

using namespace std;


class String {
private:
	size_t len{};
	unique_ptr <char[]> p{};

public:
	String(const char* s) : len{ strlen(s) } {
		p.reset(new char[len]);
		memcpy(p.get(), s, len);
	}

	friend ostream& operator << (ostream& os, const String& s) {
		for (size_t i = 0; i < s.len; ++i)
			os << s.p.get()[i];
		return os;
	}
};


int main() {
	save("FileName.cpp");

	String s{ "STL 공부를 위한 class" };

	cout << s << endl;

	String t = move(s);

	cout << t << endl;
 }







