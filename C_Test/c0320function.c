//함수
// 함수를 정의하고 그 함수를 사용하는걸 함수 호출이라고한다.
// 함수 내에서 정의되는 변수는 지역변수이다.
// 리스트9.1 -- lethad1
// #include<stdio.h>
// #include<string.h>
// #define NAME "GIAGATHINK, INC."
// #define ADDRESS "101 Megabuck Plaza"
// #define PLACE "Megapolis, CA 94904"
// #define WIDTH 40
// #define SPACE ' '
// void show_n_char(char ch, int num);
// // void starbar(void); // 함수 프로토타입
// int main(void){
//     int spaces;

//     show_n_char('*', WIDTH);
//     putchar('\n');
//     show_n_char(SPACE, 12);
//     printf("%s\n", NAME);
//     spaces = (WIDTH - strlen(ADDRESS)) / 2;

//     show_n_char(SPACE, spaces);
//     printf("%s\n", ADDRESS);
//     show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);

//     printf("%s\n", PLACE);
//     show_n_char('*', WIDTH);
//     putchar('\n');
//     return 0;
// }
// void show_n_char(char ch, int num){
//     int count;
//     for (count = 1; count <= num; count++)
//             putchar(ch);
// }
//전달인자를 사용하는 함수
//함수헤더에서 각 전달인자마다 타입을 작성해야한다. 올바른 조건에 따라서 써야한다.
// 전달인자와 동일한 타입과 변수나, 상수를 대입할 수 있다. 대입된 값이 함수에 작성된 로직에 사용된다.
// 함수 내에서 리턴을 만나면 함수를 종료한다. ㅇㅋ/
// 리턴옆에 전달인자가 있으면 종료하면서 호출한 위치로 돌아가면서 위치에 리턴값을 전달해준다. 

// void starbar(void){
//     int count;
//     for (count = 1; count <= WIDTH; count++)
//     putchar('*');
// putchar('\n');
// }
// 반복코드 줄임
// 수정사항에 따른 유지보수가 좋다
// 옵션화를 할 수 있다. 여러가지 버젼을 줄 수 있다는 말 *찍었다가 #으로도 바꾸기

//리스트 9.3
//lesser.c --둘중에서 작은것을 구한다.

// #include<stdio.h>
// int imin (int, int); //여기에서 반환된 imin의 값을 int로 이미 선언되었다. 사용될 값과 구조를 미리 알려준다ㅏ.

// int main(void){
//     int evil1, evil2;
//     printf("두 정수를 입력하시오 (끝내려면q):\n");
//     while(scanf("%d%d", &evil1, &evil2) == 2)
//     {
//         printf("(%d %d)에서 작은 것은 %d\n",evil1, evil2,imin(evil1,evil2));
//       //imin에서 반혼된 값을 대입한다.
//         printf("두 정수를 입력하시오 (끝내려면 q):\n");
//     }
//     printf("종료!\n");

// return 0;}

// int imin(int n, int m){
//     int min;
//     if (n<m){
//         min = n;
//     }else{
//         min = m;
//     }
//     return min;
// }
// 재귀함수 423페이지
// 자기 자신을 호출하는 함수 약간 반복문처럼 된다
//탈출 조건이이있다. 매개변수의 값이 달라진다.

// //recursive.c 재귀를 설명한다.
// #include<stdio.h>
// void up_and_down(int);

// int main(void){
//     up_and_down(1);
//     return 0;
// }
// void up_and_down(int n){
//     printf("Level %d: n의 메모리 수 %p\n",n ,&n); //1
//     if(n<4){
//         up_and_down(n+1);
//     }
//     printf("LEVEL %d: n의 메모리 주소%p\n",n,&n);
// }

// //리스트 9.7 factor.c 계승을 계산하기 위해 루프와 재귀를 사용한다.
// #include<stdio.h>
// long fact(int n);
// long rfact(int n);
// int main(void){
//     int num;
//     printf("이 프로그램은 계승을 계산합니다. \n");
//     printf("0-12범위의 한 값ㅇ르 입력하시오 (끝내래면 q): \n");
//     while(scanf("%d", & num) == 1){
//         if (num <0)
//         printf("음수는 계승이 정의되지 않습니다.\n");
//         else if (num >12)
//         printf("13미만을 입력 하시오.\n");
//         else{
//             printf("루프:%d!=%ld\n", num, fact(num));
//             printf("재귀:%d!= %ld\n", num ,rfact(num));
//         }
//         printf("0-12 범위의 한 값을 입력하시오 (끝내려면 q): \n");
//     }
//     printf("종료!\n");
//     return 0;
// }
// long fact(int n){
//     long ans;
//     for (ans = 1; n > 1; n--){
//         ans *=n;
//     }
//     return ans;
// }
// long rfact(int n){
//     long ans;
//     if (n>0){
//         ans = n * rfact(n-1);
//     }else
//     ans = 1;

//     return ans;
// }

// //리스트 9.8 binary.c 정수를 2진수 표기로 출력한다.

// #include<stdio.h>
// void to_binary(unsigned long n);
// int main(void){
//     unsigned long number;
//     printf("정수 하나를 입력하시오(끝내려면 q):\n");
//     while(scanf("%lu", &number) == 1){
//         printf("2진수 표기:");
//         to_binary(number);
//         putchar('\n');
//         printf("정수 하나를 입력하시오(끝내래면q):\n");
//     }
//     printf("종료!\n");
//     return 0;
// }

// void to_binary(unsigned long n){
//     int r;
//     r = n%2;
//     if(n>=2)
//         to_binary(n/2);
//         putchar(r ==0? '0': '1');
//         // 왼쪽이 참일때 오른쪽이 거짓일때

//         return ;
// }
// 피보나치는 pass한다.

// 9.11 .hotel.h .
//다음에


// 주소 연산자 가보자구
//변수는 메모리 상에 저장이 된다. 그 메모리의 주소가 있다. 16진수로 되어있다.
// 번지수로 찾기 어려우니 변수의 이름으로 호출은 한다. 하지만 주소값이  필요한 경우에는
// 그 때 주소연산자를 사용할 수 있다. 모든 변수는 메모리 번지수에 저장이 되고 
// 지역변수는 스택 메모리에 저장이되고 그곳에는 값이 있고 값이 저장된 메모리 주소가 있을것이다.
// **변수는 값과 메모리 주소를 가지고있다. c계열 언어에서만 주소장난질이 가능하다.
// 나아가면 주소를 별개로 저장할 수 있다. 주소를 변수에 저장할 수 있다. int* pnum = &num 포인터 변수 주소값을 가진 특별한 변수 포인터 변수 
// &는 주소 연산자이다. 448페이지

// //리스트 9.12 locheck.c 변수들이 어디에 저장되는 지 확인한다.
// #include<stdio.h>
// void mikado(int);
// int main(void){
//     int pooh = 2, bah = 5;
//     printf("main()에 있는 pooh = %d, &pooh= %p\n", pooh, &pooh);
//     printf("main()에 있는 bah = %d, &bah = %p\n", bah, &bah);
//     mikado(pooh);
//     return 0;
// }
// //호출 함수에 있는 변수 바꾸기
// // 교환이 안되는 예제


// void mikado(int bah){
//     int pooh = 10;
//     printf("mikado()에 있는 pooh = %d, &pooh = %p\n", pooh, &pooh);
//     printf("mikado()에 있는 bah = %d, &bah = %p\n", bah,&bah);
// }


// #include<stdio.h>
// void interchange(int u, int v);
// int main(void){

//     int x = 5, y=10;
    
//     printf("교환 전 x = %d, y =%d\n", x,y);
//     interchange(x,y);
//     printf("교환 후 x = %d, y = %d\n", x,y);
    
//     return 0;
// }
// main과 interchange는 메모리가 아예 다르다. 
//전달인자를 사용하면 값을 넘겨주는거다 다시말하면 값을 복사해서
// 다른 메모리에 넣어주는것이다. 값이 같은것이지 메모리 주소가 복사되는것이 아니다!!!!!!!
// void interchange(int u, int v)
// {
//     printf("교환 전 u = %d, v =%d\n", u,v);

//     int temp;
//     temp = u;
//     u = v;
//     v = temp;
//     printf("교환 후 u = %d, v = %d\n", u,v);

// }


// temp = *u;는 u가 저장된 주소로 가서 값을 가져온다는 말이다. 
// *u = *v는 u를 가지고 있는 주소에 v를 가지고 있는 주소의 값을 대입한다는 말이다!!!!
// *은 간접연산자 indirection연산자 또는 역참조 dereferencing 연산자라고한다. 
#include<stdio.h>
void interchange(int* u, int* v);
int main(void){

    int x = 5, y=10;
    
    printf("교환 전 x = %d, y =%d\n", x,y);
    interchange(&x,&y);
    printf("교환 후 x = %d, y = %d\n", x,y);
    
    return 0;
}
void interchange(int* u, int* v)
{

    int temp;

    temp = *u;
    *u = *v;
    *v = temp;

}