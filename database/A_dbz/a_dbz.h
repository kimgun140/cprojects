#include <iostream>
#include <mariadb/conncpp.hpp>
#include <ctime>
#include <vector>
// SELECT문 실행 함수 캠핑정보 출력
//mariadb -h 10.10.21.103 -u ADMIN -p1234
class something
{
private:
public:
    struct history_search
    {
        std::string table;
        std::string where;
        std::string input;
        std::string input2;
        int year;
        int mon;
        int day;
        int hour;
        int min;
        int sec;
    } hs;
    std::unique_ptr<sql::Connection> connect()
    {
        {
            try
            {
                // DB연결 객체 생성
                // DRIVER 객체 C++랑 연결하기 위한 객체
                // 연결을 맞아서 대화를 해주는 객체가 CONN이다
                sql::Driver *driver = sql::mariadb::get_driver_instance();
                // 연결할 DB의 특정 IP, DB를 정의
                sql::SQLString url("jdbc:mariadb://localhost:3306/dbz"); // 3306이 마리아 DB의 디폴트 PORT
                // 연결할 DB를 사용할 유저를 정의
                sql::Properties properties({{"user", "OPERATOR"}, {"password", "1234"}});
                // 객체에 값을 통하여 연결을 시도
                std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
                return conn;
            }
            catch (sql::SQLException &e)
            {
                std::cerr << "Error Connecting to MariaDB Platform: " << e.what() << std::endl;
                // 프로그램 비정상 종료
                return 0;
            }
        }
    }
    // 특산물 전부 출력
    std::vector<something::history_search> ShowProduct(std::unique_ptr<sql::Connection> &conn)
    {
        std::vector<something::history_search> qwe;
        something gggg;
        time_t timer = time(NULL);
        struct tm *t = localtime(&timer);
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery("select * from SPRODUCT;");
            // 반복문을 통해서 내부의 값을 반환
            while (res->next())
            {
                std::cout << "NO." << res->getInt(1) << std::endl;
                std::cout << " 지역: " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << " 특산물: " << res->getString(3) << std::endl;
                std::cout << " 정보: " << res->getString(4) << std::endl;

                std::cout << std::endl;
            }
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting dbz: " << e.what() << std::endl;
        }
        gggg.hs.table = "SPRODUCT";
        gggg.hs.input = "";
        gggg.hs.input2 = "";
        gggg.hs.where = "";
        gggg.hs.year = t->tm_year + 1900;
        gggg.hs.day = t->tm_mday;
        gggg.hs.mon = t->tm_mon + 1;
        gggg.hs.hour = t->tm_hour;
        gggg.hs.min = t->tm_min;
        gggg.hs.sec = t->tm_sec;
        qwe.push_back(gggg.hs);
        return qwe;
    }
    // 지역별 특산물 보기
    std::vector<something::history_search> ShowProduct_Region(std::unique_ptr<sql::Connection> &conn, std::string input)

    {
        std::vector<something::history_search> qwe;
        something gggg;
        time_t timer = time(NULL);
        struct tm *t = localtime(&timer);
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery("select * from SPRODUCT where NAME = '" + input + "';");
            // 반복문을 통해서 내부의 값을 반환
            std::cout << "-------------" << input << "지역 특산물 목록입니다.------------------ " << std::endl;
            while (res->next())
            {
                std::cout << "NO. " << res->getInt(1) << std::endl;
                std::cout << "지역: " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << "특산물: " << res->getString(3) << std::endl;
                std::cout << "정보: " << res->getString(4) << std::endl;
                // std::cout << ", INFO = " << res->getString(5) << std::endl;
                // std::cout << ", fee = " << res->getString(6) << std::endl;

                std::cout << std::endl;
            }
            std::cout << "-------------" << input << "지역 특산물 목록입니다.------------------ " << std::endl;

            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting dbz: " << e.what() << std::endl;
        }
        gggg.hs.table = "SPRODUCT";
        gggg.hs.input = input;
        gggg.hs.input2 = "";
        gggg.hs.where = "NAME";
        gggg.hs.year = t->tm_year + 1900;
        gggg.hs.day = t->tm_mday;
        gggg.hs.mon = t->tm_mon + 1;
        gggg.hs.hour = t->tm_hour;
        gggg.hs.min = t->tm_min;
        gggg.hs.sec = t->tm_sec;
        qwe.push_back(gggg.hs);
        return qwe;
    }
    // 테마별로 축제 조회하기
    std::vector<something::history_search> Show_Festival_Thema(std::unique_ptr<sql::Connection> &conn, std::string input)
    {
        std::vector<something::history_search> qwe;
        something gggg;
        time_t timer = time(NULL);
        struct tm *t = localtime(&timer);
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
            // 축제중 테마로 선택해서 조회
            sql::ResultSet *res = stmnt->executeQuery("select * from FESTIVAL where THEMA = '" + input + "';"); // 수정하셈 여기 부터 input 어떻게 넣을지
            // 반복문을 통해서 내부의 값을 반환
            std::cout << "-------------" << input << "주제 축제목록입니다.------------------ " << std::endl;

            while (res->next())
            {
                std::cout << "NO. " << res->getInt(1) << std::endl;
                std::cout << "이름: " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << "축제: " << res->getString(3) << std::endl;
                std::cout << "주제: " << res->getString(4) << std::endl;
                std::cout << "일시: " << res->getString(5) << std::endl;
                std::cout << "장소: " << res->getString(6) << std::endl;
                std::cout << "관광객수: " << res->getString(7) << std::endl;
                std::cout << "주최: " << res->getString(8) << std::endl;
                std::cout << std::endl;
            }
            std::cout << "-------------" << input << "주제 축제목록입니다.------------------ " << std::endl;

            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting dbz: " << e.what() << std::endl;
        }
        gggg.hs.table = "FESTIVAL";
        gggg.hs.input = input;
        gggg.hs.input2 = "";
        gggg.hs.where = "THEMA";
        gggg.hs.year = t->tm_year + 1900;
        gggg.hs.day = t->tm_mday;
        gggg.hs.mon = t->tm_mon + 1;
        gggg.hs.hour = t->tm_hour;
        gggg.hs.min = t->tm_min;
        gggg.hs.sec = t->tm_sec;
        qwe.push_back(gggg.hs);
        return qwe;
    }
    // 축제 전부 출력
    std::vector<something::history_search> Show_Festival(std::unique_ptr<sql::Connection> &conn)
    {
        std::vector<something::history_search> qwe;
        something gggg;
        time_t timer = time(NULL);
        struct tm *t = localtime(&timer);
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
            // 축제중 테마로 선택해서 조회
            sql::ResultSet *res = stmnt->executeQuery("select * from FESTIVAL;"); // 수정하셈 여기 부터 input 어떻게 넣을지
            // 반복문을 통해서 내부의 값을 반환
            std::cout << "------------- 전북지역 축제목록입니다.------------------ " << std::endl;

            while (res->next())
            {
                std::cout << "NO. " << res->getInt(1) << std::endl;
                std::cout << "주소: " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << "축제 이름:" << res->getString(3) << std::endl;
                std::cout << "주제: " << res->getString(4) << std::endl;
                std::cout << "축제 일시: " << res->getString(5) << std::endl;
                std::cout << "장소: " << res->getString(6) << std::endl;
                std::cout << "관광객수: " << res->getString(7) << std::endl;
                std::cout << "주최: " << res->getString(8) << std::endl;
                std::cout << std::endl;
            }
            std::cout << "------------- 전북지역 축제목록입니다.------------------ " << std::endl;

            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting dbz: " << e.what() << std::endl;
        }
        gggg.hs.table = "FESTIVAL";
        gggg.hs.input = "";
        gggg.hs.input2 = "";
        gggg.hs.where = "";
        gggg.hs.year = t->tm_year + 1900;
        gggg.hs.day = t->tm_mday;
        gggg.hs.mon = t->tm_mon + 1;
        gggg.hs.hour = t->tm_hour;
        gggg.hs.min = t->tm_min;
        gggg.hs.sec = t->tm_sec;
        qwe.push_back(gggg.hs);
        return qwe;
    }
    // 테마,지역별로 축제 조회하기
    std::vector<something::history_search> Show_Festival_Thema_Region(std::unique_ptr<sql::Connection> &conn, std::string input, std::string input2)
    {
        std::vector<something::history_search> qwe;
        something gggg;
        time_t timer = time(NULL);
        struct tm *t = localtime(&timer);
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
            // 축제중 테마로 선택해서 조회
            sql::ResultSet *res = stmnt->executeQuery("select * from FESTIVAL where THEMA = '" + input + "'and NAME = '" + input2 + " ';"); // 수정하셈 여기 부터 input 어떻게 넣을지
            // 반복문을 통해서 내부의 값을 반환
            std::cout << "-------------" << input << "지역" << input2 << "테마 축제목록입니다.------------------ " << std::endl;

            while (res->next())
            {
                std::cout << "NO. " << res->getInt(1) << std::endl;
                std::cout << "지역: " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << "축제: " << res->getString(3) << std::endl;
                std::cout << "주제: " << res->getString(4) << std::endl;
                std::cout << "일시: " << res->getString(5) << std::endl;
                std::cout << "장소: " << res->getString(6) << std::endl;
                std::cout << "관광객: " << res->getString(7) << std::endl;
                std::cout << "주최: " << res->getString(8) << std::endl;
                std::cout << std::endl;
            }
            std::cout << "-------------" << input << "지역" << input2 << "테마 축제목록입니다.------------------ " << std::endl;

            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting dbz: " << e.what() << std::endl;
        }
        gggg.hs.table = "FESTIVAL";
        gggg.hs.input = input;
        gggg.hs.input2 = input2;
        gggg.hs.where = "NAME";
        gggg.hs.year = t->tm_year + 1900;
        gggg.hs.day = t->tm_mday;
        gggg.hs.mon = t->tm_mon + 1;
        gggg.hs.hour = t->tm_hour;
        gggg.hs.min = t->tm_min;
        gggg.hs.sec = t->tm_sec;
        qwe.push_back(gggg.hs);
        return qwe;
    }
    // 캠핑장 다보기
    std::vector<something::history_search> ShowCamping(std::unique_ptr<sql::Connection> &conn)
    {
        std::vector<something::history_search> qwe;
        something gggg;
        time_t timer = time(NULL);
        struct tm *t = localtime(&timer);
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery("select * from CAMPING;");
            // 반복문을 통해서 내부의 값을 반환
            std::cout << "-----------------캠핑장리스트-----------------" << std::endl;
            while (res->next())
            {
                std::cout << "NO. " << res->getInt(1) << std::endl;
                std::cout << "지역: " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << "캠핑장: " << res->getString(3) << std::endl;
                std::cout << "주소: " << res->getString(4) << std::endl;
                std::cout << std::endl;
            }
            std::cout << "-----------------캠핑장리스트-----------------" << std::endl;

            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting dbz: " << e.what() << std::endl;
        }
        gggg.hs.table = "CAMPING";
        gggg.hs.input = "";
        gggg.hs.input2 = "";
        gggg.hs.where = "";
        gggg.hs.year = t->tm_year + 1900;
        gggg.hs.day = t->tm_mday;
        gggg.hs.mon = t->tm_mon + 1;
        gggg.hs.hour = t->tm_hour;
        gggg.hs.min = t->tm_min;
        gggg.hs.sec = t->tm_sec;
        qwe.push_back(gggg.hs);
        return qwe;
    }
    // 지역 보기
    void Show_Location(std::unique_ptr<sql::Connection> &conn)
    {
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery("select * from LOCATION;");
            // 반복문을 통해서 내부의 값을 반환
            std::cout << "-----------------지역리스트-----------------" << std::endl;
            while (res->next())
            {
                std::cout << res->getString(2) << std::endl; //  varchar는 getsting()으로
            }
            std::cout << "-----------------지역리스트-----------------" << std::endl;
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting dbz: " << e.what() << std::endl;
        }
    }
    // 지역별 캠핑장 목록 출력
    std::vector<something::history_search> ShowCamping_Name(std::unique_ptr<sql::Connection> &conn, std::string input)
    {
        std::vector<something::history_search> qwe;
        something gggg;
        time_t timer = time(NULL);
        struct tm *t = localtime(&timer);
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery("select * from CAMPING where NAME = '" + input + "';");
            // 반복문을 통해서 내부의 값을 반환
            std::cout << "-----------------" << input << "지역캠핑장리스트-----------------" << std::endl;

            while (res->next())
            {
                std::cout << "NO. " << res->getInt(1) << std::endl;
                std::cout << "지역: " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << "캠핑장: " << res->getString(3) << std::endl;
                std::cout << "주소: " << res->getString(4) << std::endl;
                std::cout << std::endl;
            }
            std::cout << "-----------------" << input << "지역캠핑장리스트-----------------" << std::endl;

            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting dbz: " << e.what() << std::endl;
        }
        gggg.hs.table = "CAMPING";
        gggg.hs.input = input;
        gggg.hs.input2 = "";
        gggg.hs.where = "NAME";
        gggg.hs.year = t->tm_year + 1900;
        gggg.hs.day = t->tm_mday;
        gggg.hs.mon = t->tm_mon + 1;
        gggg.hs.hour = t->tm_hour;
        gggg.hs.min = t->tm_min;
        gggg.hs.sec = t->tm_sec;
        qwe.push_back(gggg.hs);
        return qwe;
    }
    // 검색내역 30개만 남기기
    void history_setting(std::vector<something::history_search> qwe)
    {
        if (size(qwe) >= 30)
        {
            while (size(qwe) > 30)
            {
                qwe.erase(qwe.begin());
            }
        }
    }
};
// 관광지 전부 출력
std::vector<something::history_search> ShowtourSite(std::unique_ptr<sql::Connection> &conn)
{
    std::vector<something::history_search> qwe;
    something gggg;
    time_t timer = time(NULL);
    struct tm *t = localtime(&timer);

    try
    {
        // createStaemet 객체 생성
        std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
        // 쿼리를 실행
        sql::ResultSet *res = stmnt->executeQuery("select * from TOUR");
        // 반복문을 통해서 내부의 값을 반환
        while (res->next())
        {
            std::cout << " 지역: " << res->getString(2) << std::endl; //  varchar는 getsting()으로
            std::cout << " 관광지: " << res->getString(3) << std::endl;
            std::cout << " 주소: " << res->getString(4) << std::endl;
            std::cout << " 정보: " << res->getString(5) << std::endl;
            std::cout << " 입장료: " << res->getString(6) << std::endl;

            std::cout << std::endl;
        }
        // 실패시 오류 메세지 반환
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error selecting dbz: " << e.what() << std::endl;
    }
    gggg.hs.table = "TOUR";
    gggg.hs.input = "";
    gggg.hs.input2 = "";
    gggg.hs.where = "";
    gggg.hs.year = t->tm_year + 1900;
    gggg.hs.day = t->tm_mday;
    gggg.hs.mon = t->tm_mon + 1;
    gggg.hs.hour = t->tm_hour;
    gggg.hs.min = t->tm_min;
    gggg.hs.sec = t->tm_sec;
    qwe.push_back(gggg.hs);
    return qwe;
}

// 축제 테이블에서 선택지역 축제만 출력
void Show_Festival_Region(std::unique_ptr<sql::Connection> &conn, std::string input)
{
    try
    {
        // createStaemet 객체 생성
        std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
        // 쿼리를 실행
        sql::ResultSet *res = stmnt->executeQuery("select * from FESTIVAL where NAME = '" + input + "';"); // 수정하셈 여기 부터 input 어떻게 넣을지
        // 반복문을 통해서 내부의 값을 반환
        while (res->next())
        {
            std::cout << "CID = " << res->getInt(1) << std::endl;
            std::cout << ", NAME = " << res->getString(2) << std::endl; //  varchar는 getsting()으로
            std::cout << ", F_NAME = " << res->getString(3) << std::endl;
            std::cout << ", THEMA = " << res->getString(4) << std::endl;
            std::cout << ", DATE = " << res->getString(5) << std::endl;
            std::cout << ", FLOC = " << res->getString(6) << std::endl;
            std::cout << ", COUNT = " << res->getString(7) << std::endl;
            std::cout << ", ORGAN = " << res->getString(8) << std::endl;
            std::cout << std::endl;
        }
        // 실패시 오류 메세지 반환
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error selecting dbz: " << e.what() << std::endl;
    }
}


// 검색 기록 출력
void history_print(std::vector<something::history_search> qwe)
{
    // 오케이 검색 목록 출력 완료
    for (int i = 0; i < size(qwe) - 1; i++)
    {
        std::cout << i + 1 << "번째 검색기록" << std::endl;
        if (qwe[i].table == "CAMPING")
            std::cout << "캠핑장" << std::endl;
        else if (qwe[i].table == "FESTIVAL")
            std::cout << "축제" << std::endl;
        else if (qwe[i].table == "SPRODUCT")
            std::cout << "특산물" << std::endl;
        else if (qwe[i].table == "TOUR")
            std::cout << "관광지" << std::endl;
        if (qwe[i].where != ""){
            std::cout << "지역: ";
            std::cout << qwe[i].where << std::endl;
            
        }
        if (qwe[i].input != "")
            std::cout << qwe[i].input << std::endl;
        if (qwe[i].input2 != "")
            std::cout << qwe[i].input2 << std::endl;
        std::cout << "검색일시";
        std::cout << qwe[i].year << "/";
        std::cout << qwe[i].mon << "/";
        std::cout << qwe[i].day << "/";
        std::cout << qwe[i].hour << ".";
        std::cout << qwe[i].min << ".";
        std::cout << qwe[i].sec << ""<< std::endl;
        std::cout << std::endl;
    }
}
