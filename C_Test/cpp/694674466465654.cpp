// #include<iostream>
// void simple();

// int main(){
//     using namespace std;
//     cout << "main()에서 simple() 함수를 호출합니다: \n";
//     simple();
//     cout << "main()이 simple() 함수와 종료 됩니다. \n";
//     //cing.get();
//     return 0;
// }

// void simple(){
//     using namespace std;
//     cout << "여기는 simple() 함수입니다. \n";
// }
// 실제 매개변수 argument  형식매개변수 parameter 실제를 형식에 대입해서 함수에서 사용


/*함수와 배열
배열을 매개변수로 받는 함수
int sum_arr(int arr[], int n) // arr = 배열 이름, n = 크기;
여기서 arr은 사실 배열이 아니라 포인터이다.
포인터를 배열 이름 처럼 사용하는 방법

*/

#include<iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n);
int main(){
    using namespace std;
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    //어떤 시스템에서는 앞에 static을 넣어야 배열을 초기화 시킬 수 있다.

    int sum = sum_arr(cookies, ArSize);
    cout << "먹은 과자 수 합계: " << sum << "\n";
    return 0;
}

int sum_arr(int arr[], int n){
    int total = 0;
    for (int i = 0; i < n; i++)
    total = total + arr[i];
    return total;
}
/*
포인터와 배열을 처리하는 함수
첫 째배열의 이름은 배열의 첫 번째 원소의 주소를  나타낸다.
cookies = &cookies[0]; //배열 이름은 첫 번째 원소의 주소이다.
둘 째sizeof를 배열 이름에 적용하면 배열 전체의 크기가 바이트단위로 구해진다.
셋 째 배열이름에 &를 적용하면 전체 배열의 주소가 생선된다. 
예를 들어 &cookies를 사용하면 int가 4바이트일 때 32바이트 블록 메모리의 주소를 구하게된다.

int sum = sum_arr(cookies, ArSize);
여기서 배열의 첫 번째 주소를 매개변수로 전달하낟. 즉 int*이어야 한다.
int sum_arr(int * arr, int n); // arr = 배열 이름(첫번째 원소의 주소), n = 배열 크기
int*arr이 int arr[]을 대체하였다.  이것은 함수에서 동일한 의미이다. 
arr[i] == *(arr + i) //두 가지 형태로 표현된 값
&arr[i] == arr +i   // 두 가지 형태로 표현된 주소
배열 이름을 포함하여 포인터에 1을 더하는 것은 실제로는 지시하는 데이터형의 바이트 크기를 
더하는 것이다. 포인터 덧셈과 배열 인덱스 사용은 배열의 시작위치에서부터 배열원소를 카운트 한다는 점에 동등한것이다.

함수에 배열의 첫 번째 원소의 주소와 배열 원소의 개수 sum_arr()에 전달한다. 
함수에 cookies의 주소를 포인터 변수 arr에 대입하고 ArSize를 int 형 변수 n에 대입한다.
이 말은 배열의 실제 내용을 전달하는 것은 아니다. 대신 배열이 어디에 있는지(주소), 어떤 종류의 배열인(데이터형), 배열 원소가 몇 개인지(변수N)를 함수에 전달한다.
이정보들을 이용하여 함수는 배열의 원본에 접근할 수 있다. 함수에 일반 변수를 전달하면 복사본을 가지고 작업한다. 
그러나 함수에 배열을 전달하면 원본을 가지고 작업한다. sum_arr() 함수는 여전히 새로운 변수에 대입될 값을 전달하는것이다. 
그 값이 배열의 내용이 아니라 하나의 주소일 뿐이다.

배열의 주소를 매개변수로 사용하는 것은 전체 배열을 복사하는 것보다 시간과 메모리를 절약한다. 
*/