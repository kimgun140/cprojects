/*함수의 활용
인라인 함수
함수 호출을 하지않고 호출자리에 함수 자체를 때려박는 느낌
프로그램의 속도를 높이기 위해서 메인에서 함수로 점프했다가 다시 돌아오는과정이다.
인라인 함수는 함수 코드가 프로그램의 다른 코드안에 직접 상입되어 있다.
이 말은 컴파일러가 함수 호출을 그에 대응하는 함수 코드로 대체한다는 것을 의미한다.
함수를 그 자리에서 처리하므로 다른 주소로 점프했다가 돌아올 필요가 없다. 따라서 인라인 함수는 일반 함수보다
약간 빠르게 작동한다.
그런가 메모리 사용측면에서는 인라인 함수가 일반 함수보다 불리하다.
함수를 열 번 호출하면 프로그램은 함수의 사본 코드를 열반이나 삽입해야한다.
조심해서 사용해야한다. 함수 코드 자체를 수행하는 시간이 함수 호출 과정에 비해 더 길다면
절약되는 시간이 없다. 함수의 수행 시간이 매우 짧은 경우에는 이득이겠다.
해당함수의 빈도수가 많지 않으면 이득을 보기 어렵다.
*/

// #include <iostream>
// // 인라인 함수 정의
// inline double square(double x) { return x * x; }
// int main()
// {
//     using namespace std;
//     double a, b;
//     double c = 13.0;
//     a = square(5.0);
//     b = square(4.5 + 7.5);
//     cout << "a = " << a << ", b = " << b << endl;
//     cout << "c = " << c;
//     cout << ", c의 제곱 = " << square(c++) << endl;
//     cout << "현재 c = " << c << endl;
//     return 0;
// }
/*참조 변수

++는 참조 변수라는 새로운 복합형을 언에 추가해싿. 참조는 미리 정의 된 어떤 변수의 실제 이름 대신 쓸 수 있는 내용 이름이다ㅏ.

변수의 값을 변경하고 싶어 값만 넘겨주면 못하니까 주소값을 넘겨주면 (포인터)가능하겠다.
주소값에 씌여진 값을 다른 함수에서 수정할 수가 있었다. ㅇ
이 개념을 어려워해서 주소연산자로 넘겨주면 원본값을 넘겨주자 (이거 무슨말이야 모르겠네) ref 참조표시만 해주면
*를 붙여줄 필요도 없이 바로 원본값의 수정을 해버림
(아무튼 포인터 안쓰고 사용하려고 하는거 인듯)
int rats;
int & rodents = rats;이렇게 쓰면 rat의 대용이름으로 rodents가 됨
함수로 쓸 때 씀 여기서 &가 주소연산자가 아니라 , 데이터형 식별자으 ㅣ일부로 사용된 것이다.
변수 선언에서 char *가 문자를 지시하는 포인터를 의미하는 것처럼 int &는 int에 대한 참조를 의미한ㄷ. 참조 선언은 rats와 rodents를 서로
바꾸어 사용 할 수 있게 해 준다. 이들 둘은 모두 같은 값과 같은 메모리 위치를 참조한다.



*/

// #include<iostream>
// int main(){
//     using namespace std;
//     int rats = 101;
//     int & rodents = rats; // rodents는 참조 변수이다.
//     cout << "rats = " << rats;
//     cout << ", rodents = " << rodents << endl;
//     //어떤 시스템에서는 다음 주소들을
//     //unsigned형으로 변환해 주어야 한다.
//     cout << "rats의 주소 = " << &rats;
//     cout <<", rodents의 주소 = " << &rodents << endl;
//     return 0;
// }
/*함수 매개변수로서의 참조
포인터가 없는 언어에서 사용하는 방법이 참조이다.
함수 내에서 변수의 값을 수정하면 함수 외부의 원본 값이 바뀐다.
하지만 참조변수를 사용하면 참조변수가 가리키는 주소를 바꿀 수가없다. */

// #include <iostream>
// void swapr(int &a, int &b);
// void swapp(int *p, int *q);
// void swapv(int a, int b);
// int main()
// {

//     using namespace std;
//     int wallet1 = 3000;
//     int wallet2 = 3500;

//     cout << "지갑 1 = " << wallet1 << "원";
//     cout << ", 지갑 2 = " << wallet2 << "원\n";

//     cout << "참조를 이용하여 내용들을 교환:\n";
//     swapr(wallet1, wallet2);
//     cout << "지갑 1 = " << wallet1 << "원";
//     cout << ", 지갑 2 = " << wallet2 << "원\n";

//     cout << "포인터를 이용하여 내용들을 다시 교환: \n";
//     swapp(&wallet1, &wallet2);
//     cout << "지갑 1 = " << wallet1 << "원";
//     cout << ", 지갑 2 = " << wallet2 << "원\n";

//     cout << "값으로 전달하여 내용 교환 시도: \n";
//     swapv(wallet1, wallet2);
//     cout << "지갑 1 = " << wallet1 << "원";
//     cout << ", 지갑 2 = " << wallet2 << "원\n";
//     return 0;
// }
// void swapr(int &a, int &b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

// void swapp(int *p, int *q)
// {
//     int temp;
//     temp = *p;
//     *p = *q;
//     *q = temp;
// }

// void swapv(int a, int b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

// #include<iostream>
// double cube(double a);
// double refcube(double &a);
// int main(){
//     using namespace std;
//     double x = 3.0;
//     cout << cube(x);
//     cout << " = " << x << "의 세제곱 \n";
//     cout << refcube(x);
//     cout << " = " << x << "의 세제곱\n";
//     return 0;
// }
// double cube(double a)
// {
//     a *= a * a; // 이거 뭐임? 이게 참조인거임? 왜 *=이거 뭔데요
//     return a;
// }
// double refcube(double &ra){
//     ra *= ra * ra;
//     return ra;
// }

// #include <iostream>
// #include <string>

// struct free_throws
// {
//     std::string name;
//     int made;
//     int attempts;
//     float percent;
// };

// void display(const free_throws &ft);
// void set_pc(free_throws &ft);
// free_throws & accumulate(free_throws &target, const free_throws &source);

// int main()
// {
//     // 부분 초기화 - 멤버는 0에 세팅된 상태로 남는다.
//     free_throws one = {"ifelsa Branch", 13, 14};
//     free_throws two = {"Andor Kott", 10, 16};
//     free_throws three = {"Minnie max", 7, 9};
//     free_throws four = {"Whily Looper", 5, 9};
//     free_throws five = {"Long Long", 6, 14};
//     free_throws team = {"Throwgoods", 0, 0};

//     // 초기화 하지 않음
//     free_throws dup;
//     set_pc(one);
//     display(one);
//     accumulate(team, one);
//     display(team);
//     // 리턴값을 매개변수로 사용한다.
//     display(accumulate(team, two));
//     accumulate(accumulate(team, three), four);
//     // 리턴값ㅇ르 대입 값으로 사용한다.
//     dup = accumulate(team, five);
//     std::cout << "team 출력: \n";
//     display(team);
//     std::cout << "대입 이후 dup 출력:\n";
//     display(dup);
//     set_pc(four);
//     // 문제의 소지가 있는 대입
//     accumulate(dup, five) = four;
//     std::cout << "문제 소지가 있는 대입 이후 dup 출력: \n";
//     display(dup);
//     return 0;
// }
// void display(const free_throws &ft)
// {

//     using std::cout;
//     cout << "Name: " << ft.name << '\n';
//     cout << "Made: " << ft.name << '\t';
//     cout << "Attempts:" << ft.attempts << '\t';
//     cout << "Percent: " << ft.percent << '\n';
// }
// void set_pc(free_throws &ft)
// {
//     if (ft.attempts != 0)
//         ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
//     else
//         ft.percent = 0;
// }
// free_throws & accumulate(free_throws & target, const free_throws & source)
// {
//     target.attempts += source.attempts;
//     target.made += source.made;
//     set_pc(target);
//     return target;
// }

/*디폴트 매개 변수


*/

/*함수 오버로딩
다형성
서로 다른 여러 개의 함수가 하나의 이름을 공유하는 것이다.

*/

#include <iostream>
unsigned long left(unsigned long num, unsigned ct);
char *left(const char *str, int n = 1);
int main()
{
    using namespace std;
    char * trip = "Hawaii!!";
    unsigned long n = 12345678;
    int i;
    char *temp;
    for (i = 1; i < 10; i++)
    {
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete[] temp;
    }
    return 0;
}
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
        return 0;
    while (n /= 10)
        digits++;
    if (digits > ct)
    {
        ct = digits - ct;
        while (ct--)
            num /= 10;
        return num;
    }
    else
        return num;
}
// 이 함수는 str문자열의 앞에서부터 n개의 문자르 취하여
// 새로운 문자열을 구성하고, 그것을 지시하는 포인터를 리턴한다.
// 분할컴파일 개념이해정도만 해보자 예제는 다안해도됨 스택은 알지? 블록안에 블록 밖에 함수 안에 필요없음
char *left(const char *str, int n)
{
    if (n < 0)
        n = 0;
    char *p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];
    while (i <= n)
        p[i++] = '\0';
    return p;
}