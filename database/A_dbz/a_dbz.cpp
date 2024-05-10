#include <iostream>
#include <mariadb/conncpp.hpp>
#include <ctime>
#include <vector>
// SELECT문 실행 함수 캠핑정보 출력

class something
{
private:
public:
    struct camping
    {
        int CID;
        std::string NAME;
        std::string C_NAME;
        std::string ADDRESS;
        std::string keyword;
        int year;
        int mon;
        int day;
        int hour;
        int min;
        int sec;
        std::string table;
        std::string where;
        std::string input;

    } cp;
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
    struct table_where_input
    {
    };
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
                std::cout << "CID = " << res->getInt(1) << std::endl;
                std::cout << ", NAME = " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << ", T_NAME = " << res->getString(3) << std::endl;
                std::cout << ", ADDRESS = " << res->getString(4) << std::endl;
                std::cout << ", INFO = " << res->getString(5) << std::endl;
                std::cout << ", fee = " << res->getString(6) << std::endl;

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
            while (res->next())
            {
                std::cout << "CID = " << res->getInt(1) << std::endl;
                std::cout << ", NAME = " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << ", P_NAME = " << res->getString(3) << std::endl;
                std::cout << ", INFO = " << res->getString(4) << std::endl;
                // std::cout << ", INFO = " << res->getString(5) << std::endl;
                // std::cout << ", fee = " << res->getString(6) << std::endl;

                std::cout << std::endl;
            }
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
            while (res->next())
            {
                std::cout << "CID = " << res->getInt(1) << std::endl;
                std::cout << ", NAME = " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << ", C_NAME = " << res->getString(3) << std::endl;
                std::cout << ", ADDRESS = " << res->getString(4) << std::endl;
                std::cout << std::endl;
            }
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
            while (res->next())
            {
                // std::cout << "ID = " << res->getInt(1) << std::endl;
                std::cout << res->getString(2) << std::endl; //  varchar는 getsting()으로
                // std::cout << ", C_NAME = " << res->getString(3) << std::endl;
                // std::cout << ", ADDRESS = " << res->getString(4) << std::endl;
                // std::cout << std::endl;
            }
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
            while (res->next())
            {
                std::cout << "CID = " << res->getInt(1) << std::endl;
                std::cout << ", NAME = " << res->getString(2) << std::endl; //  varchar는 getsting()으로
                std::cout << ", C_NAME = " << res->getString(3) << std::endl;
                std::cout << ", ADDRESS = " << res->getString(4) << std::endl;
                std::cout << std::endl;
            }
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
    void tt(std::vector<something::history_search> qwe)
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
// 검색 내역 저장하기
std::vector<something::history_search> ShowCamping(std::unique_ptr<sql::Connection> &conn, std::string input, std::string table, std::string where)
{
    something camp;
    std::vector<something::camping> bal;
    std::vector<something::history_search> serch;
    time_t timer = time(NULL);
    struct tm *t = localtime(&timer);
    table = "CAMPING";
    where = "NAME";

    try
    {
        // createStaemet 객체 생성
        std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
        // 쿼리를 실행
        sql::ResultSet *res = stmnt->executeQuery("select * from " + table + " where " + where + "= '" + input + "';");
        // 반복문을 통해서 내부의 값을 반환
        while (res->next())
        {
            // camp.cp.CID = res->getInt(1);
            // camp.cp.NAME = res->getString(2);
            // camp.cp.C_NAME = res->getString(3);
            // camp.cp.ADDRESS = res->getString(4);
            // camp.cp.keyword = input;
            // camp.cp.year = t->tm_year + 1900;
            // camp.cp.mon = t->tm_mon + 1;
            // camp.cp.day = t->tm_mday;
            // camp.cp.hour = t->tm_hour;
            // camp.cp.min = t->tm_min;
            // camp.cp.sec = t->tm_sec;
            // camp.hs.input = input;
            // camp.hs.table = table;
            // camp.hs.where = where;
            // bal.push_back(camp.cp);
            // std::cout << camp.cp.CID << std::endl;
            // std::cout << camp.cp.NAME << std::endl;
            // std::cout << camp.cp.C_NAME << std::endl;
            // std::cout << camp.cp.ADDRESS << std::endl;
            // std::cout << camp.cp.year << std::endl;
            // std::cout << camp.cp.mon << std::endl;
            // std::cout << camp.cp.day << std::endl;
            // std::cout << camp.cp.hour << std::endl;
            // std::cout << camp.cp.min << std::endl;
            // std::cout << camp.cp.sec << std::endl;
            // std::cout<< res->getInt(1);
            // std::cout<< res->getString(2);
            // std::cout<< res->getString(3);
            // std::cout<< res->getString(4);
            // std::cout<< res->getString(5);

            // std::cout << bal[size(bal) - 1].CID << std::endl;
            // std::cout << bal[size(bal) - 1].NAME << std::endl;
            // std::cout << bal[size(bal) - 1].C_NAME << std::endl;
            // std::cout << bal[size(bal) - 1].ADDRESS << std::endl;
            // // std::cout << bal[size(bal) - 1].keyword << std::endl;
            // std::cout << bal[size(bal) - 1].year << std::endl;
            // std::cout << bal[size(bal) - 1].mon << std::endl;
            // std::cout << bal[size(bal) - 1].day << std::endl;
            // std::cout << bal[size(bal) - 1].hour << std::endl;
            // std::cout << bal[size(bal) - 1].min << std::endl;
            // std::cout << bal[size(bal) - 1].sec << std::endl;
        }
        camp.hs.input = input;
        camp.hs.where = where;
        camp.hs.table = table;
        camp.hs.year = t->tm_year + 1900;
        camp.hs.mon = t->tm_mon + 1;
        camp.hs.day = t->tm_mday;
        camp.hs.hour = t->tm_hour;
        camp.hs.min = t->tm_min;
        camp.hs.sec = t->tm_sec;
        serch.push_back(camp.hs);
        return serch;

        // 실패시 오류 메세지 반환
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error selecting dbz: " << e.what() << std::endl;
    }
}
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
            std::cout << ", NAME = " << res->getString(2) << std::endl; //  varchar는 getsting()으로
            std::cout << ", T_NAME = " << res->getString(3) << std::endl;
            std::cout << ", ADDRESS = " << res->getString(4) << std::endl;
            std::cout << ", INFO = " << res->getString(5) << std::endl;
            std::cout << ", fee = " << res->getString(6) << std::endl;

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
void history_search_TOUR(std::unique_ptr<sql::Connection> &conn, std::vector<something::history_search> h)
{
    // 여기서 다시 검색
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
            std::cout << "CID = " << res->getInt(1) << std::endl;
            std::cout << ", NAME = " << res->getString(2) << std::endl; //  varchar는 getsting()으로
            std::cout << ", T_NAME = " << res->getString(3) << std::endl;
            std::cout << ", ADDRESS = " << res->getString(4) << std::endl;
            std::cout << ", INFO = " << res->getString(5) << std::endl;
            std::cout << ", fee = " << res->getString(6) << std::endl;

            std::cout << std::endl;
        }
        // 실패시 오류 메세지 반환
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error selecting dbz: " << e.what() << std::endl;
    }
}
void qwe123(std::vector<something::history_search> qwe)
{
    // 오케이 검색 목록 출력 완료
    for (int i = 0; i < size(qwe) - 1; i++)
    {
        std::cout << i + 1 << "번째 검색";
        std::cout << qwe[i].table << std::endl;
        std::cout << qwe[i].where << std::endl;
        std::cout << qwe[i].input << std::endl;
        std::cout << qwe[i].input2 << std::endl;
        std::cout << "검색일시";
        std::cout << qwe[i].year << ".";
        std::cout << qwe[i].mon << ".";
        std::cout << qwe[i].day << ".";
        std::cout << qwe[i].hour << ".";
        std::cout << qwe[i].min << ".";
        std::cout << qwe[i].sec << ".";
    }
    // std::cout << bal[size(bal) - 1].year << std::endl;
    // std::cout << bal[size(bal) - 1].mon << std::endl;
    // std::cout << bal[size(bal) - 1].day << std::endl;
    // std::cout << bal[size(bal) - 1].hour << std::endl;
    // std::cout << bal[size(bal) - 1].min << std::endl;
    // std::cout << bal[size(bal) - 1].sec << std::endl;
}
// 검색 기록 30개만 남기기

int main()
{
    something gggg;
    auto conn = gggg.connect(); //  디비 연결
    std::vector<something::history_search> qwe;
    std::vector<something::history_search> abc;

    time_t timer = time(NULL);
    struct tm *t = localtime(&timer);
    gggg.hs.input;
    gggg.hs.table;
    gggg.hs.where;
    std::string input;
    std::string input2;

    std::string where;
    std::string name;
    int choice2;
    int choice;
    // std::cin >> input;
    // gggg.Show_Festival_Thema(conn,input);
    gggg.Show_Location(conn);

    while (1)
    {
        std::cout << "[전라북도]관광 정보 알림이" << std::endl;
        std::cout << "지역리스트" << std::endl;
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
            std::cin >> input2;
            std::cout << std::endl;
            qwe.push_back(gggg.Show_Festival_Thema_Region(conn, input, input2)[0]);
        }
        else if (choice == 9)
        { // 검색기록 확인하기
            while (1)
            {
                std::cout << "검색기록 확인 창입니다.";
                gggg.tt(qwe);
                // 검색 기록 출력
                qwe123(qwe);
                choice = 0;
                std::cout << "몇번기록을 조회할지 선택해주세요";
                std::cin >> choice2;
                // 검색기록으로 재검색하기
                // 검색 기록 30개중에 어떤거 할지 선택하기
                if (choice2 < 31)
                {
                    if (qwe[choice2 - 1].where == "" && qwe[choice2 + 1].table == "TOUR"){
                        ShowtourSite(conn);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "" && qwe[choice2 + 1].table == "SPRODUCT"){
                        gggg.ShowProduct(conn);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "" && qwe[choice2 + 1].table == "FESTIVAL"){
                        gggg.Show_Festival(conn);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "" && qwe[choice2 + 1].table == "CAMPING"){
                        gggg.ShowCamping(conn);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "NAME" && qwe[choice2 + 1].table == "SPRODUCT" && qwe[choice2 + 1].input == input){
                        gggg.ShowProduct_Region(conn, input);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "NAME" && qwe[choice2 + 1].table == "FESTIVAL" && qwe[choice2 + 1].input == input){
                        gggg.Show_Festival_Thema(conn, input);
                        break;
                    }
                    else if (qwe[choice2 - 1].where == "NAME" && qwe[choice2 + 1].table == "CAMPING" && qwe[choice2 + 1].input == input){
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

    // std::cout <<
}
