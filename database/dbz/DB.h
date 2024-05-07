#ifndef DB_H
#define DB_H

// Includes
#include <iostream>
#include <mariadb/conncpp.hpp>
#include <vector>
#include <string>
#include <sstream>

class DB
{
private:
    std::string url;
    std::string id;
    std::string password;
public:
    DB();
    // csv 파일을 mariadb에 읽어오는 함수
    void LoadData(std::unique_ptr<sql::Connection> &, 
                std::string, 
                std::string, 
                std::string,
                std::string,
                std::string,
                std::string,
                int);

    // SELECT문 실행 함수(conn, 테이블명, id코드)
    std::vector<std::string>* sendRowTasks(std::unique_ptr<sql::Connection>&,
                                        std::string,
                                        int);

    // SELECT문 실행함수(지역을 받고 해당지역 관광지코드들을 반환)
    std::vector<int>* regionToTDID(std::unique_ptr<sql::Connection>&, std::string);
    // 연결 함수
    std::unique_ptr<sql::Connection> Connect();
    
};

#include "DB.cpp"
#endif // DB_H