//이제껏 변수를 이용해서 값을 불러왔었다.
// 포인터를 배우면서 주소에 접근하고 불러올 수 있게 되었다.
//포인터란?
//*주소를 저장하기 위한 특별한 '변수'이다.*
//int, char, float,double, <- 정수 문자 실수
// 포인터라는거 -> 메모리 주소를 저장하는 변수
// 변수인데 속에 담긴 내용ㅇ이 메모리 주소
//메모리 주소는 보안의 강화를 위해 매실행 마다 바꿔준다.
// 포인터 변수에 담긴 주소를 통해서 거기에 있는 값을 읽어 낼 수 있다.
//그 주소에 담긴 자료형은 무엇인지 알아야
//해당 주소에서 몇바이트를 읽어야하는지를 알아야 그 자료에 정확히 접근할 수 있다.
//그 주소에 어떤 형의 데이터가 있는지를 명시 해줘야한다.
//그래서 포인터 앞에 자료형을 붙이는거다.
//포인터 변수 부르는 법
// int pointer(pointer to an in)
// int* pnum = &num
//비유 현실세계
//우리집에 놀러와 이게 우리집 주소야 호수 적힌 종이를 주면서
//실제 변수 = 친구, 포인터 =종이
//포인터에 저장된 주소도 바꿀 수 있나요??
//포인터도 변수 따라서 포인터에 저장된 값도 변경 가능합니다.

// int num1 = 10;
// int num2 =20;
// int num3 =30;
// int* ptr1 = &num1;
// int* ptr2 = &num2;
// int* ptr3 = &num3;


// ptr3 = ptr2; = &num2
// ptr2 = ptr1; = &num1
// ptr1 = ptr2; = &num1


//역참조 연산자 *
//조수에 저장된 값을 출력하세요
//int num1 = 10;
// int* ptr = &num1;
//printf("%d\n", *ptr);

//포인터가 저장하고있는 위치로 가서
//거기에 저장된 값에 접근 (읽거나 씀)gka
//포인터가 가리키는 값에 접근한다고 말함

//참조와 역 참조
//포인터가 이미 하고 있는 일
//어떤 변수의 값을 직접 가져다 쓰는게 아니라
//그게 어디 있다고 '참조'
//즉 값이 어디에 있는지 가가리키고 있는 것
//역 참조
//주소로 직접가서 거기에 저장되어 있는 값에 접근하는 것
//참조 (reference)의 반대라서 역참조(dereference) 
//실제 데이터에 간접적으로 (주소를 통해서 접근)접근 하니까
//indirect연산자 간접연산자라고도 한다.
//지금까지는 값으 복사해서 썻다.
//int fuc(inx, inxy);{
//int num1 = 10;
// int num2 = 20
// int num3 = num1; ->10
// }
// int num 4 = func(num1,num2);

//이제 그렇게 하지않고 원본에 접근해서 사용하겠다.
// 복사를 해서 메모리를 낭비 하지 않겠다.
//컴퓨터 궂조에서 데이터를 오랫동안 메모리에 저장하는 방법
//추상적 개념을 이해하는 능력 -> 컴퓨터처럼 생각

// #include<stdio.h>
// int main(void){

//     int num1 = 15;
//     int num2 = 30;
//     int num3 = 45;

//     int* ptr1 = &num1;
//     int* ptr2 = &num2;
//     int* ptr3 = &num3;

//     ptr1 = ptr2;
//     ptr2 = ptr3;

//     *ptr3 *=2;
//     *ptr1 += *ptr3;
//     *ptr2 *= 2;
//     printf("%d %d %d",num1, num2, num3);
// return 0;
// }


// 배열
// 순번이 있는(0번부터 순번을 매긴다.) 원시 자료형 스택메모리에 저장된다.
//자료형 배열이름 [크기]; 이렇게 구성된다.
// 자료형과 크기를 알려줘야 순번에 따라서  제대로 읽어올 수 있다.
//배열의 이름은 배열의 첫번째 요소의 주소다.?????
//

//배열의 초기화                 초기화
//타입 이름 [크기] = {1,2,3,4,5,6,6,7,77,6,53,34};
// //page. 467
// #include<stdio.h>
// #define MONTHS 12
// int main(void){
//     int days [MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
//     int index;

//     for (index = 0; index < MONTHS; index++)
//             printf("%2d월: 날짜 수 %2d\n", index+1, days[index]);
//     return 0;
// }
// // no_data.c -- 초기화 시키지 않은 배열
// #include<stdio.h>
// #define SIZE 4
// int main(void){
//     int no_data[SIZE];
//     int i;
//     printf("%2s%14s\n", "i", "no_data[i]");
//     for ( i = 0; i <SIZE; i++)
//             printf("%2d%14d\n", i , no_data[i]);
//     return 0;
// }
// // 초기화 시켜주지않아서 컴파일러는 우연히 그 메모리 위체 놓여 있는 값들을 사용한다. 초기화를 안했기 때문에


// #include<stdio.h>
// #define SIZE 4
// int main(void){
//     int some_data[SIZE] = {1492, 1066};
//     int i;
//     printf("%2s%14s\n", "i", "no_data[i]");
//     for ( i = 0; i <SIZE; i++)
//             printf("%2d%14d\n", i , some_data[i]);
//     return 0;
// }

// // 초기값리스트에 있는 값들을 다 사용하고 나머지는 0으로 초기화했다.

// //page. 467
// #include<stdio.h>
// #define MONTHS 12
// int main(void){
//     int days [] = {31,28,31,30,31,30,31,31,30,31,30,31};
//     int index;

//     for (index = 0; index < sizeof days/ sizeof days[0]; index++)
//             printf("%2d월: 날짜 수 %2d\n", index+1, days[index]);
//     return 0;
// }
//전체 배열의 크기를 배열의 첫번째 값의 크기만큼 나눠주면 몇개의 원소가 있는지 알 수 있다. 

//10.5는 패스

//배열에 값을 대입하기

// #include<stdio.h>
// #define MONTHS 12
// int main(void){
//     int days [] = {31,28,31,30,31,30,31,31,30,31,30,31};
//     int index;
//     int sum = 0;
//         // days[] ;
//     for (index = 0; index < sizeof days/ sizeof days[0]; index++){
//                 days[index] = 2*days[index];
//                 printf("%2d\n", days[index]);
//                 sum += days[index];
//                 // printf("%d",sum);

//     }
//                 printf("%d",sum);

//     return 0;
// }
// #include<stdio.h>
// int main (void){
    // int days[12] = {};
    // //배열의 크기가 초기화 해준 값의 크기보다 작아서 오류발생한다.
    // int sum = 0;
    // int index ;
    // for (index = 0; index <sizeof days/sizeof days[0]; index++ ){
    //         // printf("%2d",days[index]);
    //         days[index] = index;
    //         printf("%3d",days[index]);

    // }
// int num1 = 15;
// int num2 = 30;
// int num3 = 45;
// int num4 = 50;
// int num5 = 100;

// int* ptr1 = &num1;
// int* ptr2 = &num2;
// int* ptr3 = &num3;
// int* ptr4 = &num4;
// int* ptr5 = &num5;

// ptr1 = ptr2;
// ptr2 = ptr3;
// ptr4 = ptr1;
// ptr5 = ptr4;

// *ptr3 *= 2;

// printf("%d",ptr1);

// }

//p.474

// 배열의 크기가 바뀌면 버그 생기니까 보통 배열의 크기는 상수선언을 해서
// 상수로 사용한다.

//페이지478
//다차원 배열 타입 이름 [][]이부분은 리스트랑 비슷한듯?

// rain.c -- 강우량 데이터로부터 각 해의 총 강우량과 몇년에 걸쳐 계산한 연평균 강우량,각달의 월 펼균 강우량을 구한다.
#include<stdio.h>
#define MONTHS 12
#define YEARS 5
int main(void){

    //2010년에서 2014년까지의 강우량 디이터의 초기화
    const float rain[YEARS][MONTHS] = 
    {
        {4.3,1.2,4.3,4.3,4.0,2.0,1.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    int year, month;
    float subtot, total;
    float maxx = 0.0;

    printf("년도 강우량(인치)\n");
    for (year = 0, total = 0; year < YEARS; year++){
        //각 해에 대해 12달치 강우량을 더한다.
        for (month = 0, subtot = 0; month < MONTHS; month++)
                subtot += rain[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;
    }
    printf("\n년 평균 강우량은 %.1f인치입니다.\n", total/YEARS);
    printf("월편균 강우량은 다음과 같습니다. \n\n");
    printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct");
    printf("Nov Dec\n");

    for (month = 0; month < MONTHS; month++){
        for (year = 0,  subtot = 0; year< YEARS; year++)
                subtot += rain[year][month];
            printf("%4.1f", subtot/YEARS);
    }
    printf("\n");

    // for (month = 0; month < MONTHS; month++){
    //     for (year = 0, subtot = 0; year < YEARS; year++){
    //     maxx = 0;

    //             maxx = rain[year][month] >= rain[year][month+1] ? rain[year][month] : rain[year][month+1];
    //     }
                    
    //                 printf("%.1f\n", maxx);
                    
                
    //     // printf("%4.1f", subtot/YEARS);
    // }
        // for (year = 0, total = 0; year < YEARS; year++){
        // //각 해에 대해 12달치 강우량을 더한다.
        // for (month = 0, subtot = 0; month < MONTHS; month++)
        //         maxx = rain[year][month] >= rain[year][month+1] ? rain[year][month] : rain[year][month+1];
        // printf("%.1f\n", maxx);
        // maxx = 0;

        for (year = 0; year < YEARS; year++){
        //각 해에 대해 12달치 강우량을 더한다.
        for (month = 0; month < MONTHS; month++)
                if (rain[year][month] >= maxx)
                        maxx = rain[year][month];
        printf("%.1f\n", maxx);
        maxx = 0;

    }
    // printf("%.1f\n", maxx);
    printf("\n");

    return 0;
}