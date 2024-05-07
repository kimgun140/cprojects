#include "DB.h"

DB::DB() {
      this->url = "jdbc:mariadb://10.10.21.103/PROJECT05";
      this->id = "PROJECT05";
      this->password = "1234";
}

void DB::LoadData(std::unique_ptr<sql::Connection> &conn, 
                std::string FileDirName, 
                std::string TableName, 
                std::string ecd = "utf8",
                std::string ter = ",",
                std::string ecl = "\"",
                std::string LineTer = "\n",
                int ignore = 1)
    {
        try {
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
        catch(const std::exception& e)
        {
            std::cerr << "Error Loading task status: " << e.what() << '\n';
        }
    }

std::vector<std::string>* DB::sendRowTasks(std::unique_ptr<sql::Connection> &conn,
                                        std::string table,
                                        int tid) 
    {
        std::vector<std::string>* result = new std::vector<std::string>;
        try {
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
            std::string a = "select * from ";
            std::string b = " where ID = ";
            std::string c = a + table + b + std::to_string(tid);

            
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery(c);

            // 반복문을 통해서 내부의 값을 반환
            while (res->next()) {
                // 1번 테이블 td
                if ("TD" == table) {
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
                    //fesid
                    result->push_back(std::to_string(res->getInt(8)));
                    //phaid
                    result->push_back(std::to_string(res->getInt(9)));
                }
                // 2번 테이블 acc
                else if ("ACC" == table) {
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
                else if ("FES" == table) {
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
                else if ("MED" == table) {
                    // medid
                    result->push_back(std::to_string(res->getInt(1)));
                    // medname
                    result->push_back((std::string)res->getString(2));
                    // medaddr
                    result->push_back((std::string)res->getString(3));
                    // medpn
                    result->push_back((std::string)res->getString(4));
                }
                else if("PHA" == table) {
                    // phaid
                    result->push_back(std::to_string(res->getInt(1)));
                    //phaname
                    result->push_back((std::string)res->getString(2));
                    //phaaddr
                    result->push_back((std::string)res->getString(3));
                    //phapn
                    result->push_back((std::string)res->getString(4));
                }
            }
        // 실패시 오류 메세지 반환
        } catch(sql::SQLException& e){
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
    return result;
    }

std::vector<int>* DB::regionToTDID(std::unique_ptr<sql::Connection> &conn, std::string region) {
        // 반환할 2중 스트링 벡터 선언
        std::vector<int>* result = new std::vector<int>;
        try {
            // createStaemet 객체 생성
            std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
            // 쿼리를 실행
            sql::ResultSet *res = stmnt->executeQuery("select ID from TD where TDREGION = '" + region +"';");
            // DB에서 데이터를 불러와서 저장
            while (res->next()) {
                    // TDID를 벡터에 저장
                    result->push_back(res->getInt(1));
                }
            return result;
        } catch(sql::SQLException& e) {
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
        }
        return result;
    }

std::unique_ptr<sql::Connection> DB::Connect()
    {
        try{
            // DB연결 객체 생성
            sql::Driver* driver = sql::mariadb::get_driver_instance();
            // 연결할 DB의 특정 IP, DB를 정의
            sql::SQLString url(this->url);
            // 연결할 DB를 사용할 유저를 정의
            sql::Properties properties({{"user", this->id}, {"password", this->password}});
            // 객체에 값을 통하여 연결을 시도
            std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
            return conn;
        }
        catch(sql::SQLException& e) {
            std::cerr << "Error Connecting to MariaDB Platform: " << e.what() << std::endl;
            // 프로그램 비정상 종료
            exit(1);
        }
    }