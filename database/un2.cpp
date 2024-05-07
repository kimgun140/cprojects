#include "db_class.cpp"  // DB 클래스가 이전에 제공된 것으로 가정
// #include <iostream>
#include <string>
#include <unordered_map>

void displayMainMenu();  // 메인 메뉴를 표시하는 함수
void displayRegionMenu();  // 지역 메뉴를 표시하는 함수
void displayTourismMenu(const std::string& region_name);  // 관광 정보 메뉴를 표시하는 함수

// 선택한 번호에 해당하는 지역명을 반환하는 함수
std::string getRegionName(const std::string& choice) {
    const std::unordered_map<std::string, std::string> regions = {
        {"1", "서울"}, {"2", "경기/인천"}, {"3", "강원"}, {"4", "충청/대전/세종"},
        {"5", "전라/광주"}, {"6", "경남/부산/울산"}, {"7", "경북/대구"}, {"8", "제주"}
    };
    if (regions.find(choice) != regions.end()) {
        return regions.at(choice);
    }
    return "";  // 찾지 못한 경우 빈 문자열 반환
}

int main() {
    std::string input;
    DB db;  // DB 클래스가 모든 필요한 메서드를 가지고 있다고 가정
    std::unique_ptr<sql::Connection> conn = db.Connect();  // DB에 연결

    while (true) {
        displayMainMenu();  // 메인 메뉴 표시
        std::getline(std::cin, input);  // 사용자 입력 받기

        if (input == "3") {  // 종료 선택 시
            std::cout << "\n프로그램을 종료합니다.\n";
            break;
        } else if (input == "1") {  // 지역 메뉴 선택 시
            while (true) {
                displayRegionMenu();  // 지역 메뉴 표시
                std::getline(std::cin, input);  // 사용자 입력 받기
                if (input == "9") break;  // 뒤로 가기 선택 시

                std::string region_name = getRegionName(input);  // 선택한 번호에 해당하는 지역명 가져오기
                if (!region_name.empty()) {  // 유효한 지역명인 경우
                    while (true) {
                        displayTourismMenu(region_name);  // 관광 정보 메뉴 표시
                        std::getline(std::cin, input);  // 사용자 입력 받기

                        if (input == "3") break;  // 뒤로 가기 선택 시
                        else if (input == "1" || input == "2") {  // 관광지 정보 또는 축제 정보 선택 시
                            auto regionIDs = db.regionToTDID(conn, region_name);  // 지역명에 해당하는 ID 가져오기
                            for (int id : *regionIDs) {  // 모든 ID에 대해 반복
                                auto rowTasks = db.sendRowTasks(conn, "TD", id);  // 해당 ID의 정보 가져오기
                                for (const auto& task : *rowTasks) {  // 모든 정보에 대해 반복하여 출력
                                    std::cout << task << std::endl;
                                }
                                delete rowTasks;  // 할당된 메모리 해제
                            }
                            delete regionIDs;  // 할당된 메모리 해제
                            std::cout << (input == "1" ? "관광지 정보 출력 완료.\n" : "축제 정보 출력 완료.\n");  // 작업 완료 메시지 출력
                        } else {  // 잘못된 선택인 경우
                            std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
                        }
                    }
                } else {  // 잘못된 선택인 경우
                    std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
                }
            }
        } else if (input == "2") {  // 즐겨찾기 메뉴 선택 시
            std::cout << "즐겨찾기 기능을 구현합니다.\n";
            // 즐겨찾기 기능 구현
        } else {  // 잘못된 선택인 경우
            std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
        }
    }
    return 0;
}

// 메인 메뉴 표시 함수
void displayMainMenu() {
    std::cout << "\n*** 관광 정보 시스템 ***\n";
    std::cout << "1. 지역 보기\n";
    std::cout << "2. 즐겨찾기\n";
    std::cout << "3. 종료\n";
    std::cout << "선택: ";
}

// 지역 메뉴 표시 함수
void displayRegionMenu() {
    std::cout << "\n--- 지역 목록 ---\n";
    std::cout << "1. 서울\n";
    std::cout << "2. 경기/인천\n";
    std::cout << "3. 강원\n";
    std::cout << "4. 충청/대전/세종\n";
    std::cout << "5. 전라/광주\n";
    std::cout << "6. 경남/부산/울산\n";
    std::cout << "7. 경북/대구\n";
    std::cout << "8. 제주\n";
    std::cout << "9. 뒤로가기\n";
    std::cout << "지역 선택: ";
}

// 관광 정보 메뉴 표시 함수
void displayTourismMenu(const std::string& region_name) {
    std::cout << "\n** " << region_name << " 지역 관광 정보 시스템 **\n";
    std::cout << "1. 관광지 정보\n";
    std::cout << "2. 축제 정보\n";
    std::cout << "3. 뒤로가기\n";
    std::cout << "선택: ";
}