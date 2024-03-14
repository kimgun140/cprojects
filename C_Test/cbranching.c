// //colddays.c -- 영하로 내려간 날들의 백분율을 구한다.
// #include<stdio.h>
// int main(void)
// {
//     const int FREEZING = 0;
//     float temprature;
//     int cold_days = 0;
//     int all_days = 0;

//     printf("최저 기온들의 목록을 입력하시오.\n");
//     printf("섭씨 단위를 사용하시오(입력을 끝내려면 q).\n");
//     while (scanf("%f", &temprature) == 1)
//     // 숫자가 아닌 문자가 입력되면 스캔이 읽어오는데 오류가 발생해서 ==1이 성립하지않는다. 그래서 입력을 종료한다.
//     {
//         all_days++;
//         if (temprature < FREEZING)
//         cold_days++;
//     }
//     if (all_days !=0)
//     {printf("전체 %d일 중에 영하의 날씨는 %.1f%%였습니다.\n",
//     all_days, 100.0 * (float) cold_days / all_days);   
//     }
//     if (all_days == 0)
//     {
//         printf("입력된 데이터가 없습니다.!\n");
//     }
//     return 0;
// }


// //cyper1.c -- 스페이스는 유지하고, 입력을 변경한다.
// #include<stdio.h>
// #define SPACE ' '
// int main(void)
// {
//     char ch;
//     printf("문자 입력좀");
//     ch = getchar();
    
//     while (ch != '\n')
//     {
//         if (ch == SPACE)
//         {   
//             putchar(ch);
//             printf("공백말고 문자 입력좀");
            
//         }
//         else  
//         {   
//             putchar(ch +1);
//         }
            
//         ch = getchar();
//     }
    
//     putchar(ch);
//     return 0;
// }

// // cypher.c -- 알파벳 문자가 아닌 것들은 유지하고, 입력을 변경한다.
// #include<stdio.h>
// #include<ctype.h>

// int main(void)
// {

//     char ch;
//     printf("문자 입력좀");
//     while ((ch =getchar()) != '\n')
//     {
//         if (isalpha(ch)) //문자면 변경해서 출력
        
//         {
//             putchar(ch +1);
//         }
//         else // 문자가 아니면 변경하지 않고 그냥 출력
//         {printf("문자가 아님:");
//             putchar(ch);
//         }
//     }
    
//     return 0;
// }

// #include<stdio.h>
// #define RATE1 0.13230
// #define RATE2 0.15040
// #define RATE3 0.30025
// #define RATE4 0.34025
// #define BREAK1 360.0
// #define BREAK2 468.0
// #define BREAK3 720.0
// #define BASE1 (RATE1 * BREAK1)
// #define BASE2 (BASE1 + (RATE2 * (BREAK2-BREAK1)))
// #define BASE3 (BASE1 + BASE2 +(RATE3 * (BREAK3-BREAK2)))
// int main(void)
// {
//     double kwh;
//     double bill;

//     printf("사용한 전력량을 입력하시오.\n");
//     scanf("%lf", &kwh);
//     if (kwh <= BREAK2)
//         {
//             bill = RATE1 * kwh;
//         }
//     else if (kwh <= BREAK2)
//         {
//             bill = BASE1 + (RATE2* (kwh -BREAK1));
//         }
//     else if (kwh <= BREAK3){
//         bill = BASE2 + (RATE3 *(kwh -BREAK2));
//     }
//     else{
//         bill = BASE3 + (RATE4 * (kwh -BREAK3));
//     }
// printf("%.1f kwh의 정기요금은 $%1.2f입니다.\n",kwh,bill);
//     return 0;
// }

// divisors.c -- 중첩된 if문들이 어떤 수의 약수들을 출력한다
//  소수검출 
#include<stdio.h>
#include<stdbool.h>
int main(void)
{
    unsigned long num;
    unsigned long div;
    bool isPrime;
    printf("검사할 정수를 하나 입력하시오");
    printf("( 끝내려면 q)\n");
    while (scanf("%lu", &num) == 1)
    {
        for (div = 2, isPrime = true; (div *div) <=num; div++){
            if (num %div == 0){
                if ((div * div) != num){
                printf("%lu,%lu: 둘 다 %lu의 약수다.\n", div,num/div,num);
                }
                else{
                    printf("%lu %lu의 약수다.\n", div, num);
                }
                isPrime = false; //소수가 아니다
            }
        }
        if (isPrime){
        printf("%lu: 소수다\n", num);
        }
        printf("검사할 또 다른 정수를 하나 입력하시오");
        printf("(끝내려면q)\n");
 
    }
    

    return 0;
}