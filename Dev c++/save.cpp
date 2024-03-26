#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <string>
#include <iomanip>
#include <locale.h>
#include "save.h"

void save(std::string_view filename) {
	// 읽을 파일을 연다
    std::ifstream in{ filename.data() };
    
    if (!in) {
        std::cout << "Can not open file." << std::endl;
        exit(0);
    }
	
	// 쓸 파일을 덧붙이기 모드로 연다
    std::ofstream out("2024 1 월56 목78 강의저장.txt", std::ios::app);

	// 저장된 시간을 파일에 기록한다
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);  // utc 시간으로 변환 
    auto lt = localtime(&time);  // 현지 시간으로 변환 

    _wsetlocale(LC_ALL, L"korean"); 
    out << "\n" << "\n";
    out << "==================================================" << "\n";
    out << filename << std::put_time(lt, ", 저장시간: %x %A %X") << std::endl;
    out << "==================================================" << std::endl;

    out << std::endl;
	
	// 읽을 파일의 모든 내용을 읽어 쓸 파일에 덧붙인다.
    std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };
    std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{out});
}
