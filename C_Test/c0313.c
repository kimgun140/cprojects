
// #include<stdio.h>
// int main (void)
// {

// // 데이터형 변화 p.219
// // 정수나누기 정수가 실수가 되면 명시적인 형변환을 시켜줘서 자료형을
// // convert.c 자동데이터형변환
//     char ch;
//     int i;
//     float fl;
//     fl = i = ch = 'C';
//     printf("ch =  %c, i = %d, fl = %2.2f\n", ch, i ,fl);
//     ch = ch +1; // 정수형 67
//     i = fl + 2*ch; // 67 4바이트
//     fl = 2.0 * ch + i; // 67.00
//     printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
//     // 67 +1로 68 D에 해당하는 아스키코드가 반환된다.
//     ch = 1107;
//     printf("이제 ch = %c\n", ch);
//     ch = 80.99;
//     printf("이제 ch = %c\n", ch);

//     return 0;

// }


//     return 0;

// // running.c 육상선수에게 유요한 프로그램
// #include<stdio.h>
// const int S_PER_M = 60; 
// const int S_PER_H = 3600;
// const double M_PER_K = 0.62137;
// int main(void)
// {

//     double distk, distm;
//     double rate;
//     int min, sec;
//     int time;
//     double mtime;
//     int mmin, msec;

//     printf("이 프로그램은 미터단위계로 측정한 달리기 기록을\n");
//     printf("1마일을 달린 시간과, 평균속도(mph)로 변환한다.\n");
//     printf("달린 거리를 킬로미터 수로 입력하시오.\n");
//     scanf("%lf", &distk);
//     printf("달린 시간을 분 수와 초 수로 입력하시오.\n");
//     printf("먼저 분 수부터 입력하시오\n");
//     scanf("%d", &min);
//     printf("이제 초 수를 입력하시오.\n");
//     scanf("%d", &sec);

//     time = S_PER_M * min + sec;

//     distm = M_PER_K * distk;

//     rate = distm / time * S_PER_H;

//     mtime = (double) time / distm;
//     mmin = (int) mtime / S_PER_M;
//     msec = (int) mtime % S_PER_M;
//     printf("당신은 %1.2f킬로미터(%1.2f마일)를 %d분, %d초에 달렸다\n", distk, distm, min,sec);
//     printf("이 페이스는 1마일 %d분, %d초에"
//     "달린 것에 해당하낟.\n", mmin,msec);
//     printf("평균속도는 %1.2f mph였다\n", rate);

//     return 0;

// }

//  x = (2+3) *6;

#include<stdio.h>
int main (void)

{   float a = 30.0 /40.0 * 5.0;
    float b = 30.0 / (4.0 *5.0);
    float c = 30 /4 * 5;
    printf("%f",c);
    int i = 1;
    float n;
    printf("조심해! 한 무더기의 소수점을 가진 수들이 쏟아진다!\n");
    while (i++ <30)
    {
        n = 1.0/i;
        printf("%f", n);
        printf("\n");
     
    }
    printf("이제 끝이다!\n");
    
    return 0;
}

// 5번 문제
// #include<stdio.h>
// #define S_TO_M 60;
// int main (void)
// {
//     int sec, min, left;
//     printf("이 프로그램은 초 수로만 주어지는 시간을");
//     printf("분 수와 초수로 변환한다.\n");
//     printf("초 수를 입력하시오,\n");
//     printf("프로그램을 종료하려면 0을 입력하시오.\n");
//     while (sec >0);
//     {
//         scanf("%d", &sec);
//         min = sec/S_TO_M;
//         left = sec % S_TO_M;
//         printf("%d초는 %d분, %d초입니다.\n", sec, min, left);
//         printf("다음 입력은?\n");
//         /* code */
//     }
//         printf("안녕!\n");
    
//     return 0;
// }

// #include<stdio.h>
// #define FORMAT "%s! C는 멋지다.\n"
// int main(void)
// {
//     int num = 10;

//     printf(FORMAT,FORMAT);
//     printf("%d\n", ++num);
//     printf("%d\n", num++);
//     printf("%d\n", num--);
//     printf("%d\n", num);
//     return 0;

// }
// // 7번 문제
// #include<stdio.h>
// #define FORMAT 
// int main(void)
// {
//     char c1, c2;
//     int diff;
//     float num;

//     c1 = 'S';
//     c2 = '0';
//     diff = c1-c2;
//     num = diff;
//     printf("%c%c%c:%d %3.2f\n", c1,c2,c1,diff,num);
//     return 0;

// }

// //8번문제
// #include<stdio.h>
// #define TEN 10 
// int main(void)
// {

//     int n = 0;
//     while (n++ <TEN)
//     {
//         printf("%5d",n);
//         /* code */
//     }
//     printf("\n");
    
//     return 0;

// }

// // 9번 문제
// #include<stdio.h>
// #define TEN 10 
// int main(void)
// {
//     char ch = 'a';
//     while (ch <='g')
//     {
//         printf("%5c",ch);
        
//     }
//     printf("\n");



//     return 0;

// }

// #include<stdio.h>
// int main(void)
// {

    
//     return 0;

// }