// #include<iostream>
// #include<string>
// using namespace std;
// const int SIZE = 5;
// void display(const string sa[], int n);
// int main(){
//     string list[SIZE];
//     cout << "좋아하는 밤하늘의 광경을 " << SIZE << "개 입력하시오: \n";
//     for( int i =0; i < SIZE; i++){
//         cout << i+1 << " : ";
//         getline(cin, list[i]);
//     }
//     cout <<"입력하신 내용은 다음과 같습니다: \n";
//     display(list, SIZE);
//     return 0;
// }

// void display(const string sa[], int n){
//     for (int i = 0; i < n; i++)
//     cout << i +1 << ": " << sa[i] << endl;
// }

// //array 객체
// #include<iostream>
// #include<array>
// #include<string>
// //상수 데이터
// const int Seasons = 4;
// const std::array<std::string, Seasons> Sname =
// {"Spring", "Summer", "Fall","Winter"};

// //array 객체를 수정하는 기능
// void fill(std::array<double, Seasons> *pa);
// //수정하지 않고 객체를 사용하는 기능
// void show(std::array<double, Seasons>da);
// int main(){
//     std::array<double, Seasons>expenses;
//     fill(&expenses);
//     show(expenses);
//     return 0;
// }
// void fill(std:: array<double, Seasons>*pa){
//     using namespace std;
//     for( int i = 0; i <Seasons; i++){
//         cout << Sname[i] << "에 소요되는 비용: ";
//         cin >> (*pa)[i];
//     }
// }

// void show(std::array<double, Seasons> da){
//     using namespace std;

//     double total = 0.0;
//     cout << "\n계절별 비용S\n";
//     for( int i = 0; i < Seasons; i ++){
//         cout << Sname[i] << " : $" << da[i] << endl;
//         total += da[i];
//     }
//     cout << "총 비용 : $" << total << endl;
// }

// //재귀 호출

// #include<iostream>
// void countdown(int n);

// int main(){
//     countdown(4);
//     return 0;
// }
// void countdown(int n){
//     using namespace std;
//     cout << "카운트 다운 ... " << n << endl;
//     if(n >0)
//         countdown(n-1);
//     cout << n << ": Kaboom!\n";
// }

// 함수를 지시하는 포인터
/*함수를 지시하는 포인터 데이터 항목들과 마찬가지로 함수도 주소를 가지고 있다. 함수의 주소는 그 함수에 해당하는 기계어 코드가 저장되어 있는 메모리 블록의 시작 주소이다.
일반적으로 사용자가 함수의 주소를 아는것은 중요하지도 않고 유용하지도 않다.
함수 포인터의 기초
함수의 주소를얻는다.
함수를 지시하는 포인터를 선언한다.ㅏ
함수를 지시하는 포인터를 사용하여 그 함수를 호출한다.

함수 주소 얻기
뒤에 붙는 괄호를 빼고 함수 이름만 사용하면 된다ㅏ. 즉 think()의 주소를 얻으려면


함수 포인터 선언하기
double pam (int); 함수 원형
이함수를 지시한느 포인터의 적절한 선언
double (*pf)(int)
pf는 하나의 int를 매개변수로 취하고
double형을 리턴하는 함수를 지시한다.


 */
// #include<iostream>
// double gildong(int);
// double moonsoo(int);
// //두 번째 매개변수는 int형을 매개변수로 취하는 
// //double형 함수를 지시하는 포인터다.

// void estimate(int lines, double (*pf)(int));


// int main(){
//     using namespace std;
//     int code;
//     cout << "필요한 코드의 행 수를 입력하십시오: ";
//     cin >> code;
//     cout << "홍길동의 시간 예상: \n";
//     estimate(code, gildong);
//     cout << "박문수의 시간 예상: \n";
//     estimate(code, moonsoo);
//     return 0;
// }

// double gildong(int lns){
//     return 0.05 * lns;
// }
// double moonsoo(int lns){
//     return 0.03 * lns + 0.0004 * lns * lns;
// }

// void estimate(int lines, double (*pf)(int)){
//     using namespace std;
//     cout << lines << "행을 작성하는 데 ";
//     cout << (*pf)(lines) << "시간이 걸립니다.\n";
// }




