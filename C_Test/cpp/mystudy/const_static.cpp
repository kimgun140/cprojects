#include<iostream>
using namespace std;
class CountryArea{
    public:
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 957290;
    const static int SOUTH_KOREA = 9922;
};

int main(void){
    cout<< "러시아 면적: " << CountryArea::RUSSIA<<"km"<<endl;
    cout<<"캐나다면적: " << CountryArea::CANADA<<"km"<<endl; 
}
/*

const static 멤버 변수는 클래스가 정의 될떄 지정된 값이 유지되는 상수이기 때문에,
위 예제에서 보이는 바와 같이 초기화가 가능하다. 
*/