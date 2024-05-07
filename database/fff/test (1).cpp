#include "DB.h"
#include <unordered_map>

void displayMainMenu();
void displayRegionMenu();
void displayTourismMenu(const std::string &region_name);

std::string getRegionName(const std::string &choice)
{
    const std::unordered_map<std::string, std::string> regions = {
        {"1", "서울"}, {"2", "부산"}, {"3", "대구"}, {"4", "인천"}, {"5", "광주"}, {"6", "대전"}, {"7", "울산"}, {"8", "세종"}, {"9", "경기"}, {"10", "강원"}, {"11", "충북"}, {"12", "충남"}, {"13", "전북"}, {"14", "전남"}, {"15", "경북"}, {"16", "경남"}, {"17", "제주"}, {"18", "뒤로가기"}};
    if (regions.find(choice) != regions.end())
    {
        return regions.at(choice);
    }
    return ""; // 찾지 못한 경우 빈 문자열 반환
}

int main()
{
    std::string input;
    DB db;
    auto conn = db.Connect(); // DB에 연결

    while (true)
    {
        displayMainMenu();
        std::getline(std::cin, input);

        if (input == "3")
        {
            std::cout << "\n프로그램을 종료합니다.\n";
            break;
        }
        else if (input == "1")
        {
            while (true)
            {
                displayRegionMenu();
                std::getline(std::cin, input);
                if (input == "18")
                    break;

                std::string region_name = getRegionName(input);
                if (!region_name.empty())
                {
                    while (true)
                    {
                        displayTourismMenu(region_name);
                        std::getline(std::cin, input);

                        if (input == "3")
                            break;
                        else if (input == "1" || input == "2")
                        {
                            auto regionIDs = db.regionToTDID(conn, region_name);
                            for (int id : *regionIDs)
                            {
                                auto rowTasks = db.sendRowTasks(conn, "TD", id);
                                for (const auto &task : *rowTasks)
                                {
                                    std::cout << task << std::endl;
                                }
                            }
                            std::cout << (input == "1" ? "관광지 정보 출력 완료.\n" : "축제 정보 출력 완료.\n");
                        }
                        else
                        {
                            std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
                        }
                    }
                }
                else
                {
                    std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
                }
            }
        }
        else if (input == "2")
        {
            std::cout << "즐겨찾기 기능을 구현합니다.\n";
        }
        else
        {
            std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
        }
    }
    return 0;
}

// 메인 메뉴 표시 함수
void displayMainMenu()
{
    std::cout << "\n*** 관광 정보 시스템 ***\n";
    std::cout << "1. 지역 보기\n";
    std::cout << "2. 즐겨찾기\n";
    std::cout << "3. 종료\n";
    std::cout << "선택: ";
}

// 지역 메뉴 표시 함수
void displayRegionMenu()
{
    std::cout << "\n--- 지역 목록 ---\n";
    std::cout << "1. 서울\n";
    std::cout << "2. 부산\n";
    std::cout << "3. 대구\n";
    std::cout << "4. 인천\n";
    std::cout << "5. 광주\n";
    std::cout << "6. 대전\n";
    std::cout << "7. 울산\n";
    std::cout << "8. 세종\n";
    std::cout << "9. 경기\n";
    std::cout << "10. 강원\n";
    std::cout << "11. 충북\n";
    std::cout << "12. 충남\n";
    std::cout << "13. 전북\n";
    std::cout << "14. 전남\n";
    std::cout << "15. 경북\n";
    std::cout << "16. 경남\n";
    std::cout << "17. 제주\n";
    std::cout << "18. 뒤로가기\n";
    std::cout << "지역 선택: ";
}

// 관광 정보 메뉴 표시 함수
void displayTourismMenu(const std::string &region_name)
{
    std::cout << "\n** " << region_name << " 지역 관광 정보 시스템 **\n";
    std::cout << "1. 관광지 정보\n";
    std::cout << "2. 축제 정보\n";
    std::cout << "3. 뒤로가기\n";
    std::cout << "선택: ";
}