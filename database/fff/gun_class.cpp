#include "DB.h"
class gg
{
public:
    struct tourPointinfo
    {
        std::string id;
        std::string Name;
        std::string Region;
        std::string Addr;
        std::string PhoneNumber;
        std::string AccId;
        std::string MedId;
        std::string FesId;
        std::string PhaId;
        struct Fes;
    } tp;
    struct Fes
    {
        std::string FesId;
        std::string FesName;
        std::string FesRegion;
        std::string FesStart;
        std::string FesEnd;
    } fes;

    std::vector<tourPointinfo> gunturn12(std::string input)
    // 관광지 출력하고 벡터에 반환하는 함수
    {

        gg asdf;
        std::vector<tourPointinfo> www;
        try
        {
            DB pj05;

            std::unique_ptr<sql::Connection> conn = pj05.Connect();
            std::vector<int> *k = pj05.regionToTDID(conn, input);
            std::vector<int>::iterator iter0;
            for (iter0 = k->begin(); iter0 != k->end(); iter0++)
            {
                std::vector<std::string> *temp = pj05.sendRowTasks(conn, "TD", *iter0);
                std::vector<std::string>::iterator iter;

                std::vector<std::string> gun = *temp;
                // 값을 넣어주기
                for (int i = 0; i < size(gun); i++)
                {
                    if (i == 0)
                        asdf.tp.id = gun[i];
                    else if (i == 1)
                        asdf.tp.Name = gun[i];
                    else if (i == 2)
                        asdf.tp.Region = gun[i];
                    else if (i == 3)
                        asdf.tp.Addr = gun[i];
                    else if (i == 4)
                        asdf.tp.PhoneNumber = gun[i];
                    else if (i == 5)
                        asdf.tp.AccId = gun[i];
                    else if (i == 6)
                        asdf.tp.MedId = gun[i];
                    else if (i == 7)
                        asdf.tp.FesId = gun[i];
                    else if (i == 8)
                        asdf.tp.PhaId = gun[i];
                }
                www.push_back(asdf.tp);
            }
            // 출력문 : 반복될때마다 출력
            // std::cout << asdf.tp.id << std::endl;
            // std::cout << asdf.tp.Name << std::endl;
            // std::cout << asdf.tp.Region << std::endl;
            // std::cout << asdf.tp.Addr << std::endl;
            // std::cout << asdf.tp.PhoneNumber << std::endl;
            // std::cout << asdf.tp.AccId << std::endl;
            // std::cout << asdf.tp.MedId << std::endl;
            // std::cout << asdf.tp.FesId << std::endl;
            // 출력문 반복될 때 마다 벡터의 마지막 부분을 출력해서 확인
            // std::cout << www[size(www) - 1].id << std::endl;
            // std::cout << www[size(www) - 1].Name << std::endl;
            // std::cout << www[size(www) - 1].Region << std::endl;
            // std::cout << www[size(www) - 1].Addr << std::endl;
            // std::cout << www[size(www) - 1].PhoneNumber << std::endl;
            // std::cout << www[size(www) - 1].AccId << std::endl;
            // std::cout << www[size(www) - 1].MedId << std::endl;
            // std::cout << www[size(www) - 1].FesId << std::endl;
            // std::cout << www[size(www) - 1].PhaId << std::endl;
            // 연결 실패시 오류 발생
            return www;
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error on DB class: " << e.what() << std::endl;
            // 프로그램 비정상 종료
            // return 1;
        }
        return www;
    }
    std::vector<tourPointinfo> gunturn_FESTIVAL(std::string input)
    // 축제 출력하고 벡터에 반환하는 함수
    {

        gg asdf;
        std::vector<tourPointinfo> www;
        std::vector<Fes> ppp;

        try
        {
            DB pj05;

            std::unique_ptr<sql::Connection> conn = pj05.Connect();
            std::vector<int> *k = pj05.regionToTDID(conn, input);
            std::vector<int>::iterator iter0;
            for (iter0 = k->begin(); iter0 != k->end(); iter0++)
            {
                std::vector<std::string> *temp = pj05.sendRowTasks(conn, "FES", *iter0);
                std::vector<std::string>::iterator iter;

                std::vector<std::string> gun = *temp;
                // 값을 넣어주기
                for (int i = 0; i < size(gun); i++)
                {
                    if (i == 0)
                        asdf.fes.FesId = gun[i];
                    else if (i == 1)
                        asdf.fes.FesName = gun[i];
                    else if (i == 2)
                        asdf.fes.FesRegion = gun[i];
                    else if (i == 3)
                        asdf.fes.FesStart = gun[i];
                    else if (i == 4)
                        asdf.fes.FesEnd = gun[i];
                }
                ppp.push_back(asdf.fes);
            }
            // 출력문 : 반복될때마다 출력
            // std::cout << asdf.tp.id << std::endl;
            // std::cout << asdf.tp.Name << std::endl;
            // std::cout << asdf.tp.Region << std::endl;
            // std::cout << asdf.tp.Addr << std::endl;
            // std::cout << asdf.tp.PhoneNumber << std::endl;
            // std::cout << asdf.tp.AccId << std::endl;
            // std::cout << asdf.tp.MedId << std::endl;
            // std::cout << asdf.tp.FesId << std::endl;
            // 출력문 반복될 때 마다 벡터의 마지막 부분을 출력해서 확인
            // std::cout << www[size(www) - 1].id << std::endl;
            // std::cout << www[size(www) - 1].Name << std::endl;
            // std::cout << www[size(www) - 1].Region << std::endl;
            // std::cout << www[size(www) - 1].Addr << std::endl;
            // std::cout << www[size(www) - 1].PhoneNumber << std::endl;
            // std::cout << www[size(www) - 1].AccId << std::endl;
            // std::cout << www[size(www) - 1].MedId << std::endl;
            // std::cout << www[size(www) - 1].FesId << std::endl;
            // std::cout << www[size(www) - 1].PhaId << std::endl;
            // 연결 실패시 오류 발생
            return www;
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error on DB class: " << e.what() << std::endl;
            // 프로그램 비정상 종료
            // return 1;
        }
        return www;
    }
    void gun_print(std::vector<gg::tourPointinfo> www)
    // guntrun12에서 나온 백터를를 넣어 주면  관광지 데이터 출력됨
    // 관광지 출력
    {
        for (int i = 0; i < size(www); i++)
        {
            std::cout << std::endl;
            std::cout << www[i].Name << std::endl;
            std::cout << www[i].Region << std::endl;
            std::cout << www[i].Addr << std::endl;
            std::cout << www[i].PhoneNumber << std::endl;
        }
    }
};

// int main()
// {

//     gg asdf;

//     std::vector<gg::tourPointinfo> rrr;

//     std::string input;
//     std::string input_region;
//     std::string input_place;
//     std::string input_medical;
//     std::string input_festival;

//     while (true)
//     {
//         std::cout << "\n*** 관광 정보 시스템 ***\n";
//         std::cout << "1. 지역 보기\n";
//         std::cout << "2. 즐겨찾기\n";
//         std::cout << "3. 종료\n";
//         std::cout << "선택: ";
//         std::getline(std::cin, input);

//         if (input == "3")
//         {
//             std::cout << "\n프로그램을 종료합니다.\n";
//             break;
//         }
//         else if (input == "1")
//         {
//             while (true)
//             {
//                 std::cout << "\n--- 지역 목록 ---\n";
//                 std::cout << "1. 서울\n";
//                 std::cout << "2. 경기\n";
//                 std::cout << "3. 강원\n";
//                 std::cout << "4. 충청\n";
//                 std::cout << "5. 전라\n";
//                 std::cout << "6. 경남\n";
//                 std::cout << "7. 경북\n";
//                 std::cout << "8. 제주\n";
//                 std::cout << "9. 뒤로가기\n";
//                 std::cout << "지역 선택: ";
//                 std::getline(std::cin, input);
//                 // 묵여있는 것들을 같이 출력하려면 함수를 두번 실행 시키기 "경기"한번, "인천" 두번
//                 // 서울 받으면 관광지

//                 input_region = input;

//                 std::string region_name;
//                 if (input == "1")
//                 {
//                     region_name = "서울";
//                 }
//                 else if (input == "2")
//                 {
//                     region_name = "경기";
//                 }
//                 else if (input == "3")
//                 {
//                     region_name = "강원";
//                 }
//                 else if (input == "4")
//                 {
//                     region_name = "충청";
//                 }
//                 else if (input == "5")
//                 {
//                     region_name = "전라";
//                 }
//                 else if (input == "6")
//                 {
//                     region_name = "경남";
//                 }
//                 else if (input == "7")
//                 {
//                     region_name = "경북";
//                 }
//                 else if (input == "8")
//                 {
//                     region_name = "제주";
//                 }
//                 else if (input == "9")
//                 {
//                     break;
//                 }
//                 else
//                 {
//                     std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
//                     continue;
//                 }

//                 std::cout << "\n** " << region_name << " 지역 관광 정보 시스템 **\n";
//                 while (true)
//                 {
//                     std::cout << "1. 관광지 정보\n";
//                     std::cout << "2. 축제 정보\n";
//                     std::cout << "3. 뒤로가기\n";
//                     std::cout << "선택: ";
//                     std::getline(std::cin, input);
//                     input_place = input;
//                     if (input == "3")
//                     {
//                         break; // 뒤로가기 선택 시 지역 선택 메뉴로 복귀
//                     }
//                     else if (input == "1" || input == "2")
//                     {
//                         std::cout << (input == "1" ? "관광지 정보를 출력합니다.\n" : "축제 정보를 출력합니다.\n");
//                         rrr = asdf.gunturn12(region_name);
//                         asdf.gun_print(rrr);

//                         // 관광지 또는 축제 정보 출력 함수 호출
//                         input_festival = input;
//                     }
//                     else
//                     {
//                         std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
//                     }
//                 }
//             }
//         }
//         else if (input == "2")
//         {
//             std::cout << "즐겨찾기 기능을 구현합니다.\n";
//             // 즐겨찾기 기능 관련 코드
//         }
//         else
//         {
//             std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
//         }
//     }
//     return 0;
// }