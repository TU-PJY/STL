//-----------------------
//��78
// 5.6 ȭ
// 
// 6�� 6�� ����� ���� ����
// 
// STL Associative container - set / map
// 
// map - <key, value> pair�� key �������� ���Ļ��¸� ����
//----------------------
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>
#include <array>
#include "save.h"
#include "String.h" 
using namespace std;
extern bool ����;

int main() {
	save("FileName.cpp");

	fstream in{ "�̻��� ������ �ٸ���.txt" };
	if (!in) return -1;

	// ����
	// ���Ͽ� ���� �ܾ�� Ƚ���� ����϶�

	map<String, int> mp;

	String s{};

	while (in >> s) {
		mp[s]++;
		mp.insert(pair<String, int>{s, mp[s]});
	}

	for (const auto& m : mp)
		cout << m.first << " - " << m.second << endl;

	cout << "��ü �ܾ� ��: " << mp.size();

	// ���� ���� �ܾ� ���� ����϶�

 }
