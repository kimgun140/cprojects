#include <iostream>
#include <cstring>
using namespace std;
class Employee
{
private:
    char name[100];

public:
    Employee(char *name) // 생성자
    {
        strcpy(this->name, name);
        // 인수로받은 name을 멤버 변수 name에 복사해서 넣어준다.
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
};
class PermanentWorker : public Employee //<-상속받았다
{
private:
    int salary;

public:
    PermanentWorker(char *name, int money) // 생성자
        : Employee(name), salary(money)    // 멤버 이니셜라이저
    // Employee = name, salary = money 멤버변수를 초기화 하고있다.
    {
    }
    int GetPay() const // 여기서 const는 해당 함수 안에서는 어떤 변수도 바꿀 수 없을 뜻한다.
    // 함수가 클래스의 멤버 함수인 경우에만 함수 뒤에 const를 붙일 수 있다.
    // 또한 const가 붙은 함수 내에서는 다른 const가 붙은 함수만 호출할 수 있다. 붙지 않은 함수는 호출 불가능하다.
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "slaary: " << GetPay() << endl
             << endl;
    }
};
class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;

public:
    TemporaryWorker(char *name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    {
    }
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "sa;ary: " << GetPay() << endl
             << endl;
    }
};
class SlaesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;

public:
    SlaesWorker(char *name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    {
    }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay() //
               + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl
             << endl;
    }
};

class EmployeeHandler
{
private:
    Employee *empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0)
    {
    }
    void AddEmployee(Employee *emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        /*for(int i =0; i < empnum; i++)
        empList[i]->ShowSalaryInfo();
        */
    }
    void ShowTotalSalary() const
    {
        int sum = 0; /*
         for(int i =0; i , empNuml i++)
             sum+= empList[i] ->GetPay();*/
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};
int main(void)
{
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;
    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // 임시직 등록
    TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);
    // 영업직 등록
    SlaesWorker *seller = new SlaesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    // 이번달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();
    return 0;
}