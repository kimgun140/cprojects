#include <iostream>
#include <mariadb/conncpp.hpp>
#include <ctime>
#include <vector>
std::unique_ptr<sql::Connection> Connect()
{
    try
    {
        // DB연결 객체 생성
        // DRIVER 객체 C++랑 연결하기 위한 객체
        // 연결을 맞아서 대화를 해주는 객체가 CONN이다
        sql::Driver *driver = sql::mariadb::get_driver_instance();
        // 연결할 DB의 특정 IP, DB를 정의
        // sql::SQLString url("jdbc:mariadb://10.10.21.103/BM"); // 3306이 마리아 DB의 디폴트 PORT
        // 연습용
        sql::SQLString url("jdbc:mariadb://localhost:3306/dbz"); // 3306이 마리아 DB의 디폴트 PORT

        // 연결할 DB를 사용할 유저를 정의
        // sql::Properties properties({{"user", "ADMIN"}, {"password", "1234"}});
        // 연습용
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

int main(){

 auto conn = Connect();
std:: string USER_ID;

    try
    {
        // PreparedStatement 객체 생성 update 하기 위한 쿼리 회원등급 바꾸기
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("update USER set RANK = ? where USER_ID = ?"));

        std::unique_ptr<sql::Statement> stmnt2(conn->createStatement());
        // 아이디에 해당하는 정보 불러오기
        sql::ResultSet *res = stmnt2->executeQuery("select * from USER WHERE USER_ID = 'KIMGUN140' ;");
        //해당 유저의 가입일의 6개월 지났는지 보기 
        sql::ResultSet *res1 = stmnt2->executeQuery("SELECT DATE_ADD(JOINDATE, INTERVAL 6 month) FROM USER WHERE USER_ID = ;");

        while (res->next())
        {
            if (res->getString(1) == USER_ID)
            {

                // 이거는 우수회원으로 업데이트 정산반납 연속 10회이상 && 6개월 이상이면 우수회원으로 전환 우수회원은 1
                if (res->getInt(8) >= 10 && res->getInt(7)  > res1->getInt(1) )
                {
                    // 우수회원으로 전환
                    stmnt->setInt(1, 1);
                }
            }
        }
        // 객체에 값을 전달

        // 객체의 내부 함수를 이용하여 쿼리를 실행
        stmnt->executeQuery();
        // 실패시 오류 메세지 반환
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error updating USER status: " << e.what() << std::endl;
    }
}