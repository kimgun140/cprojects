#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    ifstream iFile;
    string line = "", first = "";
    int location = 0;

    iFile.open("201402.csv");
    getline(iFile, line);
    // getline(iFile, line); ifile을 line에 저장한다. 공백 문자까지 포함해서 line에 한 줄을 담는다.
    // while (getline(iFile, line))
    // {
        location = line.find(',');
        //find(begin, end, value);함수 begin 시작지점, end끝낼지점, value 찾을 값 
        //자료 구조(array, vector)에서 원하는 값의 위치를 탐색하는함수
        //
        first = line.substr(0, location); 
        //
        //substr(pos,count)
        //문자열의 일부를 리턴하는 함수  pos번쨰 문자부터 count 길이만큼의 문자열을 리턴한다. 
        // count의 길이가 본래 문자열의 길이보다 길다면 , 그 이상을 반환하지 않고 문자열 끝까지만 리턴한다. 
        //pos가 원래 문자열의 길이보다 먼 위치를 나타내면 오류난다.
        //pos는 첫번째 문자열의 위치, count 부분문자열의 길이

        line = line.substr(location + 1, line.length());
        //length() 문자열의 길이를 반환한다. 여기서는 반환할 쉼표의 위치부터 line의 string의 길이만큼 

        // cout << first << endl;
        // <<"line"<<line  <<endl;

        cout << line << endl;
    // }
    return 0;
}