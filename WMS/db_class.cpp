// Includes
#include <iostream>
#include <mariadb/conncpp.hpp>
#include <vector>

class DB
{
private:
    std::string url = "jdbc:mariadb://10.10.21.103/PROJECT05";
    std::string id = "PROJECT05";
    std::string password = "1234";

public:
    // csv 파일을 mariadb에 읽어오는 함수
    void LoadData(std::unique_ptr<sql::Connection> &conn,
                  std::string FileDirName,
                  std::string TableName,
                  std::string ecd = "utf8",
                  std::string ter = ",",
                  std::string ecl = "\"",
                  std::string LineTer = "\n",
                  int ignore = 1)
    {
        try
        {
            // PreparedStatement 객체 생성
            std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("LOAD DATA LOCAL INFILE '?' INTO TABLE '?' CHARATER SET '?' COLUMNS TERMINATED BY '?' ENCLOSED BY '?' LINES TERMINATED BY '?' IGNORE '?' LINES;"));
            // 객체에 값을 전달
            stmnt->setString(1, FileDirName);
            stmnt->setString(2, TableName);
            stmnt->setString(3, ecd);
            stmnt->setString(4, ter);
            stmnt->setString(5, ecl);
            stmnt->setString(6, LineTer);
            stmnt->setInt(7, ignore);
            // 객체의 내부 함수를 이용하여 쿼리를 실행
            stmnt->executeQuery();
            // 실패시 오류 메세지 반환
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error Loading task status: " << e.what() << '\n';
        }
    }

    // SELECT문 실행 함수(conn, 테이블명, id코드)
    std::vector<std::string> *sendRowTasks(std::unique_ptr<sql::Connection> &conn,
                                           std::string table,
                                           int tid)
    {
        std::vector<std::string> *result = new std::vector<std::string>;
        try
        {
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
            std::string a = "select * from ";
            std::string b = " where ID = ";
            std::string c = a + table + b + std::to_string(tid);

            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery(c);

            // 반복문을 통해서 내부의 값을 반환
            while (res->next())
            {
                // 1번 테이블 td
                if ("TD" == table)
                {
                    // tdid
                    result->push_back(std::to_string(res->getInt(1)));
                    // tdname
                    result->push_back((std::string)res->getString(2));
                    // tdregion
                    result->push_back((std::string)res->getString(3));
                    // tdaddr
                    result->push_back((std::string)res->getString(4));
                    // tdpn
                    result->push_back((std::string)res->getString(5));
                    // accid
                    result->push_back(std::to_string(res->getInt(6)));
                    // medid
                    result->push_back(std::to_string(res->getInt(7)));
                    // fesid
                    result->push_back(std::to_string(res->getInt(8)));
                }
                // 2번 테이블 acc
                else if ("ACC" == table)
                {
                    // accid
                    result->push_back(std::to_string(res->getInt(1)));
                    // accregion
                    result->push_back((std::string)res->getString(2));
                    // accname
                    result->push_back((std::string)res->getString(3));
                    // accoccur
                    result->push_back(std::to_string(res->getInt(4)));
                    // accfa
                    result->push_back((std::string)res->getString(5));
                }
                // 3번 테이블 fes
                else if ("FES" == table)
                {
                    // fesid
                    result->push_back(std::to_string(res->getInt(1)));
                    // fesname
                    result->push_back((std::string)res->getString(2));
                    // fesregion
                    result->push_back((std::string)res->getString(3));
                    // fesstart
                    result->push_back((std::string)res->getString(4));
                    // fesend
                    result->push_back((std::string)res->getString(5));
                }
                // 4번 테이블 med
                else if ("MED" == table)
                {
                    // medid
                    result->push_back(std::to_string(res->getInt(1)));
                    // medname
                    result->push_back((std::string)res->getString(2));
                    // medaddr
                    result->push_back((std::string)res->getString(3));
                    // medpn
                    result->push_back((std::string)res->getString(4));
                }
            }
            // 실패시 오류 메세지 반환
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting tasks: " << e.what() << std::endl;
        }
        return result;
    }

    // SELECT문 실행함수(지역을 받고 해당지역 관광지코드들을 반환)
    std::vector<int> *regionToTDID(std::unique_ptr<sql::Connection> &conn, std::string region)
    {
        // 반환할 2중 스트링 벡터 선언
        std::vector<int> *result = new std::vector<int>;
        try
        {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery("select ID from TD where TDREGION = '" + region + "';");
            // DB에서 데이터를 불러와서 저장
            while (res->next())
            {
                // TDID를 벡터에 저장
                result->push_back(res->getInt(1));
            }
            return result;
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error selecting tasks: " << e.what() << std::endl;
        }
        return result;
    }
    // 연결 함수
    std::unique_ptr<sql::Connection> Connect()
    {
        try
        {
            // DB연결 객체 생성
            sql::Driver *driver = sql::mariadb::get_driver_instance();
            // 연결할 DB의 특정 IP, DB를 정의
            sql::SQLString url(this->url);
            // 연결할 DB를 사용할 유저를 정의
            sql::Properties properties({{"user", this->id}, {"password", this->password}});
            // 객체에 값을 통하여 연결을 시도
            std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
            return conn;
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error Connecting to MariaDB Platform: " << e.what() << std::endl;
            // 프로그램 비정상 종료
            exit(1);
        }
    }
};
class gg
{
public:
    struct tourPointinfo
    {
        std::string id;
        std::string Name;
        std::string Region;
        std::string Addr;
        std::string PhoneNumber;
        std::string AccId;
        std::string MedId;
        std::string FesId;
        struct Fes;
    } tp;
    struct Fes
    {
        int id;
        std::string FesName;
        std::string FesRegion;
        std::string FesStart;
        std::string FesEnd;
    } fes;

    std::vector<tourPointinfo> gunturn(std::vector<std::string> *temp)
    {

        gg asdf;
        std::vector<tourPointinfo> www;
        std::vector<std::string> gun = *temp;
        for (int i = 0; i < size(gun); i++)
        {
            if (i == 0)
                asdf.tp.id = gun[i];
            else if (i == 1)
                asdf.tp.Name = gun[i];
            else if (i == 2)
                asdf.tp.Region = gun[i];
            else if (i == 3)
                asdf.tp.Addr = gun[i];
            else if (i == 4)
                asdf.tp.PhoneNumber = gun[i];
            else if (i == 5)
                asdf.tp.AccId = gun[i];
            else if (i == 6)
                asdf.tp.MedId = gun[i];
            else if (i == 7)
                asdf.tp.FesId = gun[i];
        }
        www.push_back(asdf.tp);

        // std::cout << asdf.tp.id << std::endl;
        // std::cout << asdf.tp.Name << std::endl;
        // std::cout << asdf.tp.Region << std::endl;
        // std::cout << asdf.tp.Addr << std::endl;
        // std::cout << asdf.tp.PhoneNumber << std::endl;
        // std::cout << asdf.tp.AccId << std::endl;
        // std::cout << asdf.tp.MedId << std::endl;
        // std::cout << asdf.tp.FesId << std::endl;
        std::cout << www[size(www) - 1].id << std::endl;
        std::cout << www[size(www) - 1].Name << std::endl;
        std::cout << www[size(www) - 1].Region << std::endl;
        std::cout << www[size(www) - 1].Addr << std::endl;
        std::cout << www[size(www) - 1].PhoneNumber << std::endl;
        std::cout << www[size(www) - 1].AccId << std::endl;
        std::cout << www[size(www) - 1].MedId << std::endl;
        std::cout << www[size(www) - 1].FesId << std::endl;
        // 연결 실패시 오류 발생
        return www;
    }
std::vector<tourPointinfo> gunturn12(std::string input)
//관광지 출력하고 벡터에 반환하는 함수 
    {

        gg asdf;
        std::vector<tourPointinfo> www;
        try
        {
            DB pj05;

            std::unique_ptr<sql::Connection> conn = pj05.Connect();
            std::vector<int> *k = pj05.regionToTDID(conn, input);
            std::vector<int>::iterator iter0;
            for (iter0 = k->begin(); iter0 != k->end(); iter0++)
            {
                std::vector<std::string> *temp = pj05.sendRowTasks(conn, "TD", *iter0);
                std::vector<std::string>::iterator iter;
               
                std::vector<std::string> gun = *temp;
                for (int i = 0; i < size(gun); i++)
                {
                    if (i == 0)
                        asdf.tp.id = gun[i];
                    else if (i == 1)
                        asdf.tp.Name = gun[i];
                    else if (i == 2)
                        asdf.tp.Region = gun[i];
                    else if (i == 3)
                        asdf.tp.Addr = gun[i];
                    else if (i == 4)
                        asdf.tp.PhoneNumber = gun[i];
                    else if (i == 5)
                        asdf.tp.AccId = gun[i];
                    else if (i == 6)
                        asdf.tp.MedId = gun[i];
                    else if (i == 7)
                        asdf.tp.FesId = gun[i];
                }
                www.push_back(asdf.tp);
            }
            // std::cout << asdf.tp.id << std::endl;
            // std::cout << asdf.tp.Name << std::endl;
            // std::cout << asdf.tp.Region << std::endl;
            // std::cout << asdf.tp.Addr << std::endl;
            // std::cout << asdf.tp.PhoneNumber << std::endl;
            // std::cout << asdf.tp.AccId << std::endl;
            // std::cout << asdf.tp.MedId << std::endl;
            // std::cout << asdf.tp.FesId << std::endl;
            std::cout << www[size(www) - 1].id << std::endl;
            std::cout << www[size(www) - 1].Name << std::endl;
            std::cout << www[size(www) - 1].Region << std::endl;
            std::cout << www[size(www) - 1].Addr << std::endl;
            std::cout << www[size(www) - 1].PhoneNumber << std::endl;
            std::cout << www[size(www) - 1].AccId << std::endl;
            std::cout << www[size(www) - 1].MedId << std::endl;
            std::cout << www[size(www) - 1].FesId << std::endl;
            // 연결 실패시 오류 발생
        }
        catch (sql::SQLException &e)
        {
            std::cerr << "Error on DB class: " << e.what() << std::endl;
            // 프로그램 비정상 종료
            // return 1;
        }
    }
};
int main()
{
    // std::string input;
    // std::cout <<"지역입력플리즈";
    // std:: cin >> input;
    gg asdf;
    // std::vector<gg::tourPointinfo> www;
    try
    {
        DB pj05;

        std::unique_ptr<sql::Connection> conn = pj05.Connect();
        std::vector<int> *k = pj05.regionToTDID(conn, "서울");
        std::vector<int>::iterator iter0;
        for (iter0 = k->begin(); iter0 != k->end(); iter0++)
        {
            std::vector<std::string> *temp = pj05.sendRowTasks(conn, "TD", *iter0);

            // vector<tourPointinfo> 를 리턴하는 gunturn()함수 temp에 있는 데이터들이 구조체에 담겨있다.
            std::vector<gg::tourPointinfo> oooo = asdf.gunturn(temp);
        }
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error on DB class: " << e.what() << std::endl;
        // 프로그램 비정상 종료
        return 1;
    }
    return 0;
}