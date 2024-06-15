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
        account("ADMIN", "1234");
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
            sql::SQLString url = "jdbc:mariadb://10.10.21.103/P8";
            sql::Properties properties({{"user", m_id}, {"password", m_pw}});
            this->m_connection = driver->connect(url, properties);
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

    // 전체 친구 목록 호출함수. 리턴값: 성공시 ','로 구분되는 친구들의 고유번호,NICK,STATUS || 실패시 "fail", 버그시 "bug";
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

    // 친구신청 리턴값: 친구신청성공 Y, 아이디부존재 N, 이미신청혹은친구상태 n, db에러 E
    std::string add_mate(const std::string id, const std::string mate_num)
    {
        try
        {
            // 고유번호 존재여부 확인
            sql::PreparedStatement *check = m_connection->prepareStatement("SELECT NO FROM USER WHERE ID = ?");
            check->setInt(1, std::stoi(id));
            sql::ResultSet *resCheck = check->executeQuery();
            // 아이디 존재
            if (resCheck->next())
            {
                int userNo = resCheck->getInt(1);
                // 이미 신청였거나 이미 친구상태인지 확인
                sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT COUNT(*) FROM MATE WHERE (SENDID = ? AND RECVID = ? AND (STATUS != -1 AND STATUS != 1)) OR (RECVID = ? AND SENDID = ? AND (STATUS != -1 AND STATUS != 1))");
                stmnt->setInt(1, userNo);
                stmnt->setInt(2, std::stoi(mate_num));
                stmnt->setInt(3, userNo);
                stmnt->setInt(4, std::stoi(mate_num));
                sql::ResultSet *res = stmnt->executeQuery();
                if (res->next() && userNo != std::stoi(mate_num))
                {
                    int checker2 = res->getInt(1);
                    // 이미 친구신청 중이거나 친구인 상태
                    if (checker2 == 0)
                    {
                        return "n";
                    }
                    // 친구 신청이 가능한 상태
                    else if (checker2 > 0)
                    {
                        sql::PreparedStatement *stmnt2 = m_connection->prepareStatement("INSERT INTO MATE (SENDID, RECVID) VALUES (?, ?)");
                        stmnt2->setInt(1, userNo);
                        stmnt2->setInt(2, std::stoi(mate_num));
                        stmnt2->executeQuery();
                        return "Y";
                    }
                    // 에러
                    else
                    {
                        return "e";
                    }
                }
                // 아이디 부존재(0)
                else
                    return "N";
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
            if (result != 0)
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

    // 채팅창을 리턴하는 함수
    std::string Call_ChatroomList(std::string id)
    {
        try
        {
            sql::PreparedStatement *stmnt0 = m_connection->prepareStatement("");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return "";
    }

    // 채팅방에 접속 시 참석 변화
    void attend_room(std::string no, std::string room)
    {
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("UPDATE CHATROOM SET ATTEND = 1 WHERE MEMBER = ? AND ROOMNAME = ?");
            stmnt->setInt(1, std::stoi(no));
            stmnt->setString(2, room);
            stmnt->executeQuery();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // 채팅방에서 나갈 시 참석 변화
    void deattend_room(std::string no, std::string room)
    {
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("UPDATE CHATROOM SET ATTEND = 0 WHERE MEMBER = ? AND ROOMNAME = ?");
            stmnt->setInt(1, std::stoi(no));
            stmnt->setString(2, room);
            stmnt->executeQuery();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // 채팅 멤버를 소켓에 푸쉬백하는 함수
    void Call_Chatroom_Member(std::string roomname, std::vector<int> &socks)
    {
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT FD FROM USER WHERE NO IN (SELECT MEMBER FROM CHATROOM WHERE ROOMNAME = ? AND ATTEND = 1)");
            stmnt->setString(1, roomname);
            sql::ResultSet *res = stmnt->executeQuery();
            while (res->next())
            {
                socks.push_back(res->getInt(1));
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return;
    }

    // 유저 정보를 리턴하는 함수
    std::string Call_UserInfo(std::string id)
    {
        try
        {
            sql::PreparedStatement *stmnt = m_connection->prepareStatement("SELECT * FROM USER WHERE ID = ?");
            stmnt->setString(1, id);
            sql::ResultSet *res = stmnt->executeQuery();
            if (res->next())
            {
                std::string no = std::to_string(res->getInt(1));
                std::string id = (std::string)(res->getString(2));
                std::string nick = (std::string)(res->getString(4));
                std::string result = no + "," + id + "," + nick;
                return result;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return "e";
    }

    // 유저의 채팅방 목록을 보여주는 함수
    std::string RoomList(std::string no)
    {
        std::string result = "";
        try
        {
            std::string temp;

            sql::PreparedStatement* stmnt = m_connection->prepareStatement("SELECT ROOMNAME FROM CHATROOM WHERE MEMBER = ?");
            stmnt->setInt(1, std::stoi(no));
            sql::ResultSet* res = stmnt->executeQuery();
            while(res->next())
            {
                temp = res->getString(1);
                result.append(temp);
                result.append("\n");

            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return "e";
        }
        return result;
    }

    // 유저가 채팅방을 참가하는 함수
    void room_make(std::string no, std::string room)
    {
        try
        {
            sql::PreparedStatement* stmnt = m_connection->prepareStatement("INSERT INTO CHATROOM VALUES (DEFAULT, ?, ?, 0)");
            stmnt->setInt(1, std::stoi(no));
            stmnt->setString(2, room);
            stmnt->executeQuery();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    
    // 1:1 채팅방을 생성하는 함수
    void mate_roomMake(std::string no, std::string mateNo)
    {
        try
        {
            std::string roomName = "temproom" + no + "to" + mateNo;
            sql::PreparedStatement* stmnt1 = m_connection->prepareStatement("INSERT INTO CHATROOM VALUES (DEFAULT, ?, ?, DEFAULT)");
            stmnt1->setInt(1, std::stoi(no));
            stmnt1->setString(2, roomName);
            sql::PreparedStatement* stmnt2 = m_connection->prepareStatement("INSERT INTO CHATROOM VALUES (DEFAULT, ?, ?, DEFAULT)");
            stmnt2->setInt(1, std::stoi(mateNo));
            stmnt2->setString(2, roomName);

            stmnt1->executeQuery();
            stmnt2->executeQuery();

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }






};