#include "DB.h"
#include "CF.h"
#include <unordered_map>
#include <iostream>

void displayMainMenu();
void displayRegionMenu();
void displayTourismMenu(const std::string& region_name);
std::string getRegionName(const std::string& choice) {
    const std::unordered_map<std::string, std::string> regions = {
        {"1", "서울"}, {"2", "부산"}, {"3", "대구"}, {"4", "인천"},
        {"5", "광주"}, {"6", "대전"}, {"7", "울산"}, {"8", "세종"},
        {"9", "경기"}, {"10", "강원"}, {"11", "충북"}, {"12", "충남"},
        {"13", "전북"}, {"14", "전남"}, {"15", "경북"}, {"16", "경남"},
        {"17", "제주"}, {"18", "뒤로가기"}
    };
    if (regions.find(choice) != regions.end()) {
        return regions.at(choice);
    }
    return ""; // 찾지 못한 경우 빈 문자열 반환
}
void processRegion(DB& db, std::unique_ptr<sql::Connection>& conn, const std::string& region_name, CFavorites& favorites);
void showTourismDetails(std::unique_ptr<sql::Connection>& conn, int id, DB& db, CFavorites& favorites);
void manageFavorites(CFavorites& favorites, DB& db, std::unique_ptr<sql::Connection>& conn);

int main() {
    std::string input;
    DB db;
    auto conn = db.Connect(); // DB 연결
    CFavorites favorites; // 즐겨찾기 객체

    while (true) {
        displayMainMenu();
        std::getline(std::cin, input);

        if (input == "3") {
            std::cout << "\n프로그램을 종료합니다.\n";
            break;
        } else if (input == "1") {
            while (true) {
                displayRegionMenu();
                std::getline(std::cin, input);
                if (input == "18") break;

                std::string region_name = getRegionName(input);
                if (!region_name.empty()) {
                    processRegion(db, conn, region_name, favorites);
                } else {
                    std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
                }
            }
        } else if (input == "2") {
            std::cout << "즐겨찾기 메뉴입니다.\n";
            manageFavorites(favorites, db, conn);
        } else {
            std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
        }
    }
    return 0;
}

void manageFavorites(CFavorites& favorites, DB& db, std::unique_ptr<sql::Connection>& conn) {
    int id = favorites.favoritemenu();
    if (id != -1) {
        // Fetch details for the selected ID from the database
        auto details = db.sendRowTasks(conn, "TD", id);
        if (!details->empty()) {
            std::cout << "즐겨찾기 상세 정보:\n";
            std::cout << "관광지명: " << (*details)[1] << "\n";   // Index assumes '1' is the name
            std::cout << "주소: " << (*details)[3] << "\n";       // Index assumes '3' is the address
            std::cout << "전화번호: " << (*details)[4] << "\n";   // Index assumes '4' is the phone number
        } else {
            std::cout << "선택한 즐겨찾기에 대한 정보를 찾을 수 없습니다.\n";
        }
        delete details; // Make sure to clean up
    } else {
        std::cout << "즐겨찾기 선택이 취소되었습니다.\n";
    }
}


void displayMainMenu() {
    std::cout << "\n*** 관광 정보 시스템 ***\n";
    std::cout << "1. 지역 보기\n";
    std::cout << "2. 즐겨찾기\n";
    std::cout << "3. 종료\n";
    std::cout << "선택: ";
}

void displayRegionMenu() {
    std::cout << "\n--- 지역 목록 ---\n";
    for (int i = 1; i <= 17; ++i) {
        std::cout << i << ". " << getRegionName(std::to_string(i)) << "\n";
    }
    std::cout << "18. 뒤로 가기\n";
    std::cout << "지역을 선택하세요: ";
}

void displayTourismMenu(const std::string& region_name) {
    std::cout << "\n** " << region_name << " 관광 정보 시스템 **\n";
    std::cout << "1. 관광 정보\n";
    std::cout << "2. 즐겨찾기 등록\n"; // 새로운 옵션 추가
    std::cout << "3. 뒤로 가기\n";
    std::cout << "선택: ";
}

void processRegion(DB& db, std::unique_ptr<sql::Connection>& conn, const std::string& region_name, CFavorites& favorites) {
    std::string input;
    while (true) {
        displayTourismMenu(region_name);
        std::getline(std::cin, input);

        if (input == "3") break;
        else if (input == "1") {
            auto regionIDs = db.regionToTDID(conn, region_name);
            for (int id : *regionIDs) {
                showTourismDetails(conn, id, db, favorites);
            }
            std::cout << "관광 정보 표시 완료.\n";
        } else if (input == "2") {
            std::cout << "번호 입력: ";
            std::getline(std::cin, input);
            int id = std::stoi(input);
            favorites.addFavoriteFromID(id, db, conn); // 즐겨찾기 등록 함수
            // std::cout << "즐겨찾기에 추가되었습니다.\n";
        } else {
            std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
        }
    }
}

void showTourismDetails(std::unique_ptr<sql::Connection>& conn, int id, DB& db, CFavorites& favorites) {
    // Fetch and display tourism details
    auto details = db.sendRowTasks(conn, "TD", id);
    if (details->size() >= 9) {
        std::cout << "즐겨찾기 코드: " << (*details)[0] << "\n";
        std::cout << "관광지명: " << (*details)[1] << "\n";
        std::cout << "주소: " << (*details)[3] << "\n";
        std::cout << "전화번호: " << (*details)[4] << "\n";

        std::vector<std::string>* fesDetails = db.sendRowTasks(conn, "FES", std::stoi((*details)[7]));
            if (fesDetails->size() >= 5) {
                std::cout << "축제명: " << (*fesDetails)[1] << "\n";                                        
                std::cout << "축제 시작일: " << (*fesDetails)[3] << "\n";
                std::cout << "축제 종료일: " << (*fesDetails)[4] << "\n";
            }
            delete fesDetails;

            // Fetching accident details
            std::vector<std::string>* accDetails = db.sendRowTasks(conn, "ACC", std::stoi((*details)[5]));
            if (accDetails->size() >= 5) {
                std::cout << "사고 이름: " << (*accDetails)[2] << "\n";
                std::cout << "사고 발생 횟수: " << (*accDetails)[3] << "\n";
                std::cout << "사고 관련 정보: " << (*accDetails)[4] << "\n";
            }
            delete accDetails;

            // 권역 응급병원
            std::vector<std::string>* medDetails = db.sendRowTasks(conn, "MED", std::stoi((*details)[6]));
            if (medDetails->size() >= 4) {
                std::cout << "권역응급병원: " << (*medDetails)[1] << "\n";
                std::cout << "주소: " << (*medDetails)[2] << "\n";
                std::cout << "전화번호: " << (*medDetails)[3] << "\n";
                
            }
            delete medDetails;

            //약국 정보
            std::vector<std::string>* phaDetails = db.sendRowTasks(conn, "PHA", std::stoi((*details)[8]));
            if (phaDetails->size() >= 4) {
                std::cout << "약국: " << (*phaDetails)[1] << "\n";
                std::cout << "주소: " << (*phaDetails)[2] << "\n";
                std::cout << "전화번호: " << (*phaDetails)[3] << "\n\n";
                
            }
            delete phaDetails;
        }
        delete details;
}
