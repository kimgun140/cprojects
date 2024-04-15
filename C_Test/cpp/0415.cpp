// 간단한 파일 입출력
// #include <iostream>
// #include<fstream>
// int main()
// {

//fin.getline(firstName,20);파일에서 문자 20개 읽기
//getline(fin,line); 파일에서 한 줄을 읽어 오기
/*

fin >> word; 파일에서 한 단어를 읽어옴*/

//iostream 헤더 파일은 포함시켜야하낟.
//iostream헤더 파일은 출력을 처리하느 ostream클래스를 정의한다.
//iostream 헤더파일은 ㅊout이라는 ostream 변수 또는 객체를 선언한다.
// std 이름 공간을 지정해야한다. 예를 들면 cout과 endl과 같은 요소들을 사용하기 위해 using 지시자 또는 std::접두사를 사용할 수 있다.
/*
1번 비/전공 
2번 나이
3번 학력
4번 
*/
// using namespace std;
// char automobie[50];
// int year;
// double a_price;
// double d_price;

// ofstream outFile;
// outFile. open("carinfo.txt");

// cout << "자동차 메이커와 차종을 입력하시오: ";
// cin.getline(automobie, 50);
// cout << "연식을 입력하시오";
// cin >> year;
// cout << "구입가격을 입력하시오";
// cin >> a_price;
// d_price = 0.913 * a_price;

// //cout으로 스크린에 정보를 디스플레이
// cout << fixed;
// cout.precision(2);
// cout.setf(ios_base::showpoint);
// cout << "메이커와 차종: " << automobie << endl;
// cout << "연식: " << year << endl;
// cout << "구입 가격$" << a_price <<endl;
// cout << "현재 가격$" << d_price <<endl;

// //cout 대신 outFile을 사용하여 똑같은 일을 처리할 수 있다.

// outFile << fixed;
// outFile.precision(2);
// outFile.setf(ios_base:: showpoint);
// outFile << "메이커와 차종: " << automobie << endl;
// outFile <<"연식: " << year << endl;
// outFile << "구입 가격$" << a_price <<endl;
// outFile << "현재 가격$" << d_price <<endl;

// outFile.close();
// return 0;


















// }
#include<iostream>
#include<fstream>
#include<cstdlib>

const int SIZE = 60;
int main(){
    using namespace std;
    char filename[SIZE];
    ifstream inFile;
    cout << "데이터 파일의 이름을 입력하시오: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);
    if (!inFile.is_open()){
        cout << filename << " 파일을 열 수 없습니다." <<endl;
        cout << "프로그램을 종료합니다.\n";
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0;
    int count = 0; //읽은 항목의 개수

    inFile >> value;
    while (inFile.good()){
        ++count;
        sum += value;
        inFile >> value;

    }
    if (inFile.eof())// 
    cout << "파일 끝에 도달했습니다.\n";
    else if (inFile.fail())
    cout << "데이터 불일치로 입력이 종료되었습니다.\n";
    else 
    cout << "알 수 없는 이유로 입력이 종료되었습니다.\n";
    if (count == 0)
    cout << "데이터가 업습니다.\n";
    else{
        cout << "읽은 항목의 개수: " << count << endl;
        cout << "합계: " << sum << endl;
        cout << "평균: " << sum / count << endl;
    }
    inFile.close();
    return 0;
}