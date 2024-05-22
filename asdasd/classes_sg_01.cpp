#include <iostream>
#include <mariadb/conncpp.hpp>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;

class DB
{
protected:
    string m_id;
    string m_pw;
    sql::Connection *m_connection;

public:
    DB() {}
    ~DB()
    {
        m_connection->close();
        cerr << "DB 접속을 종료\n";
    }

    void account(const string &id, const string &pw)
    {
        this->m_id = id;
        this->m_pw = pw;
    }

    void connect()
    {
        try
        {
            sql::Driver *driver = sql::mariadb::get_driver_instance();
            sql::SQLString url = "jdbc:mariadb://localhost:3306/chat";
            sql::Properties properties({{"user", m_id}, {"password", m_pw}});
            m_connection = driver->connect(url, properties);
            // cout << "DB 접속\n";
        }
        catch (sql::SQLException &e)
        {
            cerr << "DB 접속실패: " << e.what() << '\n';
        }
    }
};

class Rent : public DB
{
protected:
public:
    std::vector<std::string> asd;
    std::vector<std::vector<std::string>> qwe;

    Rent(){};

    Rent(std::string id, std::string pw)
    {
        m_id = id;
        m_pw = pw;
        connect();
    }

    int Rank(std::string id)
    { // 회원등급 구분
        try
        {
            int rank;
            sql::PreparedStatement *RR = m_connection->prepareStatement("SELECT RANK FROM USER WHERE USER_ID = ?");
            RR->setString(1, id);
            sql::ResultSet *res = RR->executeQuery();
            while (res->next())
            {
                if (!res->getInt(1)) // 일반회원 0
                    return rank = 4;
                else if (res->getInt(1)) // 우수회원 1
                    return rank = 7;
                else
                { // 블랙회원
                    return 1;
                }
            }
        }
        catch (sql::SQLException &e)
        {
            cerr << "Error selecting Rank: " << e.what() << endl;
        }
        return 0; // 오류
    }

    // 리턴값: 반납가능 a, 반납불가 f ,책 반납하는 함수
    std::string Return_book(std::string EnrolledNum)
    { // RENT_INFO 테이블에서 R_stat 속성에서 'R', 'O', 'D' 중 'R' 상태일 때만 반납가능 + 책 등록번호 필요
        try
        {
            int R_id;
            std::string user;
            sql::PreparedStatement *status = m_connection->prepareStatement("select R_id from RENT_INFO WHERE B_id = ? and R_stat = 'R'");
            status->setString(1, EnrolledNum);
            sql::ResultSet *res = status->executeQuery();
            while (res->next())
            {
                R_id = res->getInt(1); // 대여시 RENT_INFO 테이블에 부여된 번호(PK)
                user = Userid(R_id);
                return user; // 책 정상적으로 반납 가능한 경우
            }
        }
        catch (sql::SQLException &e)
        {
            cerr << "R_stat Error: " << e.what() << endl;
        }
        return "f"; // 책이 반납 되어 있는 경우
    }
    // Return_book에 들어있는 함수1
    std::string Userid(int R_id)
    { // RENT_INFO에서 유저 아이디 받는 함수
        try
        {
            string id;
            string B_id;
            string RI;
            sql::PreparedStatement *status = m_connection->prepareStatement("select ID, B_id from RENT_INFO WHERE R_id = ?");
            status->setInt(1, R_id);
            sql::ResultSet *res = status->executeQuery();
            while (res->next())
            {
                id = res->getString(1);
                B_id = res->getString(2);
                RI = Return_info(R_id, id, B_id);
                return RI; // 책 반납
            }
        }
        catch (sql::SQLException &e)
        {
            cerr << "R_stat Error: " << e.what() << endl;
        }
        return "f";
    }

    /* 중복 대여가 되는 버그가 있음 - 수정 필요 */
    // return 0 오류, 1 대여가능, 2 대여중
    std::string Borrow_book(std::string id, std::string EnrolledNum)
    { // 조건에 맞는 책 (등록번호 기준)
        try
        {
            sql::PreparedStatement *status = m_connection->prepareStatement("SELECT Bsituation from BOOKINFO where Enrollednum = ?");
            status->setString(1, EnrolledNum);
            sql::ResultSet *res = status->executeQuery();
            while (res->next())
            {
                if (!res->getInt(1))
                { // Bsituation = 0 << 대여가능 상태
                    std::string res = RD_Insert(id, EnrolledNum);
                    return res;
                }
                else
                {
                    // 대여중인 책입니다
                    return "n";
                }
            }
        }
        catch (sql::SQLException &e)
        {
            cerr << "Insert Error: " << e.what() << endl;
        }
        return "e"; // 오류
    }

    // 리턴값 오류: 0, 일반회원: 1, 우수회원: 2, 블랙회원: 3
    std::string RD_Insert(std::string id, std::string en)
    { // 유저 id, 책 등록번호 받아야함 대여하는 책 정보 업데이트
        int rank;
        rank = Rank(id);
        if (rank == 4)
        {
            try
            {
                sql::PreparedStatement *RD = m_connection->prepareStatement("INSERT INTO RENT_INFO (ID, B_id, R_date,R_rs) values (?,?,(SELECT DATE_FORMAT(NOW(), '%Y-%m-%d')),(select DATE_FORMAT(DATE_ADD(NOW(), INTERVAL 4 DAY),'%Y-%m-%d')))");
                RD->setString(1, id);
                RD->setString(2, en);
                RD->executeQuery();

                sql::PreparedStatement *BS = m_connection->prepareStatement("UPDATE BOOKINFO SET Bsituation = 1 where Enrollednum = ?");
                BS->setString(1, en);
                BS->executeQuery();
                return "a"; // 정상 대여(일반회원)
            }
            catch (sql::SQLException &e)
            {
                cerr << "Error inserting RD_Insert: " << e.what() << endl;
            }
        }
        else if (rank == 7)
        {
            try
            {
                sql::PreparedStatement *RD = m_connection->prepareStatement("INSERT INTO RENT_INFO (ID, B_id, R_date,R_rs) values (?, ?,(SELECT DATE_FORMAT(NOW(), '%Y-%m-%d')),(select DATE_FORMAT(DATE_ADD(NOW(), INTERVAL 7 DAY),'%Y-%m-%d')))");
                RD->setString(1, id);
                RD->setString(2, en);
                RD->executeQuery();

                sql::PreparedStatement *BS = m_connection->prepareStatement("UPDATE BOOKINFO SET Bsituation = 1 where Enrollednum = ?");
                BS->setString(1, en);
                BS->executeQuery();
                return "b"; // 정상 대여(우수회원)
            }
            catch (sql::SQLException &e)
            {
                cerr << "Error inserting RD_Insert: " << e.what() << endl;
            }
        }
        else
            return "c"; // 블랙회원
        return "e";     // 오류
    }
    // 반납할 시는 로그인 여부 X //Return_book에 들어있는 함수2
    std::string Return_info(int R_id, std::string id, std::string en)
    { // 일반회원일 경우 , 유저 id, 책 등록번호, 대여한 책 판단 함수 필요 받아야함 대여하는 책 정보 업데이트
        int rank;
        string ri = "a";
        rank = Rank(id);
        if (rank == 4)
        {
            try
            {
                sql::PreparedStatement *RT = m_connection->prepareStatement("UPDATE BOOKINFO SET Bsituation = 0 where Enrollednum = ?");
                RT->setString(1, en);
                RT->executeQuery(); // BOOKINFO 수정
                sql::PreparedStatement *RD = m_connection->prepareStatement("UPDATE RENT_INFO SET R_rd = (select date_format(now(),'%Y-%m-%d') where R_id = ?) where R_id = ?");
                RD->setInt(1, R_id);
                RD->setInt(2, R_id);
                RD->executeQuery(); // 실제 반납일부터 업데이트
                sql::PreparedStatement *RI = m_connection->prepareStatement("UPDATE RENT_INFO SET R_over = (case when (select R_rd - R_rs from RENT_INFO WHERE B_id = ? and R_stat = 'R') > 4 then (select R_rd - R_rs from RENT_INFO WHERE B_id = ? and R_stat ='R') else 0 end), R_stat = (case when (select R_rd - R_rs from RENT_INFO where B_id = ? and R_stat ='R') > 4 then 'D' else 'O' end) where B_id = ? and R_stat ='R'");
                RI->setString(1, en);
                RI->setString(2, en);
                RI->setString(3, en);
                RI->setString(4, en);
                RI->executeQuery(); // RENT_INFO 수정정
                return ri;          // 정상 반납(일반회원)
            }
            catch (sql::SQLException &e)
            {
                cerr << "Error inserting Return_book: " << e.what() << endl;
            }
        }
        else if (rank == 7)
        {
            try
            {
                sql::PreparedStatement *RT = m_connection->prepareStatement("UPDATE BOOKINFO SET Bsituation = 0 where Enrollednum = ?");
                RT->setString(1, en);
                RT->executeQuery(); // BOOKINFO 수정
                sql::PreparedStatement *RD = m_connection->prepareStatement("UPDATE RENT_INFO SET R_rd = (select date_format(now(),'%Y-%m-%d') where R_id = ?) where R_id = ?");
                RD->setInt(1, R_id);
                RD->setInt(2, R_id);
                RD->executeQuery(); // 실제 반납일부터 업데이트
                sql::PreparedStatement *RI = m_connection->prepareStatement("UPDATE RENT_INFO SET R_over = (case when (select R_rd - R_rs from RENT_INFO WHERE B_id = ? and R_stat ='R') > 7 then (select R_rd - R_rs from RENT_INFO WHERE B_id = ? and R_stat ='R') else 0 end), R_stat = (case when (select R_rd - R_rs from RENT_INFO where B_id = ? and R_stat ='R') > 7 then 'D' else 'O' end) where B_id = ? and R_stat ='R'");
                RI->setString(1, en);
                RI->setString(2, en);
                RI->setString(3, en);
                RI->setString(4, en);
                RI->executeQuery(); // RENT_INFO 업데이트
                return ri;          // 정상 반납(우수 회원)
            }
            catch (sql::SQLException &e)
            {
                cerr << "Error inserting Return_book: " << e.what() << endl;
            }
        }
        else
            return "b"; // 블랙회원일 때
        return "f";     // 오류
    }

    // 로그인  성공시 0 반환, 아이디 부존재 시 1, 비밀번호 불일치 시 2 반환, 에러발생 시 9 반환
    int LOGIN(std::string id, std::string pw)
    {
        int Login_ob = 2;
        try
        {
            // createStaemet 객체 생성
            // 아이디 검사
            sql::PreparedStatement *stmnt1 = m_connection->prepareStatement("SELECT ID FROM USER WHERE ID = ?");
            stmnt1->setString(1, id);
            sql::ResultSet *resid = stmnt1->executeQuery();
            // 로그인 5회이상인지 체크
            sql::PreparedStatement *filed_count = m_connection->prepareStatement("SELECT CONNECTION_FAILED FROM USER WHERE ID = ?");
            filed_count->setString(1, id);
            sql::ResultSet *filed_count11 = filed_count->executeQuery();
            filed_count11->next();
                filed_count11->getInt(1); // 여기에 횟수가 담겨 있네?
            if (resid->next())
            {
                // 비밀번호
                sql::PreparedStatement *stmnt2 = m_connection->prepareStatement("SELECT PW FROM USER WHERE ID = ? AND PW = ?");
                stmnt2->setString(1, id);
                stmnt2->setString(2, pw);
                sql::ResultSet *respw = stmnt2->executeQuery();
                if (respw->next()) // 값이 있으면 저게 실행이 되고 아니면 오류 나니까
                    return 0;      // 0 아이디 비번 일치
                else
                    return 2; // 2 비번 불일치
            }
            else
                return 1; // 1 아이디 부존재
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
        }
        return 9;
    }
    // 아이디 중복 검사
    // 반환할때 중복아니면 1 중복이면 2 반환 그리고 다음 칸에 나온 아이디를 담아서 줘야지 id_check[1]에는 확인된 아이디가 담긴다.
    //  중복아닐때 a 중복일 때 b 오류는 c
    std::string SINGUP_IDcheck(std::string ID)
    {
        try
        {
            // 아이디 중복 확인
            sql::Statement *stmnt2(m_connection->createStatement());
            sql::ResultSet *res = stmnt2->executeQuery("select ID from USER where ID =  '" + ID + "'");
            // std::cout << "ok" << std::endl;
            // 값이 없으면 어떤 값이 나오는거지 그냥 에러로 넘어  가는건가?
            while (res->next())
            {
                return "b"; // not ok
            }
            return "a";
            // 실패시 오류 메세지 반환
            // 중복 체크 검사를 통과
            // id_check.push_back(ID);
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return "c"; // 오류
        }
        return "a";
    }
    // EMAIL 중복
    //   중복아닐때 d 중복일 때 e 오류는 f
    std::string SINGUP_EMAILcheck(std::string EMAIL)
    {
        try
        { // 이메일 중복 확인
            sql::Statement *stmnt2 = m_connection->createStatement();
            sql::ResultSet *res = stmnt2->executeQuery("select * from USER where EMAIL = '" + EMAIL + "'");
            while (res->next())
            {
                if (EMAIL == res->getString(4))
                {
                    // std::cout << "중복된 email입니다." << std::endl;
                    // std::cout << "다시 입력해주세요" << std::endl;
                    return "e";
                }
            }
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return "f";
        }
        return "d";
    }
    // 회원가입시 전화번호를 확인해서 중복이 안되어서 사용이 가능한지  가능하면 1반환 불가능하면 2반환 기본값은 2 ㅇㅋ면 1로 바꿔서 반환
    //  중복아닐때 g 중복일 때 h 오류는 i
    std::string SINGUP_PHONEcheck(std::string PHONE)
    {
        try
        {
            // PN 중복 확인
            sql::Statement *stmnt2 = m_connection->createStatement();
            sql::ResultSet *res = stmnt2->executeQuery("select PHONE from USER where PHONE = '" + PHONE + "'");
            while (res->next())
                return "h";
            return "g";
            // if (PHONE == res->getString(5))
            // {
            //     std::cout << "중복된 전화번호입니다." << std::endl;
            //     std::cout << "다시 입력해주세요" << std::endl;
            //     return "h";
            // }

            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return "i";
        }
        return "g";
    }

    // 로그인할 때 USER overdue_history, overdue_date 업데이트
    void overdue(std::string id)
    {
        try
        {
            sql::PreparedStatement *HI = m_connection->prepareStatement("UPDATE USER SET OVERDUE_HISTORY = (SELECT COUNT(R_stat) from RENT_INFO WHERE R_stat = 'D' AND USER_ID = ?) WHERE USER_ID = ?");
            sql::PreparedStatement *DA = m_connection->prepareStatement("UPDATE USER SET OVERDUE_DATE = (SELECT SUM(R_over) FROM RENT_INFO WHERE ID = ?) WHERE USER_ID = ?");
            HI->setString(1, id);
            HI->setString(2, id);
            DA->setString(1, id);
            DA->setString(2, id);
            HI->executeQuery();
            DA->executeQuery();
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting overdue: " << e.what() << std::endl;
        }
    }
    // signup_check 이거는  1번은 회원가입 성공 2번은 회원가입 실패
    // 클라이언트가 입력한 값을 매개변수로 사용 한다. 중복 체크를 해야하는 부분은
    // 클라이언트가 입력을 하면 서버에서 입력한 정보를 받아서 서버단에서 검사함수를 돌리고 중복이라면 클라이언트에게 다시 입력하게 해야한다.
    // 중복이 아닌 데이터가 검사 함수를 통과 하면  검사를 통과한 데이터랑 비교할 필요없는데 데이터랑 전부 다 signup 함수에 매개변수로 들어가서 동작해버린다.
    // 반환값 정상 회원가입 a , 비정상 "b"
    std::string SIGNUP(std::string ID, std::string PW, std::string EMAIL, std::string NICKNAME)
    {
        try
        { // 여기서 한번에 돌리면 한번 검사하면서 줄이 내려가고 그 다음에 이메일 검사하려면 다시한번 돌려야하는데 그리고 한번 더 돌려서 검사하고
            // 그러면 다른 함수에서 검사가 끝난 값을 받아서 오는게 좋겠네 맞나? 맞다 그렇게 하려면  위의 체크 함수를 수정하자. 무슨 값이 리턴되는 지는 다른 부분 에서 중요하지 않다.
            // createStaemet 객체 생성 insert

            sql::PreparedStatement *stmnt = m_connection->prepareStatement("INSERT INTO USER (ID, PW, EMAIL, NICKNAME) values(?,?,?,?)");

            // 아이디 중복 확인
            // std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행

            // 쿼리 입력
            stmnt->setString(1, ID);
            stmnt->setString(2, PW);
            stmnt->setString(3, EMAIL);
            stmnt->setString(4, NICKNAME);

            // 객체의 내부 함수를 이용하여 쿼리를 실행
            stmnt->executeQuery();
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error INSERT USER: " << e.what() << std::endl;
            return "b";
        }
        return "a";
    }
    //  회원등급 UPDATE문 실행 함수(아이디를 이용하여 회원등급을 바꿈) 로그인시에 바뀌게 해야겠다
    //  RANK, SANCTION, R_BOOK, OVERDUE_HISTROY, OVERDUE_DATE 를 update할 거임
    //  함수 동작이상없이 동작 했으면 0 catch문에 잡혔으면 1반환
    //  윗 문장은 잘못된듯 반환하는 값은 잘된건지 아닌 건지만 반환하면 되잖아? 왜냐면!! 이미 데이터 베이스에서 동작을 끝냈으니까
    // 로그인시 자동으로 회원 업데이트하는 함수
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

            // std::cout << res1->getString(1) << std::endl; // 가입일부터 6개월 지난 시점
            // std::cout << res2->getString(1) << std::endl; // 현재 시간
            int rtc1; // 가입일 6개월 지난 시간
            int rtc2; // 현재시간

            // std::cout << "ok2" << std::endl;

            rtc1 = std::stoi((std::string)res1->getString(1));
            rtc2 = std::stoi((std::string)res2->getString(1));
            // std::cout << rtc1 << std::endl;
            // std::cout << rtc2 << std::endl;
            // std::cout << "okok" << std::endl;
            int rtc3; // 제재 시작후 30일이 지난 날짜

            if (((std::string)res3->getString(1)).empty())
            {
                std::cout << "제재 기록 없음 " << std::endl;
            }
            else
            {
                rtc3 = std::stoi((std::string)res3->getString(1));
                // std::cout << rtc3 << "okokokokokok" << std::endl;
                // 블랙 회원 제재기간이 끝나면 회원 등급을 0으로 조정시켜주기
                if (rtc3 <= rtc2)
                {
                    // std::cout << "rtc3" << rtc3 << std::endl;
                    // std::cout << "saction OVER" << std::endl;
                    // 제재가 끝났다 그러면 overdue 를 초기화 시키고 그리고 rank도 0으로 만들어준다.
                    stmnt6->executeQuery(); // 제재 날짜 11111111로 바꿔주기 제재가 끝났으니까 그리고 overdue_history,overdue_date를 0으로  초기화 시킨다.
                    stmnt3->setInt(1, 0);   // rank 기본등급으로 바꿔주기
                    Return_date(User_id);
                }
            }

            //  우수회원으로 변환
            if (rtc1 < rtc2 && res->getInt(8) >= 10)
            {
                // std::cout << "ok3";
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

    // 세빈세빈
    // 도서기본정보 a, b
    std::string Bookinfo(std::string Enrollednum) // 도서기본정보
    {
        asd.resize(0);
        qwe.resize(0);
        try
        {
            {
                sql::Statement *stmnt = m_connection->createStatement();
                sql::ResultSet *res = stmnt->executeQuery("SELECT Bname, Bwriter, Pperson, Pyear, Call_number, Bsituation FROM BOOKINFO WHERE Enrollednum = '" + Enrollednum + "'");
                while (res->next())
                {
                    asd.push_back((std::string)res->getString(1));
                    asd.push_back((std::string)res->getString(2));
                    asd.push_back((std::string)res->getString(3));
                    asd.push_back((std::string)res->getString(4));
                    asd.push_back((std::string)res->getString(5));
                    asd.push_back((std::string)res->getString(6));
                    qwe.push_back((asd));
                }
                return "a";
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
            return "b";
        }
        return "a";
    }
    // 책이름 a,b
    std::string Bnamesearch(std::string Bname)
    {
        asd.resize(0);
        qwe.resize(0);
        try
        {
            {
                sql::Statement *stmnt = m_connection->createStatement(); // 도서명별
                sql::ResultSet *res = stmnt->executeQuery("SELECT Bwriter, Pperson, Pyear, Call_number FROM BOOKINFO WHERE Bname = '" + Bname + "'");
                while (res->next())
                {
                    asd.push_back((std::string)res->getString(1));
                    asd.push_back((std::string)res->getString(2));
                    asd.push_back((std::string)res->getString(3));
                    asd.push_back((std::string)res->getString(4));
                    qwe.push_back(asd);
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
            return "b";
        }
        return "a";
    }
    // 작가 a,b
    std::string Bwritersearch(std::string Bwriter)
    {
        asd.resize(0);
        qwe.resize(0);
        try
        {
            {
                sql::Statement *stmnt = m_connection->createStatement(); // 작가별
                sql::ResultSet *res = stmnt->executeQuery("SELECT Bname, Pperson, Pyear, Call_number FROM BOOKINFO WHERE Bwriter = '" + Bwriter + "'");
                while (res->next())
                {
                    asd.push_back((std::string)res->getString(1));
                    asd.push_back((std::string)res->getString(2));
                    asd.push_back((std::string)res->getString(3));
                    asd.push_back((std::string)res->getString(4));
                    qwe.push_back(asd);
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
            return "b";
        }
        return "a";
    }
    // 출판사 a,b
    std::string Ppersonsearch(std::string Pperson)
    {
        asd.resize(0);
        qwe.resize(0);
        try
        {
            {
                sql::Statement *stmnt = m_connection->createStatement(); // 발행자별
                sql::ResultSet *res = stmnt->executeQuery("SELECT Bname, Bwriter, Pyear, Call_number FROM BOOKINFO WHERE Pperson = '" + Pperson + "'");
                while (res->next())
                {
                    asd.push_back((std::string)res->getString(1));
                    asd.push_back((std::string)res->getString(2));
                    asd.push_back((std::string)res->getString(3));
                    asd.push_back((std::string)res->getString(4));
                    qwe.push_back(asd);
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
            return "b";
        }
        return "a";
    }
    // 출판년도 a,b
    std::string Pyearsearch(std::string Pyear) // 발행연도별
    {
        asd.resize(0);
        qwe.resize(0);
        try
        {
            {
                sql::Statement *stmnt = m_connection->createStatement();
                sql::ResultSet *res = stmnt->executeQuery("SELECT Bname, Bwriter, Pperson, Call_number FROM BOOKINFO WHERE Pyear = '" + Pyear + "'");
                res->next();
                asd.push_back((std::string)res->getString(1));
                asd.push_back((std::string)res->getString(2));
                asd.push_back((std::string)res->getString(3));
                asd.push_back((std::string)res->getString(4));
                qwe.push_back(asd);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
            return "b";
        }
        return "a";
    }

    // 통합검색
    std::string search_book(std::string str)
    {
        asd.resize(0);
        qwe.resize(0);
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT Bname, Bwriter, Pyear, Call_number FROM BOOKINFO WHERE Bname LIKE ?");
            stmnt->setString(1, "%" + str + "%");
            sql::ResultSet *res = stmnt->executeQuery();
            while (res->next())
            {
                asd.push_back((std::string)res->getString(1));
                asd.push_back((std::string)res->getString(2));
                asd.push_back((std::string)res->getString(3));
                asd.push_back((std::string)res->getString(4));
                qwe.push_back(asd);
                asd.resize(0);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러" << e.what() << '\n';
            return "b";
        }
        return "a";
    }

    // 상세검색
    std::string search_d_book(std::string name, std::string writer, std::string producer, std::string year, std::string genre)
    {
        asd.resize(0);
        qwe.resize(0);
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT Bname, Bwriter, Pyear, Call_number FROM BOOKINFO WHERE Bname LIKE ? AND Bwriter LIKE ? AND Pperson LIKE ? AND Pyear LIKE ? AND (Call_number LIKE ? OR Call_number LIKE ?)");
            stmnt->setString(1, "%" + name + "%");
            stmnt->setString(2, "%" + writer + "%");
            stmnt->setString(3, "%" + producer + "%");
            stmnt->setString(4, "%" + year + "%");
            stmnt->setString(5, "%" + genre + "__.%");
            stmnt->setString(6, "%" + genre + "__-%");

            sql::ResultSet *res = stmnt->executeQuery();
            while (res->next())
            {
                asd.push_back((std::string)res->getString(1));
                asd.push_back((std::string)res->getString(2));
                asd.push_back((std::string)res->getString(3));
                asd.push_back((std::string)res->getString(4));
                qwe.push_back(asd);
                asd.resize(0);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러" << e.what() << '\n';
            return "b";
        }
        return "a";
    }

    // 추천도서
    std::string Sugest_b()
    {
        asd.resize(0);
        qwe.resize(0);
        try
        {
            sql::Statement *stmnt2 = m_connection->createStatement();
            sql::ResultSet *res = stmnt2->executeQuery("select Bname,Bwriter,Pperson from BOOKINFO ORDER BY RAND() LIMIT 5");
            while (res->next())
            {
                asd.push_back(std::string(res->getString(1)));
                asd.push_back(std::string(res->getString(2)));
                asd.push_back(std::string(res->getString(3)));
                qwe.push_back(asd);
                asd.resize(0);
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
    void Return_date(string id)
    {
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("UPDATE RENT_INFO SET R_STAT = 'R' WHERE ID = ?");
            sql::PreparedStatement *stmnt1 = m_connection->prepareStatement("UPDATE RENT_INFO SET R_OVER = 0 WHERE ID = ?");
            stmnt->setString(1, id);
            stmnt1->setString(1, id);

            sql::ResultSet *res = stmnt->executeQuery();
            sql::ResultSet *res1 = stmnt1->executeQuery();

            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error Return_info: " << e.what() << std::endl;
        }
    }

    std::string defineID(std::string EN) // 도서 반납 시 반납 회원 리턴
    {
        std::string id;
        try
        {
            sql::PreparedStatement *RT = m_connection->prepareStatement("SELECT ID FROM RENT_INFO where B_id = ? AND R_stat = 'R'");
            RT->setString(1, EN);
            sql::ResultSet *res = RT->executeQuery();
            while (res->next())
            {
                id = (std::string)res->getString(1);
                return id;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return "";
        }
        return "";
    }

    void makeblack(std::string EN) // 블랙 회원 조건 달성 시 변경
    {
        try
        {
            std::string id = defineID(EN);
            overdue(id);
            if (id == "")
                return;
            else
            {
                sql::PreparedStatement *RT = m_connection->prepareStatement("UPDATE USER SET RANK = (CASE WHEN ((SELECT OVERDUE_HISTORY FROM USER WHERE USER_ID = ?) > 2) OR ((SELECT OVERDUE_DATE FROM USER WHERE USER_ID = ?) > 14) THEN 2 ELSE (SELECT RANK FROM USER WHERE USER_ID = ?) END) WHERE USER_ID = ?)");
                RT->setString(1, id);
                RT->setString(2, id);
                RT->setString(3, id);
                RT->setString(4, id);
                RT->executeQuery();
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "update() error: " << e.what() << '\n';
        }
        return;
    }

    std::vector<std::vector<std::string>> Bookgenresearch(std::string Call_number);

    std::vector<std::vector<std::string>> res_search()
    {
        return qwe;
    }
    void CONNECTION_STATUS(int PRIMARY_NUMBER)
    // 이거 나중에 합시다
    {
        try
        { // 로그인 할때
            sql::PreparedStatement *C_status = m_connection->prepareStatement("UPDATE USER SET CONNECTION_STATUS = 1 WHERE PRIMARY_NUMBER = ?");
            // 로그인중이 아닐 때
            sql::PreparedStatement *C_status1 = m_connection->prepareStatement("UPDATE USER SET CONNECTION_STATUS = 1 WHERE PRIMARY_NUMBER = ?");
            // sql::PreparedStatement *friend = m_connection->prepareStatement("UPDATE F_LIST SET OVERDUE_DATE = (SELECT SUM(R_over) FROM RENT_INFO WHERE ID = ?) WHERE USER_ID = ?");

            C_status->setInt(1, PRIMARY_NUMBER);
            C_status->setInt(2, PRIMARY_NUMBER);
            // DA->setString(1, id);
            // DA->setString(2, id);
            C_status->executeQuery();
            // DA->executeQuery();
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting overdue: " << e.what() << std::endl;
        }
    }
    void LOGIN_FAILED(std::string ID)
    // 로그인 실패시 카운트  올라가기
    {
        try
        { // 로그인 실패시
            sql::PreparedStatement *FL_COUNT = m_connection->prepareStatement("UPDATE USER SET CONNECTION_FAILED = USER.CONNECTION_FAILED + 1 where ID = ?");
            //   update USER set CONNECTION_FAILED = USER.CONNECTION_FAILED + 1 where PRIMARY_NUMBER = '1'
            FL_COUNT->setString(1, ID);
            FL_COUNT->executeQuery();
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting LOGIN_COUNTFAILED: " << e.what() << std::endl;
        }
    }
    // 로그인 실패 5회 이상일 때
    void LOGIN_FAILED(std::string ID)
    // 로그인 실패시 카운트  5회 이상이면 로그인 다르게 하기
    {
        try
        { // 로그인 실패시
            sql::PreparedStatement *FL_COUNT = m_connection->prepareStatement("UPDATE USER SET CONNECTION_FAILED = USER.CONNECTION_FAILED + 1 where ID = ?");
            //   update USER set CONNECTION_FAILED = USER.CONNECTION_FAILED + 1 where PRIMARY_NUMBER = '1'
            FL_COUNT->setString(1, ID);
            FL_COUNT->executeQuery();
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting LOGIN_FAILED: " << e.what() << std::endl;
        }
    }
};
