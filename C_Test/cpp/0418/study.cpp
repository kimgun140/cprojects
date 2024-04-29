/*
생성자 객체도 생성과 동시에 초기화 할 수 있다.
- 클래스의 이름과 함수의 이름이 동일하다.
- 반환형이 선언되어 있지 않으며 실제로 반환하지 않는다.
- 초기화 담당이다.

생성자의 특징
-객체 생성시 딱 한번 호출된다.
-생성자도 함수의 일종이니 오버로딩이 가능하다.
-생성자도 함수의 일종이니 매개변수에 디폴트 값을 설정할 수 있다.

동적 할당등 메모리 할당도 생성자에서 처리해, 객체 생성과 함께 처리한다.

소멸자
- 생성자와 반대의 목적을 가지고 있다
- 객체가 사라지는 시점에 인스턴스가 할당 받은 메모리를 해제하고, 파일 저장 및 닫기, 네트워크 닫기 등 자원에 대한 무리르 작업


참조자
int a = 5;
int& another_a = a;
한번 참조할 대상이 정해지면 바꿀 수 없다. 곧 죽어도 같은 주소를 가르킨다.
포인터와 비슷하다.

this 포인터
객체의 주소를 통해서 멤버 함수가 작동한다.
this포인터는 멤버 함수가 호출된 객체의 주소를 가리키는 포인터이다.
this는 항상 호출된 객체를 가리킨다.
this를 명시적으로 참조해서 사용할 수 있다.
-1 멤버 변수와 이름이 같은 매개 변수를가진 생성자(또는 멤버 함수)가 있는 경우 this를 사용해서 구분할 수 있다.
다만 이경우에는 멤버 변수 이름을 m_같은 접두사를 붙이는게 좀더 좋다. (m_은 member의 약자를 나타내는 코딩 관행이다. )
-2 클래스 멤버 함수가 작업 중이던 객체를 반환하는 방식이 유용할 때가 종종있다. 이렇게 하면 같은객체의 여러 멤버 함수를 연속해서 호출할 수 있는 방법이다.
-멤버 이니셜라이저를 이용한 변수및 const 상수(변수) 초기화
    PermanentWorker(char *name, int money) // 생성자
        : Employee(name), salary(money)    // 멤버 이니셜라이저
    // Employee = name, salary = money //윗줄은 아래 줄과 같은 의미이다.
-멤버 이니셜라이저로 객체를 초기화 시킬 수도 있고 멤버 변수를 초기화 시킬 수 있고
const 멤버 변수도 초기화가 가능하다.
private:
    const int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:
    FruitSeller(int price, int num, int money)
    :APPLE_PRICE(price), numOfApples(num), myMoney(money)
여기서 const 변수 APPLE_PRICE를 멤버 이니셜라이저를 사용해서 초기화했다.

-멤버 이니셜라이저로 멤버변수로 참조자를 선언할 수 있게 한다.
class BBB{
    private:
        AAA &ref;
        const int &num;
    public:
        BBB(AAA &r, const int &n)
            :ref(r), num(n)
            //이니셜 라이저 를 사용해서 참조자를 초기화 하고 있다.

}


객체 배열
SoSimple arr[10];
열 개의 SoSimple 객체가 모여서 배열을 구성하는 형태가 된다. 구조체 배열과 차이가 없다.
여기서도 생성자가 필요하다. 보이드형태 생성자가 정의 되어야한다. 객체 배열을 생성하면 보이드 형태 생성자가 호출이된다.
SoSimple * ptrArr = new SoSimple[10];
동적으로 할당하는 경우에는 다음 형태로 선언한다.
int main(void){
    Person parr[3]; Person은 클래스
    char namestr[100];
    char * strptr;
    int age;
    int len;

    for(int i =0; i<3; i++){ 반복문안에서 이름과 나이 정보를 입력받아서, 객체를 초기화 하고있다.
        cin >> namestr;
        cin>>age;
        len = strlen(namestr)+1;
        strptr = new char[len];
        strcpy(strptr, namestr);
        parr[i].SetPersonInfo(strptr, age);
    }
}
객체 포인터 배열
객체의 주소값들의 모임
int main()
{
    Student * student[3]; // 객체 포인터 배열 생성
    char name[10];
    int age, studentID;

    for(int i=0; i<3; i++) {
        cin >> name >> age >> studentID;
        student[i] = new Student(name, age, studentID);
    }
    for(int i=0; i<3; i++)
        student[i]->GetInfo();

}

-복사 생성자
멤버 대 멤버의 복사를 진행한다. 객체를 인자로 받는 객체생성
멤버 대 멤버의 복사에 사용되는 원본을 변경 시키는 것은 복사으 ㅣ개념을 무너뜨리기 때문에 const를 삽입해서 실수를 막는것이 좋다.
별도로 멤버 대 멤버의 복사를 진행하는 (객체를 인자로 받는 객체의 생성자)를 정의하지 않으면
디폴트 복사 생성자가 자동으로 삽입된다.

-키워드 explicit
SoSimple sim2  =sim1;

SoSimple sim2(sim1);
위의 과정은 무시적 형변환을 통한것이다.
explicit SoSimple(const SoSimple & copy): num1(copy.num),num2(copy.num2)
{}
키워드 explicit을 통해서 묵시적 형변환을 막아서 대입연산자를 이용한 객체의 생성 및 초기화를 막는다.


- '깊은 복사', '얕은 복사'
디폴트 복사 생성자는 멤버 대 멤버의 복사를 진행한다. 이러한 방식의 복사를
'얕은 복사'라고 한다. 이는 멤버 변수가 힙의 메모리 공간을 참조하는 경우에 문제가 된다.

-디폴트 복사 생성자의 문제점
디폴트 복사 생성자는 멤버 대 멤버를 단순히 복사만한다. 그래서 복사의 결과가
하나의 문자열을 두 개의 객체가 동시에 참조하는 모양이 된다.
 그래서 2번째 객체가 먼저 소멸하면서 문자열을 소멸 시켜서 원본이 소멸자에서 진행하지 못한다.


 - '깊은 복사'를 위한 복사 생성자의 정의
객체별로 각각의 대상을 참조하기 때문에 '얕은 복사'의 문제가 발생하지 않는다.
멤버 뿐만 아니라 포인터로 참조하는 대상까지 깊게 복사한다는 뜻으로 정해진 이름이다.
Person(const Person& copy) : age(copy.age)
{
    name = new char[strlen(copy.name)+1];
    strcpy(name,copy.name);

}
멤버변수 age의 멤버 대 멤버 복사
메모리 공간 할당후 문자열 복사, 그리고 할당된 메모리 주소 값을 멤버 name에 저장


- 복사 생성자가 호출되는 시점은?
Person man("Lee dong woo", 29);
Person man2 = man1; // 복사 생성자 호출

복사생성자가 호출되는 시점 3
1. 기존의 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우
2. call by value 방식의 함수 호출 과정에서 객체를 인자로 전달하는 경우
3. 객체를 반환하되, 참조형으로 반호나하지 않는 경우
이들의 공통점은 객체롤 생성해야한다. 단 생성과 동시에 동일한 자료형의 객체로 초기화해야한다. !

-const객체와 const 객체의 특징들
const SoSimple sim(20);
해당 객체의 데이터 변경은 불가능하다. 해당 객체는 멤버함수의 호출만 가능하다.

-const와 함수 오버로딩
함수의 오버로딩이 성립하려면 매개변수의 수나 자료형이 달라한다.
void SimleFunc()
{}
void SimpleFunc()const
{}
이런 const선언 유무도 함수 오버로딩의 조건에 해당한다.

- 클래스의 friend 선언
두개의 클래스 ㄱ,ㄴ가 있다
ㄱ이 ㄴ클래스를 대상으로 friend 선언언을하면 ㄴ 클래스는 ㄱ클래스의 private 멤버에 직접 접근이 가능하다.
반대의 경우도 성립하려면 ㄴ클래스가 ㄱ 클래스를 대상으로 firend 선언을 해줘야한다.

class Boy
{
    private:
    int height;
    friend class Girl;
    public:
    Boy(int len) : height(len) // 이니셜라이저
    {}
};
class Girl{
    void ShowYourFriendInfo(Boy &frn){
        frn.height // private 멤버에 접근
    }
}
마찬가지로 friend 선언을 받은 함수는 대상의 private영역에 접근 가능하다.
friend Poinst PointOP:: PointAdd(const Point&, const Point&);
friend선언은 정보의 은닉성을 무너뜨리기 때문에 조심해서 사용해야한다.

- c언어에서 static 멤버 변수와 static멤버 함수

-static 멤버 변수(클래스 변수)
staticc 멤버 변수는 클래스 변수라 고도 한다. 일반적인 멤버 변수와 달리 클래스당 하나씩만 생성되기 때문이다.
class SoSimple
{
    private:
    static int simObjCnt; //static 멤버 변수, 클래스 변수
    public:
    SoSimple()
    {
        simObjCnt++;
        cout<,simObjCnt<<"번쨰 SoSimple 객체"<< endl;

    }
};
스태틱 멤버변수를 초기화 하는 방법이다.
int SoSimple::simObjCnt = 0; //static 멤버 변수의 초기화(잠시 후 설명)
해당 스태틱 변수는 객체가 생성 될 떄마다 생성되는 변수가 아니라 객체와 별개로 존속하는 변수다.

스택 멤버 변수의 또 다른 접근 방법
스태틱 멤버변수는 어디서든 접근이 가능한 변수이다. private으로 선언되면 해당 클래스 객체들만 가능하지만
퍼블릭으로 선언되면 객체이름을 통해서 접근이 가능하다.

-static 멤버 함수
선언된 클래스의 모든 객체가 공유한다.
퍼블릭으로 선언되면, 클래스 이름을 이용해서 호출이 가능하다.
객체의 멤버로 존재하는 것이 아니다.

객체의 멤버가 아닌데, 어떻게 멤버 변수에 접근을 하겠는가? 오케이 무슨말인지 알겠어

객체생성 이전에도 호출이 가능하다. 그런데 어떻게 멤버변수에 접근이 가능하겠는가?
객체가 생성되지 않았으니까 멤버 변수가 존재하지 않는다.

멤버 변수에 접근을 한다고 치자, 그렇다면 어떤 객체의 멤버 변수에 접근을 해야겠는가
객체가 존재 하지않는데 접근할 수 있는 객체가 어디 있겠냐고

결론 : " static멤버함수 내에서는 static 멤버변수와 static 멤버함수만 호출이 가능하다."
이런 특성으로 static 함수와 변수는 전역변수,함수를 대체할 수 있다.





















*/

// #include <iostream>
// // using name
// class Simple
// {
// private:
//     int m_ID;

// public:
//     Simple(int id) // Simple(int id) : m_ID(id)// 이 문장은 멤버 이니셜라이저로 객체가 아닌 멤버 변수를 초기화한것이다.
//     // 멤버 변수 m_ID를 id로 초기화 시키라는 말이다.
//     //멤버 변수를 이니셜라이저로 초기화 시키면 초기화 대상을 명확히 인식할 수 있고 성능에 이점이 있다.
//     {
//         SetID(id);
//     }
//     void SetID(int id)
//     {
//         m_ID = id;
//     }
//     int GetID()
//     {
//         return m_ID;
//     }
// };
// int main()
// {
//     Simple simple(1);
//     simple.SetID(2); // simple.SetID(&simple,2);
//     // 멤버 함수의 인수로 객체의 주소가 전달된다는 것이다.
//     // 멤버 함수 호출에 매개변수가 추가 되었으므로 멤버 함수의 정의 역시 매개 변수를 하나더 받도록 수정해야한다.
//     /*
//     void SetID(Simple * const this, int id) {이렇게 정의가 변환된다.
//         this->m_id = id;
//     }
//     */

//     std::cout << simple.GetID() << std::endl; // 2

//     return 0;
// }