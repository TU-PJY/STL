//-----------------------
//목78
// 5.6 화
// 
// 6월 6일 목요일 강의 예정
// 
// STL Associative container - set / map
// 
// map - <key, value> pair를 key 기준으로 정렬상태를 유지
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
extern bool 관찰;

int main() {
	save("FileName.cpp");

	fstream in{ "이상한 나라의 앨리스.txt" };
	if (!in) return -1;

	// 문제
	// 파일에 사용된 단어와 횟수를 출력하라

	map<String, int> mp;

	String s{};

	while (in >> s) {
		mp[s]++;
		mp.insert(pair<String, int>{s, mp[s]});
	}

	for (const auto& m : mp)
		cout << m.first << " - " << m.second << endl;

	cout << "전체 단어 수: " << mp.size();

	// 많이 사용된 단어 먼저 출력하라

 }
