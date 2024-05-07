#include <iostream>
#include <mariadb/conncpp.hpp>
void asdf(std::string input)
{
    std::string id1;
    //  std:: string name1;

    try
    {

        // DB연결 객체 생성
        // DRIVER 객체 C++랑 연결하기 위한 객체
        // 연결을 맞아서 대화를 해주는 객체가 CONN이다
        sql::Driver *driver = sql::mariadb::get_driver_instance();
        // 연결할 DB의 특정 IP, DB를 정의
        sql::SQLString url("jdbc:mariadb://localhost:3306/TEST"); // 3306이 마리아 DB의 디폴트 PORT
        // 연결할 DB를 사용할 유저를 정의
        sql::Properties properties({{"user", "OPERATOR"}, {"password", "0000"}});
        // 객체에 값을 통하여 연결을 시도
        std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));

        // 여기 위로는 기본설정임 바꿔줄거 없음 ㅇㅋ? ㅇㅋ
        // createStaemet 객체 생성

        std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행 다른데서 접근해서 해제하거나 바꾸지 못하게 선언하는듯???
        // 쿼리를 실행
        // std:: string query_enter = "select * from TASKS where ";
        sql::ResultSet *res = stmnt->executeQuery(input);
        // 여기서 쿼리문을 입력 받는거에 따라서 다르게 해주면 됨 ㅇㅋ? ㅇㅋ
        // 윗줄에서 객체를 생성한뒤 쿼리를 실행한 값을 담는다.
        //  반복문을 통해서 내부의 값을 반환
        //  std::cout << res->getInt(1);
        while (res->next()) // res-> next() 다음에 위치한 요소를 반환한다?? 이거 안해주면 처음에는 커서가 아무것도 아닌공간을 가르킨다. 그래서 값이 안나옴
        // 오 한번에 한줄 씩 움직이네 신기 ㅋ 다음 읽어올 줄이 있으면 true 없으면 false
        // 여기서 출력을 해준다. ㅇㅋ? ㅇㅋ
        {

            // if (res->getString(2) == "JANNY")
            // {
            std::cout << "id = " << res->getInt(1);        // getInt("id"); 이렇게 써도 된다 ㄷㄷ
            std::cout << ", name = " << res->getString(2); //  varchar는 getsting()으로
            std::cout << ", AGE = " << res->getInt(3);
            std::cout << ", gender = ";
            if (res->getBoolean(4))
            {
                std::cout << "Male" << std::endl;
            }
            else
            {
                std::cout << "Female" << std::endl;
            }
        }
        // }
        // 실패시 오류 메세지 반환
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error selecting TASKS: " << e.what() << std::endl;
    }
}




// SELECT문 실행 함수
void showTasks(std::string touristsites_input)
{
    try
    {
                       // DB연결 객체 생성
        // DRIVER 객체 C++랑 연결하기 위한 객체
        // 연결을 맞아서 대화를 해주는 객체가 CONN이다
        sql::Driver *driver = sql::mariadb::get_driver_instance();
        // 연결할 DB의 특정 IP, DB를 정의
        sql::SQLString url("jdbc:mariadb://localhost:3306/TEST"); // 3306이 마리아 DB의 디폴트 PORT
        // 연결할 DB를 사용할 유저를 정의
        sql::Properties properties({{"user", "OPERATOR"}, {"password", "0000"}});
        // 객체에 값을 통하여 연결을 시도
        std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));


        // createStaemet 객체 생성
        std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행 다른데서 접근해서 해제하거나 바꾸지 못하게 선언하는듯???
        // 쿼리를 실행
        sql::ResultSet *res = stmnt->executeQuery(touristsites_input);
        //윗줄에서 객체를 생성한뒤 쿼리를 실행한 값을 담는다.   
        // 반복문을 통해서 내부의 값을 반환
        // std::cout << res->getInt(1);
        while (res->next()) // res-> next() 다음에 위치한 요소를 반환한다?? 이거 안해주면 처음에는 커서가 아무것도 아닌공간을 가르킨다. 그래서 값이 안나옴 
        // 오 한번에 한줄 씩 움직이네 신기 ㅋ 다음 읽어올 줄이 있으면 true 없으면 false
        {

            // if (res->getString(2) == "JANNY")
            // {
                std::cout << "이름 = " << res->getString(2); //getInt("id"); 이렇게 써도 된다 ㄷㄷ 
                std::cout << ", 주소 = " << res->getString(3); //  varchar는 getsting()으로
                std::cout << ", 전화번호 = " << res->getString(4);
            }
        // }
        // 실패시 오류 메세지 반환
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error selecting TASKS: " << e.what() << std::endl;
    }
}
int main()
{


        std:: string name123;
        // std::string gggg ;

        std:: cin >>name123;
        // gggg =  qqqq +  name123;
        // // std:: cout<<gggg;
        std::string input ; 
        // asdf();
}