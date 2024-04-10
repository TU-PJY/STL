//-----------------------
//��78
// STL Container - A container is an object that stores other objects
//----------------------
#include <iostream>
#include <fstream>
#include <array>
#include <list>
#include <algorithm>
#include "save.h"
#include "String.h"
using namespace std;

extern bool ����;  // �޽ñ� ���� ���� �� true

int main() {
	save("FileName.cpp");

	array <String, 30> a;  // int[10]

	// a�� filename.cpp�� �ִ� string�� 30�� �о� �����϶�.
	fstream in{ "FileName.cpp" };

	if (!in)
		return 20240408;

	String s;

	for (int i = 0; i < a.size(); ++i) {
		in >> a[i];
	}

	sort(a.begin(), a.end(), [](const String& a, const String& b) {return a.get_len() < b.get_len(); });

	for (const String& s : a)
		cout << s << endl;
 }