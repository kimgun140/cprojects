/*
구조체
기본데이터형의 이름 처럼 사용할 수 있다. 멤버 연산자 (.)를 통해서
개별 멤버에 접근 가능하다.

*/
// #include<iostream>
// struct inflatible{
// //선언
//     char name[20];
//     float volume;
//     double price;
// };

// int main(){
//     using namespace std;
//     inflatible guest = {
//         //초기화
//         "Glorious Gloria", //name 값
//         1.88,               // volume 값
//         29.99               // price값
//     };                      // guest는 inflatible형의 구조체 변수이다.

//     inflatible pal = {
//         "Audacious Arthur",
//         3.12,
//         32.99
//     }; // pal은 inflatible형의 두 번째 수이다.
//     //참고 : 어떤 C++ 시스템에서는 다음과 같은 형식을 요구한다.
// // static inflatible guest =
//     cout << "지금 판매하고 있는 모형풍선은\n" << guest.name;
//     cout << "와 " << pal.name << "입니다.\n";
// // pal.name은 pal 변수의 name멤버이다.
//     cout << "두 제품을 $";
//     cout << guest.price + pal.price << "에 드리겠습니다!\n";
//      return 0;
// }

// #include<iostream>
// using namespace std;
// struct inflatable
// {//정의
//     char name[20];
//     float volume;
//     double price;

// };
// int main(){
//     using namespace std;
//     inflatable bouquet = {
//         //초기화
//         "sunflower",
//         0.20,
//         12.49
//     };
//     inflatable choice;
//     cout << "bouquet: " << bouquet.name << " for $";
//     cout << bouquet.price << endl;

//     choice  = bouquet;
//     cout << "choice: " << choice.name << " for $";
//     cout << choice.price << endl;
//     return 0;
// }

/*
구조체 배열 해리포터

*/

// #include <iostream>
// struct inflatible
// {

//     char name[20];
//     float voulme;
//     double price;
// };
// int main()
// {
//     using namespace std;
//     inflatible guest[2] = {
//         {"Bambi", 0.5, 21.99},
//         {"Godzilla", 2000, 565.99}};

//     cout << guest[0].name << "와 " << guest[1].name
//          << "의 부피를 합하면\n"
//          << guest[0].voulme + guest[1].voulme
//          << " 세제곱피트입니다.\n";
//     return 0;
// }

/*
공용체 서로다른 데이터형을 한 번에 한 가지만 보관할 수 있는 데이터형식이다. 죽
구조체는 int형과 longgudr과 ㅇuble형을 한꺼번에 보관할 수 있지만 공용체는 int 형이나 long형이나 double형 중에서
한 번에 어느 하나만
*/

/*
--열거체 enum 기능은 const를 사용하여 기호 상수를 만드는 것에 대한 또 다른 방편ㅇ르 제공한다.
그것은 제한적이기는 하지만 새로운 데이터형을 정의할 수 있게 해 준다. enum을 사용하는 구문은 구조체와 비슷하다.
enum spectrum { red, orange, yellow, green, blue, violet, indigo, ultraviolet};
이 구문은 두 가지 일을 수행한다.
-spectrum을 새로운 데이터형의 이름으로 만든다. struct형 변수를 구조체라 부르듯 enum형 변수를 열거체(enumeration)라고 부른다.
- 0에서 7까지의 정수 값으 ㄹ각각 나타내는 기호 상수로 만든다. 이 상수들을 열거자(enumerator)라 부른다.
기본적으로 첫 번쨰 열거자에 0이 대입되고 두 번쨰 열거자에 1이 대딥되는 방식으로 정수값들이 차례로 대입된다. 그러나 열거자에 정수값을
명시적으로 대입하면 이 기본값을 무시할 수 있다.

열거체의 이름을 사용하여 열거형의 변수를 선언할 수 있다.
spectrum band; //band는 spectrum형의 변수
열거체 변수는 특별한 특성을 가지고 있다.

열거체 변수에는 그 데이터형을 정의하는데 사용된 열거자 값들만 대입할 수 있다.
band = blue; //가능하다.
band = 200;//불가능하다 열거자가 아니다.

따라서 spectrum형 변수에는 단지 8개의 값만 대입할 수 이싿. 다른 값은 에러를 발생시킨다.
열거체는 대입 연산자만 사용하도록 되었다. 산술 연산은 불가능이다.
band = orange; // 가능
++band; //불가능
열거자들은 정수형이며 int형으로 승급될 수 있다. 그러나 int형이 자동으로 열거체로 변환 되지는 않는다.
int color =blue; // 맞다 spectrum형이 int형으로 승급된다.
band = 3; //틀리다, int형이 spectrum형으로 변환되지 않는다.
color = 3 +red; // 맞다 red가 int형으로 변환된다.

여기서 주의할 것은 3이 열거자 green에 해당하는값이지만, 3을 직접 band에 대입하면
데이터혀 에러를 일으킨다는 사실이다. 그러나 band에 green을 대입하는것은 허용된다. 그 이유는 band와 green 모두 sperctrum형이기 때문이다.

열거체에 적용되는 규칙은 매우 제한적이다. 실제로 열거체는 새로운 데이터형을 정의하는 수단이 아니라  상호관련이이 있는 기호 상수들을 정의하는
용도로 주로 사용된다. 예를 들면 switch 구문에 ㅏ용할 기호 상수들을 정의하기 위해 열거체를 사용한다. 단지 상수만을 사용할 계획이고열거체 변수를 만들 생각이 없다면
enum { red, orange, yellow, green, blue, violet, indigo, ultraviolet};
이렇게 열거체 이름은 생략할 수 있다.

--열거자 값의 설정
대입 연산자를 사용하여 열거자의 값을 명시적으로 지정할 수 있다.
enum bits { one = 1, two = 2, four = 4, eight = 8};
이때 대입되는 값들은 정수여야 한다. 또한 일부 열거자에만 명시적으로 값을 대입할 수도 있다.
enum bigstep {first, second = 100, third};
이러한 경우에, first는 기본적으로 0이고 , 뒤에 오는 치고화하지 않은 열거자들은
바로 앞의 열거자보다 1만큼 크다. 그래서 third는 101이 된다.
하나이상의 열거자들이 같은 값을 가질 수 있다.

--열거체의 값 범위
각 열거체는 값 범위를 가진다. 어떤 정수값이 그 범위 안에 들어 있으면 , 그것이 열거자 값이 아니더라도 데이터형 변환을 통하여 열거체 변수에 대입할 수 있다.
enum bits {one = 1, two = 2, four = 4, eight = 8};
bits myflag;
이경우 다음은 유효하다.
myflag = bits(6); //맞다 6이 bits 범위 안에 들어있다.
여기서  6은 열거자 값 중 하나는 아니지만, 열거체가 정의하는 범위 안에 들어 있다.
열거체의 값 범위는 다음과 같이 정의한다.
가장큰 열거자 잡보다 큰 2의 제곱값에서 1을 뺀것이 MAX 값이다. 위의 경우에는 15이다
최소값은 가장 작은 열거값이 양수면 0 음수인경우에는  최대값과 같은 방법으로 구한뒤 -1을 한다
최소값이 -6이면 8에 -1을 한 7이다.
이후에 클래스 사용범우이에서 다루게싿.


*/

/*
포인터와 메모리해제
어디에 저장되는가?
어떤 값이 저장되는가?
어떤 종류의 정보인가?

포인터와 c++의 철학
객체 지향 프로그래밍은 컴파일시간이 아닌 실행시간에 어떤결정을 내린다는 것을 강조하는 점에서 재래의 절차저 프로그래밍과는 다른다.
실행 시간이라는 것은 프로개름이 실제로 실행되는 동안을 의미한다. 반면에 컴파잉ㄹ 시간은 커파일러가 소스코드를 실행 코드로 변환하는 시간을 말하낟.
그러므로 실행 시간 결정이 그때그때 상황에 적절히 대체할 수 있는 융통성을 ㅏ지고 있다.
예를 들어 배열을 선언하려면 배열의 크기를 미리정해야한다. 즉 컴파잉ㄹ할 때 배열의 크기가 미리결정된다.
이것이 컴파일 시간 결정이다. 그런데 그 배열의 원소 개수가 대부분의 경우 20개면 충분하지만 , 200개가 필요ㅕ한 경우가 있다고 가정해보자.
이러한 상황에서는 안정을 위해 원소 개수가 200개인 배열을 사용해야한다. 이렇게 되면 평상시에 메모리를 크게 낭비하는 꼴이 된다.
객체지향 프로그래밍에서는 실행 시간까지 이러한 결정을 미룸으로써 프로그램에 융통성을 부여한다.
원소가 20개가 필요한지 아니면 205개가 필요한지는 프로그램이 실행될 때 사용자가 프로그램에 알려줄 수 있ㄷ.
요약하면, oop에서 배열의 크기를 실행 시간에 결정하기를 원할 수도 있다. 이것이 가능하려면,
프로그램이 실행되는 동안 배열 또는 그와 동등한 것을 생성할 수 있어야한다. c++에서는 new라는 키워드를 사용하여 원하는 만큼의 메모리를 대입하고, 이렇게 대입된 메모레의 위치를 포인터를 사용하여 추적할 수 있다.


일반 변수를 사용할 때와는 반대로, 저장된 데이터를 다루는 새로운 전략은 주소를 이름 붙인 양으로 취급하고, 값을 파생되는 양으로 취급한다ㅏ.
그래서 포이넡라는 특별한 데이터형의 변수에 어떤 값의 주소를 저장한다.
즉, 포인터의 이름이 주소를 나탙낸다. 간접값 연산자 또는 간접 참조 연산자라고 부르는 *를
포인터 이름 앞에 붙이면 그 주소에 저장되어 있는 갑이 된다.
예를 들어서 manly는 그 주소에 저장되어 있는 값을 나타낸다. *manly는 보통의 int형 변수와 동등하게 취급된다.
int * p_updates;
이 구문은 위 포인터 변수가 int형이라는 것을 나타낸다. *연산자를 포인터에 적용하여 사용하기 때문에 p_updates는 포인터임이 틀림없다.
이것을 p_updates가 int형을 지시한다 라고 말한다.
즉 p_updates의 데이터형은 int형을 지시하는 포인터, 간단히 말해 int*형이다. p_updates는 포인터(주소)이고
*p_updates는 포인터가 아니라 int형 변수다

포인터 변수는 그냥 단순한 포인터가 아니라 항상 어떤 데이터형을 지시하는 포인터라고 해야한다.
배열과 마찬가지로 포인터는 다른 데이터형을 기초로 해서 만들어진다.
--포인터의 위험
long *fellow; 선언
long * fellow = 223344;  초기화
포인터를 사용할때는 간접 참조연산자를 사용하기 전에 반드시 포인터를 적절한 주소로 초기화 시켜야한다.
--포인터 와 수
    포인터는 정수형이 아니다. 포인터는 개념적으로 정수형과는 다른 데이터형이다. 정수는 연산을 하지만
포인터는 위치를 나타내는 것이다. 따라서 두개의 위치를 서로 곱한다는 것은 의미가 없다.
다시말해 포인터에정수를 직접 대입할 수 없다.
int * pt;
pt = 0xb8000000; // 데이터형 불일치
이렇게는 사용할 수없다. 비디오메모리 주소이지만 여기서 이것이 주소라는것을 알려주는 것이 전혀 없긴 때문에
컴퓨터는 알 수가 없다.
int * pt;
pt = (int*) 0xb800000; // 데이터형 일치
이제 대입 구문의 좌변과 우변인 정수의 주소를 나타낸다 .까라서 이 대입구분은 올바른것이 된다.

-- new를 사용한 메모리 대입 p.187
 malloc()을 대신하는 새로운 new!!가 있다
 프로그램을 실행하는 동안 int형 값을 저장할 수 있는 이름이 없는 메모리를 대입하고 포인터를 사용하여 그 모메로에 접근하는 새로운 방법을 알아보자.

 new연산자는 어떤 데이터형 메모리를 원하는지 알려 주면 new연산자는 그에 알맞는 크기의 메모리 블록을 찾아 해당 주소를 리턴한다.
int *pn = new int;
new int 부분은 메모리가 필요하다고 알린다. 데이터형을 보고 크기를 파악하고 적당한 메모리 주소를 리턴한다.
여기서pn은 주소이고 *pn은 그주소에 저장되는 값이다.
typeName * pointer_anem = new typeName;
기본 데이터형이나 구조체일 수 있는 데이터 객체를 저장하기 위해 모메르릴 확보하고, 그 주소롤 포인터에
대입하는 일반적인 형식이다.

int * pt = new int; //int형을 저장할 메모리르 대입
*pt = 1001; // 대입된 메모리에 값을 저장

--메모리 부족
new로 요청하는 크기의 메모리가 여유공간에 무족하면 new는 0을 리턴한다.
널 포인터 0을 리턴하는 포인터 어떤 데이터도 지시하지않는다. 문제가 생겼다는것을 의미

--delete를 사용한 메모리 해제
new를 사용해서 메모리를 대입하고 delete를 사용해서 사용하는 메모리를 해제한다. 
int * ps = new int;
delete ps;
로 해제한다. 이것은 ps자체가 사라지는것이 아니다. ps를 새로 대입한 메모리를 지시하는 데 사용할 수 있다. 
메모리의 효율적 활용을 위해 해제는 필요하다. 하지만 한번 해제한 메모리를 다시 해제하는것은 또 다른 문제를 야기할 수 있기에 주의 해야한다. 
++ delete로 널포인터에 사용하는것은 안전한다. ++
 널포인터로 생길 수 있는 문제 있는 메모리 공간을 비워주어서인듯??

delete르 사욜 할때 가장 중요한 요구사항은 new로 대입한 메모리에만 그것을 사용하라는 것이다. 
new가 사용한 것과 동일한 포인터 변수에 사용해야한다는 뜻이 아니라 동일한 주소에 사용해야한다는 말이다. 
int * ps = new int; // 메모리를 대입하고 첫 번째 포인터로 지시
int * pq = ps;  // 같은 메모리를 지시하는 두 번째 포인터 설정
delete pq;  // 두 번째 포인터에 delete 사용
일반적으로 같은 메모리 블록을 지시하는 두 개의 포인터를 만드는 것은, 실수로 같은 메모리 블록을 두 번 삭제할 
가능성이 있기 때문에 좋지 안다. 하지만 포인터를 리턴하는 함수에서는 두 번째 포인터를 사용할 수 있다. 



-----new를 사용한 동적 배열의 생성--------p.192
    배열, 문자열 , 구조체와 같은 커다란 데이터를 다룰 때에는 new를 사용하는 것이 효율적이다. 
선언에 의해서 프로그램 시작시에 메모리를 할당하면 해당 메모리가 사용되든 안되는 메모리를 차지한다. 
이것이 정적 바인딩이다. 하지만 new를 사용하면 배열을 실행 시간동안에 생성할 수 있고 필요 없으면 하지않을 수 있다.
또는 실행중에 배열의 크기를 결정할 수도 있다. 이것을 동적 바인딩이라한다. 일허게 생성된 배열을 동적배열이라하낟. 

동적 배열의 두 가지 기본 사항 
new를 사용한 동적 배열의 생성 
int * psome = new int [10]; //10개의 int형 값을 저장할 블록을 대입 
new 연산자는 블록의 첫 번째 원소의 주소를 리턴한다. 여기서는 포인터 psome에 주소가 대입된다. 
이것을 해제 할 때
delete [] psome; 동적 배열을 해제 
대괄호가 사용되었기 때문에 포인터가 지시하는 첫 번째 원소가 해제되는것이 아니라 배열 전체가 해제 된다. 
대괄호의 위치는 delete 연산자와 포인터 사이에 사용된다. new를 대괄호 없이 사용했으면 delete도 대괄호 없이 사용해야한다. 
(new를 사용해서 메모리를 할당할 때 배열의 공간을 줬기 때문에 그공간을 해제한다는 것을 알려줘야한다.)
이렇게 해제할 때 할당할때와 형식을 맞추지 않으면 오류가 발생한다. (하지마세요)

정리하자면 다음의 규칙을 지켜야한다. 
new로 대입하지않은 메모리는 delete로 해제하지 않는다.
같은 메모리 블록을 연달아 두 번 delete로 해제하지 않는다. 
new []로 메모리를 대입한 경우에는 delete[]로 해제한다. 
new를 대괄호 없이 사용했으면 delete도 대괄호 없이 사용한다. 
널 포인터에는 delete를 사용하는 것이 안전하다. 

컴파일러는 psome이 10개의 int형 원소 중 첫 번째 원소르 지시한다는사실을 컴파일러는 전형 모른다. 
그래서 원소의 개수를 알 수 있도록 프로그램을 작성해야한다.
delete[]연산자로 바르게 해제 할 수 있도록 내부적으로는 컴퓨터는 메모리의 양르 추적한다. 
그러나 프로그래머가 그 정보를 사용 할 수 없다.
예를 들어 종덕 배열에 대입된 바이트 수를 알아보기 위해 sizeof 연산자를 사용할 수는 없다는 말이다. 

동적 배열을 위한 메모리를 대입하고 그 배열의 시작 주소를 포인터에 대입하는 일반적 경우는 다음과 같다.
type_name * pointer_name = new type_name [num_elements];

동적 배열을 생성하고 사용하자
int * psome = new int [10];
10개의 int 형 값을 넣을 수 있는 블록과, 그 블록의 첫 번째 원소를 지시하는 psome 포인터를 생성한다. 
이 포인터를  첫 번째 원소를 가리키는 손가락이라고 생각하고 4바이트가 원소 하나의 공간이라고 한다면
4바이트만큼 손가락을 움직이면 첫 번째에서 두 번째 원소를 가르키게 된다. 10개의 원소가 존재하는 공간이 
그 손가락이 4바이트 만큼 움직이는 손가락이 이동할 수 있는 버무이다. 
이것은 *psome이지만 psome[0]이라고 표현할 수 있다. *psome은 배열의 첫번째 가르킨다. 
** 이런 방법이 가능한 이유는 c와 c++가 배열을 사용할 때 내부적으로는 포인터를 사용하기 때문이다.





*/
// // pointer.cpp
// #include <iostream>
// int main()
// {

//     using namespace std;
//     int updates = 6; // int형 변수를 선언
//     int *p_updates;  // int형을 지시하는 포인터를 선언

//     p_updates = &updates; // int형의 주소를 포인터에 대입
//     // 값을 두 가지 방법으로 표현
//     cout << "값: updates = " << updates;
//     cout << ", *p_updates = " << *p_updates << endl;

//     // 주소를 두 가지 방법으로 표현
//     cout << "주소: &updates = " << &updates;
//     cout << ", p_updates = " << p_updates << endl;

//     // 포인터를 사용하여 값ㅇ르 변경
//     *p_updates = *p_updates + 1;
//     cout << "변경된 updates = " << updates << endl;
//     return 0;
// }
// #include <iostream>
// int main()
// {

//     using namespace std;

//     int ducks = 12;
//     int *birddong = &ducks;
//     cout << ducks << endl;
//     cout << birddong;

//     return 0;
// }
/*
int * pn = new int;
int형 데티어를 저장할 새로운 메모리가 필요하다고 프로그램에게 알린다.
new연산자는 뒤따르는데이터형을

*/
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int nights = 0.01;
//     int *pt = new int; // int형을 저장할 메모리를 대입
//     *pt = 1001;        // 대입된 메모레에 값을 저장

//     cout << "nights의 값 = ";
//     cout << nights << " : 메모리 위치 " << &nights << endl;
//     cout << "int 형";
//     cout << " 값 = " << *pt << ": 메모리 위치 = " << pt << endl;

//     double *pd = new double; // double형을 저장할 메모레를 대입
//     *pd = 10000001.0;        // 그메모리에 double형을 값을 저장

//     cout << "double 형";
//     cout << "값 = " << *pd << ": 메모리 위치 = " << pd << endl;
//     cout << "포인터 pd의 메모리 위치: " << &pd << endl;
//     cout << "pt의 크기 = " << sizeof(pt);
//     cout << ": *pt의 크기 = " << sizeof(*pt) << endl;
//     cout << "pd의 크기 = " << sizeof(*pd) << endl;
//     cout << ": *pd의 크기" << sizeof(*pd) << endl;
//     return 0;
// }
/*
delete를 사용한 메모리 해제
new를 사용해서 메모리를 할당받고 delete를 사용해서 해제해준다. free()랑 비슷

*/

/*
new 를 사용한 동적 배열의 생성
프로그램이 단지 하나의 값만을 요구한다면 단순한 변수르 선언하는 것이 new와 포인터를 사용하여 작은 데이터 객체를 관리하는 것보다 간단하다. 그러낙
배열, 문자열 구조체와 같은 커다란 데이터를 다룰 때에네는 new를 사용하는 것이 훨 씬 더 효율적이다. 예를 들어 프ㅗ그램이 실행되는 동안에 주저잊는 어떤 정보에 따라 배열을 생성하거나
생성하지 않는 프로그램을 작성한다고 가정해보자, 선언에 의해 배열을 생성하면 프로그래밍 컴파일 될 때 배열을 위한 메모리가 대입된다.
프로그램이 실행됭 때 이 배열은 사용되늗ㄴ 안 되는 항상 메모르릴 차지한다.
이 방식을 정적 바인딩이라한다. 이것은 배열이 컴파일 시간에 생성된다는 것을 뜻한다.
그러나 new를 사용하면 배열을 실행 시간에 생성할 수 있고, 필요 없으면 생성하지 않을 수도 있다.
또는 프로그램을 실행한느 동안에 배열의 크기를 결정할 수 있다. 이방식을 동적 바인딩이라고한다.
이것은 배열이 실행 시간에 생성된다는 것으 뜻한다. 이러한 배열을 동적 배열이라 한다. 정적 바인딩에서는 프로그램을 작성할 때 배열의 크기를 정하지만, 동적 바인딩에서는 실행하는동안에 배열의 크기를 정할 수 있다.

new를 사용한 동적 배열의 생성
c++에서는 동적 배열을 쉽게 만들 수 있다. 배열 원소의 데이터형과 개수를 new에게 알려주면된다. 예를 들어 10개의 int형원소를 갖는 배열잉 필요하다면,
대괄화 안에 원소의 개수를 넣어 다음과 같은 형식으로 덩적 배열을 생성한다.
int * psome = new int[10]; //10개의 int형 값을 저장할 블록을 대입
new 연산자는 그 블록의 첫 번째 원소의 주소를 리턴한다. 이 예에서는 포인터 psome에 그 주소가 대입된다.
new를 사용하여 생성된 메모리 블록은 프로그램이 사용을 끝낸 후에 반드시 delete로 해제해 주어야 한다.
new를 사용하여 생성된 배열을 해제할 때에는 , 다음과 같이 delete의 또 다른 형식을 사용하여 컴파일러에게 그 배열을 해제한다는 사실을 알려야한다.
delete [] psome; // 동적 배열을 해제
대괄호 [] 가 사용되었기 때문에 포인터가 지시하는 첫 번째 원소가 해제되는 것이 아니라 배열 전체가 해제된다.
대괄호는 delete와 포인터 사이에 사용된다. new를 대괄호 없이 사용했으면 delete도 대괄호 없이 사용해야하나. new를 대괄호를 넣어 사용했으면 delte도 대괄호를 넣어 사용해야한다.
c++의 구식 버전은 대괄호 표기를 인식하지 못할 수도 있다. new와 delete의 짝이 맞지 않는 경우에 그 결과를 정의하지 않았으므로 그 결과를 신뢰할 수 없다.
int * pt = new int;
short * ps = new short [500];
delete [] pt ; // 결과 미정의, 사용 불가
delelte ps; // 결과 미정의 사용불가
간단히 말해 new와 delete를 사용할 때 다음과 같은 규칙을 지켜야 한다.
new로 대입하지 않은 메모리는 delete로 해제하지 않는다.
같은 메모리 블록을 연달아 두 번 delete로 해제하지 않는다.
new [] 로 메모리를 대입한 경우에는 delete[]로 해제한다.
new를 대괄호 없이 사용했으면 delete도 대괄호 없이 사용한다.
널 포인터에는 delete를 사용하는 것이 안전하다 (아무일도 일어나지 않는다.)
*/


#include<iostream>
int main(){
    using namespace std;
    double * p3 = new double [3];

    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    p3[3] = 0.8;

    p3 = p3 +1;
    cout << p3[3];
    

}
/*
위의 예제에서 포인터를 증가시키고 동적배열의 범위를 벗어나는 값을 출력하면 주소가 나온다.
이것은 값이 담겨있지않은 위치를 읽어온것이라서 나오는것은 없는것같다. 
포인터 연산에서 int 형의 값들에 +1을 하면 해당 주소의 값에 변화가 아니라 다음 차례의 원소를 가르키게 된다. 




04.8 포인터 배열 포인터 연산
포인터 변수에 1을 더하면 값이 포인터가 지시하는 데이터형의 바이트 만큼 증가한다.
-- 프로그램 분석
미리 할당한 배열의 크기를 넣어서는 곳에 값을 넣어주면 malloce()에러가 발생하나. 
배열 stacks[1]은 *(stacks + 1) 과 같다. 
arrayname[i] 를 *(arrayname +1)로 변환한다.
pointername[i]를 *(pointername + i)로 변환한다. 
따라서 stacks[i]를 사용할 때 *(stacks + i)로 사용해서 배열이 아니라 포인터 표기를 할 수 있다.

한 가지 차이점이 있다면 배열 이름은 값을 변경 할 수 없는 상수인 반면에 포인터는 값을 변강할 수 있는 변수라는 사실 이다. 
pointername = pointername +1 // 맞다 이렇게 하면 주소에 들어있는 값에 연산을 한 값이 나온다. 
arrayname = arrayname +1; 틀린다.  이렇게 계산하면 다음 번째 원소가 나올거같았는데 아니다
또한가지 차이점은 배열 이름에 sizeof 연산자를 적용하면 배열의 크기가 얻어 지지만 포인터에 sizeof 연산자를 적용하면 
비록 포인터가 배열을 지시하고 있더라도 포인터의 크기가 얻어진다는 것이다. 
예를 들어 
24 = wages 배열의 크기 sizeof(wages) 출력
4  = pw 포인터의 크기 sizeof(pw) 출력
이 경우에는 배열이름을 주소로 해석하지않는다 .
*/





// // 04.18 arraynew.cpp
// #include <iostream>
// int main()
// {
//     using namespace std;
//     double *p3 = new double[3]; // double형 데이터3개를 저장할 수
//                                 // 있는 공간을 대입한다

//     p3[0] = 0.2; // p3을 배열 이름처럼 취급한다.
//     p3[1] = 0.5;
//     p3[2] = 0.8;
//     cout << "p3[1]은 " << p3[1] << "입니다. \n";
//     p3 = p3 + 1; // 포인터를 증가시킨다.
//     cout << "이제는 p3[0]이 " << p3[0] << "이고, ";
//     cout << "p3[1]이 " << p3[1] << "입니다.\n";
//     p3 = p3 - 1; // 다시 시작 위치를 지시한다
//     delete[] p3; // 배열 메모리를 해제한다.
//     return 0;
// }

/*
04.8 포인터, 배열, 포인터 연산
pw = &pw, *pw = 10000.0
pw = +1
pw = &pw+1 *pw =
*/

/*포인터와 문자열





*/

// // ptrstr.cpp 04.20
// #include <iostream>
// #include <cstring> // strlen(), strcpy()를 선언
// int main()
// {
//     using namespace std;
//     char animal[20] = "bear"; // animal에 bear가 들어있다.
//     const char *bird = "wren"; // bird에 문자열의 주소가 들어 이싸.
//     char *ps; //초기화 되지 않았다.
//     cout << animal << " and "; //bear를 출력한다.
//     cout << bird << "\n";   //wren을 출력한다.
//     // cout << ps << "\n"; // 쓰레기를 출력하거나 먹통이 될 수도 있다.

//     cout << "동물의 종류를 입력하십시오: ";
//     cin >> animal;  //입력이 20문자 이내여야한다.
//     // cin >> ps; 절대로 해서는 안 될 엄청난 실수이다.
//     // ps가 대입된 공간을 지시하고 있지않다.

//     ps = animal;    //ps를 문자열를 지시하도록 설정한다.
//     cout << ps << "s!\n";  // 맞다, animal을 사용하는 것과 동등
//     cout << "strcpy() 사용 전:\n";
//     cout << (int *)animal << ": " << animal << endl;
//     cout << (int *)ps << ": " << ps << endl;

//     ps = new char[strlen(animal) + 1]; // 새메모리르 대입한다.
//     strcpy(ps, animal); // 새 메모리에 문자열을 복사
//     cout << "strcpy() 사용 후 : \n";
//     cout << (int *)animal << ": " << animal << endl;
//     cout << (int *)ps << ": " << ps << endl;
//     delete[] ps;
//     return 0;
// }

/*
    new를 사용한 동적 구조체의 생성
지금까지 커파일 시간보다는 실행 시간에 배열을 생성하는 것이 훨 씬 유리하다는 것을 알아보았다.


*/

// // newstruct.cpp 0421

// #include <iostream>
// struct inflatable

// { // 구조체 정의
//     char name[20];
//     float volume;
//     double price;
// };
// void a(inflatable *ps);
// void b(inflatable *ps);
// using namespace std;

// int main()
// {
//     inflatable *ps = new inflatable; // 구조체를 위한 메모리 대입
//     // cout << "모형풍선의 이름을 입력하십시오: ";
//     // cin.get(ps->name, 20); // 멤버에 접근하는 제1 방법
//     // cout << "부피를 세제곱피트 단위로 입력하십시오: ";
//     // cin >> (*ps).volume; // 멤버에 접근하는 제 2 방법
//     // cout << "가격을 달러 단위로 입력하십시오: $";
//     // cin >> ps->price;
//     // cout << "이름: " << (*ps).name << endl;            // 제2 방법
//     // cout << "부피 : " << ps->volume << "cubic feet\n"; // 제1 방법
//     // cout << "가격: $" << ps->price << endl;            // 제 1방법
//      a(ps);
//      b( ps);
//     delete ps;                                         // 구조체가 사용한 메모리 해제
//     return 0;
// }
// void a(inflatable *ps)
// {
//     // inflatable *ps = new inflatable; // 구조체를 위한 메모리 대입
//     cout << "모형풍선의 이름을 입력하십시오: ";
//     cin.get(ps->name, 20); // 멤버에 접근하는 제1 방법
//     cout << "부피를 세제곱피트 단위로 입력하십시오: ";
//     cin >> (*ps).volume; // 멤버에 접근하는 제 2 방법
//     cout << "가격을 달러 단위로 입력하십시오: $";
//     cin >> ps->price;
// }

// void b(inflatable *ps)
// {
//     cout << "이름: " << (*ps).name << endl;            // 제2 방법
//     cout << "부피 : " << ps->volume << "cubic feet\n"; // 제1 방법
//     cout << "가격: $" << ps->price << endl;
// }

/*
s01 = 1998
s02 = 1999
trio[0] = 2003;
trio->year = 2003
arp[3] = {&s01, &s02, &s03}
arp[1]->year = 1999

**ppa = arp; 이게 뭐임


*/

/*
배열의 대안
vector 템플릿 클래스


*/
// #include<iostream>
// #include<vector>
// #include<array>
// int main(){
//     using namespace std;
//     double a1[4] = {1.2,2.4,3.6,4.8};
//     vector<double> a2(4);
//     a2[0] = 1.0/3.0;
//     a2[1] = 1.0/5.0;
//     a2[2] = 1.0/7.0;
//     a2[3] = 1.0/9.0;

//     array<double, 4 > a3 = {3.14, 2.72, .162, 1.41};
//     array<double, 4> a4;
//     a4 = a3;

//     cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
//     cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
//     cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
//     cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

//     a1[-2] = 20.2;
//     cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
//     cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
//     cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
//     return 0;

// }

/*루프

*/
// #include<iostream>
// #include<string>
// int main() {
//     using namespace std;
//     cout << "단어를 하나 입력하십시오: ";
//     string word;
//     cin >> word;

//     char temp;
//     int i,j;
//     for ( j = 0, i = word.size() -1; j<i; --i, j++){

//         temp = word[i];
//         word[i] = word[j];
//         word[j] = temp;
//     }
//     cout << word << "\n종료.\n";
//     return 0;
// }

// #include<iostream>
// int main(){
//     using namespace std;
//     // cin, cout 화이트스페이스를 무시한다. 그래서 그다음 버전 cin.get(ch)를 사용
//     // cin.get()은 \n를 읽어드려서 다음 출력에서 처음에 반환한다. 그래서 cin.get()을 한번더 출력하면 개행문자를 비워낸다.
//     // 들여쓰기를 인식해야할 때는 end of file로 확인한다. cin.fail()로 문장의 끝인지를 검사한다.

//     char ch;
//     int count = 0;
//     cin.get(ch);// 문자 하나를 읽는다
//     while (cin.fail() == false){  // EOF인지 검사한다.
//         cout << ch;            // 문자를 에코한다.
//         ++count;
//         cin.get(ch); // 다음 문자를 읽는다.

//     }
//     cout << count << " 문자를 읽었습니다.\n";
//     return 0;
// }

// #include<iostream>
// int main(void){
//     using namespace std;
//     int ch;
//     int count = 0;
//     while ((ch = cin.get()) !=EOF){
//         cout.put(char(ch));
//         ++count;
//     }
//     cout << count << " 문자를 읽었습니다. \n";
//     return 0;
// }

/*2차원 배열
 1차원 배열들의 모임을 2차원 배열이라고 한다.


*/

// #include <iostream>
// const int Cities =5;
// const int Years =4;
// using namespace std;
// int max(int(*)[Cities]);
// int main()
// {
//     const char* cities[Cities] ={
//         "Seoul","Jeju","Busan","Gangneung",
//         "Daegu"
//     };
//     int maxtemps[Years][Cities]=
//     {
//         {35,32,33,36,35},
//         {33,32,34,35,31},
//         {33,34,32,35,34},
//         {36,35,34,37,35}
//     };

//     cout << "2009년부터 2012년까지의 연중 최고 온도\n\n";
//     for (int city = 0; city < Cities; ++city)
//     {
//         cout << cities[city] << ":\t";
//         for (int year  = 0; year < Years; ++year)
//         {
//             cout << maxtemps[year][city] <<"\t";
//         }
//         cout <<endl;
//     }
//     int m=max(maxtemps);
//     cout << "최대값: " << m <<endl;
//     return 0;
// }

// int max(int(*max)[Cities])
// {
//     int m=0;
//     for (int city = 0; city < Cities; ++city)
//     {
//         for (int year  = 0; year < Years; ++year)
//         {
//             m= m < max[year][city] ? max[year][city] : m ;
//         }
//     }
// return m;
// }

/*p.352
논리곱 연산자


*/
// #include <iostream>
// const char *qaulify[4] = {
//     "만미터 달리기",
//     "모래사장 씨름",
//     "비치발리",
//     "부메랑 던지기"};

// int main()
// {

//     using namespace std;
//     int age;
//     cout << "나이를 입력하십시오: ";
//     cin >> age;
//     int index;

//     if (age > 17 && age < 35)
//         index = 0;
//     else if (age >= 35 && age < 50)
//         index = 1;
//     else if (age >= 50 && age < 65)
//         index = 2;
//     else
//         index = 3;
//     cout << "당신은 " << qaulify[index] << "에 참가할 수 있습니다.\n";
//     return 0;
// }

/*
6.8
cctypes.cpp
*/
// #include <iostream>
// #include <cctype> //문자 관련 함수들의 원형
// int main()
// {
//     using namespace std;
//     cout << "분석할 텍스트를 입력하십시오. "
//             "입력의 끝을 @으로 표시하십시오. \n";
//     char ch;
//     int whitspace = 0;
//     int digits = 0;
//     int chars = 0;
//     int punct = 0;
//     int others = 0;

//     cin.get(ch); // 첫문자를 입력받는다
//     while (ch != '@')
//     {                    // 종료표시 문자인지 검사한다.
//         if (isalpha(ch)) // 영문자인가?
//             whitspace++;
//         else if (isspace(ch)) // 화이트스페이스?
//             whitspace++;
//         else if (isdigit(ch)) // 숫자인가?
//             digits++;
//         else if (ispunct(ch)) // 구두점인가?
//             punct++;
//         else
//             others++;
//         cin.get(ch); // 다음 문자를 입력받는다.
//     }
//     cout << "알파벳 문자 " << chars << ", "
//          << "화이트스페이스 " << whitspace << ", "
//          << "숫자 " << digits << ", "
//          << "구두점 " << punct << ", "
//          << "기타 " << others << endl;
//     return 0;
// }

/*
p. 376
cinglof.cpp
*/
// #include <iostream>
// const int Max = 5;
// int main()
// {

//     using namespace std;
//     int golf[Max];
//     cout << "골프 점수를 입력하십시오. \n";
//     cout << "총 " << Max << " 라운드 점수를 입력해야 합니다. \n";
//     int i;
//     for (i = 0; i < Max; i++)
//     {
//         cout << "round #" << i + 1 << ": ";
//         while (!(cin >> golf[i]))
//         {
//             cin.clear();
//             while (cin.get() != '\n')
//                 continue;
//             cout << " 골프점수를 입력하십시오: ";
//         }
//     }
//     // 평균을 계산한다
//     double total = 0.0;
//     for (i = 0; i < Max; i++)
//         total += golf[i];
//     // 결과를 보고한다.
//     cout << "chd " << Max << "라운드의 평균 점수 + "
//          << total / Max << endl;
//     return 0;
// }