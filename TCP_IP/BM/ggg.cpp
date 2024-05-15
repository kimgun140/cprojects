#include <iostream>
#include <mariadb/conncpp.hpp>
#include <ctime>
#include <vector>
#include <string>

class USER
{

public:
    // 로그인  성공시 1 반환 실패시 2반환 기본값은 2로 시작해 로그인 정보가 맞으면 1로 바꿔주고 반환한다.
    int LOGIN(std::unique_ptr<sql::Connection> &conn)
    {
        std::string ID;
        std::string PW;
        std::cout << "ID 입력플리즈";
        std::cin >> ID;
        std::cout << "PW 입력플리즈";
        std::cin >> PW;
        int Login_ob = 2;
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery("select * from USER");
            // 반복문을 통해서 내부의 값을 반환
            while (res->next())
            {
                if (ID == res->getString(1) && PW == res->getString(2))
                {
                    // return_id.push_back((std::string)res->getString(1));
                    // return_id.push_back((std::string)res->getString(2));
                    std::cout << "로그인 성공입니다.";
                    Login_ob = 1;
                    break;
                }
            }
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
        }
        return Login_ob;
    }
    // 아이디 중복 검사
    // 반환할때 중복아니면 1 중복이면 2 반환 그리고 다음 칸에 나온 아이디를 담아서 줘야지 id_check[1]에는 확인된 아이디가 담긴다.
    // 중복체크가 통과가 안되면 id_check[1]에는 값이 안담긴다. ㅇㅋ?
    std::vector<std::string> SINGUP_IDcheck(std::unique_ptr<sql::Connection> &conn, std::string ID)
    {
        std::vector<std::string> id_check;
        try
        {
            // 아이디 중복 확인
            std::unique_ptr<sql::Statement> stmnt2(conn->createStatement());
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER");
            while (res->next())
            {

                if (ID == res->getString(1))
                {
                    std::cout << "중복된 아이디입니다." << std::endl;
                    std::cout << "다시 입력해주세요" << std::endl;
                    id_check.push_back("2");
                }
            }
            // 실패시 오류 메세지 반환
            // 중복 체크 검사를 통과
            // id_check.push_back(ID);
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
        }
        return id_check;
    }
    // 1반환하면 중복안됨 사용가능 중복이면 2반환 email_check[0], 중복검사 통과한 이메일이 담긴다. email_check[1] 여기에 
    std::vector<std::string> SINGUP_EMAILcheck(std::unique_ptr<sql::Connection> &conn, std::string EMAIL)
    {
        std::vector<std::string> email_check ;
        try
        {
            // 아이디 중복 확인
            std::unique_ptr<sql::Statement> stmnt2(conn->createStatement());
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER");
            while (res->next())
            {

                if (EMAIL == res->getString(6))
                {
                    std::cout << "중복된 email입니다." << std::endl;
                    std::cout << "다시 입력해주세요" << std::endl;
                    email_check.push_back("2");
                    break;
                }
            }
            email_check.push_back(EMAIL);
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            // return 0;
        }
        return email_check;
    }
    // 회원가입시 전화번호를 확인해서 중복이 안되어서 사용이 가능한지  가능하면 1반환 불가능하면 2반환 기본값은 2 ㅇㅋ면 1로 바꿔서 반환
    std::vector<std::string> SINGUP_PHONEcheck(std::unique_ptr<sql::Connection> &conn, std::string EMAIL)
    {
        std::vector<std::string> PHONE_CHECK ;
        try
        {
            // 아이디 중복 확인
            std::unique_ptr<sql::Statement> stmnt2(conn->createStatement());
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER");
            while (res->next())
            {

                if (EMAIL == res->getString(6))
                {
                    std::cout << "중복된 email입니다." << std::endl;
                    std::cout << "다시 입력해주세요" << std::endl;
                    PHONE_CHECK.push_back("2");
                    break;
                }
            }
            PHONE_CHECK.push_back("1");
            PHONE_CHECK.push_back(EMAIL);
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            // return 0;
        }
        return PHONE_CHECK;
    }

    // signup_check 이거는  1번은 회원가입 성공 2번은 회원가입 실패
    int SINGUP(std::unique_ptr<sql::Connection> &conn, std::string ID, std::string PW, std::string U_NAME, std::string ADDRESS, std::string EMAIL, std::string PHONE, int JOINDATE)
    {
        int SINGUP_CHECK = 0;
        try
        {   // 여기서 한번에 돌리면 한번 검사하면서 줄이 내려가고 그 다음에 이메일 검사하려면 다시한번 돌려야하는데 그리고 한번 더 돌려서 검사하고
            // 그러면 다른 함수에서 검사가 끝난 값을 받아서 오는게 좋겠네 맞나? 맞다 그렇게 하려면  위의 체크 함수를 수정하자. 무슨 값이 리턴되는 지는 다른 부분 에서 중요하지 않다.
            // createStaemet 객체 생성 insert
            std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("INSERT INTO USER (USER_ID, PW, U_NAME, ADDRESS, PHONE, EMAIL,JOINDATE) VALUES(?,?,?,?,?,?,?)"));

            // 아이디 중복 확인
            // std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행

            // 쿼리 입력
            stmnt->setString(1, ID);
            stmnt->setString(2, PW);
            stmnt->setString(3, U_NAME);
            stmnt->setString(4, ADDRESS);
            stmnt->setString(5, PHONE);
            stmnt->setString(6, EMAIL);
            stmnt->setInt(7, JOINDATE);
            // 객체의 내부 함수를 이용하여 쿼리를 실행
            stmnt->executeQuery();
            SINGUP_CHECK = 1;
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            SINGUP_CHECK = 2;
        }
        return SINGUP_CHECK;
    }
    // UPDATE문 실행 함수(아이디를 이용하여 회원등급을 바꿈) 로그인시에 바뀌게 해야겠다
    //  UPDATE_CHECK를 반환할건데 0이면 기본 등급으로 변환 1이면 우수회원 2이면 블랙회원 기본은 0
    int UPDATE_USER(std::unique_ptr<sql::Connection> &conn, std::string User_id)
    {
        int RANK_CHECK = 0;
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement());  // conn.createStatement()를 실행
            std::unique_ptr<sql::Statement> stmnt1(conn->createStatement()); // conn.createStatement()를 실행
            std::unique_ptr<sql::Statement> stmnt2(conn->createStatement()); // conn.createStatement()를 실행

            // 아이디 체크하기
            sql::ResultSet *res = stmnt->executeQuery("select * from USER");
            // 가입일에서 6개월 지난 시간
            sql::ResultSet *res1 = stmnt1->executeQuery("select date_format(date_add(JOINDATE,INTERVAL 6 MONTH), '%Y%m%d') from USER where USER_ID = '" + User_id + "'");
            // 현재시간
            sql::ResultSet *res2 = stmnt2->executeQuery("select date_format(NOW(), '%Y%m%d')");
            // 랭크 바꾸기
            std::unique_ptr<sql::PreparedStatement> stmnt3(conn->prepareStatement("update USER set RANK = ? where USER_ID = '" + User_id + "'"));

            // 반복문을 통해서 내부의 값을 반환
            while (res->next())
            {
                // 아이디 체크 8번임 r_book
                if (res->getString(1) == "KIMGUN140")
                {
                    // 블랙회원으로 등급변환
                    if (res->getInt(10) >= 3 || res->getInt(11) >= 14)
                    {
                        stmnt3->setInt(1, 2);
                        RANK_CHECK = 2;
                    }
                    res1->next();
                    res2->next();
                    std::cout << "ok1" << std::endl;
                    std::cout << res1->getString(1) << std::endl;
                    std::cout << res2->getString(1) << std::endl;
                    int rtc1;
                    int rtc2;
                    rtc1 = std::stoi((std::string)res1->getString(1));
                    rtc2 = std::stoi((std::string)res2->getString(1));
                    std::cout << rtc1 << std::endl;
                    std::cout << rtc2 << std::endl;

                    //  우수회원으로 변환
                    if (rtc1 < rtc2 && res->getInt(8) >= 10)
                    {
                        std::cout << "ok2";
                        stmnt3->setInt(1, 1);
                        RANK_CHECK = 1;
                    }
                }
            }
            stmnt3->executeQuery();
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error updating USER status: " << e.what() << std::endl;
        }
        return RANK_CHECK;
    }

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
};

int main()
{
    std::vector<std::string> login_ob;
    USER asd;

    std::unique_ptr<sql::Connection> conn = asd.Connect();
    int choice;
    std::cout << "선택플리즈";
    std::cin >> choice;
    // choice 가 1이면 로그인 2이면 회원가입
    while (1)
    {
        // 로그인한다.
        if (choice == 1)
            asd.LOGIN(conn);
        else if (choice == 2)
        {
            // asd.SINGUP()
        }
    }

    // asd.UPDATE_USER(conn);
    // asd.LOGIN(conn);

    // std::string PW;
    // std::cout << "입력플리즈" << std::endl;
    // std::cin >> PW;

    // std::string U_NAME;
    // std::cout << "입력플리즈" << std::endl;
    // std::cin >> U_NAME;

    // std::string ADDRESS;
    // std::cout << "입력플리즈" << std::endl;
    // std::cin >> ADDRESS;

    // std::string PHONE;
    // std::cout << "입력플리즈" << std::endl;
    // std::cin >> PHONE;

    // std::string EMAIL;
    // std::cout << "입력플리즈" << std::endl;
    // std::cin >> EMAIL;

    // int JOINDATE;
    // std::cout << "입력플리즈" << std::endl;
    // std::cin >> JOINDATE;
    // SINGUP(conn, ID, PW, U_NAME, ADDRESS, PHONE, EMAIL, JOINDATE);

    return 0;
}