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
    std::string check_login(std::string line, int sock)
    {
        try
        {
            std::stringstream input(line);
            std::string id;
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
    std::string check_SLogin(std::string line, int sock)
    {
        try
        {
            std::stringstream input(line);
            std::string id, pw, num;
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
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT ID, NICK, STATUS FROM USER WHERE (STATUS = 1 OR STATUS = 0) AND NO IN (SELECT MATE.RECVID FROM MATE WHERE MATE.SENDID = ? AND MATE.STATUS = 1 UNION SELECT MATE.SENDID FROM MATE WHERE MATE.RECVID = ? AND MATE.STATUS = 1)");
            stmnt->setInt(1, user_no);
            stmnt->setInt(2, user_no);
            sql::ResultSet *res = stmnt->executeQuery();
            while (res->next())
            {
                result.append((std::string)res->getString(1));
                result.append(",");
                result.append((std::string)res->getString(2));
                result.append(",");
                result.append(std::to_string(res->getInt(3)));
                result.append("\n");
            }
            return result;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return "e";
    }

    // 전체 친구 목록 호출함수. 리턴값: 성공시 ','로 구분되는 친구들의 고유번호, 실패시 "fail", 버그시 "bug";
    std::string Call_Mate_all(std::string id)
    {
        try
        {
            sql::PreparedStatement *stmn1 = m_connection->prepareStatement("SELECT NO FROM USER WHERE ID = ?");
            stmn1->setString(1, id);
            sql::ResultSet *res = stmn1->executeQuery();
            if (res->next())
            {
                int user_no = res->getInt(1);
                std::string mates = Call_mate_all_sub01(user_no);
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


    // 로그아웃  성공 1 오류 2
    std::string Logout(std::string line)
    {

        try
        {

            std::stringstream input(line);
            std::string id;
            std::string pw;
            getline(input, id, ',');
            getline(input, pw, ',');
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("UPDATE  USER SET STATUS = 0 WHERE ID = ?");
            sql::PreparedStatement *stmnt1 = m_connection->prepareStatement("UPDATE  USER SET FD = NULL WHERE ID = ?");

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
