// chapter 10
/*객체와 클래스
고급 패러다임
절차식프로그레밍
객체지향 oop objective oriented programing

클래스의 속성은 변수다.
속성을 정의 했으면 기능을 정의해야하낟.
속성들을 변경하거나 set하는 기능들이 있을것이다.
class

*/
#ifndef STOCK00_H_ // 가 없으면 하고 있으면 안한다.
#define STOCK00_H_

#include <string>
class Stock
{        // 클래스 선언
private: // 접근 제한자 access modifier
         // 동작중에 외부 파일에서 변경할 수 없게
    // 외부 파일이 접근 가능하다는건 다른프로그램에서 접근해서 변경가능하다
    /*마구잡이로 바뀌는걸 막기위해서 접근을 제한해야한다. 그러한 등급을 설정해주는게 private이다. 등급이다.
    ㅔpublic, pivate(다른 파일에서 변경 못하게 된거임) 이걸 변경해주려면 변경해주는 함수들을 설정해준다.

    은닉성
    객체의 속성을 밖에서 바로 접근해서 수정하지 못하게
    내부에서 함수를 만들어서 수정할 수 있게 해주자.
    사물이 변할 때는 원인이 있고 과정과 결과가 있다.
    행위를 통해서만 속성이 변하게 되는거다 여기가 함수다.

    클래스를 다른곳에서 선언해서 가져오는 이유가 메인이 ㅈㄴ 뒤로 밀려버림
    문제지점 파악하기 accompany
    */
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot()
    {
        total_val = shares * share_val;
    }

public:
    // Stock();// 디폴트 생성자
    // Stock(const std::string &co, long n = 0, double pr = 0.0);
    // ~Stock();// 파괴자
    void acquire(const std::string &cp, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif
