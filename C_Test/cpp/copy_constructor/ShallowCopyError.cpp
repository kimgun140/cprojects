#include <iostream>
#include <cstring>
using namespace std;
class Person
{
private:
    char *name;
    int age;

public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person()
    {
        delete[] name;
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29); 
    Person man2 = man1;
    man1.ShowPersonInfo();// man1 이 삭제가 되어버러면 man2가 문제가 생겨버린다.
    man2.ShowPersonInfo();// 같은 포인터를 가리키니까 문제가 생길 수 있음 이게 얕은 복사의 문제점이다. 
    // 깊은 복사를 해서 포인터가 가르키는 주소값도 새로 만들어서 해주고싶어라
    return 0;
}