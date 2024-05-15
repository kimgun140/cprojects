#include <iostream>
#include <mariadb/conncpp.hpp>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <time.h>

class DB
{
protected:
    std::string m_id;
    std::string m_pw;
    sql::Connection *m_connection;

public:
    DB() {}
    ~DB()
    {
        m_connection->close();
        std::cerr << "DB 접속을 종료\n";
    }

    void account(const std::string &id, const std::string &pw)
    {
        this->m_id = id;
        this->m_pw = pw;
    }

    void connect()
    {
        try
        {
            sql::Driver *driver = sql::mariadb::get_driver_instance();
            sql::SQLString url = "jdbc:mariadb://10.10.21.103/BM";
            sql::Properties properties({{"user", m_id}, {"password", m_pw}});
            m_connection = driver->connect(url, properties);
            std::cout << "DB 접속\n";
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "DB 접속실패: " << e.what() << '\n';
        }
    }
};

class USER : public DB
{

public:
    USER() {}

    USER(std::string id, std::string pw)
    {
        m_id = id;
        m_pw = pw;
        connect();
    }
    // 로그인  성공시 1 반환 실패시 2반환 기본값은 2로 시작해 로그인 정보가 맞으면 1로 바꿔주고 반환한다.
    int LOGIN()
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
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("select * from USER"); // conn.createStatement()를 실행
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery();
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
    // 중복일 때 0 중복아닐때 1 오류는 2
    int SINGUP_IDcheck(std::string ID)
    {
        try
        {
            // 아이디 중복 확인
            sql::Statement *stmnt2(m_connection->createStatement());
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER");
            while (res->next())
            {
                if (ID == res->getString(1))
                {
                    std::cout << "중복된 아이디입니다.\n"
                              << std::endl;
                    std::cout << "다시 입력해주세요" << std::endl;
                    return 0;
                    break;
                }
            }
            // 실패시 오류 메세지 반환
            // 중복 체크 검사를 통과
            // id_check.push_back(ID);
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return 2; // 오류
        }
        return 1;
    }
    // 0은 중복 아님 1은 중복
    int SINGUP_EMAILcheck(std::string EMAIL)
    {
        try
        { // 이메일 중복 확인
            sql::Statement *stmnt2 = m_connection->createStatement();
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER");
            while (res->next())
            {

                if (EMAIL == res->getString(6))
                {
                    std::cout << "중복된 email입니다." << std::endl;
                    std::cout << "다시 입력해주세요" << std::endl;
                    return 0;
                    break;
                }
            }
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return 2;
        }

        return 1;
    }
    // 회원가입시 전화번호를 확인해서 중복이 안되어서 사용이 가능한지  가능하면 1반환 불가능하면 2반환 기본값은 2 ㅇㅋ면 1로 바꿔서 반환
    // 중복일 때 0 중복아닐때 1 오류는 2
    int SINGUP_PHONEcheck(std::string PHONE)
    {
        try
        {
            // 아이디 중복 확인
            sql::Statement *stmnt2 = m_connection->createStatement();
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER");
            while (res->next())
            {

                if (PHONE == res->getString(5))
                {
                    std::cout << "중복된 전화번호입니다." << std::endl;
                    std::cout << "다시 입력해주세요" << std::endl;
                    return 0;
                    break;
                }
            }
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return 2;
        }
        return 1;
    }

    // signup_check 이거는  1번은 회원가입 성공 2번은 회원가입 실패
    int SINGUP()
    {
        std::string ID;
        std::string PW;
        std::string U_NAME;
        std::string ADDRESS;
        std::string PHONE;
        std::string EMAIL;
        std::string JOINDATE;
        while (1)
        {
            std::cout << "id를 입력하세요: ";
            getline(std::cin, ID);
            std::cout << "ok?";
            int ok;
            ok = SINGUP_IDcheck(ID);
            if (ok == 1) // 아이디 중복 아닐 때 1 일때
            {
                std::cout << "ok";
                break;
            }
            else if (ok == 0) // 아이디 중복일때 0
            {

                std::cout << " not ok";
                continue;
            }
        }

        std::cout << "비밀번호를 입력하세요: ";
        getline(std::cin, PW);

        std::cout << "이름을 입력하세요: ";
        getline(std::cin, U_NAME);

        std::cout << "주소를 입력하세요: ";
        getline(std::cin, ADDRESS);

        while (1)
        {
            std::cout << "연락처를 입력하세요: ";
            getline(std::cin, PHONE);

            int ok2 = SINGUP_PHONEcheck(PHONE);
            if (ok2 == 1) // 중복일 때 0
            {
                std::cout << " ok";
                break;
            }
            else if (ok2 == 0) // 중복아닐  1 때
            {
                std::cout << " not ok";
                continue;
            }
        }
        while (1)
        {
            std::cout << "이메일을 입력하세요: ";
            getline(std::cin, EMAIL);
            int ok3 = SINGUP_EMAILcheck(EMAIL);
            if (ok3 == 1) // 중복일 때 0
            {
                std::cout << " ok" << std::endl;
                break;
            }
            else if (ok3 == 0) // 중복아닐  0 때
            {
                std::cout << " ok" << std::endl;
                continue;
            }
        }
        std::cout << "date 입력하세요: ";
        getline(std::cin, JOINDATE);

        try
        { // 여기서 한번에 돌리면 한번 검사하면서 줄이 내려가고 그 다음에 이메일 검사하려면 다시한번 돌려야하는데 그리고 한번 더 돌려서 검사하고
            // 그러면 다른 함수에서 검사가 끝난 값을 받아서 오는게 좋겠네 맞나? 맞다 그렇게 하려면  위의 체크 함수를 수정하자. 무슨 값이 리턴되는 지는 다른 부분 에서 중요하지 않다.
            // createStaemet 객체 생성 insert
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("INSERT INTO USER (USER_ID, PW, U_NAME, ADDRESS, PHONE, EMAIL,JOINDATE) VALUES(?,?,?,?,?,?,?)");

            // 아이디 중복 확인
            // std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행

            // 쿼리 입력
            stmnt->setString(1, ID);
            stmnt->setString(2, PW);
            stmnt->setString(3, U_NAME);
            stmnt->setString(4, ADDRESS);
            stmnt->setString(5, PHONE);
            stmnt->setString(6, EMAIL);
            stmnt->setString(7, JOINDATE);

            // 객체의 내부 함수를 이용하여 쿼리를 실행
            stmnt->executeQuery();
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return 2;
        }
        return 0;
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
                        RANK_CHECK = 2; //회원등급
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
                        RANK_CHECK = 1; //우수회원
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
};

int main()
{
    std::vector<std::string> login_ob;
    std::string id = "ADMIN";
    std::string pw = "1234";
    USER asd(id, pw);

    // asd.SINGUP();
    asd.SINGUP();
    return 0;
}