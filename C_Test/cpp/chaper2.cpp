#include <iostream>
int stonetolb(int);

int main (){

    using namespace std;
    int stone;
    cout << "체중을 스톤 단위로 입력하시오 ";
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone << " 스톤은 ";
    cout << pounds << " 파운드입니다." << endl;


    return 0;

}
int stonetolb(int sts){
    return 14 * sts;
}

/*
int main()은 C++에서 int main(void)와 같다. 메인 함수가 운영체재에서 호출받아 
사용되고 반환하는 값은 정수 값이다. 그리고 다른 함수로부터 어떤 값도 전달받지 않는다는 말이다. 
void main()은 c++표준형이 아니기 때문에 피해야한다. 
    return 문을 만나지 못하고 main()이 끝나면 c++는 return 0;와 같은 효과를 낸다.


c++전처리기와 iostream파일 일반적인 입출력 기능을 사용하려면 다음 두행을 프로그램에 꼭 넣어야한다.
#include <iostream>
using namespace std; 
위의 예제는 전처리기 iostream을 사용하고있다. 전처리기는 따로 호출하는것이 아니라 컴파일 시에 자동으로 
실행된다.  해당 전처리기에는 input output의 의미를 담고있다. 전처리지시자를 통해서 실행되는 iostream 헤더파일은
(파일의 앞부분에 들어간다는 의미) c++는 헤더파일에 확장자를 사용하지않는다. 



iostream.h 대신 iostream을 사용할 때 프로그램이 iostream의 정의를 사용하려면 
이름 공간 지시자를 사용해야한다. 이것을 using 지시자라한다. using namespace std; 
이름 공간은 새로운 기능이다. 이름 공간은 같은 이름을 가진 코드들을 사용할 수 있도록 해준다.
wanda()라는 함수가 들어있는 2개의 제품에서 컴파일러는 무엇을 사용해야할지 구분할 수 없다.
그래서 이름 공간이라는 방법이 사용된다. 하나의 제품을 이름 공간이라는 하나의 단위로 포장하는 것이다. 
Microflop이라는 이름 공간으로 포장하면 Microflop::wanda()라는 이름으로 사용해서 구분할 수 있게 해주는것이다.
실제로는 std::cout으로 호출되고 endl이 std::endl이라는 의미이다. using지시자를 사용하지않고도 작성이 가능하다.
std::cout
std::endl
번거러운 과정을 스킵 할 수 있다. 



cout
문자열, 숫자,수,문자 들을 포함한 여러가지 정보들을 출력하는 방법을 알고 있는 객체다.
cout << string; 이게 출력에 필요한 전부다 (string은 정보를 담은 변수)
cout은 문자열을 출력하고 다음행의 시작위치로 커서를 자동으로 넘겨주지않는다. 
그래서 endl을 써줘서 행을 나눠준다.  \n도 사용이 가능하다. 
printf()와 다르게 %d같은 지시자를 통해서 출력할 대상의 타입을 설정해줄 필요가 없다.
편리하다. 이러한 기능은  << 연산자 뒤에 오는 데이터형에 따라서 동작을 결정하기 때문이다. 

cin
키보드로 쳐 넣은 일련의 문자들인 입력을 그것을 저장 할 변수가 받아들이는 형태로 바꾼다. 



연산자 오버로딩 
같은 기호가 여러가지 의미로 사용될 수 있음 <가 비교연산자를 의미라기도하고
출력문에서 << 이렇게 사용될 수도 있음을 의미한다. 컴파일러가 문맥을 통해서 구분한다. 



*/
