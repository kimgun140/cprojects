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
    std::string m_id;              // DB 접속 아이디
    std::string m_pw;              // DB 접속 패스워드
    sql::Connection *m_connection; // DB 연결

public:
    DB() {}
    ~DB()
    {
        m_connection->close();
        std::cout << "DB 접속을 종료\n";
    }
    void account(const std::string &id, const std::string &pw)
    {
        this->m_id = id;
        this->m_pw = pw;
    }
    void connect() // db와 연결
    {
        try
        {
            sql::Driver *driver = sql::mariadb::get_driver_instance();
            sql::SQLString url = "jdbc:mariadb://10.10.21.103:3306/BM";       // db의 주소
            sql::Properties properties({{"user", m_id}, {"password", m_pw}}); // 로그인
            m_connection = driver->connect(url, properties);
            std::cout << "DB 접속 성공\n";
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "DB 접속 실패: " << e.what() << '\n';
        }
    }
};

class Book : public DB
{
public:
    std::vector<std::string> asd;
    std::vector<std::vector<std::string>> qwe;
    Book() {}
    Book(std::string id, std::string pw)
    {
        m_id = id;
        m_pw = pw;
        connect();
    }

    std::vector<std::vector<std::string>> Bookinfo(std::string Enrollednum) // 도서기본정보
    {
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

                    std::cout << res->getString(1);
                    std::cout << res->getString(2);
                    std::cout << res->getString(3);
                    std::cout << res->getString(4);
                    std::cout << res->getString(5);
                    std::cout << res->getString(6);
                    std::cout << "----------------------" << std::endl;
                }
                return qwe;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
        }
        return qwe;
    }

    std::vector<std::string> *Bnamesearch(std::string Bname)
    {
        std::vector<std::string> *i2 = new std::vector<std::string>;
        try
        {
            {
                sql::Statement *stmnt = m_connection->createStatement(); // 도서명별
                sql::ResultSet *res = stmnt->executeQuery("SELECT Bwriter, Pperson, Pyear, Call_number FROM BOOKINFO WHERE Bname = '" + Bname + "'");
                res->next();
                i2->push_back((std::string)res->getString(1));
                i2->push_back((std::string)res->getString(2));
                i2->push_back((std::string)res->getString(3));
                i2->push_back((std::string)res->getString(4));

                std::cout << res->getString(1);
                std::cout << res->getString(2);
                std::cout << res->getString(3);
                std::cout << res->getString(4);
                std::cout << "----------------------" << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
        }
        return i2;
    }

    std::vector<std::string> *Bwritersearch(std::string Bwriter)
    {
        std::vector<std::string> *i3 = new std::vector<std::string>;
        try
        {
            {
                sql::Statement *stmnt = m_connection->createStatement(); // 작가별
                sql::ResultSet *res = stmnt->executeQuery("SELECT Bname, Pperson, Pyear, Call_number FROM BOOKINFO WHERE Bwriter = '" + Bwriter + "'");
                res->next();
                i3->push_back((std::string)res->getString(1));
                i3->push_back((std::string)res->getString(2));
                i3->push_back((std::string)res->getString(3));
                i3->push_back((std::string)res->getString(4));
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
        }
        return i3;
    }

    std::vector<std::string> *Ppersonsearch(std::string Pperson)
    {
        std::vector<std::string> *i4 = new std::vector<std::string>;
        try
        {
            {
                sql::Statement *stmnt = m_connection->createStatement(); // 발행자별
                sql::ResultSet *res = stmnt->executeQuery("SELECT Bname, Bwriter, Pyear, Call_number FROM BOOKINFO WHERE Pperson = '" + Pperson + "'");
                res->next();
                i4->push_back((std::string)res->getString(1));
                i4->push_back((std::string)res->getString(2));
                i4->push_back((std::string)res->getString(3));
                i4->push_back((std::string)res->getString(4));
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
        }
        return i4;
    }

    std::vector<std::string> *Pyearsearch(std::string Pyear) // 발행연도별
    {
        std::vector<std::string> *i5 = new std::vector<std::string>;
        try
        {
            {
                sql::Statement *stmnt = m_connection->createStatement();
                sql::ResultSet *res = stmnt->executeQuery("SELECT Bname, Bwriter, Pperson, Call_number FROM BOOKINFO WHERE Pyear = '" + Pyear + "'");
                res->next();
                i5->push_back((std::string)res->getString(1));
                i5->push_back((std::string)res->getString(2));
                i5->push_back((std::string)res->getString(3));
                i5->push_back((std::string)res->getString(4));
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "입력에러 : " << e.what() << '\n';
        }
        return i5;
    }

    //     std::vector<std::string> Bookgenresearch(std::string Call_number);
};

// std::vector<std::string> book()
// {
//     std::vector<std::string> book;
//     std::string Enrollednum;
//     std::string query = "SELECT Bname, Bwriter, Pperson, Pyear, Call_number, Bsituation FROM BOOKINFO WHERE Enrollednum = '" + Enrollednum + "';";
//     sql::Statement*
// }

// std::vector<std::string> showbookname()
// {
//     std::vector<std::string> bookname;
//     std::string Bname;
//     std::string query = "SELECT Bname FROM BOOKINFO";
//     sql::Statement* bif(m_connection->createStatement());
//     sql::ResultSet* resBIF = bif->executeQuery(query);

//     while(resBIF->next())
//     {
//         std::cout << ") " << resBIF->getString(1) << " ";
//         Bname = resBIF->getString(1);
//         bookname.push_back(Bname);
//     }
//     std::cout << std::endl << std::endl;
//     return bookname;
// }

// std::vector<std::string> showbookwriter()
// {
//     std::vector<std::string> bookwriter;
//     std::string Bwriter;
//     std::string query = "SELECT Bwriter FROM BOOKINFO";
//     sql::Statement* bwr(m_connection->createStatement());
//     sql::ResultSet* resBWR = bwr->executeQuery(query);

//     while(resBWR->next())
//     {
//         std::cout << resBWR->getString(2) << " ";
//         Bwriter = resBWR->getString(2);
//         bookwriter.push_back(Bwriter);
//     }
//     std::cout << std::endl << std::endl;
//     return bookwriter;
// }

// std::vector<std::string> showbookpublisher()
// {
//     std::vector<std::string> bookpublisher;
//     std::string Pperson;
//     std::string query = "SELECT Pperson FROM BOOKINFO";
//     sql::Statement* pperson(m_connection->createStatement());
//     sql::ResultSet* resPPER = pperson->executeQuery(query);

//     while(resPPER->next())
//     {
//         std::cout << resPPER->getString(3) << " ";
//         Pperson = resPPER->getString(3);
//         bookpublisher.push_back(Pperson);
//     }
//     std::cout << std::endl << std::endl;
//     return bookpublisher;
// }

// std::vector<std::string> showbookpublishyear()
// {
//     std::vector<std::string> bookpublishyear;
//     std::string Pyear;
//     std::string query = "SELECT Pyear FROM BOOKINFO";
//     sql::Statement* pyear(m_connection->createStatement());
//     sql::ResultSet* resPY = pyear->executeQuery(query);

//     while(resPY->next())
//     {
//         std::cout << resPY->getString(4) << " ";
//         Pyear = resPY->getString(4);
//         bookpublishyear.push_back(Pyear);
//     }
//     std::cout <<std::endl << std::endl;
//     return bookpublishyear;
// }

// std::vector<std::string> showbookborrow()
// {
//     std::vector<std::string> bookborrow;
//     std::string Bsituation;
//     std::string query = "SELECT Bsituation FROM BOOKINFO";
//     sql::Statement* bsituation(m_connection->createStatement());
//     sql::ResultSet* resBS = bsituation->executeQuery(query);

//     while(resBS->next())
//     {
//         std::cout << resBS->getBoolean(5) << " ";
//         Bsituation = resBS->getBoolean(5);
//         bookborrow.push_back(Bsituation);
//     }
//     std::cout << std::endl << std::endl;
//     return bookborrow;
// }

// void showEnrollednum(const std::string& Enrollednum)
// {
//     try
//     {
//         std::string query = "SELECT Bname, Bwriter, Pperson, Pyear, Call_number, Bsituation FROM BOOKINFO WHERE Enrollednum = '" + Enrollednum + "';";
//         sql::ResultSet *res = ();
//         while(res->next())
//         {
//             std::cout << "등록번호 = " << Enrollednum;
//             std::cout << "  도서명 = " << res->getString(1);
//             std::cout << ", 저작자 = " << res->getString(2);
//             std::cout << ", 발행자 = " << res->getString(3);
//             std::cout << ", 발행연도 = " << res->getString(4);
//             std::cout << ", 청구기호 = " << res->getString(5);
//             std::cout << ", 대여여부 = " << res->getString(6);
//             std::cout << std::endl;
//         }
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << "입력에러 : " << e.what() << '\n';
//     }

// }

// };

// class FindBookCondition
// {
// private:
//     DB& mDB;
// public:
//     FindBookCondition(DB& db) : mDB(db) { }
//     void showBookName(const std::string& Bname)
//     {
//         try
//         {
//             std::string query = "SELECT Bwriter, Pperson, Pyear, Call_number FROM BOOKINFO WHERE Bname = '" + Bname + "';";
//             sql::ResultSet *res = mDB.executeQuery(query);
//             while(res->next())
//             {
//                 std::cout << "도서명 : " << Bname;
//                 std::cout << "  저작자 ; " << res->getString(1);
//                 std::cout << ", 발행자 : " << res->getString(2);
//                 std::cout << ", 발행연도 : " << res->getString(3);
//                 std::cout << ", 청구기호 : " << res->getString(4);
//                 std::cout << std::endl;
//             }
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << "입력에러 : " << e.what() << '\n';
//         }

//     }
//     void showBookWriter(const std::string& Bwriter)
//     {
//         try
//         {
//             std::string query = "SELECT Bname, Pperson, Pyear, Call_number FROM BOOKINFO WHERE Bwriter = '" + Bwriter + "';";
//             sql::ResultSet *res = mDB.executeQuery(query);
//             while(res->next())
//             {
//                 std::cout << "저작자 : " << Bwriter;
//                 std::cout << "  도서명 : " << res->getString(1);
//                 std::cout << ", 발행자 : " << res->getString(2);
//                 std::cout << ", 발행연도 : " << res->getString(3);
//                 std::cout << ", 청구기호 : " << res->getString(4);
//                 std::cout << std::endl;
//             }
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << "입력에러 : " << e.what() << '\n';
//         }

//     }
//     void showBookPublisher(const std::string& Pperson)
//     {
//         try
//         {
//             std::string query = "SELECT Bname, Bwriter, Pyear, Call_number FROM BOOKINFO WHERE Pperson = '" + Pperson + "';";
//             sql::ResultSet *res = mDB.executeQuery(query);
//             while(res->next())
//             {
//                 std::cout << "발행자 : " << Pperson;
//                 std::cout << "  도서명 : " << res->getString(1);
//                 std::cout << ", 저작자 : " << res->getString(2);
//                 std::cout << ", 발행연도 : " << res->getString(3);
//                 std::cout << ", 청구기호 : " << res->getString(4);
//                 std::cout << std::endl;
//             }
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << "입력에러 : " << e.what() << '\n';
//         }

//     }
//     void showBookPublishYear(const std::string& Pyear)
//     {
//         try
//         {
//             {
//                 std::string query = "SELECT Bname, Bwriter, Pperson, Call_number FROM BOOKINFO WHERE Pyear = '" + Pyear + "';";
//                 sql::ResultSet *res = mDB.executeQuery(query);
//                 while(res->next())
//                 {
//                     std::cout << "발행연도 : " << Pyear;
//                     std::cout << "  도서명 : " << res->getString(1);
//                     std::cout << ", 저작자 : " << res->getString(2);
//                     std::cout << ", 발행자 : " << res->getString(3);
//                     std::cout << ", 청구기호 : " << res->getString(4);
//                     std::cout << std::endl;
//                 }
//             }
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << "입력에러 : " << e.what() << '\n';
//         }

//     }

// };

// class Handler
// {
// private:
//     DB mDB;
// public:
//     void ShowBookInfo()
//     {
//         std::string enrollednum;
//         BookInfo rr(mDB);
//         std::cout << "등록번호를 입력하세요 : ";
//         std::cin >> enrollednum;
//         rr.showEnrollednum(enrollednum);
//     }

//     void BookName()
//     {
//         std::string bname;
//         BookInfo rr(mDB);
//         std::cout << "도서명을 입력하세요 : ";
//         std::cin >> bname;
//         rr.b(bname);
//     }
//     void LoginAccount(const std::string& id, const std::string& pw)
//     {
//         mDB.setAccount(id, pw);
//         mDB.connect();
//     }
// };

int main()
{
    std::string id = "ADMIN";
    std::string pw = "1234";
    Book DB(id, pw);
    Book a;

    // std::vector<std::vector<std::string>> qwe;
    // std::vector<std::vector<std::string>>qqq =  DB.qwe;
    DB.Bookinfo("JM0000000001");
    // b.()
    std::cout << DB.qwe[0][0];
    std::cout << DB.qwe[1][1];
    std::cout << DB.qwe[2][2];
    std::cout << DB.qwe[3][3];
    std::cout << DB.qwe[4][4];
    std::cout << DB.qwe[5][5];
    // std::vector<std::string>::iterator* it;
}