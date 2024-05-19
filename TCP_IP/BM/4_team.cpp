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
    //  중복아닐때 0 중복일 때 1 오류는 2
    int SINGUP_IDcheck(std::string ID)
    {
        try
        {
            // 아이디 중복 확인
            sql::Statement *stmnt2(m_connection->createStatement());
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER where USER_ID =  '" + ID + "'");
            std::cout << "ok" << std::endl;
            // 값이 없으면 어떤 값이 나오는거지 그냥 에러로 넘어  가는건가?
            res->next();
            while (1)
            {
                std::cout << "ok" << std::endl;

                if (ID == res->getString(1))
                // 값이 있으면 중복이 된다는 거지
                {
                    std::cout << "ok" << std::endl;

                    std::cout << "중복된 아이디입니다.\n"
                              << std::endl;
                    std::cout << "다시 입력해주세요" << std::endl;
                    return 1;
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
        return 0;
    }
    // 0은 중복 아님 1은 중복
    int SINGUP_EMAILcheck(std::string EMAIL)
    {
        try
        { // 이메일 중복 확인
            sql::Statement *stmnt2 = m_connection->createStatement();
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER where EMAIL = '" + EMAIL + "'");
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
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER where PHONE = '" + PHONE + "'");
            res->next();

            if (PHONE == res->getString(5))
            {
                std::cout << "중복된 전화번호입니다." << std::endl;
                std::cout << "다시 입력해주세요" << std::endl;
                return 0;
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
    // 클라이언트가 입력한 값을 매개변수로 사용 한다. 중복 체크를 해야하는 부분은
    // 클라이언트가 입력을 하면 서버에서 입력한 정보를 받아서 서버단에서 검사함수를 돌리고 중복이라면 클라이언트에게 다시 입력하게 해야한다.
    // 중복이 아닌 데이터가 검사 함수를 통과 하면  검사를 통과한 데이터랑 비교할 필요없는데 데이터랑 전부 다 signup 함수에 매개변수로 들어가서 동작해버린다.
    int SINGUP(std::string ID, std::string PW, std::string U_NAME, std::string ADDRESS, std::string PHONE, std::string EMAIL)
    {
        try
        { // 여기서 한번에 돌리면 한번 검사하면서 줄이 내려가고 그 다음에 이메일 검사하려면 다시한번 돌려야하는데 그리고 한번 더 돌려서 검사하고
            // 그러면 다른 함수에서 검사가 끝난 값을 받아서 오는게 좋겠네 맞나? 맞다 그렇게 하려면  위의 체크 함수를 수정하자. 무슨 값이 리턴되는 지는 다른 부분 에서 중요하지 않다.
            // createStaemet 객체 생성 insert
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("INSERT INTO USER (USER_ID, PW, U_NAME, ADDRESS, PHONE, EMAIL,JOINDATE) VALUES(?,?,?,?,?,?,date_format(now(),'%Y%m%d'))");

            // 아이디 중복 확인
            // std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행

            // 쿼리 입력
            stmnt->setString(1, ID);
            stmnt->setString(2, PW);
            stmnt->setString(3, U_NAME);
            stmnt->setString(4, ADDRESS);
            stmnt->setString(5, PHONE);
            stmnt->setString(6, EMAIL);

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
    //  회원등급 UPDATE문 실행 함수(아이디를 이용하여 회원등급을 바꿈) 로그인시에 바뀌게 해야겠다
    //  RANK, SANCTION, R_BOOK, OVERDUE_HISTROY, OVERDUE_DATE 를 update할 거임
    //  함수 동작이상없이 동작 했으면 0 catch문에 잡혔으면 1반환
    //  윗 문장은 잘못된듯 반환하는 값은 잘된건지 아닌 건지만 반환하면 되잖아? 왜냐면!! 이미 데이터 베이스에서 동작을 끝냈으니까
    // 정상 작동 g 오작동e
    std::string UPDATE_USER(std::string User_id)
    {
        std::string RANK_CHECK;
        try
        {
            // createStaemet 객체 생성
            sql::Statement *stmnt = m_connection->createStatement();  // conn.createStatement()를 실행
            sql::Statement *stmnt1 = m_connection->createStatement(); // conn.createStatement()를 실행
            sql::Statement *stmnt2 = m_connection->createStatement(); // conn.createStatement()를 실행
            sql::Statement *stmnt8 = m_connection->createStatement(); // conn.createStatement()를 실행

            // 아이디 체크하기/ 쓰는 거임
            sql::ResultSet *res = stmnt->executeQuery("select * from USER where USER_ID = '" + User_id + "'");
            // 가입일에서 6개월 지난 시간
            sql::ResultSet *res1 = stmnt1->executeQuery("select date_format(date_add(JOINDATE,INTERVAL 6 MONTH), '%Y%m%d') from USER where USER_ID = '" + User_id + "'");
            // 제재날짜에서 30일 지난 시간
            sql::ResultSet *res3 = stmnt8->executeQuery("select date_format(date_add(SANCTION,INTERVAL 30 DAY), '%Y%m%d') from USER where USER_ID = '" + User_id + "'");
            // 현재시간
            sql::ResultSet *res2 = stmnt2->executeQuery("select date_format(NOW(), '%Y%m%d')");
            // 랭크 바꾸기
            sql::PreparedStatement *stmnt3 = m_connection->prepareStatement("update USER set RANK = ? where USER_ID = '" + User_id + "'");
            // 제재 시작하는 날 설정
            sql::PreparedStatement *stmnt4 = m_connection->prepareStatement("update USER set SANCTION = DATE_FORMAT(NOW(),'%Y%m%d') where USER_ID = '" + User_id + "'");
            // 제재 해제 해주기
            sql::PreparedStatement *stmnt5 = m_connection->prepareStatement("update USER set SANCTION = DATE_FORMAT(NOW(),'%Y%m%d') where USER_ID = '" + User_id + "'");

            // 제재 날짜 초기화 제재 끝났으니까 overdue_history,date 0으로 초기화 시켜주기
            sql::PreparedStatement *stmnt6 = m_connection->prepareStatement("update USER set R_BOOK = 0, SANCTION = 11111111, OVERDUE_HISTORY = 0, OVERDUE_DATE = 0 where USER_ID = '" + User_id + "'");
            // 제재 끝났으니까 overdue_history,date 0으로 초기화 시켜주기
            sql::PreparedStatement *stmnt7 = m_connection->prepareStatement("update USER set OVERDUE_HISTORY = 0, OVERDUE_DATE = 0 where USER_ID = '" + User_id + "'");

            // 반복문을 통해서 내부의 값을 반환
            // 아이디 체크 8번임 r_book
            res->next();
            res1->next();
            res2->next();
            res3->next();

            std::cout << "ok1" << std::endl;
            std::cout << res1->getString(1) << std::endl; // 가입일부터 6개월 지난 시점
            std::cout << res2->getString(1) << std::endl; // 현재 시간
            int rtc1;                                     // 가입일 6개월 지난 시간
            int rtc2;                                     // 현재시간

            std::cout << "ok2" << std::endl;

            rtc1 = std::stoi((std::string)res1->getString(1));
            rtc2 = std::stoi((std::string)res2->getString(1));
            std::cout << rtc1 << std::endl;
            std::cout << rtc2 << std::endl;
            std::cout << "okok" << std::endl;
            int rtc3; // 제재 시작후 30일이 지난 날짜
            // 블랙회원으로 등급변환
            if (res->getInt(10) >= 3 || res->getInt(11) >= 14)
            {
                stmnt3->setInt(1, 2);
                stmnt4->executeQuery();

                RANK_CHECK = "g";
            }

            if (((std::string)res3->getString(1)).empty())
            {
                std::cout << "제재 기록 없음 " << std::endl;
            }
            else
            {
                rtc3 = std::stoi((std::string)res3->getString(1));
                std::cout << rtc3 << "okokokokokok" << std::endl;
                // 블랙 회원 제재기간이 끝나면 회원 등급을 0으로 조정시켜주기
                if (rtc3 <= rtc2)
                {
                    std::cout << "rtc3" << rtc3 << std::endl;
                    std::cout << "saction OVER" << std::endl;
                    // 제재가 끝났다 그러면 overdue 를 초기화 시키고 그리고 rank도 0으로 만들어준다.
                    stmnt6->executeQuery(); // 제재 날짜 11111111로 바꿔주기 제재가 끝났으니까 그리고 overdue_history,overdue_date를 0으로  초기화 시킨다.
                    stmnt3->setInt(1, 0);   // rank 기본등급으로 바꿔주기
                }
            }

            //  우수회원으로 변환
            if (rtc1 < rtc2 && res->getInt(8) >= 10)
            {
                std::cout << "ok3";
                stmnt3->setInt(1, 1);
                stmnt3->executeQuery();
                return "g"; // 우수회원
            }
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error updating USER status: " << e.what() << std::endl;
            return "e";
        }
        return "g";
    }

    std::string Good_book()
    {
        std::vector<std::string> asd;
        std::vector<std::vector<std::string>> qwe;
        try
        {
            // 아이디 중복 확인
            sql::Statement *stmnt2 = m_connection->createStatement();
            sql::ResultSet *res = stmnt2->executeQuery("select * from BOOKINFO ORDER BY RAND() LIMIT 100");
            int count = 1;
            while (res->next())
            {
                asd.push_back(std::string(res->getString(1)));
                asd.push_back(std::string(res->getString(2)));
                asd.push_back(std::string(res->getString(3)));
                asd.push_back(std::string(res->getString(4)));
                asd.push_back(std::string(res->getString(5)));
                asd.push_back(std::string(res->getString(6)));
                asd.push_back(std::string(res->getString(7)));
                qwe.push_back(asd);
                std::cout << res->getString(1) << std::endl;
                std::cout << res->getString(2) << std::endl;
                std::cout << res->getString(3) << std::endl;
                std::cout << res->getString(4) << std::endl;
                std::cout << res->getString(5) << std::endl;
                std::cout << res->getString(6) << std::endl;
                std::cout << res->getString(7) << std::endl;
                std::cout << count << std::endl;
                std::cout << "=========================================" << std::endl;
                count++;
            }
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting Good: " << e.what() << std::endl;
            return "b";
        }
        return "a";
    }
};

int main()
{
    std::vector<std::string> login_ob;
    std::string id = "ADMIN";
    std::string pw = "1234";
    USER asd(id, pw);
    // std::string user_id = "28137642387456";
    // // asd.SINGUP_IDcheck(user_id);
    // std::string IDD = "22";
    // std::string PWW = "1234";
    // // std::string
    // // asd.SINGUP();
    // // asd.SINGUP();
    // // asd.UPDATE_USER(user_id);
    // asd.SINGUP_PHONEcheck("01087500018");
    // // asd.UPDATE_USER(IDD);
    std::string a;
    a = asd.Good_book();
    if (a == "a")
        std::cout << "검색완료" << std::endl;
    return 0;
}