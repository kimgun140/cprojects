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
    DB()
    {
        account("OPERATOR", "1234");
        connect();
    }
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
            sql::SQLString url = "jdbc:mariadb://localhost:3306/chat";
            sql::Properties properties({{"user", m_id}, {"password", m_pw}});
            this->m_connection = driver->connect(url, properties);
            // cout << "DB 접속\n";
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "DB 접속실패: " << e.what() << '\n';
        }
    }
    // 리턴값: id비중복 a, id중복 b, 오류발생 c
    std::string IDcheck(std::string ID)
    {
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT * FROM USER WHERE ID = ?");

            // sql::PreparedStatement *check = m_connection->prepareStatement("SELECT ID FROM USER WHERE ID = ?");
            stmnt->setString(1, ID);
            sql::ResultSet *res = stmnt->executeQuery();
            while (res->next())
                return "b";
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return "c"; // 오류
        }
        return "a";
    }

    // 리턴값: id비중복 a, id중복 b, 오류발생 c
    std::string EMAILcheck(std::string email)
    {
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT * FROM USER WHERE EMAIL = ?");
            stmnt->setString(1, email);
            sql::ResultSet *res = stmnt->executeQuery();
            while (res->next())
                return "b";
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return "c"; // 오류
        }
        return "a";
    }

    // 리턴값: 고유번호, 오류시 b
    std::string insert_member(std::string line)
    {
        try
        {
            std::stringstream input(line);
            std::string id;
            std::string pw;
            std::string e;
            std::string n;
            getline(input, id, ',');
            getline(input, pw, ',');
            getline(input, e, ',');
            getline(input, n, ',');
            sql::PreparedStatement *stmnt =
                m_connection->prepareStatement("INSERT INTO USER (ID, PW, NICK, EMAIL) VALUES (?, ?, ?, ?)");
            stmnt->setString(1, id);
            stmnt->setString(2, pw);
            stmnt->setString(3, e);
            stmnt->setString(4, n);
            stmnt->executeQuery();
            sql::PreparedStatement *check =
                m_connection->prepareStatement("SELECT * FROM USER WHERE ID = ? AND PW = ? AND NICK = ? AND EMAIL = ?");
            check->setString(1, id);
            check->setString(2, pw);
            check->setString(3, e);
            check->setString(4, n);
            sql::ResultSet *res = check->executeQuery();
            if (res->next())
            {
                int num = res->getInt(1);
                return std::to_string(num);
            }
            else
            {
                return "b";
            }
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
        }
        return "c"; // 오류
    }

    // 리턴값: 로그인성공 시 0, 로그인실패 실패 횟수(1~5)
    std::string check_login(std::string line, int sock, std::string &id)
    {
        try
        {
            std::stringstream input(line);
            // std::string id;
            std::string pw;
            getline(input, id, ',');
            getline(input, pw, ',');
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT NO FROM USER WHERE ID = ? AND PW = ?");
            stmnt->setString(1, id);
            stmnt->setString(2, pw);
            sql::ResultSet *res = stmnt->executeQuery();
            while (res->next())
            {
                // 접속상태 변환
                // fd키 등록
                int num = login_true_update(id, pw, sock);
                return std::to_string(num);
            }
            // 로그인 실패 시 유저정보 수정
            int num = login_false_num(id);
            return std::to_string(num);
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error login USER: " << e.what() << std::endl;
        }
        return "9"; // 오류
    }

    // 리턴값 성공시: 0 || 실패시: 5 || 오류발생: 9
    int login_true_update(std::string id, std::string pw, int sock)
    {
        int num = 1;
        try
        {
            sql::PreparedStatement *stmnt3 =
                m_connection->prepareStatement("SELECT WRONG FROM USER WHERE ID = ? AND PW = ?");
            stmnt3->setString(1, id);
            stmnt3->setString(2, pw);
            sql::ResultSet *res = stmnt3->executeQuery();
            if (res->next())
            {
                num = res->getInt(1);
                std::cout << num << std::endl;
                if (num < 5)
                {
                    sql::PreparedStatement *stmnt1 =
                        m_connection->prepareStatement("UPDATE USER SET STATUS = 1 WHERE ID = ? AND PW = ?");
                    stmnt1->setString(1, id);
                    stmnt1->setString(2, pw);

                    sql::PreparedStatement *stmnt2 =
                        m_connection->prepareStatement("UPDATE USER SET FD = ? WHERE ID = ? AND PW = ?");
                    stmnt2->setInt(1, sock);
                    stmnt2->setString(2, id);
                    stmnt2->setString(3, pw);

                    sql::PreparedStatement *stmnt4 =
                        m_connection->prepareStatement("UPDATE USER SET WRONG = 0 WHERE ID = ? AND PW = ?");
                    stmnt4->setString(1, id);
                    stmnt4->setString(2, pw);

                    stmnt1->executeQuery();
                    stmnt2->executeQuery();
                    stmnt4->executeQuery();
                    return 0;
                }
                else
                    return 5;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error updating user when loginSuccess: " << e.what() << '\n';
        }
        return 9;
    }

    // 리턴값 실패횟수1~4: 1~4 || 실패횟수 5이상: 5 || 오류발생: 9
    int login_false_num(std::string id)
    {
        int num = 1;
        try
        {
            sql::PreparedStatement *stmnt1 =
                m_connection->prepareStatement("SELECT WRONG FROM USER WHERE ID = ?");
            stmnt1->setString(1, id);
            sql::ResultSet *res = stmnt1->executeQuery();
            if (res->next())
            {
                num = res->getInt(1);
                if (num < 5)
                {
                    sql::PreparedStatement *stmnt2 =
                        m_connection->prepareStatement("UPDATE USER SET WRONG = ? WHERE ID = ?");
                    stmnt2->setInt(1, num + 1);
                    stmnt2->setString(2, id);
                    stmnt2->executeQuery();
                    return num + 1;
                }
                else
                    return 5;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "login error when loginfail: " << e.what() << '\n';
        }
        return 9;
    }

    // 리턴값 성공: 0 || 실패: 1, 아이디부존재:2 비번틀림:3 고유번호오류:4 || 오류: 9
    std::string check_SLogin(std::string line, int sock, std::string &id)
    {
        try
        {
            std::stringstream input(line);
            std::string pw, num;
            std::string cid, cpw, cnum;
            getline(input, id, ',');
            getline(input, pw, ',');
            getline(input, num, ',');

            sql::PreparedStatement *stmnt =
                m_connection->prepareStatement("SELECT ID, PW, NO FROM USER WHERE ID = ?");
            stmnt->setString(1, id);
            sql::ResultSet *res = stmnt->executeQuery();
            if (res->next())
            {
                cid = res->getString(1);
                cpw = res->getString(2);
                cnum = std::to_string(res->getInt(3));
                if (cpw != pw)
                    return "3";
                else if (cnum != num)
                    return "4";
                else
                {
                    sql::PreparedStatement *stmnt2 =
                        m_connection->prepareStatement("UPDATE USER SET WRONG = 0 WHERE ID = ? AND PW = ?");
                    stmnt2->setString(1, id);
                    stmnt2->setString(2, pw);
                    stmnt2->executeQuery();

                    sql::PreparedStatement *stmnt3 =
                        m_connection->prepareStatement("UPDATE USER SET STATUS = 1 WHERE ID = ? AND PW = ?");
                    stmnt3->setString(1, id);
                    stmnt3->setString(2, pw);
                    stmnt3->executeQuery();

                    sql::PreparedStatement *stmnt4 =
                        m_connection->prepareStatement("UPDATE USER SET FD = ? WHERE ID = ? AND PW = ?");
                    stmnt4->setInt(1, sock);
                    stmnt4->setString(2, id);
                    stmnt4->setString(3, pw);
                    stmnt4->executeQuery();

                    return "0";
                }
            }
            else
            {
                return "2";
            }
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return "9"; // 오류
        }
        return "1";
    }

    // DEBUG 하지 않은 함수들

    // 전체 친구 목록 호출함수용 함수
    std::string Call_mate_all_sub01(int user_no)
    {
        try
        {
            std::string result;
            // 내 고유번호로 찾는다 내가 친구 신청을 했거나, 내가 친구를 신청을 받았는데 그 신청의 상태가 수락인(친구 상태인) 상대편(친구)의 id,nick,접속상태를 뽑아오는거네
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT ID, NICK, STATUS FROM USER WHERE (STATUS = 1 OR STATUS = 0) AND NO IN (SELECT MATE.RECVID FROM MATE WHERE MATE.SENDID = ? AND MATE.STATUS = 1 UNION SELECT MATE.SENDID FROM MATE WHERE MATE.RECVID = ? AND MATE.STATUS = 1)");
            stmnt->setInt(1, user_no);
            stmnt->setInt(2, user_no);
            sql::ResultSet *res = stmnt->executeQuery();
            //    std::cout << "call_mate_all_sub01 돌아가냐?"<<std::endl;

            while (res->next())
            { // id/nick/status/\n 개행문자까지만 읽으니까 이걸 반복시키면 그 사람들을 다 끊어서 가져올 수 있겠네
                // id/nick/status/
                result.append((std::string)res->getString(1));
                result.append(",");
                result.append((std::string)res->getString(2));
                result.append(",");
                result.append(std::to_string(res->getInt(3)));
                result.append("\n");
                std::cout << result << std::endl;
                std::cout << "result" << std::endl;
            }
            return result;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return "e";
    }

    // 전체 친구 목록 호출함수. 리턴값: 성공시 ','로 구분되는 친구들의 고유번호,NICK,STATUS || 실패시 "fail", 버그시 "bug";
    std::string Call_Mate_all(std::string id)
    {
        try
        {
            sql::PreparedStatement *stmn1 = m_connection->prepareStatement("SELECT ID FROM USER WHERE ID = ?"); // 내....
            stmn1->setString(1, id);
            sql::ResultSet *res = stmn1->executeQuery();
            if (res->next())
            {
                int user_ID = res->getInt(1);
                std::string mates = Call_mate_all_sub01(user_ID); // 고유번호를 매개변수로 주네
                return mates;
            }
            else
            {
                return "fail";
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "친구전체목록 호출 중 에러: " << e.what() << '\n';
        }
        return "bug";
    }

    // 친구신청 리턴값: 친구신청성공 Y, 아이디부존재 N, 이미신청혹은친구상태 n, db에러 E
    std::string add_mate(const std::string id, const std::string mate_num)
    {
        try
        {
            // 고유번호 존재여부 확인
            sql::PreparedStatement *check = m_connection->prepareStatement("SELECT NO FROM USER WHERE ID = ?");
            check->setInt(1, std::stoi(id));
            sql::ResultSet *resCheck = check->executeQuery();
            std::cout << "check1" << std::endl;
            // 아이디 존재
            if (resCheck->next())
            {
                std::cout << "check2" << std::endl;

                int userNo = resCheck->getInt(1);
                // 이미 신청였거나 이미 친구상태인지 확인 1친구 -1 대기 0 친구아님 거부
                // 이거 하면 나오는게 뭐냐면 status 가 0인걸 찾는거임           그래서 0이면 친구 신청이 거부된거임 카운트가 있으면 친구
                // status가 -1이 있으면 친구 추가가 되네
                sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT COUNT(*) FROM MATE WHERE (SENDID = ? AND RECVID = ? AND (STATUS != -1 AND STATUS != 1)) OR (RECVID = ? AND SENDID = ? AND (STATUS != -1 AND STATUS != 1))");
                stmnt->setInt(1, userNo);
                stmnt->setInt(2, std::stoi(mate_num));
                stmnt->setInt(3, userNo);
                stmnt->setInt(4, std::stoi(mate_num));
                sql::ResultSet *res = stmnt->executeQuery();
                if (res->next() && userNo != std::stoi(mate_num))
                {
                    std::cout << "check3" << std::endl;
                    int checker2 = res->getInt(1);
                    // 이미 친구신청 중이거나 친구인 상태
                    if (checker2 == 0)
                    {
                        std::cout << "check4" << std::endl;
                        return "n";
                    }
                    // 친구 신청이 가능한 상태
                    else if (checker2 == 1)
                    {
                        std::cout << "check5" << std::endl;

                        sql::PreparedStatement *stmnt2 = m_connection->prepareStatement("INSERT INTO MATE (SENDID, RECVID) VALUES (?, ?)");
                        stmnt2->setInt(1, userNo);
                        stmnt2->setInt(2, std::stoi(mate_num));
                        stmnt2->executeQuery();
                        return "Y";
                    }
                    // 에러
                    else
                    {
                        std::cout << "check6" << std::endl;

                        return "e";
                    }
                }
                // 아이디 부존재(0)
                else
                {
                    std::cout << "check7" << std::endl;

                    return "N";
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "친구추가 중 에러" << e.what() << '\n';
        }
        return "e";
    }
    // 친구 삭제
    std::string Erase_Mate(const std::string id, const std::string FID)
    {
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT A.NO FROM USER AS A WHERE A.ID = ? UNION SELECT B.NO FROM USER AS B WHERE B.ID = ?");
            stmnt->setString(1, id);
            stmnt->setString(2, FID);
            sql::ResultSet *res = stmnt->executeQuery();

            int user_no, fri_no;

            if (res->next())
                user_no = res->getInt(1);
            else
                return "e";

            if (res->next())
                fri_no = res->getInt(1);
            else
                return "e";

            sql::PreparedStatement *stmnt2 = m_connection->prepareStatement("UPDATE MATE SET STATUS = 0 WHERE (SENDID = ? AND RECVID = ? AND STATUS = 1) OR (SENDID = ? AND RECVID = ? AND STATUS = 1)");

            stmnt2->setInt(1, user_no);
            stmnt2->setInt(2, fri_no);
            stmnt2->setInt(3, fri_no);
            stmnt2->setInt(4, user_no);

            stmnt2->executeQuery();

            sql::PreparedStatement *stmnt3 = m_connection->prepareStatement("SELECT ROW_COUNT()");
            sql::ResultSet *res2 = stmnt3->executeQuery();
            res2->next();
            int result = res2->getInt(1);
            if (result == 1)
                return "Y";
            else
                return "e";
        }
        catch (const std::exception &e)
        {
            std::cerr << "친구 삭제 중 오류: " << e.what() << '\n';
            return "e";
        }
        return "Y";
    }

    // 친구 요청을 한 유저정보 반환 실패시:e
    std::string Call_requestMate(std::string user_id)
    {
        std::string result = "";
        std::cout << "Call_requestMate1" << std::endl;
        
        try
        {
            sql::PreparedStatement *stmnt0 = m_connection->prepareStatement("SELECT NO FROM USER WHERE ID = ?");
            stmnt0->setString(1, user_id);
            sql::ResultSet *res0 = stmnt0->executeQuery();
            res0->next();
            int user_no = res0->getInt(1);
            std::cout << "Call_requestMate2" << std::endl;

            sql::PreparedStatement *stmnt1 = m_connection->prepareStatement("SELECT NO, NICK FROM USER WHERE USER.ID IN(SELECT SENDID FROM MATE WHERE RECVID = ? AND STATUS = -1)");
            stmnt1->setString(1, user_id);
            sql::ResultSet *res1 = stmnt1->executeQuery();
            while (res1->next())
            {
                std::cout << "Call_requestMate3" << std::endl;
                result.append(std::to_string(res1->getInt(1)));
                result.append(",");
                result.append(std::string(res1->getString(2)));
                result.append("\n");
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "친구 요청 확인 중 오류: " << e.what() << '\n';
            return "e";
        }
        return result;
    }

    // 친구 요청 승락
    void accept_mate(std::string user_id, std::string sender)
    {
        try
        {
            sql::PreparedStatement *stmnt0 = m_connection->prepareStatement("SELECT NO FROM USER WHERE ID = ?");
            stmnt0->setString(1, user_id);
            sql::ResultSet *res0 = stmnt0->executeQuery();
            res0->next();
            int userNo = res0->getInt(1);
            int sendNo = std::stoi(sender);
            if (userNo != sendNo)
            {
                sql::PreparedStatement *stmnt = m_connection->prepareStatement("UPDATE MATE SET STATUS = 1 WHERE SENDID = ? AND RECVID = ?");
                stmnt->setInt(1, sendNo);
                stmnt->setInt(2, userNo);
                stmnt->executeQuery();
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "친구요청승락 중 오류: " << e.what() << '\n';
        }
    }
    // 친구 요청 거부
    void deny_mate(std::string user_id, std::string sender)
    {
        try
        {
            sql::PreparedStatement *stmnt0 = m_connection->prepareStatement("SELECT NO FROM USER WHERE ID = ?");
            stmnt0->setString(1, user_id);
            sql::ResultSet *res0 = stmnt0->executeQuery();
            res0->next();
            int userNo = res0->getInt(1);
            if (userNo != std::stoi(sender))
            {
                sql::PreparedStatement *stmnt = m_connection->prepareStatement("UPDATE MATE SET STATUS = 0 WHERE SENDID = ? AND RECVID = ?");
                stmnt->setInt(1, std::stoi(sender));
                stmnt->setInt(2, userNo);
                stmnt->executeQuery();
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "친구요청거부 중 오류: " << e.what() << '\n';
        }
    }

    //  로그아웃  성공 1 오류 2
    std::string Logout(std::string id)
    {
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("UPDATE USER SET STATUS = 0 WHERE ID = ?");
            sql::PreparedStatement *stmnt1 = m_connection->prepareStatement("UPDATE USER SET FD = NULL WHERE ID = ?");

            stmnt->setString(1, id);
            stmnt1->setString(1, id);
            sql::ResultSet *res = stmnt->executeQuery();
            sql::ResultSet *res1 = stmnt1->executeQuery();
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting USER: " << e.what() << std::endl;
            return "2"; // 오류
        }
        return "1";
    }
};
