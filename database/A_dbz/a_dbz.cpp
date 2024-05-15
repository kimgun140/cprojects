#include"a_dbz.h"

int main()
{
    something gggg;
    auto conn = gggg.connect(); //  디비 연결
    std::vector<something::history_search> qwe;
    std::vector<something::history_search> abc;
    std::string input;
    std::string input2;
    std::string where;
    std::string name;
    int choice2;
    int choice;
    gggg.Show_Location(conn);

    while (1)
    {
        std::cout << "[전라북도]관광 정보 알림이" << std::endl;
        std::cout << "1. 전북지역 특산물 리스트 출력" << std::endl;
        std::cout << "2. 전북지역 관광지 출력" << std::endl;
        std::cout << "3. 전북지역 축제 출력" << std::endl;
        std::cout << "4. 캠핑장 검색 " << std::endl;
        std::cout << "5. 지역별 특산물 검색 " << std::endl;
        std::cout << "6. 축제유형 검색" << std::endl;
        std::cout << "7. 지역 캠핑장검색 " << std::endl;
        std::cout << "8. 지역,테마별 축제 검색 " << std::endl;
        std::cout << "9. 검색내역 " << std::endl;
        std::cin >> choice;

        if (choice == 1)
            // 특산물 전부 출력 체크 다 했음
            qwe.push_back(gggg.ShowProduct(conn)[0]);
        else if (choice == 2)
            // 관광지 전부 출력
            qwe.push_back(ShowtourSite(conn)[0]);
        else if (choice == 3)
            qwe.push_back(gggg.Show_Festival(conn)[0]);
        else if (choice == 4)
            qwe.push_back(gggg.ShowCamping(conn)[0]);
        else if (choice == 5)
        {
            std::cout << "지역별 특산물 검색입니다." << std::endl;
            std::cout << "검색할 지역을 입력해주세요" << std::endl;
            std::cin >> input;
            std::cout << std::endl;
            qwe.push_back(gggg.ShowProduct_Region(conn, input)[0]);
        }
        else if (choice == 6)
        {
            std::cout << "축제 유형검색입니다." << std::endl;
            std::cout << "검색할 축제테마를 입력해주세요" << std::endl;
            std::cin >> input;
            std::cout << std::endl;

            qwe.push_back(gggg.Show_Festival_Thema(conn, input)[0]);
        }
        else if (choice == 7)
        {
            std::cout << "지역별 캠핑장 검색입니다." << std::endl;
            std::cout << "검색할 지역을 입력해주세요" << std::endl;
            std::cin >> input;
            std::cout << std::endl;
            qwe.push_back(gggg.ShowCamping_Name(conn, input)[0]);
        }
        else if (choice == 8)
        {
            std::cout << "지역,테마별 축제검색입니다." << std::endl;
            std::cout << "검색할 지역을 입력해주세요" << std::endl;
            std::cin >> input;
            std::cout << std::endl;
            std::cout << "검색할 축제주제를 입력해주세요" << std::endl;

            std::cin >> input2;
            std::cout << std::endl;
            qwe.push_back(gggg.Show_Festival_Thema_Region(conn, input, input2)[0]);
        }
        else if (choice == 9)
        { // 검색기록 확인하기
            while (1)
            {
                std::cout << "검색기록 확인 창입니다.";
                gggg.history_setting(qwe);
                // 검색 기록 출력
                history_print(qwe);
                choice = 0;
                std::cout << "몇번기록을 조회할지 선택해주세요";
                std::cin >> choice2;
                // 검색기록으로 재검색하기
                // 검색 기록 30개중에 어떤거 할지 선택하기
                if (choice2 < 31)
                {
                    if (qwe[choice2 - 1].where == "" && qwe[choice2 + 1].table == "TOUR")
                    {
                        ShowtourSite(conn);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "" && qwe[choice2 + 1].table == "SPRODUCT")
                    {
                        gggg.ShowProduct(conn);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "" && qwe[choice2 + 1].table == "FESTIVAL")
                    {
                        gggg.Show_Festival(conn);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "" && qwe[choice2 + 1].table == "CAMPING")
                    {
                        gggg.ShowCamping(conn);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "NAME" && qwe[choice2 + 1].table == "SPRODUCT" && qwe[choice2 + 1].input == input)
                    {
                        gggg.ShowProduct_Region(conn, input);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "NAME" && qwe[choice2 + 1].table == "FESTIVAL" && qwe[choice2 + 1].input == input)
                    {
                        gggg.Show_Festival_Thema(conn, input);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "NAME" && qwe[choice2 + 1].table == "CAMPING" && qwe[choice2 + 1].input == input)
                    {
                        gggg.ShowCamping_Name(conn, input);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "NAME" && qwe[choice2 + 1].table == "FESTIVAL" && qwe[choice2 + 1].input == input && qwe[choice2 + 1].input2 == input2)
                    {
                        gggg.Show_Festival_Thema_Region(conn, input, input2);
                        break;
                    }
                }
                else
                    std::cout << "잘못된입력입니다 다시입력입니다. " << std::endl;
            }
        }
    }
}
