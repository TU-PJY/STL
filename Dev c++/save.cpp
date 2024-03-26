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
	// ���� ������ ����
    std::ifstream in{ filename.data() };
    
    if (!in) {
        std::cout << "Can not open file." << std::endl;
        exit(0);
    }
	
	// �� ������ �����̱� ���� ����
    std::ofstream out("2024 1 ��56 ��78 ��������.txt", std::ios::app);

	// ����� �ð��� ���Ͽ� ����Ѵ�
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);  // utc �ð����� ��ȯ 
    auto lt = localtime(&time);  // ���� �ð����� ��ȯ 

    _wsetlocale(LC_ALL, L"korean"); 
    out << "\n" << "\n";
    out << "==================================================" << "\n";
    out << filename << std::put_time(lt, ", ����ð�: %x %A %X") << std::endl;
    out << "==================================================" << std::endl;

    out << std::endl;
	
	// ���� ������ ��� ������ �о� �� ���Ͽ� �����δ�.
    std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };
    std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{out});
}
