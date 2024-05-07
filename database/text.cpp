// Includes
#include <iostream>
#include <mariadb/conncpp.hpp>

// DELETE문 실행 함수(id를 이용한)
void deleteTask(std::unique_ptr<sql::Connection> &conn, std::string name) {
    // std::unique_ptr<A> pa(new A()); 특정 객체에 유일한 소유권을 부여한다.
    // 그렇게 되면 해당객체를 소멸(like delete something) 시킬 수 있는 권리는 해당객체만이 가지게 된다.

    // 
    try {
        // PreparedStatement 객체 생성
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("delete from TASKS where name = ?"));
        // 객체에 값을 전달
        stmnt->setString(1, name);
        // 객체의 내부 함수를 이용하여 쿼리를 실행
        stmnt->executeQuery();
    // 실패시 오류 메세지 반환
    } catch(sql::SQLException& e){
      std::cerr << "Error deleting task: " << e.what() << std::endl;
   }
}

// UPDATE문 실행 함수(이름을 이용하여 성별을 바꿈)
void updateTask(std::unique_ptr<sql::Connection> &conn, std::string name, bool gender) {
    try {
        // PreparedStatement 객체 생성
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("update TASKS set gender = ? where name = ?"));
        // 객체에 값을 전달
        stmnt->setBoolean(1, gender);
        stmnt->setString(2, name);
        // 객체의 내부 함수를 이용하여 쿼리를 실행
        stmnt->executeQuery();
    // 실패시 오류 메세지 반환
    } catch(sql::SQLException& e){
      std::cerr << "Error updating task status: " << e.what() << std::endl;
   }
}

// Insert문 실행 함수
// 인자로 값을 넣는다. (id값은 AUTO_INCEREMENT이기 때문에 없어도 상관 없다.)
void addTask(std::unique_ptr<sql::Connection> &conn, std::string name, int age, bool gender) {
    try {
        // PreparedStatement 객체 생성
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("insert into TASKS values (default, ?, ?, ?)"));
       // PreparedStatement 조작 가능성을 막는다. 여기 있는건 값이다. 쿼리문이 아니다. select는 단순히 보여준느 거니까
        // 객체에 값을 전달
        stmnt->setString(1, name);
        stmnt->setInt(2, age);
        stmnt->setBoolean(3, gender);
        // 객체의 내부 함수를 이용하여 쿼리를 실행
        stmnt->executeQuery();
    // 실패시 오류 메세지 반환
    } catch(sql::SQLException& e){
      std::cerr << "Error inserting new task: " << e.what() << std::endl;
   }
}

// SELECT문 실행 함수
void showTasks(std::unique_ptr<sql::Connection> &conn) {
    try {
        // createStaemet 객체 생성
        std::unique_ptr<sql::Statement> stmnt(conn->createStatement()); // conn.createStatement()를 실행 
        // 쿼리를 실행
        sql::ResultSet *res = stmnt->executeQuery("select * from TASKS");
        // 반복문을 통해서 내부의 값을 반환
        while (res->next()) {
            std::cout << "id = " << res->getInt(1);
            std::cout << ", name = " << res->getString(2); //  varchar는 getsting()으로
            std::cout << ", AGE = " << res->getInt(3);
            std::cout << ", gender = ";
            if (res->getBoolean(4)) {
                std::cout << "Male" << std::endl;
            } else {
                std::cout << "Female" << std::endl;
            }
                
        }
    // 실패시 오류 메세지 반환
    } catch(sql::SQLException& e){
      std::cerr << "Error selecting TASKS: " << e.what() << std::endl;
   }
}

int main() {
    try {
        // DB연결 객체 생성
        // DRIVER 객체 C++랑 연결하기 위한 객체  
        // 연결을 맞아서 대화를 해주는 객체가 CONN이다 
        sql::Driver* driver = sql::mariadb::get_driver_instance();
        // 연결할 DB의 특정 IP, DB를 정의
        sql::SQLString url("jdbc:mariadb://localhost:3306/TEST"); // 3306이 마리아 DB의 디폴트 PORT
        // 연결할 DB를 사용할 유저를 정의
        sql::Properties properties({{"user", "OPERATOR"}, {"password", "0000"}});
        // 객체에 값을 통하여 연결을 시도
        std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));

        showTasks(conn); 
        addTask(conn, "Tom", 15, false); 
        addTask(conn, "None", 0, false);
        updateTask(conn, "Tom", true);
        deleteTask(conn, "None");
        std::cout << "-------------------------------" << std::endl;
        showTasks(conn);


    // 연결 실패시 오류 발생    
    } catch(sql::SQLException& e) {
        std::cerr << "Error Connecting to MariaDB Platform: " << e.what() << std::endl;
        // 프로그램 비정상 종료
        return 1;
    }
    
    return 0;
}