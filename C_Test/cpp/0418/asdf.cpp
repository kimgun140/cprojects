/*순수 가상함수와 추상클래스
순수 가상함수를 다른 곳에서 호출하지 못하게 만든다.
순수 가상함ㅅ란 함수의 몸체가 정의되지않은 함수를 의미하낟. \\

다형성
모습은 같은데 형태는 다르다. 문장은 같은데 결과는 다르다.




*/

#include <iostream>
// #include <iostream>
#include <cstring>
using namespace std;
class First
{
private: //속성
    char *strOne;

public: //기능
    First(char *str)
    {
        strOne = new char[strlen(str) + 1];
    }
    virtual ~First()
    {
        cout << "~First()" << endl;
        delete[] strOne;
    }
};
class Second: public First{
    private:
    char * strTwo;
    public:
    Second(char * str1, char *str2) : First(str1)
    {
        strTwo = new char[strlen(str2)+1];
    }
    virtual ~Second(){
        cout << "~Second()" << endl;
        delete []strTwo;
    }
};
int main(void){
    First * ptr = new Second("simple", "complex");
    delete ptr;
    return 0;

}
//왜 퍼스트만 해제됨? 상속의 맨 위에 존재하는 기초 클래스의 소멸자에만 virtual을
// 붙이면 아래 단에서 상속받는 애들은 다들 virtual이 받아진다. 
/*
참조자와 참조가능성
*/