// 배열
//배열의 이름은 배열의 메모리 주소의 첫번째 위치를 가르킨다.
//scanf에서  이름을 써서 주소에 접근하는것을 보면 안다.이름이 주소를 가르킨다.
//flizny == &flizny[0]  이건 동일하지
// 포인터를 활용해서 배열의 요소에 접근할 수 있다.
// #include<stdio.h>
// #define SIZE 4
// int main(void){
//     short dates[SIZE];
//     short* pti;
//     short index;
//     double bills[SIZE];
//     double* ptf;

//     pti = dates;
//     ptf = bills;
//     printf("%23s %15s\n", "short", "double");
//     for (index = 0; index <SIZE; index++){
//         printf("포인터 + %d: %10p %10p\n", index, pti+ index, ptf +index);

//     }
// return 0;
// }

// //day_mon3. -- 포인터 표기 사용한다.
// #include<stdio.h>
// #define MONTHS 12

// int main(void){
//     int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
//     int index;

//     for (index = 0; index <MONTHS; index++)
//     printf("%2d월: 날짜 수 %2d\n", index +1, *(days+index)); //days[index]와 같다.
//     return 0;
//     //포인터에 1을 더한다는것 기억단위를 하나 더하는것이다. doubl형은 8바이트를 사용한다 따라서 기억단위는 8바이트가 되고 그렇기 때문에 포인터를 선언할때 객체의 타입을 선언해줘야하는 이유이다. 
//     //그래서 데이터의 타입을 알아야 다음데이터를 찾으려면 크기를 알아야하고 크기를 알기 위해서는 데이터 타입을 알아야한다. ㅇㅋ? ㅇㅋ
// }



// //페이지 487 
// //함수 배열 포인터
// //주소값에 접근해서 원본값을 수정하겠다.
// //sum_arr1.c -- 배열의 원소들의 합을 구한다.
// #include<stdio.h>
// #define SIZE 10
// int sum(int ar[], int n); //전방 선언 함수의 원형 (프로토타입) 얘를 호출할 수 있다. 안해주면 함수전체를 위에 써야 메인에서 사용이 가능할것이다. 
// //타입 이름 (입력인자1 입력인자2(argument)) 
// int main(void){
//     int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
//     long answer;

//     answer = sum(marbles,SIZE);
//     printf("구슬의 전체 개수는 %ld개입니다. \n", answer);
//     printf("marbles의 크기는 %zd바이트입니다.\n", sizeof marbles);

//     return 0;
// }

// int sum (int ar[], int n){ //배열 크기느 얼마 일까??
// // 함수 내에서는 int ar[]이 마블즈인지 모른다. 단지 주소값을 복사해서 받았을 뿐이다.
// // 그 주소를 활용해서 배열처럼 썻을 뿐이지 전체 크기는 모른다. 이름만 가지고 전체 크기를 확인할 수 없다. 배열의 크기를 써주는이유다.
// //자료구조를 함수에 넣으면 원본구조의 값을 바꾼다. 
//     int i;
//     int total = 0;
//     for (i =0; i<n; i++)
//     total +=ar[i];
//     printf("ar의 크기는 %ld바이트 입니다.\n", sizeof ar);

//     return total;
// }

// //sum_arr2.c -- 배열의 원소들의 합을 구한다.
// #include<stdio.h>
// #define SIZE 10
// int sump(int* start, int* end); //전방 선언 함수의 원형 (프로토타입) 얘를 호출할 수 있다. 안해주면 함수전체를 위에 써야 메인에서 사용이 가능할것이다. 
// //타입 이름 (입력인자1 입력인자2(argument)) 
// int main(void){
//     int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
//     long answer;

//     answer = sump(marbles,SIZE + marbles);
//     printf("구슬의 전체 개수는 %ld개입니다. \n", answer);

//     return 0;
// }

// int sump (int* start, int* end){ //배열 크기느 얼마 일까??
// // 함수 내에서는 int ar[]이 마블즈인지 모른다. 단지 주소값을 복사해서 받았을 뿐이다.
// // 그 주소를 활용해서 배열처럼 썻을 뿐이지 전체 크기는 모른다. 이름만 가지고 전체 크기를 확인할 수 없다. 배열의 크기를 써주는이유다.
// //자료구조를 함수에 넣으면 원본구조의 값을 바꾼다. 
//     int total = 0;
//   while( start <end){
//     total += *start;
//     start++;
//   }
//     return total;
// }

//order.c --포인터 연산에서의 우선순위
// #include<stdio.h>
// int data[2] = {100,200};
// int moredata[2] = {300,400};
// int main(void){
//     int *p1,*p2,*p3;
//     p1 = p2 = data;
//     p3 =moredata;
//     printf(" *p1 = %d,  *p2 = %d,   *p3 = %d\n",
//                     *p1,*p2,*p3);
//     printf("*p1++ = %d, *++p2  = %d, (*p3)++ = %d\n",
//                     *p1,*p2,*p3);
//     printf("*p1 = %d, *p2=%d, *p3 = %d\n",
//                     *p1, *p2,*p3);
//     return 0;
// }

//리스트 10.13ptr_ops.c -- 포인터 연산
// #include<stdio.h>
// int main(void){
//     int urn[5] = {100, 200,300,400,500};
//     int* ptr1,*ptr2,*ptr3;

//     ptr1 = urn; //포인터에 주소를 대입한다.
//     ptr2 = &urn[2]; //포인터에 주소를 대입한다.
//         //역참조된 포인터를 참조하여 포인터 주소를 얻는다.
//     printf("포인터의 값, 역참조된 포인터가 가리키는 값, 포인터의 주소:\n");
//     printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
//                     ptr1, *ptr1, &ptr1);

//     //포인터 덧셈
//     ptr3 = ptr1 +4;
//     printf("\n포인터에 정수를 더한다.:\n ");
//     printf("ptr1 +4 = %p, *(ptr4 + 3) = %d\n",
//                     ptr1 + 4, *(ptr1 +3));

//     ptr1++;
//     printf("\n ptr1++를 수행한 후의 값:\n");
//     printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
//                     ptr1, *ptr1, &ptr1);
//     ptr2--;
//     printf("\n--ptr2 를 수행한 후의 값:\n");
//     printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
//                     ptr2, *ptr2, &ptr2);
//     --ptr1;         //최초의 값으로 복원한다.
//     ++ptr2;         //최초의 값으로 복원한다.
//     printf("\n두 포인터를 최초의 값으로 복원한다.:\n");
//     printf("ptr1 =%p, ptr2 = %p\n", ptr1,ptr2);
//                     //포인터에서 다른 포인터를 뺀다.
//     printf("\n포인터에서 다른 포인터를 뺀다:\n");
//     printf("ptr2 = %p, ptr1 = %p, ptr2 -ptr1 = %td\n", 
//                      ptr2 , ptr1,ptr2 -ptr1);
//                         //포인터에서 정수를 뺀다.
//     printf("\n포인터에서 정수를 뺀다:\n");
//     printf("ptr3 = %p, ptr3 -2 = %p\n", ptr3, ptr3 -2);
    
//     return 0;
// }


#include<stdio.h>
int main(void){
    int zippo[4][2] = {{2,4}, {6,8}, {1,3}, {5,7}};
    int (*pz)[2];
    pz = zippo;

    printf("pz = %p,        pz + 1 = %p",
                pz,             pz +1);
    printf("pz[0] = %p, pz[0] + 1 = %p \n",
                *pz,        *pz + 1);
    printf("    *pz = %p,       *pz + 1 = %p\n",
                *pz,            *pz +1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("    *pz[0] = %d\n", *pz[0]);
    printf("        **pz = %d\n",**pz );


    return 0;
}