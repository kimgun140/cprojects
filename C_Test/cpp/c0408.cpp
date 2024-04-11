// #include<iostream>
// #include<cmath>
// int main()
// {

    // using namespace std;
    // cout << "c++의 세계로 오십시오";
    // cout << endl;
    // cout << "후회하지 않으실겁니다!" << endl;
    // return 0;

    // using namespace std;
    // int carrots; 

    // carrots = 25;
    // cout << "나는 당근을";
    // cout << carrots;
    // cout << "개 가지고 있다.";
    // cout << endl;
    // carrots = carrots -1;
    // cout << "아삭아삭, 이제 당근은 " << carrots << "개이다." << endl;
    // return 0;
// cout은 데이터형을 알아서 판단해서 출력해준다. printf에서는 직접 %d라든가 정해줘야하지만
//여기서는 훨씬 편하네

// using namespace std;

// double area;
// cout << "마루 면적을 평방피트 단위로 입력하시오";
// cin >> area;
// double side; 
// side = sqrt(area);
// cout << "사각형 마루라면 한 변이 " << side
//      <<"피트에 상당합니다." <<endl;
// cout << "멋지네요!" <<endl;
// return 0;







// }

// 함수 사용해보기
// void simon(int);
// int main ()
// {
//     using namespace std; // 라이프 사이클주기 설정? 함수등등 사용되고 삭제되게
//     simon(3);
//     cout << "정수를 하나 고르시오: ";
//     int count;
//     cin >> count; // 입력함수 
//     simon(count);
//     cout << "끝!" <<endl;
//     return 0;

// }
// void simon(int n)
// {
//     using namespace std;
//     cout << "Simons 왈, 발가락을" << n << "번 두드려라." << endl; //보이드형 함수에는 return이 필요없다. 
// }

//convert 

// #include<iostream>
// int stonetolb(int);
// int main(){

//     using namespace std;
//     int stone;
//     cout << "체중을 스톤단위로 입력하시오";
//     cin >> stone;
//     int  pound = stonetolb(stone);
//     cout << stone << " 스톤은 ";
//     cout << pound << " 파운입니다." << endl;
//     return 0;

// }   

// int stonetolb(int sts){
//     return 14 * sts;
// }



// chapter 03 데이터 처리 

/*객체 지향 프로그래밍의 진수는 사용자가 데이터형을 스슷로 설계하고 확장할 수 있다는데 있다.
이것이 정말로 가능하다면 데이터를 처리하는 작업이 훨 씬 간단해질 것이다. 그러나 사용자 정의 데이터형에 대해 설명하기 전에 먼저 ++에 내장되어진 걸 알아보자
대부분의 프로그램이 정보를 저장한다. 아이비엠 주식의 현시세 뉴욕시시의 평균습도 헌벙에 가장많이 나오는 단어와 빈도 수 등등 많은 정보가 될 수 있다. 
컴퓨터에 이러한 정보를 저장하려면 프로그램은 3가지를 알아야한다.

어디에 저장되는가 - 메모리에 저장 - 지역변수(스택메모리) ,전역변수(data)영역에 저장된다. 프로그램 시작될때 활성화된다. 
(heap)메모리에 동적할당으로 준다. 메모리 올로케이션 memory allocation  
first in last out 선입후출 (스택) 
stack과 que(선입선출) 자료구조
어떤 값이 저장되는가 - 
어떤 종류의 정보인가

초기화는선언과 대입을 하나로 조합한다.
int n_int = INT_MAX; 
초기화를 안해주면 쓰레기 값이 들어가니까 
unsingned 음수표기를 포기하고 자료의 최대값을 늘릴 수 있다. 


*/

// // exceed /reset point라는걸 확인해보자
// #include<iostream>
// #define ZERO 0 
// #include<climits>
// int main(){
//     using namespace std;
//     short Dohee = SHRT_MAX;
//     unsigned short Insuk = Dohee;

//     cout << "도희의 계좌에는 " << Dohee << "원이 들어 있고, ";
//     cout << "인숙이의 계좌에도 " << Insuk << "원이 들어 있다. " <<endl;
//     cout << "각각의 계좌에 1원씩 입금한다." << endl << "이제 ";
//     Dohee += 1;
//     Insuk += 1;
//     cout << "도희의 잔고는 " << Dohee << "원이 되었고, "; // overflow
//     cout << "인숙이의 잔고는 : " << Insuk << "원이 되었다." << endl;
//     cout << "이럴 수가! 도희가 나 몰래 대출을 했나?" << endl;
//     Dohee = ZERO;
//     Insuk = ZERO;
//     cout <<"도희의 계좌에는 " << Dohee << "원이 들어 있고 ";
//     cout << "인숙이의 계좌에도 " <<Insuk << "원이 들어 있다. " <<endl;
//     cout << "각각의 계좌에서 1원씩 인출한다. " << endl << "이제 " ;
//     Dohee = Dohee-1;
//     Insuk = Insuk -1;
//     cout << "도희의 잔고는 " << Dohee << "원이 되었고, ";
//     cout << "인숙이의 잔고는 : " << Insuk << "원이 되었다." << endl;
//     cout << "이럴 수가! 인숙이가 복권에 당첨되었나?" << endl;
//     return 0;

// }


// #include<iostream>
// int main(){
//     using namespace std;
// char ch = 'M';
// int i = ch;
// cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

// cout << "이 문자 코드에 1을 더해 보겠습니다." << endl;
// ch = ch +1;
// i = ch;
// cout << ch << "의 ASCII 코드는 " << i << "입니다."<< endl;

// //cout.put() 멤버 함수를 사용하여 char형 변수 ch를 출력한다.
// cout << "cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
// cout.put(ch);

// cout.put('!');
// cout << endl << "종료" << endl;
// return 0;
// }
// // cout.put()함수는 무엇일까 
// /*
// 클래스는 데이터 형식과 그 데이터르 다루는 방법을 정의 해놓은것이다. 멤버함수는
// 클래스에 속하고, 클래스의 데이털르 다루는 방법을 정의한다. 예를들어
// ostream클래스는 문자를 출력하도록 설계된 put()이라는 멤버 함수를 가지고있다. 
//     멤버 함수는 그 클래스의 특정 객체를 통해서만 사용할 수 있다. 이번에는
// cout 객체를 통해 put() 멤버함수를 사용했다.
// */


//확장 char형 wchar_t
/*


*/

// bool이라는 새로운데이터형이 추가되었다.  false true 표현이 가능하다.
// true = 1 false = 0 like this

// float 부동 소수점형 
// 부동소수점형 상수 1.2f
// c++ 연산자 다 똑같은듯 c랑
//연산자 오버로딩 같은 이름의 함수가 매개변수의 개수나 데이터타입이 달라질 때 
// C++가 알아서 문맥을 파악해서 다른 기능을 실행하는것이다. 인트 끼리 연산할 때와 플롯이랑 연수할때 
// 두가지는 다른 경우인데 같은 나누기 연산자로 알아서 자연스럽게 쓰는것.

/*
묵시적 형변환
큰 데이터에서 작은 데이터형으로 바꾸면 데이터 손실이 생긴다.
소수형에서 정수형으로 변환되면 소수부를 잃어버릴 수 있다.

*/

// //init.cpp
// #include<iostream>
// int main()
// {
//     using namespace std;
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     float tree = 3;
//     int guess = 3.9832;
//     int debt = 7.2E12;
//     cout << "tree =  " << tree << endl;
//     cout << "guess + "<<guess << endl;
//     cout << "debt - " <<debt << endl;
//     return 0;
// }


// #include<iostream>
// int main(){
//     using namespace std;
//     int yams[3];
//     yams[0] = 7;
//     yams[1] = 8;
//     yams[2] = 6;

//     int yamscosts[3] = {200,300,50};

//     cout << "고구마 합계 = ";
//     cout << yams[0] + yams[1] + yams[2] << endl;
//     cout << yams[1] << "개가 들어 있는 포장은 ";
//     cout << "개당 " << yamscosts[1] << "원씩입니다.\n";
//     int total = yams[0] * yamscosts[0] + yams[1] * yamscosts[1];
//     total = total + yams[2] * yamscosts[2];
//     cout << "세 포장의 총 가격은 " << total << "원입니다. \n";
//     cout << "\nyams 배열의 크기는 " << sizeof yams;
//     cout <<"바이트입니다.\n";
//     cout << "원소 하나의 크기는 " << sizeof yams[0];
//     cout << "바이트입니다. \n";
//     return 0;

// }

// //strings.cpp
// #include<iostream>
// #include <cstring>

// int main()
// {

//     using namespace std;
//     const int Size = 15;
//     char name1[Size];
//     char name2[Size] = "C++owboy";


// cout << "안녕하세요! 저는 " << name2;
// cout << "입니다! 실례지만 성함이? \n";
// cin >> name1;
// cout << "아, " << name1 << "씨! 당신의 이름은 " ;
// cout << strlen(name1) << "자입니다만 \n";
// cout << sizeof (name1) << "바이트 크기의 배열에 저장되었습니다. \n";
// cout << "이름이 " <<name1[0] << "자로 시작하는군요.\n";
// name2[3] = '\0'; //널문자 
// cout << "제 이름의 처음 세 문자는 다음과 같습니다.: ";
// cout << name2 << endl;
// return 0;
// // getline은 개행문자를 읽고 그것을 널문자로 대체한다. 문자열 저장하는 제일 깔끔한 방법이다.
// //get은 널문자를 입력 스트림에 남겨둔다.  그래서 다음 문자를 그냥 출력하면 널문자가 나오면서 그냥 종료가 되어버림? 


// }




// #include<iostream>
// int main()
// {
//     using namespace std;
//     const int ArSize = 20;
//     char name[ArSize];
//     char dessert[ArSize];

//     cout << "이름을 입력하십시오: \n";
//     cin >> name;
//     cout << "좋아하는 디저트를 입력하십시오: \n";
//     cin >> dessert;
//     cout << "맛있는 " << dessert;
//     cout << " 디저트를 준비하겠습니다. " << name << "님! \n";
//     return 0;
// }

// #include<iostream>
// #include<string>
// int main(){
//     using namespace std;
//     char charr1[20];
//     char charr2[20] = "jaguar";
//     string str1;
//     string str2 = "panther";

//     cout << "고양이과의 동물 한 종을 입력하시오: ";
//     cin>> charr1;
//     cout << "고양이과의 또 다른 동물 한 종을 입력하시오:";
//     cin >> str1;
//     cout << "아래 동물들은 모두 고양이과입니다: \n";
//     cout << charr1 << " " << charr2 << " "
//         <<str1 << " " << str2 
//         << endl;
//     cout << charr2 << "에서 세 번째 글자: "
//         << charr2[2] << endl;
//     cout << str2 << "에서 세 번째 글자: "
//         <<str2[2] << endl;

//         return 0;
// }




// #include<iostream>
// #include<string>

// int main(){

//     using namespace std;
//     string s1 = "penguin";
//     string s2, s3;

//     cout << "string 객체를 string 객체에 대입할 수 있다.: s2 = s1\n";
//     s2 = s1;
//     cout << "s1: " << s1 << " , s2: " << s2 << endl;
//     cout << "string 객체에 C 스타일 문자열을 대입할 수 있다. \n";
//     cout << "s2 = \"buzzard\" \n";
//     s2 = "buzzard";
//     cout << "s2: " << s2 << endl;
//     cout << "string 객체들을 결합할 수 있다.: s3 = s1 + s2\n";
//     s3 = s1 + s2;
//     cout << "s3: " << s3 << endl;
//     cout << "string 객체들을 추가할 수 있다.\n";
//     s1 += s2;
//     cout << "s1 += s2 --> s1 = " << s1 << endl;
//     s2 += "for a day";
//     cout << "s2 += \" for a day\" --> s2 = " << s2 << endl;
//     return 0;
// }


//strtyrp4 행단위 입력

#include<iostream>
#include<string>
#include<cstring>

int main(){

    using namespace std;
    char charr[20];
    string str;
    cout << "입력 이전에 charr에 있는 문자열의 길이: "
        <<strlen(charr) << endl;
    cout << "입력 이전에 str에 있는 문자열의 길이: "
        << str.size() << endl;
    cout << "텍스트 한 행을 입려하시오:\n" ;
    cin.getline(charr, 200);
    cout << "입력한 텍스트: " << charr << endl;
    cout << "또 다른 텍스트 한 행을 입력하시오: \n";
    getline(cin, str);
    cout << "입력한 텍스트: " << str << endl;
    cout << "입력 이후 charr에 있는 문자열의 길이: "
        <<strlen(charr) << endl;
    cout << "입력 이후에 str에 있는 문자열의 길이: "
        << str.size() << endl;
// 한글은 입력이 안되네?
    return 0; 
}


