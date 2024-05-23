#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <memory>
#include <numeric>
#include <string>


class Player {
public:
    Player() {}

    bool read(std::istream& is) {
        is.read((char*)this, sizeof(Player) - sizeof(std::unique_ptr<char[]>));
        char temp[sizeof(std::unique_ptr<char[]>)];

        is.read(temp, sizeof(std::unique_ptr<char[]>));
        p = std::make_unique<char[]>(num + 1);

        is.read((char*)p.get(), num);

        p[num] = '\0';

        return (bool)is;
    }

    
    friend std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << "이름: " << player.name
            << ", 아이디: " << player.id
            << ", 점수: " << player.score
            << ", 자원수: " << player.num << std::endl
            << "저장된 글자: " << player.p.get();

        return os;
    }

    bool operator==(const size_t value) const {
        return id == value;
    }

    bool operator==(const std::string str) const {
        return name == str;
    }

    bool operator<(const Player& other) const {
        if (id != other.id) 
            return id < other.id;

        if (name != other.name)
            return std::lexicographical_compare(name.begin(), name.end(), other.name.begin(), other.name.end());
        
        if (score != other.score)
            return score < other.score;
    }


    // p에 할당된 문자열 정렬
    void sort_p() {
        std::string str(p.get());
        std::sort(str.begin(), str.end());
        
        p = std::make_unique<char[]>(str.length() + 1);

        strcpy(p.get(), str.c_str());
    }


    // p에 할당된 문자열이 a부터 z까지 있는지 확인
    bool check_is_a_to_z() {
        std::string str(p.get());
        std::string alphabets = "abcdefghijklmnopqrstuvwxyz";

        // std::includes를 사용하여 알파벳이 모두 존재하는지 확인
        return std::includes(str.begin(), str.end(), alphabets.begin(), alphabets.end());
    }


    int get_score() const { return score; }

    size_t get_id() const { return id; }

    std::string get_name() const { return name; }


private:
    std::string name{};
    int score{};
    size_t id{};
    size_t num{};
    std::unique_ptr<char[]> p{};
};

// 이전, 현재, 다음 정보를 출력하는 함수
void show_3_info(std::vector<Player>::iterator iter);

// Player 객체를 저장하는 벡터
std::vector<Player> player_list;

// true일 시 5번 문제에서 아이디 정렬을 건너 뛴다
bool player_list_sorted{};


// define 시 1~4번 문제 생략
//#define PASS


int main() {
    // 1. 파일에 저장된 모든 Player 정보를 컨테이너에 저장하라.
    // 제일 마지막 Player의 정보를 다음과 같은 형식으로 화면에 출력하라.

    // 과제 설명문에서 명시한 객체의 개수 만큼 컨테이너를 확보한다
    player_list.reserve(2000000);

    std::ifstream in{ "2024 STL 과제 파일", std::ios::binary };
    if (!in) {
        std::cout << "Can not open file." << std::endl;
        return -1;
    }

    Player p;

    // 파일로부터 객체 데이터를 읽어 read()를 통해 컨데이너에 저장한다
    while (p.read(in)) {
        player_list.push_back(std::move(p));
    }


#ifndef PASS

    std::cout << "==== 마지막 Player의 정보 ====" << std::endl;
    std::cout << player_list.back() << std::endl << std::endl;






    // 2. 점수가 가장 큰 Player를 찾아 화면에 출력하라.
    // Player의 평균 점수를 계산하여 화면에 출력하라.

    // max_element로 가장 큰 점수를 가진 Player 객체를 찾는다
    auto max_score_player = std::max_element(player_list.begin(), player_list.end(),
        [](const Player& a, const Player& b) {
            return a.get_score() < b.get_score();
        });

    std::cout << "==== 점수가 가장 큰 Player ====" << std::endl;
    std::cout << *max_score_player << std::endl << std::endl;


    // accumulate로 모든 객체의 점수 합을 구한 후 컨테이너에 저장된 객체 수로 나누어 평균을 구한다
    long long score_sum = std::accumulate(player_list.begin(), player_list.end(), 0LL,
        [](long long sum, const Player& p) {
            return sum + p.get_score();
        });

    long long score_avg = (score_sum / (long long)player_list.size());

    std::cout << "==== Player의 평균 점수 ====" << std::endl;
    std::cout << score_avg << " 점" << std::endl << std::endl;






    // 3. id가 서로 같은 객체를 찾아 "같은아이디.txt"에 기록하라.
    // id가 같은 객체는 모두 몇 개인지 화면에 출력하라.
    // - "같은아이디.txt" 일에는 Player 마다 이름과 아이디 정보만을 한 줄씩 기록한다.
    std::cout << "처리 중..." << std::endl << std::endl;

    // 중복 아이디를 쉽게 찾기 위해 아이디를 기준으로 오름차순 정렬한다
    std::sort(player_list.begin(), player_list.end(),
        [](const Player& a, const Player& b) {
            return a.get_id() < b.get_id();
        });

    // 5번 문제 최초 실행 시 아이디 정렬을 건너뛴다
    player_list_sorted = true;

    // 최초의 중복 아이디가 발견되면 해당 위치를 시작 위치로 지정한다
    auto start_it = std::adjacent_find(player_list.begin(), player_list.end(), 
        [](const Player& a, const Player& b) {
            return a.get_id() == b.get_id();
        });

    // 발견되면 나머지 중복 아이디를 찾고, 그렇지 않다면 건너뛴다
    if (start_it != player_list.end()) {
        std::ofstream out{ "같은아이디.txt" };

        // 먼저 발견한 두 중복 아이디를 파일에 기록한다
        out.width(25);
        out << std::left << start_it->get_name() << std::right << start_it->get_id() << std::endl;
        out.width(25);
        out << std::left << std::next(start_it)->get_name() << std::right << std::next(start_it)->get_id() << std::endl;

        // 2개를 찾았으므로 카운트는 2부터 시작
        int same_id_count = 2;

        for (auto it = start_it + 1; it != player_list.end() - 1; ++it) {
            // 현재 아이디와 다음 아이디가 같을 떄
            if (it->get_id() == std::next(it)->get_id()) {

                // 이전 위치에서 중복을 찾았다면 카운트 1 증가 시킨다
                if (std::prev(it)->get_id() == it->get_id()) {
                    out.width(25);  // 파일에 기록한다
                    out << std::left << std::next(it)->get_name() << std::right << std::next(it)->get_id() << std::endl;

                    ++same_id_count;
                }

                // 이전 위치까지 중복을 발견하지 못하다가 현재 위치에서 중복을 발견하면 카운트 2 증가시킨다
                else {
                    out.width(25);  // 파일에 두 아이디를 기록한다
                    out << std::left << it->get_name() << std::right << it->get_id() << std::endl;
                    out.width(25);
                    out << std::left << std::next(it)->get_name() << std::right << std::next(it)->get_id() << std::endl;

                    same_id_count += 2;
                }
            }
        }

        std::cout << "==== 같은 아이디를 가지는 Player 객체 개수 ====" << std::endl;
        std::cout << same_id_count << "개 존재" << std::endl << std::endl;
    }

    else
        std::cout << "같은 아이디를 가지는 Player 객체를 찾을 수 없습니다." << std::endl << std::endl;




    // 4. 멤버 p가 소유한 메모리로 읽어온 char를 오름차순으로 정렬하라.
    // 'a'부터 ‘z’까지 모든 문자가 메모리에 있는 Player의 개수를 화면에 출력하라.

    std::cout << "처리 중..." << std::endl << std::endl;

    int a_to_z_count{};

    // 각 객체의 p 정렬 후 a 부터 z 까지 존재하는 객체 수 카운트
    for (auto& p : player_list) {
        p.sort_p();

        // a부터 z까지 모두 존재하는지 확인
        if (p.check_is_a_to_z())
            ++a_to_z_count;
    }

    std::cout << "==== a 부터 z까지 모두 존재하는 p를 가진 Player 객체의 개수 ====" << std::endl;
    std::cout << a_to_z_count << "개 존재" << std::endl << std::endl;

#endif




    // 5.[LOOP] id를 입력받아 존재하는 id라면 다음 내용을 한 번에 화면 출력하라.
    // - Player를 id 오름차순으로 정렬하였을 때해당 id 포함 앞과 뒤 Player의 정보를 출력한다.
    // id가 같은 Player가 둘 이상이면 이들의 정보를 모두 출력하여야 한다.
    // - Player를 name 오름차순으로 정렬하였을 때해당 name 포함 앞과 뒤 Player의 정보를 출력한다.
    // - Player를 score 오름차순으로 정렬하였을 때해당 score 포함 앞과 뒤 Player의 정보를 출력한다.
    // * 프로그램은 5번 과제를 무한히 반복할 수 있어야 한다.

    while (true) {
        std::string cmd{};
        bool incorrect_cmd{};

        // 검색 반복자
        std::vector<Player>::iterator search{};

        std::cout << "아이디 입력 >> ";

        std::getline(std::cin, cmd);
        size_t search_id = std::stoi(cmd);

        // 입력한 내용이 올바른지 검사한다
        for (auto c : cmd) {
            if (!std::isdigit(c) || std::isspace(c)) {
                std::cout << "올바른 입력이 아닙니다." << std::endl << std::endl;
                incorrect_cmd = true;
                break;
            }
        }

        if (incorrect_cmd)
            continue;

        std::cout << search_id <<" 을/를 검색 중입니다..." << std::endl << std::endl;
            


        // 아이디에 대해 오름차순 정렬되어있다면 정렬을 생략하고 이진 탐색한다
        if (player_list_sorted) {
            search = std::lower_bound(player_list.begin(), player_list.end(), search_id,
                [](const Player& p, size_t id) {
                    return p.get_id() < id;
                });

            if (search == player_list.end() || search->get_id() != search_id) {
                std::cout << "존재하지 않는 아이디 입니다." << std::endl << std::endl;
                continue;
            }
        }

        // 아이디에 대해 오름차순 정렬되어있지 않다면 아이디 오름차순 정렬 후 이진 탐색 한다
        else {
            std::sort(player_list.begin(), player_list.end(),
                [](const Player& a, const Player& b) {
                    return a.get_id() < b.get_id();
                });

            // 정렬 되었으므로 continue 이후의 검색 시 정렬을 생략한다
            player_list_sorted = true;

            search = std::lower_bound(player_list.begin(), player_list.end(), search_id,
                [](const Player& p, size_t id) {
                    return p.get_id() < id;
                });

            if (search == player_list.end() || search->get_id() != search_id) {
                std::cout << "존재하지 않는 아이디 입니다." << std::endl << std::endl;
                continue;
            }
        }



        std::cout << std::endl << std::endl << "================================================" << std::endl;
        std::cout << "======== 아이디 오름차순 정렬 ========" << std::endl << std::endl;



        show_3_info(search);

        // 해당 아이디를 가지는 객체의 이름과 점수 기억
        std::string search_name = search->get_name();
        int search_score = search->get_score();

        // 같은 아이디가 두 개 이상 나오면
        // 오름차순 정렬 되었으므로 현재 위치의 아이디와 다음 위치의 아이디가 같은 경우밖에 존재하지 않는다.
        if (std::next(search) != player_list.end()) {
            if (search->get_id() == std::next(search)->get_id()) {
                int next_move = 2;

                // 중복되지 않는 아이디가 발견될 때까지 다음 위치의 객체 정보를 출력한다
                while (std::next(search + next_move) != player_list.end() && std::next(search + next_move)->get_id() == search_id) {
                    std::cout << *std::next(search, next_move) << std::endl << std::endl;
                    ++next_move;
                }
            }
        }



        std::cout << std::endl << std::endl << "================================================" << std::endl;
        std::cout << "======== 이름 오름차순 정렬 ========" << std::endl << std::endl;

        
        // 이름 정렬은 std::lexicographical_compare로 비교 후 정렬한다
        std::sort(player_list.begin(), player_list.end(),
            [](const Player& a, const Player& b) {
                return a.get_name() < b.get_name();
            });

        // 이름과 점수의 경우 아이디로 검색한 객체와 동일한 객체임을 보장하기 위해 find_if를 사용한다
        search = std::find_if(player_list.begin(), player_list.end(),
            [&search_name, &search_id, &search_score](const Player& p) {
                return p.get_name() == search_name && p.get_id() == search_id && p.get_score() == search_score;
            });
        show_3_info(search);



        std::cout << std::endl << std::endl << "================================================" << std::endl;
        std::cout << "======== 점수 오름차순 정렬 ========" << std::endl << std::endl;



        std::sort(player_list.begin(), player_list.end(),
            [](const Player& a, const Player& b) {
                return a.get_score() < b.get_score();
            });

        search = std::find_if(player_list.begin(), player_list.end(),
            [&search_name, &search_id, &search_score](const Player& p) {
                return p.get_name() == search_name && p.get_id() == search_id && p.get_score() == search_score;
            });
        show_3_info(search);

        std::cout << std::endl << std::endl << "출력 완료" << std::endl << std::endl; 

        // 이후 아이디 검색 시 정렬 실행
        player_list_sorted = false;
    }
}


// 현재 위치, 이전 위치, 다음 위치의 객체 정보를 출력하는 함수
void show_3_info(std::vector<Player>::iterator iter) {
    if (iter != player_list.begin())
        std::cout << *std::prev(iter) << std::endl << std::endl;

    std::cout << "--> " << *iter << std::endl << std::endl;

    if (std::next(iter) != player_list.end())
        std::cout << *std::next(iter) << std::endl << std::endl;
}